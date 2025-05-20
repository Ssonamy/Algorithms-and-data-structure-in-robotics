using System.Data;

using Npgsql;

namespace LibraryCatalog
{
    public partial class LibraryMainForm : Form
    {
        private string connectionString;

        public LibraryMainForm(string connectionString)
        {
            InitializeComponent();
            this.connectionString = connectionString;
            LoadBooks();
        }

        private void LoadBooks()
        {
            using (var connection = new NpgsqlConnection(connectionString))
            {
                connection.Open();
                string query = "SELECT * FROM books";
                var adapter = new NpgsqlDataAdapter(query, connection);
                var table = new DataTable();
                adapter.Fill(table);
                dgvBooks.DataSource = table;
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtTitle.Text) || string.IsNullOrWhiteSpace(txtAuthor.Text))
            {
                MessageBox.Show("Пожалуйста, заполните поля Название и Автор!", "Ошибка");
                return;
            }

            using (var connection = new NpgsqlConnection(connectionString))
            {
                connection.Open();
                string query = "INSERT INTO books (title, author) VALUES (@title, @author)";
                using (var command = new NpgsqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("title", txtTitle.Text); // Название книги
                    command.Parameters.AddWithValue("author", txtAuthor.Text); // Автор книги
                    command.ExecuteNonQuery(); // Выполнение запроса
                }
                LoadBooks(); // Обновление списка
            }
        }



        private void btnEdit_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtId.Text) || string.IsNullOrWhiteSpace(txtTitle.Text) || string.IsNullOrWhiteSpace(txtAuthor.Text))
            {
                MessageBox.Show("Пожалуйста, заполните все поля: ID, Название и Автор!", "Ошибка");
                return;
            }

            if (!int.TryParse(txtId.Text, out int bookId))
            {
                MessageBox.Show("ID книги должно быть числом!", "Ошибка");
                return;
            }

            using (var connection = new NpgsqlConnection(connectionString))
            {
                connection.Open();
                string query = "UPDATE books SET title = @title, author = @author WHERE id = @id";
                using (var command = new NpgsqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("title", txtTitle.Text);  // Новое название книги
                    command.Parameters.AddWithValue("author", txtAuthor.Text); // Новый автор
                    command.Parameters.AddWithValue("id", bookId); // Указанный ID (число)
                    command.ExecuteNonQuery(); // Выполнение запроса
                }
                LoadBooks(); // Обновление отображаемого списка книг
            }
        }


        private void btnDelete_Click(object sender, EventArgs e)
{
    if (string.IsNullOrWhiteSpace(txtId.Text))
    {
        MessageBox.Show("Пожалуйста, укажите ID книги для удаления!", "Ошибка");
        return;
    }

    if (!int.TryParse(txtId.Text, out int bookId))
    {
        MessageBox.Show("ID книги должно быть числом!", "Ошибка");
        return;
    }

    using (var connection = new NpgsqlConnection(connectionString))
    {
        connection.Open();
        string query = "DELETE FROM books WHERE id = @id";
        using (var command = new NpgsqlCommand(query, connection))
        {
            command.Parameters.AddWithValue("id", bookId); // Указанный ID (число)
            command.ExecuteNonQuery(); // Выполнение запроса
        }
        LoadBooks(); // Обновление списка
    }
}



        private void btnSearch_Click(object sender, EventArgs e)
        {
            using (var connection = new NpgsqlConnection(connectionString))
            {
                connection.Open();
                string query = "SELECT * FROM books WHERE author = @author";
                using (var command = new NpgsqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("author", txtSearchAuthor.Text);
                    var adapter = new NpgsqlDataAdapter(command);
                    var table = new DataTable();
                    adapter.Fill(table);
                    dgvBooks.DataSource = table;
                }
            }
        }
    }
}
