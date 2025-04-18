#include <windows.h>						//Для изменения кодировки
#include <iostream>							//Для ввода вывода
#include <string>							//Для getline'а
#include <vector>							//Для записи оценок студента
#include <sstream>							//Для ввода в массив
#include <numeric>							//Для нахождения суммы оценок
using namespace std;						//Чтобы не писать "std::"

//Переменные для вызова функций (см ForSwitch)
string first = "Студент";
string second = "Библиотека";
string help = "Помощь";
string EXIT = "Выход";

class Student {
private:
	string name;							// Имя студента
	int age;								// Возраст студента
	double averageGrade;					// Средний балл
	vector<int> grades;						// Массив для хранения оценок

	// Метод для вычисления среднего балла
	void calculateAverage() {
		if (!grades.empty()) {
			averageGrade = static_cast<double>(
				accumulate(grades.begin(), grades.end(), 0)) / grades.size();
		}
		else {
			averageGrade = 0.0;
		}
	}

public:

	// Конструктор для инициализации имени и возраста
	Student(const string& studentName, int studentAge) {
		name = studentName;
		age = studentAge;
		averageGrade = 0.0;					//Средний балл по умолчанию
	}

	// Метод для добавления оценок
	void addGrades(const vector<int>& newGrades) {
		for (int grade : newGrades) {
			grades.push_back(grade);
		}
		calculateAverage();					// Пересчитываем средний балл
	}

	// Метод для вывода информации о студенте
	void displayInfo() const {
		cout << "Имя: " << name << endl;
		cout << "Возраст: " << age << endl;
		cout << "Оценки: " << endl;
		for (int grade : grades) {
			cout << grade << " ";
		}
		cout << endl;
		cout << "Средний балл: " << averageGrade << endl;
	}

	string getName() const {
		return name;
	}
};

class Book {

private:
	string title;
	string author;
	int year;

public:
	// Конструктор по умолчанию
	Book() : title("Неизвестно"), author("Неизвестен"), year(0) {}

	// Конструктор с параметрами	
	Book(const string& bookTitle, const string& bookAuthor, int bookYear)
		: title(bookTitle), author(bookAuthor), year(bookYear) {
	}

	// Метод для вывода информации о книге
	void displayInfo() const {
		cout << "Название: " << title << endl;
		cout << "Автор: " << author << endl;
		cout << "Год издания: " << year << endl;
	}

	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	int getYear() const { return year; }

};

class Library {
private:
	vector<Book> books;

public:

	void addBook(const string& title, const string& author, int year) {
		books.emplace_back(title, author, year);
	}

	void displayBooks() const {
		if (books.empty()) {
			cout << "Библиотека пуста." << endl;
			return;
		}

		cout << "Книги в библиотеке:" << endl;
		for (const auto& book : books) {
			book.displayInfo();
			cout << "--------------------" << endl;
		}
	}

	void findBookByTitle(const string& searchTitle) const {
		for (const auto& book : books) {
			if (book.getTitle() == searchTitle) {
				cout << "Книга найдена:" << endl;
				book.displayInfo();
				return;
			}
		}
		cout << "Книга с названием \"" << searchTitle << "\" не найдена." << endl;
	}

	void removeBookByTitle(const string& title) {
		auto it = remove_if(books.begin(), books.end(),
			[&title](const Book& book) { return book.getTitle() == title; });

		if (it != books.end()) {
			books.erase(it, books.end());
			cout << "Книга с названием \"" << title << "\" удалена." << endl;
		}
		else {
			cout << "Книга с названием \"" << title << "\" не найдена." << endl;
		}
	}
};

//Проверка является ли строка числом
bool isInt(string input) {
	try {
		int n = stoi(input);
		return true;
	}
	catch (...) {
		return false;
	}
}

//Перевод из строки в число
int toInt(string input = "") {
	//Если функция не получает данных на вход
	if (input == "") {
		cout << "Введите число: ";
		do {
			cin >> input;
			try {
				return stoi(input);
			}
			catch (...) {
				cout << "Введите корректное значение: ";
			}
		} while (true);
	}
	//Если получает данные на вход
	else {
		try {
			return stoi(input);
		}
		catch (...) {}
	}
}

