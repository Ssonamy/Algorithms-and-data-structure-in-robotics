using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SecondPractik
{
    public partial class SecondPractical21 : Form
    {
        public SecondPractical21()
        {
            InitializeComponent();
        }

        private void goButton_Click(object sender, EventArgs e)
        {
            webBrowser1.Navigate(new Uri(comboBox1.SelectedItem.ToString()));
        }

        private void домашняяСтраницаToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            webBrowser1.GoHome();
        }

        private void назадToolStripMenuItem_Click(object sender, EventArgs e)
        {
            webBrowser1.GoBack();
        }

        private void впередToolStripMenuItem_Click(object sender, EventArgs e)
        {
            webBrowser1.GoForward();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;
            webBrowser1.GoHome();
        }
    }
}
