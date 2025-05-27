using System;
using System.Drawing;
using System.Windows.Forms;

namespace BallCollisionSimulation
{
    public partial class Colosion : Form
    {
        // Размеры игрового поля
        private const int fieldWidth = 640;
        private const int fieldHeight = 480;

        // Свойства мяча
        private float ballX, ballY;         // координаты центра мяча
        private float ballVX, ballVY;       // компоненты скорости (в пикселях за тик)
        private float ballSpeed = 5f;       // модуль скорости (настраивается)
        private float ballRadius = 10f;     // радиус мяча (настраивается)

        // Свойства бит (препятствий)
        private int batWidth = 10;          // ширина бит (фиксированная)
        private int leftBatHeight = 80;     // высота левой биты
        private int rightBatHeight = 80;    // высота правой биты
        private int leftBatX = 20;          // X-координата левой биты
        private int rightBatX = fieldWidth - 20 - 10; // X-координата правой биты (учитываем batWidth)
        private int leftBatY;               // Y-координата (верх) левой биты
        private int rightBatY;              // Y-координата (верх) правой биты

        // Счёт (очки игроков)
        private int leftScore = 0;
        private int rightScore = 0;

        // Таймер для симуляции (явно используем System.Windows.Forms.Timer)
        private System.Windows.Forms.Timer timer;

        private bool simulationRunning = false; // режим работы (запущена или остановлена)

        public Colosion()
        {
            InitializeComponent();

            // Фиксированное окно
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            // Размер формы: игровое поле + панель настроек сверху
            this.ClientSize = new Size(800, 600);

            // Начальное положение мяча – центр поля
            ResetBall();

            // Инициализируем биты по вертикали – по центру игрового поля
            leftBatY = (fieldHeight - leftBatHeight) / 2;
            rightBatY = (fieldHeight - rightBatHeight) / 2;

            // Устанавливаем значения настроек в контролах (NumericUpDown)
            numericUpDownBallRadius.Value = (decimal)ballRadius;
            numericUpDownBallSpeed.Value = (decimal)ballSpeed;
            numericUpDownLeftBatHeight.Value = leftBatHeight;
            numericUpDownRightBatHeight.Value = rightBatHeight;

            // Инициализируем счет
            UpdateScoreLabel();

            // Настраиваем таймер
            timer = new System.Windows.Forms.Timer();
            timer.Interval = 20; // примерно 50 кадров в секунду
            timer.Tick += Timer_Tick;

            // Чтобы форма принимала события клавиатуры (для управления левой битой)
            this.KeyPreview = true;
            this.KeyDown += Form1_KeyDown;

            // Для управления правой битой – событие перемещения мыши на pictureBox
            pictureBox.MouseMove += PictureBox_MouseMove;
            // Дополнительно – можно добавить событие клика для сброса мяча (если нужно)
            pictureBox.MouseClick += PictureBox_MouseClick;
        }

        // Сброс мяча в центре с произвольным направлением, соблюдая, чтобы вектор имел нужный знак:
        private void ResetBall()
        {
            ballX = fieldWidth / 2;
            ballY = fieldHeight / 2;
            Random rnd = new Random();
            // случайный угол в диапазоне -45 ... 45 градусов
            double angle = (rnd.NextDouble() * 90 - 45) * Math.PI / 180.0;
            // случайное направление
            int direction = rnd.Next(0, 2) == 0 ? 1 : -1;
            ballVX = (float)(direction * ballSpeed * Math.Cos(angle));
            ballVY = (float)(ballSpeed * Math.Sin(angle));
        }

        // Таймер "тик"
        private void Timer_Tick(object sender, EventArgs e)
        {
            // Перемещаем мяч согласно его скорости
            ballX += ballVX;
            ballY += ballVY;

            // Отскок от верхней и нижней границ
            if (ballY - ballRadius < 0)
            {
                ballY = ballRadius;
                ballVY = -ballVY;
            }
            else if (ballY + ballRadius > fieldHeight)
            {
                ballY = fieldHeight - ballRadius;
                ballVY = -ballVY;
            }

            // Столкновение с левой битой
            if (ballX - ballRadius <= leftBatX + batWidth)
            {
                if (ballY >= leftBatY && ballY <= leftBatY + leftBatHeight)
                {
                    ballX = leftBatX + batWidth + ballRadius;
                    ballVX = Math.Abs(ballVX); // отскок вправо
                }
            }

            // Столкновение с правой битой
            if (ballX + ballRadius >= rightBatX)
            {
                if (ballY >= rightBatY && ballY <= rightBatY + rightBatHeight)
                {
                    ballX = rightBatX - ballRadius;
                    ballVX = -Math.Abs(ballVX); // отскок влево
                }
            }

            // Проверка выхода мяча за левую или правую границу (ворота)
            if (ballX - ballRadius < 0)
            {
                // Выезд влево – зарабатывает правая сторона
                rightScore++;
                ResetBall();
                UpdateScoreLabel();
            }
            else if (ballX + ballRadius > fieldWidth)
            {
                // Выезд вправо – зарабатывает левая сторона
                leftScore++;
                ResetBall();
                UpdateScoreLabel();
            }

            pictureBox.Invalidate();
        }

