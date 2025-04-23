using System.Windows.Forms;
using SecondPractik;

namespace HighLevel
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {

            Console.WriteLine("Добро пожаловать в сборник программ по дисциплине\n" +
                "Программирование и алгоритмизация на языках высокого уровня\n");
            string choice;

            while (true)
            {
                bool cycle = true;
                Console.WriteLine(
                "---------------\n" +
                "Введите:\n" +
                "1. Лабораторные работы\n" +
                "2. Практические работы\n" +
                "0. Выход\n" +
                "---------------\n");

                Console.Write("Введите: ");

                choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        while (cycle)
                        {
                            Console.WriteLine(
                            "---------------\n" +
                            "Лабораторные работы:\n" +
                            "1. 'Разработка консольных приложений на C#' \n" +
                            "2. 'Применение циклических алгоритмов' \n" +
                            "3. \n" +
                            "4. \n" +
                            "5. \n" +
                            "6. \n" +
                            "0. Назад\n" +
                            "-1. Выход \n" +
                            "---------------\n");
                            Console.Write("Введите: ");
                            choice = Console.ReadLine();
                            switch (choice)
                            {
                                case "1":
                                    Console.Write("\n");
                                    firstLaboratory.main();
                                    break;

                                case "2":
                                    Console.Write("\n");
                                    secondLaboratory.main();
                                    break;

                                case "3":
                                    Console.Write("\n");

                                    break;

                                case "4":
                                    Console.Write("\n");

                                    break;

                                case "5":
                                    Console.Write("\n");

                                    break;

                                case "6":
                                    Console.Write("\n");

                                    break;

                                case "0":
                                    cycle = false;
                                    break;

                                case "-1":
                                    return;

                                default:
                                    Console.WriteLine("Некорректное значение.");
                                    break;

                            }
                        }
                        break;

                    case "2":
                        while (cycle)
                        {
                            Console.WriteLine(
                            "---------------\n" +
                            "Практические работы:\n" +
                            "1. 'Калькулятор'\n" +
                            "2. 'Калькулятор (с графическим интерфейсом)'\n" +
                            "2.1 'Веб-обозреватель'\n" +
                            "3. \n" +
                            "4. \n" +
                            "5. \n" +
                            "6. \n" +
                            "0. Назад\n" +
                            "-1. Выход \n" +
                            "---------------\n");
                            Console.Write("Введите: ");
                            choice = Console.ReadLine();
                            switch (choice)
                            {
                                case "1":
                                    Console.Write("\n");
                                    firstPractical.CalculatorCs();
                                    break;

                                case "2":
                                    Console.Write("\n");

                                    break;
                                case "2.1":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();
                                    Application.SetCompatibleTextRenderingDefault(false);

                                    // Запуск формы из другого проекта
                                    Application.Run(new Form1());
                                    break;

                                case "3":
                                    Console.Write("\n");

                                    break;

                                case "4":
                                    Console.Write("\n");

                                    break;

                                case "5":
                                    Console.Write("\n");

                                    break;

                                case "6":
                                    Console.Write("\n");

                                    break;

                                case "0":
                                    cycle = false;
                                    break;

                                case "-1":
                                    return;

                                default:
                                    Console.WriteLine("Некорректное значение.");
                                    break;
                            }
                        }
                        break;

                    case "0":
                        return;
                }
            }
        }
    }
}