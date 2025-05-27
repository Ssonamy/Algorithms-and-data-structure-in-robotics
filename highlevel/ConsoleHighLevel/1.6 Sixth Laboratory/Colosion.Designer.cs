using System.Windows.Forms;
using System.Drawing;
using static System.Net.Mime.MediaTypeNames;
using System.Drawing.Printing;
using System.Xml.Linq;

namespace BallCollisionSimulation
{
    partial class Colosion
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        // Элементы управления
        private Panel panelControls;
        private PictureBox pictureBox;
        private Button buttonStartStop;
        private Button buttonResetScore;
        private Label labelScore;
        private Label labelBallRadius;
        private NumericUpDown numericUpDownBallRadius;
        private Label labelBallSpeed;
        private NumericUpDown numericUpDownBallSpeed;
        private Label labelLeftBatHeight;
        private NumericUpDown numericUpDownLeftBatHeight;
        private Label labelRightBatHeight;
        private NumericUpDown numericUpDownRightBatHeight;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            panelControls = new Panel();
            buttonStartStop = new Button();
            buttonResetScore = new Button();
            labelScore = new Label();
            labelBallRadius = new Label();
            numericUpDownBallRadius = new NumericUpDown();
            labelBallSpeed = new Label();
            numericUpDownBallSpeed = new NumericUpDown();
            labelLeftBatHeight = new Label();
            numericUpDownLeftBatHeight = new NumericUpDown();
            labelRightBatHeight = new Label();
            numericUpDownRightBatHeight = new NumericUpDown();
            pictureBox = new PictureBox();
            panelControls.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)numericUpDownBallRadius).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownBallSpeed).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownLeftBatHeight).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownRightBatHeight).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox).BeginInit();
            SuspendLayout();
            // 
            // panelControls
            // 
            panelControls.BackColor = SystemColors.ControlLight;
            panelControls.Controls.Add(buttonStartStop);
            panelControls.Controls.Add(buttonResetScore);
            panelControls.Controls.Add(labelScore);
            panelControls.Controls.Add(labelBallRadius);
            panelControls.Controls.Add(numericUpDownBallRadius);
            panelControls.Controls.Add(labelBallSpeed);
            panelControls.Controls.Add(numericUpDownBallSpeed);
            panelControls.Controls.Add(labelLeftBatHeight);
            panelControls.Controls.Add(numericUpDownLeftBatHeight);
            panelControls.Controls.Add(labelRightBatHeight);
            panelControls.Controls.Add(numericUpDownRightBatHeight);
            panelControls.Dock = DockStyle.Top;
            panelControls.Location = new Point(0, 0);
            panelControls.Margin = new Padding(4, 5, 4, 5);
            panelControls.Name = "panelControls";
            panelControls.Size = new Size(1143, 167);
            panelControls.TabIndex = 0;
            // 
            // buttonStartStop
            // 
            buttonStartStop.Location = new Point(29, 25);
            buttonStartStop.Margin = new Padding(4, 5, 4, 5);
            buttonStartStop.Name = "buttonStartStop";
            buttonStartStop.Size = new Size(143, 38);
            buttonStartStop.TabIndex = 0;
            buttonStartStop.Text = "Start";
            buttonStartStop.UseVisualStyleBackColor = true;
            buttonStartStop.Click += buttonStartStop_Click;
            // 
            // buttonResetScore
            // 
            buttonResetScore.Location = new Point(29, 75);
            buttonResetScore.Margin = new Padding(4, 5, 4, 5);
            buttonResetScore.Name = "buttonResetScore";
            buttonResetScore.Size = new Size(143, 38);
            buttonResetScore.TabIndex = 1;
            buttonResetScore.Text = "Reset Score";
            buttonResetScore.UseVisualStyleBackColor = true;
            buttonResetScore.Click += buttonResetScore_Click;
            // 
            // labelScore
            // 
            labelScore.AutoSize = true;
            labelScore.Location = new Point(29, 125);
            labelScore.Margin = new Padding(4, 0, 4, 0);
            labelScore.Name = "labelScore";
            labelScore.Size = new Size(136, 25);
            labelScore.TabIndex = 2;
            labelScore.Text = "Left: 0   Right: 0";
            // 
            // labelBallRadius
            // 
            labelBallRadius.AutoSize = true;
            labelBallRadius.Location = new Point(214, 25);
            labelBallRadius.Margin = new Padding(4, 0, 4, 0);
            labelBallRadius.Name = "labelBallRadius";
            labelBallRadius.Size = new Size(101, 25);
            labelBallRadius.TabIndex = 3;
            labelBallRadius.Text = "Ball Radius:";
            // 
            // numericUpDownBallRadius
            // 
            numericUpDownBallRadius.Location = new Point(314, 22);
            numericUpDownBallRadius.Margin = new Padding(4, 5, 4, 5);
            numericUpDownBallRadius.Minimum = new decimal(new int[] { 5, 0, 0, 0 });
            numericUpDownBallRadius.Name = "numericUpDownBallRadius";
            numericUpDownBallRadius.Size = new Size(86, 31);
            numericUpDownBallRadius.TabIndex = 4;
            numericUpDownBallRadius.Value = new decimal(new int[] { 10, 0, 0, 0 });
            numericUpDownBallRadius.ValueChanged += numericUpDownBallRadius_ValueChanged;
            // 
            // labelBallSpeed
            // 
            labelBallSpeed.AutoSize = true;
            labelBallSpeed.Location = new Point(214, 75);
            labelBallSpeed.Margin = new Padding(4, 0, 4, 0);
            labelBallSpeed.Name = "labelBallSpeed";
            labelBallSpeed.Size = new Size(98, 25);
            labelBallSpeed.TabIndex = 5;
            labelBallSpeed.Text = "Ball Speed:";
            // 
            // numericUpDownBallSpeed
            // 
            numericUpDownBallSpeed.DecimalPlaces = 1;
            numericUpDownBallSpeed.Increment = new decimal(new int[] { 1, 0, 0, 65536 });
            numericUpDownBallSpeed.Location = new Point(314, 72);
            numericUpDownBallSpeed.Margin = new Padding(4, 5, 4, 5);
            numericUpDownBallSpeed.Minimum = new decimal(new int[] { 1, 0, 0, 0 });
            numericUpDownBallSpeed.Name = "numericUpDownBallSpeed";
            numericUpDownBallSpeed.Size = new Size(86, 31);
            numericUpDownBallSpeed.TabIndex = 6;
            numericUpDownBallSpeed.Value = new decimal(new int[] { 5, 0, 0, 0 });
            numericUpDownBallSpeed.ValueChanged += numericUpDownBallSpeed_ValueChanged;
            // 
            // labelLeftBatHeight
            // 
            labelLeftBatHeight.AutoSize = true;
            labelLeftBatHeight.Location = new Point(429, 25);
            labelLeftBatHeight.Margin = new Padding(4, 0, 4, 0);
            labelLeftBatHeight.Name = "labelLeftBatHeight";
            labelLeftBatHeight.Size = new Size(133, 25);
            labelLeftBatHeight.TabIndex = 7;
            labelLeftBatHeight.Text = "Left Bat Height:";
            // 
            // numericUpDownLeftBatHeight
            // 
            numericUpDownLeftBatHeight.Location = new Point(571, 22);
            numericUpDownLeftBatHeight.Margin = new Padding(4, 5, 4, 5);
            numericUpDownLeftBatHeight.Minimum = new decimal(new int[] { 20, 0, 0, 0 });
            numericUpDownLeftBatHeight.Name = "numericUpDownLeftBatHeight";
            numericUpDownLeftBatHeight.Size = new Size(86, 31);
            numericUpDownLeftBatHeight.TabIndex = 8;
            numericUpDownLeftBatHeight.Value = new decimal(new int[] { 80, 0, 0, 0 });
            numericUpDownLeftBatHeight.ValueChanged += numericUpDownLeftBatHeight_ValueChanged;
            // 
            // labelRightBatHeight
            // 
            labelRightBatHeight.AutoSize = true;
            labelRightBatHeight.Location = new Point(429, 75);
            labelRightBatHeight.Margin = new Padding(4, 0, 4, 0);
            labelRightBatHeight.Name = "labelRightBatHeight";
            labelRightBatHeight.Size = new Size(146, 25);
            labelRightBatHeight.TabIndex = 9;
            labelRightBatHeight.Text = "Right Bat Height:";
            // 
            // numericUpDownRightBatHeight
            // 
            numericUpDownRightBatHeight.Location = new Point(571, 72);
            numericUpDownRightBatHeight.Margin = new Padding(4, 5, 4, 5);
            numericUpDownRightBatHeight.Minimum = new decimal(new int[] { 20, 0, 0, 0 });
            numericUpDownRightBatHeight.Name = "numericUpDownRightBatHeight";
            numericUpDownRightBatHeight.Size = new Size(86, 31);
            numericUpDownRightBatHeight.TabIndex = 10;
            numericUpDownRightBatHeight.Value = new decimal(new int[] { 80, 0, 0, 0 });
            numericUpDownRightBatHeight.ValueChanged += numericUpDownRightBatHeight_ValueChanged;
            // 
            // pictureBox
            // 
            pictureBox.BackColor = Color.Black;
            pictureBox.Dock = DockStyle.Fill;
            pictureBox.Location = new Point(0, 167);
            pictureBox.Margin = new Padding(4, 5, 4, 5);
            pictureBox.Name = "pictureBox";
            pictureBox.Size = new Size(1143, 883);
            pictureBox.TabIndex = 1;
            pictureBox.TabStop = false;
            pictureBox.Paint += pictureBox_Paint;
            pictureBox.MouseClick += PictureBox_MouseClick;
            pictureBox.MouseMove += PictureBox_MouseMove;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1143, 1050);
            Controls.Add(pictureBox);
            Controls.Add(panelControls);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Margin = new Padding(4, 5, 4, 5);
            MaximizeBox = false;
            Name = "Form1";
            Text = "Ball Collision Simulation";
            KeyDown += Form1_KeyDown;
            panelControls.ResumeLayout(false);
            panelControls.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)numericUpDownBallRadius).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownBallSpeed).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownLeftBatHeight).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownRightBatHeight).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox).EndInit();
            ResumeLayout(false);
        }

        #endregion
    }
}
