using System;
using System.Data;
using System.Linq;
using System.Windows.Forms;
using Npgsql;


namespace CompanyApp
{

    public partial class ProductForm : Form
    {
        private DataTable dtProducts;

        public ProductForm()
        {
            InitializeComponent();
            ConfigureGrid();
            LoadData();
        }

        private void ConfigureGrid()
        {
            dgvProducts.AutoGenerateColumns = true;
            dgvProducts.AllowUserToAddRows = true;
            dgvProducts.AllowUserToDeleteRows = true;
        }

        private void LoadData()
        {
            try
            {
                dtProducts = DatabaseHelper.ExecuteQuery("SELECT * FROM products");
                dgvProducts.DataSource = dtProducts;
                FormatColumns();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка загрузки: {ex.Message}");
            }
        }

        private void FormatColumns()
        {
            string[] numericColumns = { "production_jan", "price_jan", "production_dec", "price_dec" };
            foreach (DataGridViewColumn col in dgvProducts.Columns)
            {
                if (numericColumns.Contains(col.Name))
                {
                    col.DefaultCellStyle.Format = "N2";
                    col.DefaultCellStyle.Alignment = DataGridViewContentAlignment.MiddleRight;
                }
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                using (var conn = new NpgsqlConnection(DatabaseHelper.connectionString))
                {
                    conn.Open();
                    var adapter = new NpgsqlDataAdapter("SELECT * FROM products", conn);
                    var builder = new NpgsqlCommandBuilder(adapter);

                    adapter.Update(dtProducts);
                    MessageBox.Show("Данные сохранены!");
                    LoadData(); // Обновляем данные
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка сохранения: {ex.Message}");
            }
        }

        private void dgvProducts_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            string[] numericColumns = { "production_jan", "price_jan", "production_dec", "price_dec" };

            if (numericColumns.Contains(dgvProducts.Columns[e.ColumnIndex].Name))
            {
                if (!decimal.TryParse(e.FormattedValue.ToString(), out _))
                {
                    e.Cancel = true;
                    dgvProducts.Rows[e.RowIndex].ErrorText = "Введите число!";
                }
            }
        }

        private void ProductForm_Load(object sender, EventArgs e)
        {

        }
    }
}
