using System.Windows.Forms.DataVisualization.Charting;

namespace SurfaceScanner
{
    partial class MainSurfaceForm
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Button btnExport;
        private System.Windows.Forms.DateTimePicker dateTimePickerStart;
        private System.Windows.Forms.DateTimePicker dateTimePickerEnd;
        private System.Windows.Forms.Button btnGenerate;
        private System.Windows.Forms.Button btnDrawHeightMap;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart;
        private System.Windows.Forms.TextBox txtK;
        private System.Windows.Forms.TextBox txtB;
        private System.Windows.Forms.Button btnDrawSection;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnClearDb;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
                components.Dispose();
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            pictureBox = new PictureBox();
            btnExport = new Button();
            dateTimePickerStart = new DateTimePicker();
            dateTimePickerEnd = new DateTimePicker();
            btnGenerate = new Button();
            btnDrawHeightMap = new Button();
            txtK = new TextBox();
            txtB = new TextBox();
            btnDrawSection = new Button();
            label1 = new Label();
            label2 = new Label();
            btnClearDb = new Button();
            ((System.ComponentModel.ISupportInitialize)pictureBox).BeginInit();
            SuspendLayout();
            // 
            // pictureBox
            // 
            pictureBox.BackColor = SystemColors.Window;
            pictureBox.BorderStyle = BorderStyle.FixedSingle;
            pictureBox.Location = new Point(20, 23);
            pictureBox.Name = "pictureBox";
            pictureBox.Size = new Size(665, 575);
            pictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox.TabIndex = 0;
            pictureBox.TabStop = false;
            // 
            // btnExport
            // 
            btnExport.Location = new Point(697, 23);
            btnExport.Name = "btnExport";
            btnExport.Size = new Size(200, 58);
            btnExport.TabIndex = 1;
            btnExport.Text = "Экспорт данных";
            btnExport.UseVisualStyleBackColor = true;
            btnExport.Click += btnExport_Click;
            // 
            // dateTimePickerStart
            // 
            dateTimePickerStart.Location = new Point(697, 115);
            dateTimePickerStart.Name = "dateTimePickerStart";
            dateTimePickerStart.Size = new Size(331, 31);
            dateTimePickerStart.TabIndex = 2;
            // 
            // dateTimePickerEnd
            // 
            dateTimePickerEnd.Location = new Point(697, 165);
            dateTimePickerEnd.Name = "dateTimePickerEnd";
            dateTimePickerEnd.Size = new Size(331, 31);
            dateTimePickerEnd.TabIndex = 3;
            // 
            // btnGenerate
            // 
            btnGenerate.Location = new Point(697, 215);
            btnGenerate.Name = "btnGenerate";
            btnGenerate.Size = new Size(200, 58);
            btnGenerate.TabIndex = 4;
            btnGenerate.Text = "Генератор данных";
            btnGenerate.UseVisualStyleBackColor = true;
            btnGenerate.Click += btnGenerate_Click;
            // 
            // btnDrawHeightMap
            // 
            btnDrawHeightMap.Location = new Point(697, 285);
            btnDrawHeightMap.Name = "btnDrawHeightMap";
            btnDrawHeightMap.Size = new Size(200, 58);
            btnDrawHeightMap.TabIndex = 5;
            btnDrawHeightMap.Text = "Карта высот";
            btnDrawHeightMap.UseVisualStyleBackColor = true;
            btnDrawHeightMap.Click += btnDrawHeightMap_Click;
            // 
            // txtK
            // 
            txtK.Location = new Point(907, 246);
            txtK.Name = "txtK";
            txtK.Size = new Size(81, 31);
            txtK.TabIndex = 7;
            // 
            // txtB
            // 
            txtB.Location = new Point(907, 335);
            txtB.Name = "txtB";
            txtB.Size = new Size(81, 31);
            txtB.TabIndex = 8;
            // 
            // btnDrawSection
            // 
            btnDrawSection.Location = new Point(907, 385);
            btnDrawSection.Name = "btnDrawSection";
            btnDrawSection.Size = new Size(125, 44);
            btnDrawSection.TabIndex = 9;
            btnDrawSection.Text = "Построить сечение";
            btnDrawSection.UseVisualStyleBackColor = true;
            btnDrawSection.Click += btnDrawSection_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(909, 215);
            label1.Name = "label1";
            label1.Size = new Size(25, 25);
            label1.TabIndex = 10;
            label1.Text = "k:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(907, 304);
            label2.Name = "label2";
            label2.Size = new Size(27, 25);
            label2.TabIndex = 11;
            label2.Text = "b:";
            // 
            // btnClearDb
            // 
            btnClearDb.Location = new Point(697, 355);
            btnClearDb.Name = "btnClearDb";
            btnClearDb.Size = new Size(200, 58);
            btnClearDb.TabIndex = 13;
            btnClearDb.Text = "Очистить базу";
            btnClearDb.UseVisualStyleBackColor = true;
            btnClearDb.Click += clearDb_Click;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1133, 930);
            Controls.Add(btnClearDb);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(btnDrawSection);
            Controls.Add(txtB);
            Controls.Add(txtK);
            Controls.Add(btnDrawHeightMap);
            Controls.Add(btnGenerate);
            Controls.Add(dateTimePickerEnd);
            Controls.Add(dateTimePickerStart);
            Controls.Add(btnExport);
            Controls.Add(pictureBox);
            Name = "MainForm";
            Text = "Сканер рельефа";
            Load += MainForm_Load;
            ((System.ComponentModel.ISupportInitialize)pictureBox).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }
    }
}
