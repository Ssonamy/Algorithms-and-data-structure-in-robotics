using Npgsql;
using System.Data;

namespace CompanyApp
{
    public static class DatabaseHelper
    {
        public static string connectionString =
            "Host=localhost;" +
            "Port=5434;" +
            "Database=enterprise_db;" +
            "Username=postgres;" +
            "Password=hj1314Srf;";

        // Для обычных запросов
        public static DataTable ExecuteQuery(string query)
        {
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();
                using (var cmd = new NpgsqlCommand(query, conn))
                {
                    DataTable dt = new DataTable();
                    new NpgsqlDataAdapter(cmd).Fill(dt);
                    return dt;
                }
            }
        }

        // Для параметризованных запросов
        public static DataTable ExecuteParameterizedQuery(string query, NpgsqlParameter[] parameters)
        {
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();
                using (var cmd = new NpgsqlCommand(query, conn))
                {
                    cmd.Parameters.AddRange(parameters);
                    DataTable dt = new DataTable();
                    new NpgsqlDataAdapter(cmd).Fill(dt);
                    return dt;
                }
            }
        }

        // Для выполнения команд UPDATE/INSERT/DELETE
        public static int ExecuteNonQuery(string query, NpgsqlParameter[] parameters = null)
        {
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();
                using (var cmd = new NpgsqlCommand(query, conn))
                {
                    if (parameters != null)
                        cmd.Parameters.AddRange(parameters);
                    return cmd.ExecuteNonQuery();
                }
            }
        }
    }
}