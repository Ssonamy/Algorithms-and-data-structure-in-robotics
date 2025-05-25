namespace CompanyApp
{
    partial class CompanyForm
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
            dgvCompanies = new DataGridView();
            btnSave = new Button();
            ((System.ComponentModel.ISupportInitialize)dgvCompanies).BeginInit();
            SuspendLayout();
            // 
            // dgvCompanies
            // 
            dgvCompanies.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            dgvCompanies.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvCompanies.Location = new Point(20, 23);
            dgvCompanies.Margin = new Padding(5, 6, 5, 6);
            dgvCompanies.Name = "dgvCompanies";
            dgvCompanies.RowHeadersWidth = 62;
            dgvCompanies.Size = new Size(933, 769);
            dgvCompanies.TabIndex = 0;
            // 
            // btnSave
            // 
            btnSave.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            btnSave.Location = new Point(753, 804);
            btnSave.Margin = new Padding(5, 6, 5, 6);
            btnSave.Name = "btnSave";
            btnSave.Size = new Size(200, 58);
            btnSave.TabIndex = 1;
            btnSave.Text = "Сохранить";
            btnSave.UseVisualStyleBackColor = true;
            btnSave.Click += btnSave_Click;
            // 
            // CompanyForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(973, 887);
            Controls.Add(btnSave);
            Controls.Add(dgvCompanies);
            Margin = new Padding(5, 6, 5, 6);
            Name = "CompanyForm";
            Text = "Управление компаниями";
            ((System.ComponentModel.ISupportInitialize)dgvCompanies).EndInit();
            ResumeLayout(false);
        }
        #endregion

        private System.Windows.Forms.DataGridView dgvCompanies;
        private System.Windows.Forms.Button btnSave;
    }
}