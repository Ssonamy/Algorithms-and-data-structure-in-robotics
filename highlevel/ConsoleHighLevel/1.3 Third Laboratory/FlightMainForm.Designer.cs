namespace Laba3Var27
{
    partial class FlightMainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            dataGridViewFlights = new DataGridView();
            buttonEditFlight = new Button();
            buttonAdd = new Button();
            buttonInfo = new Button();
            ((System.ComponentModel.ISupportInitialize)dataGridViewFlights).BeginInit();
            SuspendLayout();
            // 
            // dataGridViewFlights
            // 
            dataGridViewFlights.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewFlights.Location = new Point(12, 12);
            dataGridViewFlights.MultiSelect = false;
            dataGridViewFlights.Name = "dataGridViewFlights";
            dataGridViewFlights.ReadOnly = true;
            dataGridViewFlights.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dataGridViewFlights.Size = new Size(776, 397);
            dataGridViewFlights.TabIndex = 0;
            // 
            // buttonEditFlight
            // 
            buttonEditFlight.Location = new Point(463, 415);
            buttonEditFlight.Name = "buttonEditFlight";
            buttonEditFlight.Size = new Size(164, 23);
            buttonEditFlight.TabIndex = 1;
            buttonEditFlight.Text = "Редактировать рейс";
            buttonEditFlight.UseVisualStyleBackColor = true;
            buttonEditFlight.Click += buttonEditFlight_Click;
            // 
            // buttonAdd
            // 
            buttonAdd.Location = new Point(633, 415);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(155, 23);
            buttonAdd.TabIndex = 2;
            buttonAdd.Text = "Добавить рейс";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // buttonInfo
            // 
            buttonInfo.Location = new Point(12, 415);
            buttonInfo.Name = "buttonInfo";
            buttonInfo.Size = new Size(75, 23);
            buttonInfo.TabIndex = 3;
            buttonInfo.Text = "Справка";
            buttonInfo.UseVisualStyleBackColor = true;
            buttonInfo.Click += buttonInfo_Click;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(buttonInfo);
            Controls.Add(buttonAdd);
            Controls.Add(buttonEditFlight);
            Controls.Add(dataGridViewFlights);
            Name = "MainForm";
            Text = "Главная";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridViewFlights).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private DataGridView dataGridViewFlights;
        private Button buttonEditFlight;
        private Button buttonAdd;
        private Button buttonInfo;
    }
}