void student(vector<Student>& students) {
	int input;
	do {
		cout << "\nВыберите действие\n";
		cout << "1. Добавить студента\n";
		cout << "2. Добавить оценки студенту\n";
		cout << "3. Показать всех студентов\n";
		cout << "0. Выход\n";
		cout << "Ваш выбор: ";
		input = toInt();
		cin.ignore();

		switch (input) {
		case 0:
			cout << "Выход из функции." << endl;
			return;

		case 1:
			while (true) {
				cout << "\nВведите имя студента (или 'Stop' для завершения):\n";
				string name;
				cin >> name;

				if (name == "Stop") { // Проверяем условие выхода
					break;
				}

				cout << "Введите ворзаст студента: ";
				int age = toInt();

				if (age <= 0) {
					cout << "Возраст должен быть положительным числом. Попробуйте ещё раз." << endl;
					continue;
				}

				students.emplace_back(name, age);
				cout << "Студент добавлен!" << endl;
			}
			break;

		case 2: {
			cout << endl << "Введите имя студента: ";
			string forVec, name;
			vector<int> vec;
			int num;
			cin >> name;

			cin.ignore();
			bool found = false;
			for (auto& student : students) {
				if (student.getName() == name) {
					found = true;

					cout << endl << "Введите оценки через пробел" << endl;
					getline(cin, forVec);

					istringstream ss(forVec);
					while (ss >> num) {
						vec.push_back(num);
					}

					student.addGrades(vec);
					cout << "Оценки добавлены!" << endl;
					break;
				}
			}

			if (!found) {
				cout << "Студент с именем " << name << " не найден." << endl;
			}
			break;
		}
		case 3:
			if (students.empty()) {
				cout << "Список студентов пуст." << endl;
				break;
			}

			cout << endl << "Список студентов:" << endl;
			for (const auto& student : students) {
				student.displayInfo();
				cout << "-----------------" << endl;
			}
			break;

		default:
			cout << "Неверный ввод. Попробуйте ещё раз." << endl;
		}
	} while (input != 0);
}

void library() {
	int input;
	Library library;

	do {

		cout << "\nВыберите действие\n";
		cout << "1. Добавить книгу\n";
		cout << "2. Поиск книги\n";
		cout << "3. Показать все книги\n";
		cout << "4. Удалить книгу\n";
		cout << "0. Выход\n";
		cout << "Ваш выбор: ";
		input = toInt();
		cin.ignore();

		switch (input) {
		case 1: {
			string title, author;
			int year;

			do {
				cout << "\nВведите название книги (введите Stop для завершения ввода, если неизвестен один или несколько полей оставьте их пустыми):";
				getline(cin, title);

				if (title != "Stop") {

					cout << "\nВведите автора:";
					getline(cin, author);

					cout << "\nВведите год издания:";
					year = toInt();
					cin.ignore();

					library.addBook(title, author, year);
					cout << "Книга успешно добавлена!" << endl;
					continue;
				}
				cout << "Спасибо что добавили книги!";
			} while (title != "Stop");
			break;
		}

		case 2: {
			string input;
			cout << endl;
			cout << "Поиск по названию.\n";
			cout << "Введите название книги: ";
			getline(cin, input);
			library.findBookByTitle(input);
			break;
		}

		case 3:
			cout << endl;
			library.displayBooks();
			break;

		case 4: {
			string title;

			cout << endl;
			cout << "Удаление книги" << endl;
			cout << "Введите название книги:" << endl << endl;

			getline(cin, title);
			library.removeBookByTitle(title);
		}
		}
	} while (input != 0);
}

//Функция перевода команд в цифры
int forSwitch(string input) {
	if (isInt(input)) {
		return toInt(input);
	}
	else {
		if (input == first) {
			return 1;
		}
		else if (input == second) {
			return 2;
		}
		else if (input == help) {
			return 3;
		}
		else if (input == EXIT) {
			return 0;
		}
	}
}

//Список команд
void list() {
	cout << "__________________________________________________________________________________\n";
	cout << "1. Студент: Добавление и просмотр информации о студентах." << endl;
	cout << "2. Библиотека: Добавление, удаление, вывод всех книг." << endl;
	cout << "__________________________________________________________________________________\n";
}

//Главная функция
int SeventhLaba() {
	vector<Student> students;
	//Изменение кодировки на ввод и вывод
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Приветствие?
	cout << "__________________________________________________________________________________\n";
	cout << "Вы запустили сборник функций лабораторной №7.\n";
	cout << "Для обращения к функциям наберите порядковый номер задачи или укажите её название.\n";
	cout << "Для вызова справки введите 'Помощь'.\nДля выхода введите 'Выход'.\n";
	cout << "__________________________________________________________________________________\n";

	//Бесконечный цикл для выбора команд
	while (true) {
		cout << "Ваш выбор: ";
		string input;
		cin >> input;
		cout << endl;

		switch (forSwitch(input)) {

		case 0:
			cout << "Выход из программы.";
			return 0;
		case 1:
			cout << "Работа со студентами." << endl;
			student(students);
			break;
		case 2:
			cout << "Библиотека." << endl;
			library();
			break;
		case 3:
			list();
			break;
		default:
			cout << "Введите корректное значение. Для вызова справки введите 'Помощь'." << endl;
		}
	}

	return 0;
}