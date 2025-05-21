
using System;
using System.IO;
using System.Windows.Forms;
using System.Linq;

namespace CSVEditor
{
    public partial class CVSForm : Form
    {
        public CVSForm()
        {
            InitializeComponent();
        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
                openFileDialog.FilterIndex = 1;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        // Чтение всех строк из файла
                        string[] lines = File.ReadAllLines(openFileDialog.FileName);

                        if (lines.Length == 0) return;

                        // Очистка DataGridView
                        dataGridView.Rows.Clear();
                        dataGridView.Columns.Clear();

                        // Разделение первой строки для заголовков столбцов
                        string[] headers = lines[0].Split(',');
                        foreach (string header in headers)
                        {
                            dataGridView.Columns.Add(header, header);
                        }

                        // Добавление строк данных
                        for (int i = 1; i < lines.Length; i++)
                        {
                            string[] rowData = lines[i].Split(',');
                            dataGridView.Rows.Add(rowData);
                        }

                        lblStatus.Text = $"Файл загружен: {openFileDialog.FileName}";
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show($"Ошибка при открытии файла: {ex.Message}", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            if (dataGridView.Rows.Count == 0)
            {
                MessageBox.Show("Нет данных для сохранения", "Информация", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }

            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
                saveFileDialog.FilterIndex = 1;
                saveFileDialog.RestoreDirectory = true;

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        using (StreamWriter writer = new StreamWriter(saveFileDialog.FileName))
                        {
                            // Запись заголовков
                            var headers = dataGridView.Columns.Cast<DataGridViewColumn>()
                                .Select(column => column.HeaderText);
                            writer.WriteLine(string.Join(",", headers));

                            // Запись данных
                            foreach (DataGridViewRow row in dataGridView.Rows)
                            {
                                if (!row.IsNewRow)
                                {
                                    var cells = row.Cells.Cast<DataGridViewCell>()
                                        .Select(cell => cell.Value?.ToString() ?? "");
                                    writer.WriteLine(string.Join(",", cells));
                                }
                            }
                        }

                        lblStatus.Text = $"Файл сохранен: {saveFileDialog.FileName}";
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show($"Ошибка при сохранении файла: {ex.Message}", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            dataGridView.Rows.Clear();
            dataGridView.Columns.Clear();
            lblStatus.Text = "Создан новый документ";
        }

        private void btnAddColumn_Click(object sender, EventArgs e)
        {
            string columnName = Microsoft.VisualBasic.Interaction.InputBox("Введите название столбца:", "Добавить столбец", "Новый столбец");
            if (!string.IsNullOrEmpty(columnName))
            {
                dataGridView.Columns.Add(columnName, columnName);
            }
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}