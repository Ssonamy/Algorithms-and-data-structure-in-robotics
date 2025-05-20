namespace ThirdPractik
{
    partial class ThirdPractical
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
            dataGridViewMatrix = new DataGridView();
            txtRows = new TextBox();
            txtColumns = new TextBox();
            btnGenerate = new Button();
            ((System.ComponentModel.ISupportInitialize)dataGridViewMatrix).BeginInit();
            SuspendLayout();
            // 
            // dataGridViewMatrix
            // 
            dataGridViewMatrix.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewMatrix.Location = new Point(12, 41);
            dataGridViewMatrix.Name = "dataGridViewMatrix";
            dataGridViewMatrix.Size = new Size(776, 397);
            dataGridViewMatrix.TabIndex = 0;
            // 
            // txtRows
            // 
            txtRows.Location = new Point(193, 12);
            txtRows.Name = "txtRows";
            txtRows.Size = new Size(155, 23);
            txtRows.TabIndex = 1;
            txtRows.TextAlign = HorizontalAlignment.Right;
            // 
            // txtColumns
            // 
            txtColumns.Location = new Point(12, 12);
            txtColumns.Name = "txtColumns";
            txtColumns.Size = new Size(175, 23);
            txtColumns.TabIndex = 2;
            txtColumns.Tag = "Введите количество столбцов";
            txtColumns.TextAlign = HorizontalAlignment.Right;
            // 
            // btnGenerate
            // 
            btnGenerate.Location = new Point(354, 12);
            btnGenerate.Name = "btnGenerate";
            btnGenerate.Size = new Size(142, 23);
            btnGenerate.TabIndex = 3;
            btnGenerate.Text = "Сгенерировать";
            btnGenerate.UseVisualStyleBackColor = true;
            btnGenerate.Click += btnGenerate_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(btnGenerate);
            Controls.Add(txtColumns);
            Controls.Add(txtRows);
            Controls.Add(dataGridViewMatrix);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridViewMatrix).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private DataGridView dataGridViewMatrix;
        private TextBox txtRows;
        private TextBox txtColumns;
        private Button btnGenerate;
    }
}
