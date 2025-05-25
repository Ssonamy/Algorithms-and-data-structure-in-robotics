using System;
using System.Data;
using System.Windows.Forms;
using Npgsql;

namespace CompanyApp
{
    

    public partial class MainEnterpriceForm : Form
    {
        public MainEnterpriceForm()
        {
            InitializeComponent();
            ConfigureGrid();
        }

        private void ConfigureGrid()
        {
            dgvResults.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvResults.ReadOnly = true;
        }

        // Кнопка показать компании
        private void btnShowCompanies_Click(object sender, EventArgs e)
        {
            using (var form = new CompanyForm())
            {
                form.ShowDialog();
            }
        }

        // Кнопка показать продукты
        private void btnShowProducts_Click(object sender, EventArgs e)
        {
            using (var form = new ProductForm())
            {
                form.ShowDialog();
            }
        }

        // Запрос 1: Предприятия с ростом по всем показателям
        private void btnQuery1_Click(object sender, EventArgs e)
        {
            try
            {
                string query = @"SELECT c.enterprise_code, c.name, c.phone
                            FROM enterprises c
                            WHERE NOT EXISTS (
                                SELECT 1 FROM products p 
                                WHERE p.enterprise_code = c.enterprise_code 
                                AND (p.production_dec <= p.production_jan 
                                OR p.price_dec <= p.price_jan))";

                dgvResults.DataSource = DatabaseHelper.ExecuteQuery(query);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}");
            }
        }

        // Запрос 2: Фильтр по продукции
        private void btnQuery2_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtProduct.Text))
            {
                MessageBox.Show("Введите название продукции!");
                return;
            }

            try
            {
                string query = @"SELECT DISTINCT c.* 
                            FROM enterprises c
                            JOIN products p ON c.enterprise_code = p.enterprise_code
                            WHERE p.product_name ILIKE @product
                            AND (p.price_dec - p.price_jan)/p.price_jan <= 0.2";

                var parameters = new NpgsqlParameter[] {
                new NpgsqlParameter("@product", $"%{txtProduct.Text}%")
            };

                dgvResults.DataSource = DatabaseHelper.ExecuteParameterizedQuery(query, parameters);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}");
            }
        }

        // Запрос 3: Статистика
        private void btnQuery3_Click(object sender, EventArgs e)
        {
            try
            {
                string query = @"SELECT c.enterprise_code, c.name, 
                            COUNT(p.product_id) AS products_count,
                            ROUND(AVG(p.price_dec), 2) AS avg_price
                            FROM enterprises c
                            LEFT JOIN products p ON c.enterprise_code = p.enterprise_code
                            GROUP BY c.enterprise_code";

                dgvResults.DataSource = DatabaseHelper.ExecuteQuery(query);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}");
            }
        }

        // Запрос 4: Обновление цены
        private void btnQuery4_Click(object sender, EventArgs e)
        {
            if (!int.TryParse(txtCompanyId.Text, out int companyId)
                || string.IsNullOrWhiteSpace(txtProductName.Text))
            {
                MessageBox.Show("Проверьте правильность ввода!");
                return;
            }

            try
            {
                string query = @"UPDATE products 
                            SET price_dec = price_dec * 1.07
                            WHERE enterprise_code = @companyId 
                            AND product_name = @productName
                            RETURNING *";

                var parameters = new NpgsqlParameter[] {
                new NpgsqlParameter("@companyId", companyId),
                new NpgsqlParameter("@productName", txtProductName.Text)
            };

                var result = DatabaseHelper.ExecuteParameterizedQuery(query, parameters);
                dgvResults.DataSource = result;
                MessageBox.Show($"Обновлено записей: {result.Rows.Count}");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}");
            }
        }
    }
}
