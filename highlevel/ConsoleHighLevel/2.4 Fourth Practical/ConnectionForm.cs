
using Npgsql;

namespace LibraryCatalog
{
    public partial class ConnectionForm : Form
    {
        public ConnectionForm()
        {
            InitializeComponent();
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            string connectionString = $"Host={txtHost.Text};Port={txtPort.Text};Username={txtUsername.Text};Password={txtPassword.Text};Database={txtDatabase.Text};";
            try
            {
                using (var connection = new NpgsqlConnection(connectionString))
                {
                    connection.Open();
                    MessageBox.Show("Успешное подключение!", "Сообщение");
                    LibraryMainForm mainForm = new LibraryMainForm(connectionString);
                    mainForm.Show();
                    this.Hide();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка подключения: {ex.Message}", "Ошибка");
            }
        }
    }
}
