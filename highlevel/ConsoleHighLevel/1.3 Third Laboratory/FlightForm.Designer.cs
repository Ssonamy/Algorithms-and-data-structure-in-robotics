namespace Laba3Var27
{
    partial class FlightForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            textBoxName = new TextBox();
            numericSeats = new NumericUpDown();
            numericSold = new NumericUpDown();
            numericPrice = new NumericUpDown();
            buttonSave = new Button();
            labelName = new Label();
            labelSeats = new Label();
            labelSold = new Label();
            labelPrice = new Label();
            trackBarSeats = new TrackBar();
            trackBarSold = new TrackBar();
            trackBarPrice = new TrackBar();
            buttonCancel = new Button();
            ((System.ComponentModel.ISupportInitialize)numericSeats).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericSold).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericPrice).BeginInit();
            ((System.ComponentModel.ISupportInitialize)trackBarSeats).BeginInit();
            ((System.ComponentModel.ISupportInitialize)trackBarSold).BeginInit();
            ((System.ComponentModel.ISupportInitialize)trackBarPrice).BeginInit();
            SuspendLayout();
            // 
            // textBoxName
            // 
            textBoxName.AllowDrop = true;
            textBoxName.Location = new Point(156, 12);
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(244, 23);
            textBoxName.TabIndex = 0;
            // 
            // numericSeats
            // 
            numericSeats.AllowDrop = true;
            numericSeats.Location = new Point(156, 63);
            numericSeats.Maximum = new decimal(new int[] { 500, 0, 0, 0 });
            numericSeats.Name = "numericSeats";
            numericSeats.Size = new Size(120, 23);
            numericSeats.TabIndex = 1;
            numericSeats.ValueChanged += numericSeats_ValueChanged;
            // 
            // numericSold
            // 
            numericSold.AllowDrop = true;
            numericSold.Location = new Point(156, 120);
            numericSold.Maximum = new decimal(new int[] { 500, 0, 0, 0 });
            numericSold.Name = "numericSold";
            numericSold.Size = new Size(120, 23);
            numericSold.TabIndex = 2;
            numericSold.ValueChanged += numericSold_ValueChanged;
            // 
            // numericPrice
            // 
            numericPrice.AllowDrop = true;
            numericPrice.Increment = new decimal(new int[] { 50, 0, 0, 0 });
            numericPrice.Location = new Point(156, 171);
            numericPrice.Maximum = new decimal(new int[] { 500, 0, 0, 0 });
            numericPrice.Name = "numericPrice";
            numericPrice.Size = new Size(120, 23);
            numericPrice.TabIndex = 3;
            numericPrice.ValueChanged += numericPrice_ValueChanged;
            // 
            // buttonSave
            // 
            buttonSave.Location = new Point(15, 217);
            buttonSave.Name = "buttonSave";
            buttonSave.Size = new Size(96, 23);
            buttonSave.TabIndex = 4;
            buttonSave.Text = "Сохранить";
            buttonSave.UseVisualStyleBackColor = true;
            buttonSave.Click += buttonSave_Click;
            // 
            // labelName
            // 
            labelName.Location = new Point(15, 12);
            labelName.Name = "labelName";
            labelName.Size = new Size(120, 23);
            labelName.TabIndex = 5;
            labelName.Text = "Название рейса";
            labelName.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // labelSeats
            // 
            labelSeats.Location = new Point(15, 120);
            labelSeats.Name = "labelSeats";
            labelSeats.Size = new Size(120, 23);
            labelSeats.TabIndex = 6;
            labelSeats.Text = "Количество мест";
            labelSeats.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // labelSold
            // 
            labelSold.Location = new Point(15, 63);
            labelSold.Name = "labelSold";
            labelSold.Size = new Size(120, 23);
            labelSold.TabIndex = 7;
            labelSold.Text = "Проданных билетов";
            labelSold.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // labelPrice
            // 
            labelPrice.Location = new Point(15, 171);
            labelPrice.Name = "labelPrice";
            labelPrice.Size = new Size(120, 23);
            labelPrice.TabIndex = 8;
            labelPrice.Text = "Стоимость билета";
            labelPrice.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // trackBarSeats
            // 
            trackBarSeats.LargeChange = 50;
            trackBarSeats.Location = new Point(296, 63);
            trackBarSeats.Maximum = 500;
            trackBarSeats.Name = "trackBarSeats";
            trackBarSeats.Size = new Size(104, 45);
            trackBarSeats.TabIndex = 10;
            trackBarSeats.Scroll += trackBarSeats_Scroll;
            // 
            // trackBarSold
            // 
            trackBarSold.LargeChange = 50;
            trackBarSold.Location = new Point(296, 120);
            trackBarSold.Maximum = 500;
            trackBarSold.Name = "trackBarSold";
            trackBarSold.Size = new Size(104, 45);
            trackBarSold.TabIndex = 11;
            trackBarSold.Value = 1;
            trackBarSold.Scroll += trackBarSold_Scroll;
            // 
            // trackBarPrice
            // 
            trackBarPrice.LargeChange = 100;
            trackBarPrice.Location = new Point(296, 171);
            trackBarPrice.Maximum = 500;
            trackBarPrice.Name = "trackBarPrice";
            trackBarPrice.Size = new Size(104, 45);
            trackBarPrice.SmallChange = 50;
            trackBarPrice.TabIndex = 12;
            trackBarPrice.Scroll += trackBarPrice_Scroll;
            // 
            // buttonCancel
            // 
            buttonCancel.Location = new Point(304, 222);
            buttonCancel.Name = "buttonCancel";
            buttonCancel.Size = new Size(96, 23);
            buttonCancel.TabIndex = 13;
            buttonCancel.Text = "Отмена";
            buttonCancel.UseVisualStyleBackColor = true;
            buttonCancel.Click += buttonCancel_Click;
            // 
            // FlightForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(406, 257);
            Controls.Add(buttonCancel);
            Controls.Add(trackBarPrice);
            Controls.Add(trackBarSold);
            Controls.Add(trackBarSeats);
            Controls.Add(labelPrice);
            Controls.Add(labelSold);
            Controls.Add(labelSeats);
            Controls.Add(labelName);
            Controls.Add(buttonSave);
            Controls.Add(numericPrice);
            Controls.Add(numericSold);
            Controls.Add(numericSeats);
            Controls.Add(textBoxName);
            Name = "FlightForm";
            Text = "Редактировать";
            ((System.ComponentModel.ISupportInitialize)numericSeats).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericSold).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericPrice).EndInit();
            ((System.ComponentModel.ISupportInitialize)trackBarSeats).EndInit();
            ((System.ComponentModel.ISupportInitialize)trackBarSold).EndInit();
            ((System.ComponentModel.ISupportInitialize)trackBarPrice).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox textBoxName;
        private NumericUpDown numericSeats;
        private NumericUpDown numericSold;
        private NumericUpDown numericPrice;
        private Button buttonSave;
        private Label labelName;
        private Label labelSeats;
        private Label labelSold;
        private Label labelPrice;
        private TrackBar trackBarSeats;
        private TrackBar trackBarSold;
        private TrackBar trackBarPrice;
        private Button buttonCancel;
    }
}