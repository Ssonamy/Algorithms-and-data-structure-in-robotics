namespace ShapeDrawer
{
    partial class Drower
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Button btnLoadFile;
        private System.Windows.Forms.Button btnSaveImage;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null)) components.Dispose();
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            pictureBox = new PictureBox();
            btnLoadFile = new Button();
            btnSaveImage = new Button();
            ((System.ComponentModel.ISupportInitialize)pictureBox).BeginInit();
            SuspendLayout();
            // 
            // pictureBox
            // 
            pictureBox.BackColor = Color.White;
            pictureBox.BorderStyle = BorderStyle.FixedSingle;
            pictureBox.Location = new Point(12, 12);
            pictureBox.Name = "pictureBox";
            pictureBox.Size = new Size(600, 400);
            pictureBox.TabIndex = 0;
            pictureBox.TabStop = false;
            // 
            // btnLoadFile
            // 
            btnLoadFile.Location = new Point(630, 12);
            btnLoadFile.Name = "btnLoadFile";
            btnLoadFile.Size = new Size(120, 40);
            btnLoadFile.TabIndex = 1;
            btnLoadFile.Text = "Загрузить файл";
            btnLoadFile.UseVisualStyleBackColor = true;
            btnLoadFile.Click += btnLoadFile_Click;
            // 
            // btnSaveImage
            // 
            btnSaveImage.Location = new Point(630, 58);
            btnSaveImage.Name = "btnSaveImage";
            btnSaveImage.Size = new Size(120, 40);
            btnSaveImage.TabIndex = 2;
            btnSaveImage.Text = "Сохранить PNG";
            btnSaveImage.UseVisualStyleBackColor = true;
            btnSaveImage.Click += btnSaveImage_Click;
            // 
            // Drower
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(770, 430);
            Controls.Add(pictureBox);
            Controls.Add(btnLoadFile);
            Controls.Add(btnSaveImage);
            Name = "Drower";
            Text = "Рисование из файла";
            ((System.ComponentModel.ISupportInitialize)pictureBox).EndInit();
            ResumeLayout(false);
        }
    }
}
