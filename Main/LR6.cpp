#include <iostream>
#include <windows.h>
#include <fstream> // Для работы с файлами
#include <string>
using namespace std;

// Определяем структуру для 4, 5 функций
struct Person {
	string name;  // Используем string вместо массива char
	int age;
	double height;
};

//Определение целочисленности числа
bool isInt(string x) {
	bool e;
	try {
		int num = stoi(x);
		return e = 1;
	}
	catch (...) {
		return e = 0;
	}

} // функция, определяющая является ли ввод числом 

//Перевод из строки в число
int INTj() {
	while (true) {
		string number;
		int num;

		cout << "Введите число:" << endl;
		cin >> number;
		if (isInt(number)) {
			return num = stoi(number);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}
}

//Первая функция, записывает в файл ввод пользователя
void textToFile() {
	// Имя файла
	string filename = "output.txt";

	// Создаем объект ofstream и открываем файл в режиме записи (перезапишет файл, если он уже существует)
	ofstream file(filename, ios::trunc);

	// Проверяем, удалось ли открыть файл
	if (!file) {
		cerr << "Ошибка при открытии файла для записи!" << endl;
		return; // Завершаем программу с ошибкой
	}

	// Ввод данных от пользователя
	cout << "Введите строки для записи в файл (введите \"STOP\" для завершения ввода):" << endl;

	string line;
	while (true) {
		getline(cin, line); // Считываем строку от пользователя
		if (line == "STOP") {
			break; // Завершаем ввод, если пользователь ввел "STOP"
		}
		file << line << "\n"; // Записываем строку в файл
	}

	// Закрываем файл
	file.close();

	// Сообщаем пользователю об успешной записи
	cout << "Данные успешно записаны в файл: " << filename << endl;
}

//Вторая функция, выводит то что было записанно в файл с помощью первой функции
void fileToDisplay() {
	// Имя файла (тот же файл, который использовался для записи)
	string filename = "output.txt";

	// Создаем объект ifstream для чтения из файла
	ifstream file(filename);

	// Проверяем, удалось ли открыть файл
	if (!file) {
		cerr << "Ошибка: невозможно открыть файл " << filename << " для чтения!" << endl;
		return; // Завершаем программу с ошибкой
	}

	// Читаем строки из файла и выводим их на экран
	cout << "Содержимое файла \"" << filename << "\":" << endl;

	string line;
	while (getline(file, line)) {
		cout << line << endl; // Выводим каждую строку
	}

	// Закрываем файл
	file.close();

}

//Третья фунция добавляет в файл дополнительные строки, не удаляя исходного текста
void addstrings() {
	// Имя файла
	string filename = "output.txt";

	// Создаем объект ofstream в режиме добавления
	ofstream file(filename, ios::app);

	// Проверяем, удалось ли открыть файл
	if (!file) {
		cerr << "Ошибка при открытии файла для добавления данных!" << endl;
		return; // Завершаем программу с ошибкой
	}

	// Ввод данных от пользователя
	cout << "Введите строки для добавления в файл (введите \"STOP\" для завершения ввода):" << endl;

	string line;
	while (true) {
		getline(cin, line); // Считываем строку от пользователя
		if (line == "STOP") {
			break; // Завершаем ввод, если пользователь ввел "STOP"
		}
		file << line << "\n"; // Добавляем строку в файл
	}

	// Закрываем файл
	file.close();

	// Сообщаем пользователю об успешной записи
	cout << "Данные успешно добавлены в файл: " << filename << endl;
}

//Четвертая фунция, записывает ввод пользователя в отдельную структуру
void writeToFile() {
	string filename = "data.bin";
	ofstream file(filename);
	if (!file) {
		cerr << "Ошибка при открытии файла для записи!" << endl;
		return;
	}

	Person person;
	cout << "Введите имя: ";
	getline(cin, person.name);
	cout << "Введите возраст: ";
	person.age = INTj();
	cout << "Введите рост (в сантиматрах): ";
	person.height = INTj();

	// Записываем данные в текстовом формате
	file << person.name << "\n";
	file << person.age << "\n";
	file << person.height << "\n";

	cout << "Данные успешно записаны в файл." << endl;
}

void readFromFile() {
	string filename = "data.bin";
	ifstream file(filename);
	if (!file) {
		cerr << "Ошибка при открытии файла для чтения!" << endl;
		return;
	}

	Person person;

	// Читаем данные из файла
	getline(file, person.name);
	file >> person.age;
	file >> person.height;

	// Выводим данные
	cout << "Имя: " << person.name << endl;
	cout << "Возраст: " << person.age << endl;
	cout << "Рост: " << person.height << " см" << endl;
}


void copyingToAnother() {
	//Исходный файл
	string sourceFile = "output.txt";

	//Файл назначения
	string destinationFile = "destinationFile.txt";

	// Открываем исходный файл
	ifstream inputFile(sourceFile);
	if (!inputFile) {
		cerr << "Не удалось открыть файл " << sourceFile << " для чтения!" << endl;
		return;
	}

	// Открываем файл назначения
	ofstream outputFile(destinationFile);
	if (!outputFile) {
		cerr << "Не удалось открыть файл " << destinationFile << " для записи!" << endl;
		return;
	}

	// Читаем построчно и записываем
	string line;
	while (getline(inputFile, line)) {
		outputFile << line << '\n';
	}

	cout << "Файл успешно скопирован." << endl;
}

//Вызов справки
void hepl() {
	cout << "Список команд:" << endl;
	cout << "1. Текст в файл -- Записывает вводимый текст в файл." << endl;
	cout << "2. Вывод -- Выводит текст из файла." << endl;
	cout << "3. Добавление строк -- Записывает вводимый текст в конец файла." << endl;
	cout << "4. Бинарный файл -- Фукция для работы с бинарными файлами: запись структуры данных в файл и последующее чтение из него." << endl;
	cout << "5. Копирование файла в другой -- Копирует содержимое одного файла в другой." << endl;
	cout << "6. Помощь -- вызывает этот список." << endl;
}

//Перевод команд в числа, для работы переключателя в мэйне
int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		num = stoi(input);
		return num;
	}
	else {
		if (input == "Текст в файл") {
			return 1;
		}
		else if (input == "Вывод") {
			return 2;
		}
		else if (input == "Добавление строк") {
			return 3;
		}
		else if (input == "Бинарный файл") {
			return 4;
		}
		else if (input == "Копирование файла в другой") {
			return 5;
		}
		else if (input == "Помощь") {
			return 6;
		}
		else if (input == "Выход") {
			return 0;
		}
	}

	return num = 6;
}

