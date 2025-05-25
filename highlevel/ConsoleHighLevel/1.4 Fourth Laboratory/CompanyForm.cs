
using System;
using System.Data;
using System.Windows.Forms;
using Npgsql;


namespace CompanyApp
{
    public partial class CompanyForm : Form
    {
        private DataTable dtCompanies;

        public CompanyForm()
        {
            InitializeComponent();
            ConfigureGrid();
            LoadData();
        }

        private void ConfigureGrid()
        {
            dgvCompanies.AutoGenerateColumns = true;
            dgvCompanies.AllowUserToAddRows = true;
            dgvCompanies.AllowUserToDeleteRows = true;
        }

        private void LoadData()
        {
            try
            {
                dtCompanies = DatabaseHelper.ExecuteQuery("SELECT * FROM enterprises ORDER BY enterprise_code");
                dgvCompanies.DataSource = dtCompanies;
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка загрузки: {ex.Message}");
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                using (var conn = new NpgsqlConnection(DatabaseHelper.connectionString))
                {
                    conn.Open();
                    var adapter = new NpgsqlDataAdapter("SELECT * FROM enterprises", conn);
                    var builder = new NpgsqlCommandBuilder(adapter);

                    adapter.Update(dtCompanies);
                    MessageBox.Show("Данные сохранены!");
                    LoadData(); // Обновляем данные
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка сохранения: {ex.Message}");
            }
        }

        private void dgvCompanies_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            if (dgvCompanies.Columns[e.ColumnIndex].Name == "phone")
            {
                if (!System.Text.RegularExpressions.Regex.IsMatch(e.FormattedValue.ToString(),
                    @"^\+?[0-9\- ]{7,20}$"))
                {
                    e.Cancel = true;
                    dgvCompanies.Rows[e.RowIndex].ErrorText = "Неверный формат телефона!";
                }
            }
        }
    }
}
