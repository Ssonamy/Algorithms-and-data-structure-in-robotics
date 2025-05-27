using Npgsql;
using System.Windows.Forms.DataVisualization.Charting;

namespace SurfaceScanner
{
    public partial class MainSurfaceForm : Form
    {
        private NpgsqlConnection connection;

        public MainSurfaceForm()
        {
            InitializeComponent();
            ConnectToDatabase();
        }

        private void ConnectToDatabase()
        {
            try
            {
                string connString = 
                    "Host=localhost;" +
                    "Port=5434;" +
                    "Username=postgres;" +
                    "Password=hj1314Srf;" +
                    "Database=surface_scan";

                connection = new NpgsqlConnection(connString);
                connection.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Database error: {ex.Message}");
            }
        }

        public void SaveMeasurement(float x, float y, float z)
        {
            using (var cmd = new NpgsqlCommand(
                "INSERT INTO measurements (x, y, z) VALUES (@x, @y, @z)", connection))
            {
                cmd.Parameters.AddWithValue("x", x);
                cmd.Parameters.AddWithValue("y", y);
                cmd.Parameters.AddWithValue("z", z);
                cmd.ExecuteNonQuery();
            }
        }

        private void btnExport_Click(object sender, EventArgs e)
        {
            using (var saveDialog = new SaveFileDialog())
            {
                saveDialog.Filter = "Text files|*.txt";
                if (saveDialog.ShowDialog() == DialogResult.OK)
                {
                    ExportToFile(dateTimePickerStart.Value, dateTimePickerEnd.Value, saveDialog.FileName);
                }
            }
        }

        private void ExportToFile(DateTime start, DateTime end, string path)
        {
            try
            {
                using (var cmd = new NpgsqlCommand(
                    "SELECT x, y, z, measure_time FROM measurements WHERE measure_time BETWEEN @start AND @end",
                    connection))
                {
                    cmd.Parameters.AddWithValue("start", start);
                    cmd.Parameters.AddWithValue("end", end);

                    using (var reader = cmd.ExecuteReader())
                    using (var writer = new StreamWriter(path))
                    {
                        while (reader.Read())
                        {
                            writer.WriteLine(
                                $"{reader.GetDouble(0):F2}\t{reader.GetDouble(1):F2}\t" +
                                $"{reader.GetDouble(2):F2}\t{reader.GetDateTime(3)}");
                        }
                    }
                }
                MessageBox.Show("Export completed!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Export error: {ex.Message}");
            }
        }

        private void btnGenerate_Click(object sender, EventArgs e)
        {
            var generatorForm = new DataGeneratorForm();
            generatorForm.DataGenerated += (x, y, z) => SaveMeasurement(x, y, z);
            generatorForm.Show();
        }

        private void btnDrawHeightMap_Click(object sender, EventArgs e)
        {
            DrawHeightMap();
        }

        private void DrawHeightMap()
        {
            try
            {
                if (connection == null)
                {
                    MessageBox.Show("Database connection is not established.");
                    return;
                }
                if (pictureBox == null)
                {
                    MessageBox.Show("PictureBox is not initialized.");
                    return;
                }

                Bitmap bmp = new Bitmap(pictureBox.Width, pictureBox.Height);
                (float minZ, float maxZ) = GetHeightRange();

                if (minZ == maxZ)
                {
                    MessageBox.Show("Height range is invalid (all heights are the same).");
                    return;
                }

                using (var cmd = new NpgsqlCommand("SELECT x, y, z FROM measurements", connection))
                using (var reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        try
                        {
                            int x = Convert.ToInt32(reader["x"]);
                            int y = Convert.ToInt32(reader["y"]);
                            double z = Convert.ToDouble(reader["z"]);

                            if (x >= 0 && x < bmp.Width && y >= 0 && y < bmp.Height)
                            {
                                float ratio = (float)((z - minZ) / (maxZ - minZ));

                                int r, g, b;

                                if (ratio <= 0.33f)
                                {
                                    r = 0;
                                    g = (int)(255 * (1 - ratio * 3));
                                    b = 0;
                                }
                                else if (ratio <= 0.66f)
                                {
                                    r = 0;
                                    g = (int)(255 * (1 - (ratio - 0.33f) * 3));
                                    b = 255;
                                }
                                else
                                {
                                    r = (int)(255 * ((ratio - 0.66f) * 3));
                                    g = 0;
                                    b = 0;
                                }

                                r = Math.Max(0, Math.Min(255, r));
                                g = Math.Max(0, Math.Min(255, g));
                                b = Math.Max(0, Math.Min(255, b));

                                bmp.SetPixel(x, y, Color.FromArgb(r, g, b));
                            }
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine($"Error processing row: {ex.Message}");
                        }
                    }
                }

                pictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
                pictureBox.Image = bmp;
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Drawing error: {ex.Message}");
            }
        }

        private (float, float) GetHeightRange()
        {
            using (var cmd = new NpgsqlCommand("SELECT MIN(z), MAX(z) FROM measurements", connection))
            using (var reader = cmd.ExecuteReader())
            {
                if (reader.Read())
                {
                    return (reader.GetFloat(0), reader.GetFloat(1));
                }
                return (0, 0);
            }
        }

        private void btnDrawSection_Click(object sender, EventArgs e)
        {
            if (float.TryParse(txtK.Text, out float k) && float.TryParse(txtB.Text, out float b))
            {
                DrawCrossSection(k, b);
            }
        }

        private void DrawCrossSection(float k, float b)
        {
            if (chart.Series.IndexOf("CrossSection") != -1)
            {
                chart.Series.Remove(chart.Series["CrossSection"]);
            }

            Series sectionSeries = new Series("CrossSection")
            {
                ChartType = SeriesChartType.Line
            };
            chart.Series.Add(sectionSeries);

            using (var cmd = new NpgsqlCommand(
                "SELECT x, z FROM measurements WHERE ABS(y - (@k*x + @b)) < 0.1 ORDER BY x",
                connection))
            {
                cmd.Parameters.AddWithValue("k", k);
                cmd.Parameters.AddWithValue("b", b);

                using (var reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        sectionSeries.Points.AddXY(
                            reader.GetDouble(0),
                            reader.GetDouble(1));
                    }
                }
            }
        }

        private void clearDb_Click(object sender, EventArgs e)
        {
            using (var cmd = new NpgsqlCommand("DELETE FROM measurements", connection))
            {
                cmd.ExecuteNonQuery();
            }

            MessageBox.Show("База данных очищена.", "Успешно", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void MainForm_Load(object sender, EventArgs e)
        {

        }
    }
}
