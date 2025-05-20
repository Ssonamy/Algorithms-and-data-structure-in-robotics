using System;
using System.Windows.Forms;

namespace Laba3Var27
{
    public partial class FlightForm : Form
    {
        public Flight? FlightData { get; private set; } // Данные рейса

        public FlightForm(Flight existingFlight)
        {
            InitializeComponent();
            FlightData = existingFlight;

            // Заполняем форму данными рейса
            textBoxName.Text = existingFlight.Name;
            numericSeats.Value = existingFlight.Seats;
            numericSold.Value = existingFlight.Sold;
            numericPrice.Value = (decimal)existingFlight.Price;
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textBoxName.Text))
            {
                MessageBox.Show("Введите название рейса!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            FlightData = new Flight
            {
                Name = textBoxName.Text,
                Seats = (int)numericSeats.Value,
                Sold = (int)numericSold.Value,
                Price = (double)numericPrice.Value
            };

            DialogResult = DialogResult.OK;
            Close();
        }

        private void numericSeats_ValueChanged(object sender, EventArgs e)
        {
            trackBarSeats.Value = (int)numericSeats.Value;
        }

        private void numericSold_ValueChanged(object sender, EventArgs e)
        {
            trackBarSold.Value = (int)numericSold.Value;
        }

        private void numericPrice_ValueChanged(object sender, EventArgs e)
        {
            trackBarPrice.Value = (int)numericPrice.Value;
        }

        private void trackBarSeats_Scroll(object sender, EventArgs e)
        {
            numericSeats.Value = trackBarSeats.Value;
        }

        private void trackBarSold_Scroll(object sender, EventArgs e)
        {
            numericSold.Value = trackBarSold.Value;
        }

        private void trackBarPrice_Scroll(object sender, EventArgs e)
        {
            numericPrice.Value = trackBarPrice.Value;
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close(); // Закрываем форму
        }
    }
}
