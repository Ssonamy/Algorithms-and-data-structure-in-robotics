namespace Laba3Var27
{
    partial class InfoForm
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
            listBoxFlights = new ListBox();
            textBoxInfo = new TextBox();
            buttonClose = new Button();
            labelFlightsList = new Label();
            labelFlightInfo = new Label();
            SuspendLayout();
            // 
            // listBoxFlights
            // 
            listBoxFlights.FormattingEnabled = true;
            listBoxFlights.ItemHeight = 15;
            listBoxFlights.Location = new Point(12, 27);
            listBoxFlights.Name = "listBoxFlights";
            listBoxFlights.Size = new Size(776, 169);
            listBoxFlights.TabIndex = 0;
            // 
            // textBoxInfo
            // 
            textBoxInfo.Location = new Point(12, 217);
            textBoxInfo.Multiline = true;
            textBoxInfo.Name = "textBoxInfo";
            textBoxInfo.ReadOnly = true;
            textBoxInfo.Size = new Size(776, 192);
            textBoxInfo.TabIndex = 1;
            // 
            // buttonClose
            // 
            buttonClose.Location = new Point(668, 415);
            buttonClose.Name = "buttonClose";
            buttonClose.Size = new Size(120, 23);
            buttonClose.TabIndex = 2;
            buttonClose.Text = "Закрыть";
            buttonClose.UseVisualStyleBackColor = true;
            buttonClose.Click += buttonClose_Click;
            // 
            // labelFlightsList
            // 
            labelFlightsList.AutoSize = true;
            labelFlightsList.Location = new Point(12, 9);
            labelFlightsList.Name = "labelFlightsList";
            labelFlightsList.Size = new Size(90, 15);
            labelFlightsList.TabIndex = 3;
            labelFlightsList.Text = "Список рейсов";
            // 
            // labelFlightInfo
            // 
            labelFlightInfo.AutoSize = true;
            labelFlightInfo.Location = new Point(12, 199);
            labelFlightInfo.Name = "labelFlightInfo";
            labelFlightInfo.Size = new Size(126, 15);
            labelFlightInfo.TabIndex = 4;
            labelFlightInfo.Text = "Информация о рейсе";
            // 
            // InfoForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(labelFlightInfo);
            Controls.Add(labelFlightsList);
            Controls.Add(buttonClose);
            Controls.Add(textBoxInfo);
            Controls.Add(listBoxFlights);
            Name = "InfoForm";
            Text = "InfoForm";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListBox listBoxFlights;
        private TextBox textBoxInfo;
        private Button buttonClose;
        private Label labelFlightsList;
        private Label labelFlightInfo;
    }
}