int SixthLaba() {
	int choice;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Вы запустили сборник функций лабораторной №5.\nДля обращения к функциям наберите порядковый номер задачи или укажите её название.\nДля вызова справки введите 'Помощь'.\nДля выхода введите 'Выход'." << endl;
	while (true) {

		string input;
		int* newInput = new int;
		getline(cin, input);
		*newInput = forSwitch(input);

		switch (*newInput) {
		case 0:
			cout << "Выход из программы...";
			return 0;
		case 1:
			cout << "Текст в файл" << endl;
			textToFile();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			//cin.ignore(); // Убираем остаток символов из буфера
			break;
		case 2:
			cout << "Вывод" << endl;
			fileToDisplay();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			//cin.ignore(); // Убираем остаток символов из буфера
			break;
		case 3:
			cout << "Добавление строк" << endl;
			while (true) {
				addstrings();
				delete newInput;
				newInput = nullptr;
				cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
				//cin.ignore(); // Убираем остаток символов из буфера
				break;
		case 4:
			cout << "Бинарный файл" << endl;
			do {
				cout << "\nВыберите действие:\n";
				cout << "1. Записать данные в файл\n";
				cout << "2. Прочитать данные из файла\n";
				cout << "0. Выход\n";
				cout << "Ваш выбор: ";
				choice = INTj();
				cin.ignore(); // Убираем остаток символов из буфера

				switch (choice) {
				case 1:
					writeToFile();
					break;
				case 2:
					readFromFile();
					break;
				case 0:
					cout << "Выход из программы." << endl;
					break;
				default:
					cout << "Некорректный выбор! Попробуйте снова." << endl;
				}
			} while (choice != 0);
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 5:
			cout << "Копирование файла в другой" << endl;
			copyingToAnother();
			delete newInput;
			newInput = nullptr;
			//cin.ignore(); // Убираем остаток символов из буфера
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 6:
			cout << "Помощь" << endl;
			hepl();
			delete newInput;
			newInput = nullptr;
			//cin.ignore(); // Убираем остаток символов из буфера
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;

		default:
			cout << "Введите корректную команду.\n";
			delete newInput;
			newInput = nullptr;
			//cin.ignore(); // Убираем остаток символов из буфера
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
			}
		}
	}
}