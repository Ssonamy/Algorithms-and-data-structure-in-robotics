namespace CompanyApp
{
    partial class MainEnterpriceForm
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
            dgvResults = new DataGridView();
            btnShowCompanies = new Button();
            btnShowProducts = new Button();
            btnQuery1 = new Button();
            btnQuery2 = new Button();
            btnQuery3 = new Button();
            btnQuery4 = new Button();
            txtProduct = new TextBox();
            txtProductName = new TextBox();
            txtCompanyId = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            ((System.ComponentModel.ISupportInitialize)dgvResults).BeginInit();
            SuspendLayout();
            // 
            // dgvResults
            // 
            dgvResults.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            dgvResults.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvResults.Location = new Point(14, 173);
            dgvResults.Margin = new Padding(4, 4, 4, 4);
            dgvResults.Name = "dgvResults";
            dgvResults.RowHeadersWidth = 62;
            dgvResults.Size = new Size(887, 445);
            dgvResults.TabIndex = 0;
            // 
            // btnShowCompanies
            // 
            btnShowCompanies.Location = new Point(14, 14);
            btnShowCompanies.Margin = new Padding(4, 4, 4, 4);
            btnShowCompanies.Name = "btnShowCompanies";
            btnShowCompanies.Size = new Size(175, 35);
            btnShowCompanies.TabIndex = 1;
            btnShowCompanies.Text = "Показать компании";
            btnShowCompanies.UseVisualStyleBackColor = true;
            btnShowCompanies.Click += btnShowCompanies_Click;
            // 
            // btnShowProducts
            // 
            btnShowProducts.Location = new Point(196, 14);
            btnShowProducts.Margin = new Padding(4, 4, 4, 4);
            btnShowProducts.Name = "btnShowProducts";
            btnShowProducts.Size = new Size(175, 35);
            btnShowProducts.TabIndex = 2;
            btnShowProducts.Text = "Показать продукты";
            btnShowProducts.UseVisualStyleBackColor = true;
            btnShowProducts.Click += btnShowProducts_Click;
            // 
            // btnQuery1
            // 
            btnQuery1.Location = new Point(14, 69);
            btnQuery1.Margin = new Padding(4, 4, 4, 4);
            btnQuery1.Name = "btnQuery1";
            btnQuery1.Size = new Size(175, 35);
            btnQuery1.TabIndex = 3;
            btnQuery1.Text = "Запрос 1";
            btnQuery1.UseVisualStyleBackColor = true;
            btnQuery1.Click += btnQuery1_Click;
            // 
            // btnQuery2
            // 
            btnQuery2.Location = new Point(196, 69);
            btnQuery2.Margin = new Padding(4, 4, 4, 4);
            btnQuery2.Name = "btnQuery2";
            btnQuery2.Size = new Size(175, 35);
            btnQuery2.TabIndex = 4;
            btnQuery2.Text = "Запрос 2";
            btnQuery2.UseVisualStyleBackColor = true;
            btnQuery2.Click += btnQuery2_Click;
            // 
            // btnQuery3
            // 
            btnQuery3.Location = new Point(378, 69);
            btnQuery3.Margin = new Padding(4, 4, 4, 4);
            btnQuery3.Name = "btnQuery3";
            btnQuery3.Size = new Size(175, 35);
            btnQuery3.TabIndex = 5;
            btnQuery3.Text = "Запрос 3";
            btnQuery3.UseVisualStyleBackColor = true;
            btnQuery3.Click += btnQuery3_Click;
            // 
            // btnQuery4
            // 
            btnQuery4.Location = new Point(560, 69);
            btnQuery4.Margin = new Padding(4, 4, 4, 4);
            btnQuery4.Name = "btnQuery4";
            btnQuery4.Size = new Size(175, 35);
            btnQuery4.TabIndex = 6;
            btnQuery4.Text = "Запрос 4";
            btnQuery4.UseVisualStyleBackColor = true;
            btnQuery4.Click += btnQuery4_Click;
            // 
            // txtProduct
            // 
            txtProduct.Location = new Point(196, 127);
            txtProduct.Margin = new Padding(4, 4, 4, 4);
            txtProduct.Name = "txtProduct";
            txtProduct.Size = new Size(174, 23);
            txtProduct.TabIndex = 7;
            // 
            // txtProductName
            // 
            txtProductName.Location = new Point(560, 127);
            txtProductName.Margin = new Padding(4, 4, 4, 4);
            txtProductName.Name = "txtProductName";
            txtProductName.Size = new Size(174, 23);
            txtProductName.TabIndex = 8;
            // 
            // txtCompanyId
            // 
            txtCompanyId.Location = new Point(378, 127);
            txtCompanyId.Margin = new Padding(4, 4, 4, 4);
            txtCompanyId.Name = "txtCompanyId";
            txtCompanyId.Size = new Size(174, 23);
            txtCompanyId.TabIndex = 9;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(192, 109);
            label1.Margin = new Padding(4, 0, 4, 0);
            label1.Name = "label1";
            label1.Size = new Size(112, 15);
            label1.TabIndex = 10;
            label1.Text = "Название продукта";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(374, 109);
            label2.Margin = new Padding(4, 0, 4, 0);
            label2.Name = "label2";
            label2.Size = new Size(101, 15);
            label2.TabIndex = 11;
            label2.Text = "Код предприятия";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(556, 109);
            label3.Margin = new Padding(4, 0, 4, 0);
            label3.Name = "label3";
            label3.Size = new Size(115, 15);
            label3.TabIndex = 12;
            label3.Text = "Продукт для обнов.";
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(915, 630);
            Controls.Add(dgvResults);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(txtCompanyId);
            Controls.Add(txtProductName);
            Controls.Add(txtProduct);
            Controls.Add(btnQuery4);
            Controls.Add(btnQuery3);
            Controls.Add(btnQuery2);
            Controls.Add(btnShowProducts);
            Controls.Add(btnShowCompanies);
            Controls.Add(btnQuery1);
            Margin = new Padding(4, 4, 4, 4);
            Name = "MainForm";
            Text = "Enterprise DB Manager";
            ((System.ComponentModel.ISupportInitialize)dgvResults).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }
        #endregion

        private System.Windows.Forms.DataGridView dgvResults;
        private System.Windows.Forms.Button btnShowCompanies;
        private System.Windows.Forms.Button btnShowProducts;
        private System.Windows.Forms.Button btnQuery1;
        private System.Windows.Forms.Button btnQuery2;
        private System.Windows.Forms.Button btnQuery3;
        private System.Windows.Forms.Button btnQuery4;
        private System.Windows.Forms.TextBox txtProduct;
        private System.Windows.Forms.TextBox txtProductName;
        private System.Windows.Forms.TextBox txtCompanyId;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}