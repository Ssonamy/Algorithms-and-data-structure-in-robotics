//using System;
//using System.Windows.Forms;

namespace ThirdPractik
{
    public partial class ThirdPractical : Form
    {
        public ThirdPractical()
        {
            InitializeComponent();

            txtRows.Text = placeholderRows;
            txtRows.ForeColor = System.Drawing.Color.Gray;

            txtColumns.Text = placeholderCols;
            txtColumns.ForeColor = System.Drawing.Color.Gray;

            btnGenerate.Click += BtnGenerate_Click;

            txtRows.Enter += TextBox_Enter;
            txtRows.Leave += TextBox_Leave;

            txtColumns.Enter += TextBox_Enter;
            txtColumns.Leave += TextBox_Leave;
        }

        private string placeholderRows = "Введите строки";
        private string placeholderCols = "Введите столбцы";


        private void TextBox_Enter(object sender, EventArgs e)
        {
            TextBox textBox = sender as TextBox;
            if (textBox != null && (textBox.Text == placeholderRows || textBox.Text == placeholderCols))
            {
                textBox.Text = "";
                textBox.ForeColor = System.Drawing.Color.Black;
            }
        }

        private void TextBox_Leave(object sender, EventArgs e)
        {
            TextBox textBox = sender as TextBox;
            if (textBox != null && string.IsNullOrWhiteSpace(textBox.Text))
            {
                if (textBox == txtRows) 
                    textBox.Text = placeholderRows;
                else if (textBox == txtColumns)
                    textBox.Text = placeholderCols;

                textBox.ForeColor = System.Drawing.Color.Gray;
            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void BtnGenerate_Click(object sender, EventArgs e)
        {
            // Проверяем, корректные ли данные введены
            if (!int.TryParse(txtRows.Text, out int rows) || rows <= 0 ||
                !int.TryParse(txtColumns.Text, out int cols) || cols <= 0)
            {
                MessageBox.Show("Введите корректное количество строк и столбцов!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            // Очищаем таблицу перед новой генерацией
            dataGridViewMatrix.Columns.Clear();
            dataGridViewMatrix.Rows.Clear();

            // Создаем столбцы
            for (int i = 0; i < cols; i++)
            {
                dataGridViewMatrix.Columns.Add($"col{i}", $"Столбец {i + 1}");
            }

            // Генерируем случайные числа и заполняем таблицу
            Random rand = new Random();
            for (int i = 0; i < rows; i++)
            {
                object[] rowValues = new object[cols];
                for (int j = 0; j < cols; j++)
                {
                    rowValues[j] = rand.Next(0, 101); // Числа от 0 до 100
                }
                dataGridViewMatrix.Rows.Add(rowValues);
            }
        }
        private void btnGenerate_Click(object sender, EventArgs e)
        {

        }
    }
}