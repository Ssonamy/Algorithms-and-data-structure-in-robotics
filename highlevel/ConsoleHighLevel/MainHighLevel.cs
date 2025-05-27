//using System.Windows.Forms;
using SecondPractik;
using calcWInForms;
using ThirdPractik;
using LibraryCatalog;
using Laba3Var27;
using CSVEditor;
using ShapeDrawer;
using CompanyApp;
using SurfaceScanner;
using BallCollisionSimulation;

namespace HighLevel
{
    internal static class Program
    {

        // Метод для закрытия/активации формы
        private static void OpenOrActivateForm(string formName, Form formInstance)
        {
            // Проверяем, если форма с таким именем уже открыта
            if (Application.OpenForms[formName] == null)
            {
                // Если форма не открыта, запускаем её
                Application.Run(formInstance);
            }
            else
            {
                // Если форма уже открыта, активируем её
                    Application.OpenForms[formName].Activate();
            }
        }


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
                            "3. 'Расписание рейсов самолетов'\n" +
                            "4. 'Предприятие'\n" +
                            "5. ''\n" +
                            "6. ''\n" +
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
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("FlightMainForm", new FlightMainForm());

                                    break;

                                case "4":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("MainEnterpriceForm", new MainEnterpriceForm());
                                    break;

                                case "5":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("MainSurfaceForm", new MainSurfaceForm());
                                    break;

                                case "6":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("Colosion", new Colosion());
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
                            "3. 'Двумерный массив'\n" +
                            "4. 'Библиотека' \n" +
                            "5.1. 'Работа с файлами' \n" +
                            "5.2. 'Редактор CVS' \n" +
                            "6. 'Рисоватор' \n" +
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
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("Calc", new Calc());
                                    break;
                                case "2.1":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("SecondPractical21", new SecondPractical21());
                                    break;

                                case "3":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("ThirdPractical", new ThirdPractical());
                                    break;

                                case "4":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("ConnectionForm", new ConnectionForm());
                                    break;

                                case "5.2":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("CVSForm", new CVSForm());
                                    break;

                                case "6":
                                    Console.Write("\n");
                                    Application.EnableVisualStyles();

                                    OpenOrActivateForm("Drawer", new Drower());
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