public static class firstLaboratory
{
    public static void main()
    {
        bool exit = false;
        int varX = 0;
        double result = 0;
        Console.WriteLine("Программа вычисления Y по формуле при введенном X");
        while (true)
        {

            while (true)
            {
                Console.Write("Введите X (Для выхода впишите 'выход'): ");

                string input = Console.ReadLine();
                if (input == "Выход" || input == "выход")
                {
                    exit = true;
                    break;
                }
                if (int.TryParse(input, out varX))
                {
                    break;
                }
                else
                {
                    Console.WriteLine("\nНекорректное значение.");
                }
            }
            if (exit)
            {
                Console.WriteLine("Завершение программы... \n(Для выхода нажмите любую клавишу)");
                Console.ReadKey();
                break;

            }

            if (varX > 10)
            {
                result = varX - (Math.Pow(varX, 2.4) / (varX - 1 / varX));
                Console.WriteLine($"При Х = {varX} функция вычисляется по формуле Y = x - (x^2.4)/(x - 1.х). \nРезультат = {result}");
            }
            else if (-1 < varX && varX <= 3)
            {
                result = varX + (Math.Pow((varX + 2), (2.5)));
                Console.WriteLine($"При Х = {varX} функция вычисляется по формуле Y = x +(x + 2)^(2.5). \nРезультат = {result}");
            }
            else
            {
                Console.WriteLine($"При Х = {varX} функция не определена.");
            }
        }

    }
}