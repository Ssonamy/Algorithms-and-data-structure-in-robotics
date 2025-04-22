public static class firstPractical
{
    public static void CalculatorCs()
    {
        int first = 0;
        bool exit = false;
        int second = 0;
        string op;
        Console.WriteLine("____Калькулятор____");
        while (!exit)
        {
            while (true)
            {
                Console.Write("Введите первое число (Для выхода 'выход'): ");
                string input = Console.ReadLine();
                if (input == "выход" || input == "Выход")
                {
                    exit = true;
                    break;
                }
                if (int.TryParse(input, out first))
                {
                    break;
                }
                else
                {
                    Console.WriteLine("\nНекорректное значение.");
                }
            } // Ввод первого числа
            if (exit)
            {
                break;
            }
            while (true)
            {
                Console.Write("\nВведите второе число: ");
                string input = Console.ReadLine();
                if (int.TryParse(input, out second))
                {
                    break;
                }
                else
                {
                    Console.WriteLine("\nНекорректное значение.");
                }

            } // Ввод вторгого числа

            while (true)
            {

                Console.Write("\nВыберите действие (+, -, *, /): ");
                op = Console.ReadLine();
                if (op == "+" || op == "-" || op == "*" || op == "/")
                {
                    break;
                }
                else
                {
                    Console.WriteLine("\nНекорректное значение.");
                }
            }

            switch (op)
            {

                case "+":
                    Console.WriteLine($"\nВыражение {first} + {second} равно {first + second}\n ");
                    break;
                case "-":
                    Console.WriteLine($"\nВыражение {first} - {second} равно {first - second}\n");
                    break;
                case "*":
                    Console.WriteLine($"\nВыражение {first} * {second} равно {first * second}\n");
                    break;
                case "/":
                    if (second != 0)
                    {
                        Console.WriteLine($"\nВыражение {first} / {second} равно {first / second} \n");
                        break;
                    }
                    else
                    {
                        Console.WriteLine("\nНа ноль делить нельзя!\n");
                        break;
                    }
            }

        }

    }
}