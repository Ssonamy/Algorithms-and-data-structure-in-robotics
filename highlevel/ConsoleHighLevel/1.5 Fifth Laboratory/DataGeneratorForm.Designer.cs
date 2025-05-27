namespace SurfaceScanner
{
    partial class DataGeneratorForm
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.TextBox txtAmplitude;
        private System.Windows.Forms.TextBox txtPeriod;
        private System.Windows.Forms.TextBox txtStep;
        private System.Windows.Forms.Button btnGenerate;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            txtAmplitude = new TextBox();
            txtPeriod = new TextBox();
            txtStep = new TextBox();
            btnGenerate = new Button();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            SuspendLayout();
            // 
            // txtAmplitude
            // 
            txtAmplitude.Location = new Point(167, 38);
            txtAmplitude.Margin = new Padding(5, 6, 5, 6);
            txtAmplitude.Name = "txtAmplitude";
            txtAmplitude.Size = new Size(164, 31);
            txtAmplitude.TabIndex = 0;
            // 
            // txtPeriod
            // 
            txtPeriod.Location = new Point(167, 96);
            txtPeriod.Margin = new Padding(5, 6, 5, 6);
            txtPeriod.Name = "txtPeriod";
            txtPeriod.Size = new Size(164, 31);
            txtPeriod.TabIndex = 1;
            // 
            // txtStep
            // 
            txtStep.Location = new Point(167, 154);
            txtStep.Margin = new Padding(5, 6, 5, 6);
            txtStep.Name = "txtStep";
            txtStep.Size = new Size(164, 31);
            txtStep.TabIndex = 2;
            // 
            // btnGenerate
            // 
            btnGenerate.Location = new Point(167, 231);
            btnGenerate.Margin = new Padding(5, 6, 5, 6);
            btnGenerate.Name = "btnGenerate";
            btnGenerate.Size = new Size(167, 58);
            btnGenerate.TabIndex = 3;
            btnGenerate.Text = "Сгенерировать";
            btnGenerate.UseVisualStyleBackColor = true;
            btnGenerate.Click += btnGenerate_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(33, 44);
            label1.Margin = new Padding(5, 0, 5, 0);
            label1.Name = "label1";
            label1.Size = new Size(105, 25);
            label1.TabIndex = 4;
            label1.Text = "Амплитуда:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(12, 102);
            label2.Margin = new Padding(5, 0, 5, 0);
            label2.Name = "label2";
            label2.Size = new Size(145, 25);
            label2.TabIndex = 5;
            label2.Text = "Периодичность:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(14, 160);
            label3.Margin = new Padding(5, 0, 5, 0);
            label3.Name = "label3";
            label3.Size = new Size(144, 25);
            label3.TabIndex = 6;
            label3.Text = "Шаг измерений:";
            // 
            // DataGeneratorForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(390, 310);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(btnGenerate);
            Controls.Add(txtStep);
            Controls.Add(txtPeriod);
            Controls.Add(txtAmplitude);
            Margin = new Padding(5, 6, 5, 6);
            Name = "DataGeneratorForm";
            Text = "Генератор данных";
            Load += DataGeneratorForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }
    }
}