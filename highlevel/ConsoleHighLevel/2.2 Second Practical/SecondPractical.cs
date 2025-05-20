using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;

namespace calcWInForms
{
    public partial class Calc : Form
    {
        public Calc()
        {
            InitializeComponent();
            button1.Click += NumberButton_Click;
            button2.Click += NumberButton_Click;
            button3.Click += NumberButton_Click;
            button4.Click += NumberButton_Click;
            button5.Click += NumberButton_Click;
            button6.Click += NumberButton_Click;
            button7.Click += NumberButton_Click;
            button8.Click += NumberButton_Click;
            button9.Click += NumberButton_Click;
            button0.Click += NumberButton_Click;
            PlusButton.Click += OperationButton_Click;
            MinusButton.Click += OperationButton_Click;
            MultiplyButton.Click += OperationButton_Click;
            DivisionButton.Click += OperationButton_Click;
            EqualsButton.Click += EqualButton_Click;
            DotButton.Click += ButtonDecimal_Click;

        }

        private bool isNewEntry = true; // Флаг, чтобы понимать, когда ввод нового числа
        private bool firstChar = true;
        private bool secondEqual = false;
        private double firstNumber;
        private double secondNumber;
        private double result;
        private string operation = "";

        private void calculate(EventArgs e)
        {
            if (!double.TryParse(textBoxCurrentInput.Text, out secondNumber) && !secondEqual)
            {
                MessageBox.Show("Ошибка: Некорректное число!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            result = 0;

            switch (operation)
            {
                case "+":
                    result = firstNumber + secondNumber;
                    break;
                case "-":
                    result = firstNumber - secondNumber;
                    break;
                case "×":
                    result = firstNumber * secondNumber;
                    break;
                case "÷":
                    result = secondNumber != 0 ? firstNumber / secondNumber : double.NaN;
                    break;
            }


        }
        private void NumberButton_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;
            if (btn != null)
            {
                if (textBoxCurrentInput.Text == "0" || firstChar == true)
                {
                    if (isNewEntry)
                    {
                        ClearAllButton_Click(sender, e);
                    }
                    textBoxCurrentInput.Text = btn.Text;  // Если в поле "0", заменяем его
                    firstChar = false;
                }
                else
                    textBoxCurrentInput.Text += btn.Text; // Добавляем цифру в конец строки
            }
        }
        private void OperationButton_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;
            if (btn != null)
            {
                if (isNewEntry)
                {
                    firstNumber = double.Parse(textBoxCurrentInput.Text); // Сохраняем текущее число
                    operation = btn.Text; // Сохраняем операцию

                    // Обновляем выражение и очищаем поле текущего ввода
                    textBoxExpression.Text += textBoxCurrentInput.Text + $" {operation} ";
                    textBoxCurrentInput.Text = "";
                    isNewEntry = false;
                }
                else
                {
                    calculate(e);
                    operation = btn.Text; // Сохраняем операцию

                    textBoxExpression.Text = result.ToString() + $" {operation} ";
                    //operation = "";
                    firstNumber = result;
                    //result = 0;
                    //secondNumber = 0;
                    firstChar = true;
                    //textBoxExpression.Text += textBoxCurrentInput.Text + $" {operation} ";

                }
            }
        }
        private void EqualButton_Click(object sender, EventArgs e)
        {
            if (secondEqual)
            {
                firstNumber = result;

            }
            calculate(e);
            // Выводим результат
            textBoxExpression.Text += textBoxCurrentInput.Text + " = ";
            textBoxCurrentInput.Text = result.ToString();
            isNewEntry = true;
            firstChar = true;

        }

        private void ButtonDecimal_Click(object sender, EventArgs e)
        {
            if (!textBoxCurrentInput.Text.Contains(",")) // Проверяем, есть ли уже запятая
            {
                if (firstChar)
                {
                    ClearAllButton_Click(sender, e);
                    textBoxCurrentInput.Text = "0";
                    textBoxCurrentInput.Text += ","; // Добавляем запятую в текущее число
                    firstChar = false;
                }
            }
        }


        private void button0_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {

        }

        private void DevisionButton_Click(object sender, EventArgs e)
        {

        }

        private void MultiplyButton_Click(object sender, EventArgs e)
        {

        }

        private void MinusButton_Click(object sender, EventArgs e)
        {

        }

        private void PlusButton_Click(object sender, EventArgs e)
        {

        }

        private void Button_Click(object sender, EventArgs e)
        {

        }

        private void DotButton_Click(object sender, EventArgs e)
        {

        }

        private void ClearButton_Click(object sender, EventArgs e)
        {
            textBoxCurrentInput.Text = "0"; // Очищает только ввод
        }

        private void ClearAllButton_Click(object sender, EventArgs e)
        {
            // Полный сброс всех данных
            textBoxCurrentInput.Text = "0";
            textBoxExpression.Text = "";
            firstNumber = 0;
            secondNumber = 0;
            operation = "";
            isNewEntry = true;
            firstChar = true;
        }

        private void BackspaceButton_Click(object sender, EventArgs e)
        {
            // Удаление последнего символа в текущем вводе
            if (textBoxCurrentInput.Text.Length > 1)
            {
                textBoxCurrentInput.Text = textBoxCurrentInput.Text.Substring(0, textBoxCurrentInput.Text.Length - 1);
            }
            else
            {
                textBoxCurrentInput.Text = "0"; // Если удалили последний символ, ставим "0"
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.D0:
                case Keys.NumPad0:
                    button0.PerformClick();
                    break;
                case Keys.D1:
                case Keys.NumPad1:
                    button1.PerformClick();
                    break;
                case Keys.D2:
                case Keys.NumPad2:
                    button2.PerformClick();
                    break;
                case Keys.D3:
                case Keys.NumPad3:
                    button3.PerformClick();
                    break;
                case Keys.D4:
                case Keys.NumPad4:
                    button4.PerformClick();
                    break;
                case Keys.D5:
                case Keys.NumPad5:
                    button5.PerformClick();
                    break;
                case Keys.D6:
                case Keys.NumPad6:
                    button6.PerformClick();
                    break;
                case Keys.D7:
                case Keys.NumPad7:
                    button7.PerformClick();
                    break;
                case Keys.D8:
                case Keys.NumPad8:
                    button8.PerformClick();
                    break;
                case Keys.D9:
                case Keys.NumPad9:
                    button9.PerformClick();
                    break;
                case Keys.Add:
                case Keys.Oemplus:
                    PlusButton.PerformClick();
                    break;
                case Keys.Subtract:
                case Keys.OemMinus:
                    MinusButton.PerformClick();
                    break;
                case Keys.Multiply:
                    MultiplyButton.PerformClick();
                    break;
                case Keys.Divide:
                case Keys.Oem2: // "/" на основной клавиатуре
                    DivisionButton.PerformClick();
                    break;
                case Keys.Enter:
                    EqualsButton.PerformClick();
                    break;
                case Keys.Back:
                    BackspaceButton.PerformClick();
                    break;
                case Keys.Escape:
                    ClearAllButton.PerformClick();
                    break;
                case Keys.Decimal:
                case Keys.Oemcomma:
                case Keys.OemPeriod:
                    DotButton.PerformClick();
                    break;
            }
        }
    }
}
