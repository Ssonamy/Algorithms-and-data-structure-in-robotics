public static class secondLaboratory
{
    public static void main()
    {
        int valueK = 0; // Количество столбцов -- показывает количество предприятий
        int valueM = 0; // Количество строк -- показывает количество периодов (1период = 4 месяца)
        bool exit = false; // Флаг для выхода
        string act; // Типа действие для свичкейса
        int[,] sheet = null; // Двумерный массив, который заполняется случайными числами
        int numberK = 0;
        int numberM = 0;
        int minValue = 101;
        int maxEfitencyComp = 0;
        bool isSheetFull = false;


        Console.WriteLine("Добро пожаловать в программу учета электроэнергии предприятиями!\n");

        while (!exit)
        {
            Console.WriteLine("Введите:");
            Console.WriteLine("1 -- Ввести количество предприятий и периодов учета.");
            Console.WriteLine("2 -- Ввести таблицу учета.");
            Console.WriteLine("3 -- Определить среднее арифметическое значение расходов определенного предприятия.");
            Console.WriteLine("4 -- Определить наиболее экономное предприятие за определенный период.");
            Console.WriteLine("0 -- Выход.\n");
            Console.Write("Введите: ");

            act = Console.ReadLine();
            switch (act)
            {
                case "0":
                    Console.WriteLine("Выход.\nНажмите любую клавишу.");
                    exit = true;
                    Console.ReadKey();
                    break;

                case "1":
                    Console.WriteLine("Заполнение данных для таблицы учета.");

                    while (true)
                    {
                        Console.Write("Введите кодичество предприятий: ");
                        string input = Console.ReadLine();
                        if (int.TryParse(input, out valueK) && valueK > 0)
                        {
                            break;
                        }
                        else
                        {
                            Console.WriteLine("\nНекорректное значение.");
                        }
                    }

                    while (true)
                    {
                        Console.Write("Введите кодичество периодов учета (1 период равен четырем месяцам): ");
                        string input = Console.ReadLine();
                        if (int.TryParse(input, out valueM) && valueM > 0)
                        {
                            break;
                        }
                        else
                        {
                            Console.WriteLine("\nНекорректное значение.");
                        }
                    }

                    sheet = new int[valueM, valueK];
                    Random rand = new Random();

                    for (int i = 0; i < valueM; i++)
                    {
                        for (int j = 0; j < valueK; j++)
                        {
                            sheet[i, j] = rand.Next(0, 100);
                        }
                    }
                    Console.Write("\n");
                    isSheetFull = true;
                    break;

                case "2":
                    if (isSheetFull)
                    {
                        Console.WriteLine("\nТаблица учета (Столбец - предприятие, строка - период): \n");
                        for (int i = 0; i < valueM; i++)
                        {
                            for (int j = 0; j < valueK; j++)
                            {
                                if (sheet[i, j] / 10 < 1)
                                {
                                    Console.Write(sheet[i, j] + "  ");
                                }
                                else
                                {
                                    Console.Write(sheet[i, j] + " ");
                                }
                            }
                            Console.WriteLine("\n");
                        }
                    }
                    else { Console.WriteLine("Таблица не указана.\nВначале заполните таблицу.\n"); }
                    break;


                case "3":
                    if (isSheetFull)
                    {
                        Console.WriteLine("Определение среднего арифметического расходов предприятия.");
                        int sum = 0;

                        while (true)
                        {
                            Console.Write("Введите номер предприятия: ");
                            string input = Console.ReadLine();
                            if (int.TryParse(input, out numberK) && numberK <= valueK && numberK > 0)
                            {
                                break;
                            }
                            else
                            {
                                Console.WriteLine("\nНекорректное значение.");
                            }
                        }
                        for (int i = 0; i < valueM; i++)
                        {
                            sum += sheet[i, numberK - 1];
                        }

                        Console.WriteLine($"\nСреднее арифметическое значение расхода = {(double)sum / (double)valueM}. \n");
                    }
                    else { Console.WriteLine("Таблица не указана.\nВначале заполните таблицу.\n"); }
                    break;

                case "4":
                    if (isSheetFull)
                    {
                        Console.WriteLine("Определение самого экономичного предприятия за период.\n");

                        while (true)
                        {
                            Console.Write("Введите номер периода: ");
                            string input = Console.ReadLine();
                            if (int.TryParse(input, out numberM) && numberM <= valueM && numberM > 0)
                            {
                                break;
                            }
                            else
                            {
                                Console.WriteLine("\nНекорректное значение.");
                            }
                        }
                        for (int i = 0; i < valueK; i++)
                        {
                            if (sheet[numberM - 1, i] < minValue)
                            {
                                minValue = sheet[numberM - 1, i];
                                maxEfitencyComp = i;
                            }
                        }
                        Console.WriteLine($"Наиболее экономное предприятие -- предприятие номер {maxEfitencyComp + 1}. Её расход = {minValue}.\n");
                    }
                    else { Console.WriteLine("Таблица не указана.\nВначале заполните таблицу.\n"); }
                    break;

                default:
                    Console.WriteLine("Команда не распознана.\n");
                    break;
            }
        }

    }
}