using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Windows.Forms;

namespace ShapeDrawer
{
    public partial class Drower : Form
    {
        private Bitmap drawingBitmap;
        private Graphics graphics;

        public Drower()
        {
            InitializeComponent();
            InitializeDrawingSurface();
        }

        private void InitializeDrawingSurface()
        {
            // Освобождаем предыдущие ресурсы
            graphics?.Dispose();
            drawingBitmap?.Dispose();

            // Создаем новые
            drawingBitmap = new Bitmap(pictureBox.Width, pictureBox.Height);
            graphics = Graphics.FromImage(drawingBitmap);
            pictureBox.Image = drawingBitmap;
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            base.OnFormClosing(e);
            graphics?.Dispose();
            drawingBitmap?.Dispose();
        }

        private void btnLoadFile_Click(object sender, EventArgs e)
        {
            using (var openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "Text Files (*.txt)|*.txt";
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    // Переинициализируем поверхность для очистки
                    InitializeDrawingSurface();
                    graphics.Clear(Color.White);

                    try
                    {
                        ProcessFile(openFileDialog.FileName);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show($"Ошибка: {ex.Message}");
                    }

                    pictureBox.Invalidate();
                }
            }
        }

        private void ProcessFile(string filePath)
        {
            var lines = File.ReadAllLines(filePath);
            foreach (var line in lines)
            {
                var parts = line.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                if (parts.Length == 0) continue;

                var command = parts[0].ToUpper();
                ProcessCommand(command, parts);
            }
        }

        private void ProcessCommand(string command, string[] parts)
        {
            switch (command)
            {
                case "TEXT":
                    if (parts.Length >= 4 &&
                        int.TryParse(parts[1], out int tx) &&
                        int.TryParse(parts[2], out int ty))
                    {
                        var text = string.Join(" ", parts, 3, parts.Length - 3);
                        graphics.DrawString(text, Font, Brushes.Black, tx, ty);
                    }
                    break;

                case "CIRCLE":
                    if (parts.Length == 4 &&
                        int.TryParse(parts[1], out int cx) &&
                        int.TryParse(parts[2], out int cy) &&
                        int.TryParse(parts[3], out int radius))
                    {
                        using (var pen = new Pen(Color.Red))
                        {
                            graphics.DrawEllipse(pen, cx - radius, cy - radius, radius * 2, radius * 2);
                        }
                    }
                    break;

                case "RECT":
                    if (parts.Length == 5 &&
                        int.TryParse(parts[1], out int rx) &&
                        int.TryParse(parts[2], out int ry) &&
                        int.TryParse(parts[3], out int rw) &&
                        int.TryParse(parts[4], out int rh))
                    {
                        using (var pen = new Pen(Color.Blue))
                        {
                            graphics.DrawRectangle(pen, rx, ry, rw, rh);
                        }
                    }
                    break;

                case "LINE":
                    if (parts.Length == 5 &&
                        int.TryParse(parts[1], out int x1) &&
                        int.TryParse(parts[2], out int y1) &&
                        int.TryParse(parts[3], out int x2) &&
                        int.TryParse(parts[4], out int y2))
                    {
                        using (var pen = new Pen(Color.Green))
                        {
                            graphics.DrawLine(pen, x1, y1, x2, y2);
                        }
                    }
                    break;

                case "TRIANGLE":
                    if (parts.Length == 7 &&
                        int.TryParse(parts[1], out int t1x) &&
                        int.TryParse(parts[2], out int t1y) &&
                        int.TryParse(parts[3], out int t2x) &&
                        int.TryParse(parts[4], out int t2y) &&
                        int.TryParse(parts[5], out int t3x) &&
                        int.TryParse(parts[6], out int t3y))
                    {
                        using (var pen = new Pen(Color.Purple))
                        {
                            var triangle = new[]
                            {
                                new Point(t1x, t1y),
                                new Point(t2x, t2y),
                                new Point(t3x, t3y)
                            };
                            graphics.DrawPolygon(pen, triangle);
                        }
                    }
                    break;
            }
        }

        private void btnSaveImage_Click(object sender, EventArgs e)
        {
            using (var saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.Filter = "PNG Image|*.png";
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        drawingBitmap.Save(saveFileDialog.FileName, ImageFormat.Png);
                        MessageBox.Show("Изображение сохранено.");
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show($"Ошибка сохранения: {ex.Message}");
                    }
                }
            }
        }
    }
}