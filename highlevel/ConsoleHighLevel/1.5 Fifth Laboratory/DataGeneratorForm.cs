namespace SurfaceScanner
{
    public partial class DataGeneratorForm : Form
    {
        public event Action<float, float, float> DataGenerated;

        public DataGeneratorForm()
        {
            InitializeComponent();
        }

        private void btnGenerate_Click(object sender, EventArgs e)
        {
            if (!ValidateInput()) return;

            float amplitude = float.Parse(txtAmplitude.Text);
            float period = float.Parse(txtPeriod.Text);
            float step = float.Parse(txtStep.Text);

            Random rand = new Random();
            for (float x = 0; x < 100; x += step)
            {
                for (float y = 0; y < 100; y += step)
                {
                    float z = amplitude * (float)Math.Sin(2 * Math.PI * x / period)
                             + (float)rand.NextDouble() * amplitude * 0.2f;
                    DataGenerated?.Invoke(x, y, z);
                }
            }
            Close();
        }

        private bool ValidateInput()
        {
            bool valid = float.TryParse(txtAmplitude.Text, out float amp) && amp > 0;
            valid &= float.TryParse(txtPeriod.Text, out float period) && period > 0;
            valid &= float.TryParse(txtStep.Text, out float step) && step > 0;

            if (!valid) MessageBox.Show("Invalid parameters!");
            return valid;
        }

        private void DataGeneratorForm_Load(object sender, EventArgs e)
        {

        }
    }
}