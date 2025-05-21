namespace CSVEditor
{
    partial class CVSForm
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            dataGridView = new DataGridView();
            btnOpen = new Button();
            btnSave = new Button();
            btnNew = new Button();
            lblStatus = new Label();
            ((System.ComponentModel.ISupportInitialize)dataGridView).BeginInit();
            SuspendLayout();
            // 
            // dataGridView
            // 
            dataGridView.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            dataGridView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView.Location = new Point(14, 47);
            dataGridView.Margin = new Padding(4, 3, 4, 3);
            dataGridView.Name = "dataGridView";
            dataGridView.Size = new Size(887, 528);
            dataGridView.TabIndex = 0;
            // 
            // btnOpen
            // 
            btnOpen.Location = new Point(14, 14);
            btnOpen.Margin = new Padding(4, 3, 4, 3);
            btnOpen.Name = "btnOpen";
            btnOpen.Size = new Size(88, 27);
            btnOpen.TabIndex = 1;
            btnOpen.Text = "Открыть";
            btnOpen.UseVisualStyleBackColor = true;
            btnOpen.Click += btnOpen_Click;
            // 
            // btnSave
            // 
            btnSave.Location = new Point(108, 14);
            btnSave.Margin = new Padding(4, 3, 4, 3);
            btnSave.Name = "btnSave";
            btnSave.Size = new Size(88, 27);
            btnSave.TabIndex = 2;
            btnSave.Text = "Сохранить";
            btnSave.UseVisualStyleBackColor = true;
            btnSave.Click += btnSave_Click;
            // 
            // btnNew
            // 
            btnNew.Location = new Point(203, 14);
            btnNew.Margin = new Padding(4, 3, 4, 3);
            btnNew.Name = "btnNew";
            btnNew.Size = new Size(88, 27);
            btnNew.TabIndex = 3;
            btnNew.Text = "Новый";
            btnNew.UseVisualStyleBackColor = true;
            btnNew.Click += btnNew_Click;
            // 
            // lblStatus
            // 
            lblStatus.Anchor = AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            lblStatus.BorderStyle = BorderStyle.Fixed3D;
            lblStatus.Location = new Point(14, 579);
            lblStatus.Margin = new Padding(4, 0, 4, 0);
            lblStatus.Name = "lblStatus";
            lblStatus.Size = new Size(887, 27);
            lblStatus.TabIndex = 5;
            lblStatus.Text = "Готов";
            lblStatus.TextAlign = ContentAlignment.MiddleLeft;
            // 
            // CVSForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(915, 616);
            Controls.Add(lblStatus);
            Controls.Add(btnNew);
            Controls.Add(btnSave);
            Controls.Add(btnOpen);
            Controls.Add(dataGridView);
            Margin = new Padding(4, 3, 4, 3);
            Name = "CVSForm";
            Text = "CSV Editor";
            ((System.ComponentModel.ISupportInitialize)dataGridView).EndInit();
            ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.Button btnOpen;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnNew;
        private System.Windows.Forms.Label lblStatus;
    }
}