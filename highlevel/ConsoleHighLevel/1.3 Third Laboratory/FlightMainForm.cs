using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace Laba3Var27
{

    public partial class FlightMainForm : Form
    {
        private List<Flight> flights = new List<Flight>();

        public FlightMainForm()
        {
            InitializeComponent();
            UpdateGrid();
        }
        private void buttonAdd_Click(object sender, EventArgs e)
        {
            var form = new FlightForm(new Flight()); // Новая форма с пустыми данными
            if (form.ShowDialog() == DialogResult.OK)
            {
                flights.Add(form.FlightData.Value);
                UpdateGrid();
            }
        }

        private void buttonEditFlight_Click(object sender, EventArgs e)
        {
            if (dataGridViewFlights.SelectedRows.Count > 0)
            {
                int index = dataGridViewFlights.SelectedRows[0].Index;
               if (index >= 0 && index < flights.Count) 
                {
                    var form = new FlightForm(flights[index]); // Передаем выделенный рейс

                    if (form.ShowDialog() == DialogResult.OK)
                    {
                        flights[index] = form.FlightData.Value;
                        UpdateGrid();
                    }
                }
            }
            else
            {
                MessageBox.Show("Выберите рейс для редактирования!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void buttonInfo_Click(object sender, EventArgs e)
        {
            var form = new InfoForm(flights);
            form.ShowDialog();
        }

        private void UpdateGrid()
        {
            dataGridViewFlights.DataSource = null;
            dataGridViewFlights.DataSource = flights;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

    }
}
