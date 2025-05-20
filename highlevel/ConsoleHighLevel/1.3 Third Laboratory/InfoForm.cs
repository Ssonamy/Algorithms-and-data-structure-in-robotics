using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace Laba3Var27
{
    public partial class InfoForm : Form
    {
        private List<Flight> flights; // Добавил поле для хранения списка рейсов
        public InfoForm(List<Flight> flights)
        {
            InitializeComponent();
            this.flights = flights; // Сохранил переданный список рейсов
            listBoxFlights.DataSource = flights.Select(f => f.Name).ToList();
        }

        private void listBoxFlights_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxFlights.SelectedIndex >= 0)
            {
                string selectedFlight = listBoxFlights.SelectedItem.ToString();
                ShowFlightInfo(selectedFlight);
            }
        }

        private void ShowFlightInfo(string flightName)
        {
            Flight? flight = flights.FirstOrDefault(f => f.Name == flightName);

            if (!flight.HasValue) // Если рейс не найден, ничего не делаем
            {
                textBoxInfo.Text = "Ошибка: рейс не найден!";
                return;
            }

            double revenue = flight.Value.Sold * flight.Value.Price;
            double loss = (flight.Value.Seats - flight.Value.Sold) * flight.Value.Price;

            textBoxInfo.Text = $"Рейс: {flight.Value.Name}\r\nВыручка: {revenue:C}\r\nПотери: {loss:C}";
        }

        private void buttonClose_Click(object sender, EventArgs e)
        {
            this.Close(); // Закрываем форму
        }
    }
}