        // Отрисовка игровой области
        private void pictureBox_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            // Заполняем фон (игровое поле) черным
            g.Clear(Color.Black);

            // Рисуем мяч (белый круг)
            g.FillEllipse(Brushes.White, ballX - ballRadius, ballY - ballRadius, ballRadius * 2, ballRadius * 2);

            // Рисуем левую биту (синяя)
            g.FillRectangle(Brushes.Blue, leftBatX, leftBatY, batWidth, leftBatHeight);

            // Рисуем правую биту (красная)
            g.FillRectangle(Brushes.Red, rightBatX, rightBatY, batWidth, rightBatHeight);
        }

        // Обработчик кнопки Start/Pause
        private void buttonStartStop_Click(object sender, EventArgs e)
        {
            simulationRunning = !simulationRunning;
            if (simulationRunning)
            {
                timer.Start();
                buttonStartStop.Text = "Pause";
                EnableSettings(false);
            }
            else
            {
                timer.Stop();
                buttonStartStop.Text = "Start";
                EnableSettings(true);
            }
        }

        // Включить/выключить настройки (NumericUpDown и сброс счета) в режиме паузы
        private void EnableSettings(bool enabled)
        {
            numericUpDownBallRadius.Enabled = enabled;
            numericUpDownBallSpeed.Enabled = enabled;
            numericUpDownLeftBatHeight.Enabled = enabled;
            numericUpDownRightBatHeight.Enabled = enabled;
            buttonResetScore.Enabled = enabled;
        }

        // Сброс счета
        private void buttonResetScore_Click(object sender, EventArgs e)
        {
            leftScore = 0;
            rightScore = 0;
            UpdateScoreLabel();
            ResetBall();
        }

        // Обновление метки счета
        private void UpdateScoreLabel()
        {
            labelScore.Text = $"Left: {leftScore}   Right: {rightScore}";
        }

        // Обработчики изменения настроек
        private void numericUpDownBallRadius_ValueChanged(object sender, EventArgs e)
        {
            ballRadius = (float)numericUpDownBallRadius.Value;
            pictureBox.Invalidate();
        }

        private void numericUpDownBallSpeed_ValueChanged(object sender, EventArgs e)
        {
            ballSpeed = (float)numericUpDownBallSpeed.Value;
            // Изменяем скорость с сохранением направления
            double angle = Math.Atan2(ballVY, ballVX);
            ballVX = (float)(ballSpeed * Math.Cos(angle));
            ballVY = (float)(ballSpeed * Math.Sin(angle));
        }

        private void numericUpDownLeftBatHeight_ValueChanged(object sender, EventArgs e)
        {
            leftBatHeight = (int)numericUpDownLeftBatHeight.Value;
            if (leftBatY + leftBatHeight > fieldHeight)
                leftBatY = fieldHeight - leftBatHeight;
            pictureBox.Invalidate();
        }

        private void numericUpDownRightBatHeight_ValueChanged(object sender, EventArgs e)
        {
            rightBatHeight = (int)numericUpDownRightBatHeight.Value;
            if (rightBatY + rightBatHeight > fieldHeight)
                rightBatY = fieldHeight - rightBatHeight;
            pictureBox.Invalidate();
        }

        // Управление левой битой с клавиатуры (W и S)
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            int delta = 10;

            if (e.KeyCode == Keys.W) // Вверх
            {
                leftBatY -= delta;
                if (leftBatY < 0)
                    leftBatY = 0;
                pictureBox.Invalidate();
            }
            else if (e.KeyCode == Keys.S) // Вниз
            {
                leftBatY += delta;
                if (leftBatY + leftBatHeight > fieldHeight)
                    leftBatY = fieldHeight - leftBatHeight;
                pictureBox.Invalidate();
            }
        }


        // Управление правой битой мышью (движение указателя по pictureBox)
        private void PictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            // Центрируем правую биту по Y относительно указателя мыши
            rightBatY = e.Y - rightBatHeight / 2;
            if (rightBatY < 0)
                rightBatY = 0;
            if (rightBatY + rightBatHeight > fieldHeight)
                rightBatY = fieldHeight - rightBatHeight;
            pictureBox.Invalidate();
        }


        // При клике по pictureBox можно, например, сбрасывать мяч
        private void PictureBox_MouseClick(object sender, MouseEventArgs e)
        {
            if (!simulationRunning)
            {
                ResetBall();
                pictureBox.Invalidate();
            }
        }
    }
}
