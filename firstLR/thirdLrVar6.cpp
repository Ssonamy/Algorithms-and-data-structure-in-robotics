#include <iostream>
#include "functions.h"
#include <clocale>
#include <string>
#include <vector>
#include "tests.h"
#include "CelestialBody.h"
#include <memory>
#include "CelestialSystem.h"

using namespace std;

vector<shared_ptr<CelestialBody>> bodies;
vector<shared_ptr<CelestialSystem>> systems;

// Добавление тела
static void addBody() {
    string name, input; 
    auto manuallyAddedCelestialBody = std::make_shared<CelestialBody>();

    cout << "Создание тела:" << endl << endl;
    cout << "Введите название тела: "; 
    cin >> name;

    manuallyAddedCelestialBody->setName(name);
    cout << "Значение задано успешно!" << endl;

    while (true) {
        cout << endl << "Введите звездную величину (Для справки - ?): ";
        cin >> input;

        if (input == "?") {
            cout << endl << "	Звёздная величина (Magnitude)" << endl;
            cout << "	Единицы: безразмерная шкала (-30, 30)" << endl;
            cout << "	Характеризует яркость объекта: чем меньше значение, тем ярче объект." << endl;
            cout << "	Звёзды видимые невооружённым глазом имеют значения от примерно -1.5 (яркие) до +6.0 (самые тусклые, едва видимые)." << endl;
            cout << "	Пример: Солнце: -26.7, Луна: -12.7, Сириус: -1.46" << endl << endl;
        }

        else if (isDouble(input)) {
            try {
                manuallyAddedCelestialBody->setMagnitude(stod(input));
                cout << "Значение задано успешно!" << endl;
            }
            catch (invalid_argument) {
                cout << "Некорректное значение!\nУстановлено значение по умолчанию (0)" << endl;
                manuallyAddedCelestialBody->setMagnitude(0);
            }
            break;
        }

        else {
            cout << "Некорректное значение" << endl;
        }
    }
    cout << endl << "Координаты:" << endl << endl;

    while (true){
        cout << "Введите прямое восхождение (Для справки - ?): ";
        cin >> input;

        if (input == "?") {
            cout << endl << "	Прямое восхождение (Right Ascension, RA)" << endl;
            cout << "	Единицы измерения: градусы (0-360°)" << endl;
            cout << "	Это аналог долготы на небесной сфере." << endl;
            cout << "	Показывает, насколько «восточнее» звезда от точки весеннего равноденствия." << endl;
            cout << "	Пример: 82,5 градуса — это 82,5 градуса дуги." << endl << endl;
        }

        else if (isDouble(input)) {
                manuallyAddedCelestialBody->setRightAscension(stod(input));
                cout << "Значение задано успешно!" << endl << endl;
            break;
        }

        else {
            cout << "Некорректное значение" << endl;
        }
    }	

    while (true) {
        cout << "Введите cклонение (Для справки - ?): ";
        cin >> input;

        if (input == "?") {
            cout << endl << "	Склонение (Declination, Dec)" << endl;
            cout << "	Единицы измерения: градусы (-90° до +90°)" << endl;
            cout << "	Это аналог широты на небесной сфере." << endl;
            cout << "	Значение показывает, насколько объект находится к северу (положительное значение) или к югу (отрицательное значение) от небесного экватора." << endl;
            cout << "	Пример: -30° - южное полушарие, +45° - северное." << endl << endl;
        }

        else if (isDouble(input)) {
            try {
                manuallyAddedCelestialBody->setDeclination(stod(input));
                cout << "Значение задано успешно!" << endl << endl;
            }
            catch (invalid_argument) {
                cout << "Некорректное значение!\nУстановлено значение по умолчанию (0)" << endl;
               manuallyAddedCelestialBody->setDeclination(0);
            }
            break;
        }

        else {
            cout << "Некорректное значение" << endl;
        }
    }

    cout << "Вывести информацию о этом теле? \n1 - Да\n2 - Нет \n";
    int choice = autoInt();
    bool infoFlag = true;
    while (infoFlag) {
        switch (choice)
        {
        case 1:
            cout << endl;
            manuallyAddedCelestialBody->printInfo();
            infoFlag = false;
            break;

        case 2:
            infoFlag = false;
            break;

        default:
            cout << "Некорректное значение" << endl;
            break;
        }
    }
    cout << endl << "Сохранить тело? \n1 - Да\n2 - Нет \n";
    choice = autoInt();

    bool saveFlag = true;

    while (saveFlag) {
        switch (choice)
        {
        case 1:
            bodies.push_back(manuallyAddedCelestialBody);
            cout << "Тело добавлено!" << endl << endl;
            saveFlag = false;

            break;
        case 2:
            cout << "Отмена изменений" << endl;
            saveFlag = false;
            break;

        default:
            cout << "Некорректное значение" << endl << endl;
            continue;
        }
    }
}

static void showBodies() {
    bool mainFlag = true;

    while (mainFlag) {
        int i = 1;

        cout << endl << "Сохраненные тела:" << endl;
        for (const auto& body : bodies) {
            cout << i << ". " << body->getName() << endl;
            i++;
        }

        cout << endl << "Отоброзить подробную информацию? " << endl;
        cout << "	Для подробной информации по каждому телу - 0" << endl;
        cout << "	Для подробной информации по конкретному телу - его номер" << endl;
        cout << "	Для возвращения в меню - -1" << endl;

        int choice = autoInt() - 1;
        i = 1;

        if (choice == -2) {
            mainFlag = false;
        }

        else if (choice == -1) {
            cout << endl;
            for (const auto& body : bodies) {
                cout << i << "." << endl;
                body->printInfo();
                i++;
                cout << endl;
            } 
            mainFlag = false;
        }

        else if (static_cast<size_t>(choice) <= bodies.size()) {
            cout << endl;
            bodies[choice]->printInfo();
            mainFlag = false;
        }

        else {
            cout << "Некорректное значение" << endl;
        }
    }
}

void deleteBody(const shared_ptr<CelestialBody>& bodyToDelete,
    vector<shared_ptr<CelestialSystem>>& systems,
    vector<shared_ptr<CelestialBody>>& bodies) {

    // Удаляем из всех систем
    for (auto& system : systems) {
        system->removeBody(bodyToDelete);
    }

    // Удаляем из основного списка
    auto it = std::find(bodies.begin(), bodies.end(), bodyToDelete);
    if (it != bodies.end()) {
        bodies.erase(it);
        cout << "Тело удалено." << endl;
    }
    else {
        cout << "Не удалось найти тело для удаления." << endl;
    }
}

static void changeDeliteBodies() {
    bool mainFlag = true;

    while (mainFlag) {
        cout << endl << "Список тел:" << endl;
        int i = 1;
        for (const auto& body : bodies) {
            cout << i << ". " << body->getName() << endl;
            i++;
        }
        cout << endl << "Введите номер тела (-1 для выхода в меню): ";
        int choice = autoInt();

        if (choice == -1) {
            mainFlag = false;
        }
        else if (static_cast<size_t>(choice - 1) <= bodies.size()) {

            while (true) {
            cout << "Выбраное тело: " << bodies[choice]->getName() << endl << endl;
            cout << "Введите: " << endl;
            cout << "1. Изменить название" << endl;
            cout << "2. Изменить прямое восхождение" << endl;
            cout << "3. Изменить склонение" << endl;
            cout << "4. Изменить видимую звездную величину" << endl;
            cout << "5. Удалить тело" << endl;
            cout << "0. Назад." << endl << endl;

            string input;
            int forSwitch = autoInt();
                switch (forSwitch)
                {
                case 1:
                    cout << "Введите название: ";
                    cin >> input;
                    bodies[choice]->setName(input);
                    break;

                case 2:
                    while (true) {
                        cout << "Введите прямое восхождение: ";
                        cin >> input;
                        if (isDouble(input)) {
                            bodies[choice]->setRightAscension(stod(input));
                            break;
                        }
                        else {
                            cout << endl << "Некорректное значение" << endl;
                        }
                    }
                    break;

                case 3:
                    while (true) {
                        cout << "Введите склонение: ";
                        cin >> input;
                        if (isDouble(input)) {
                            try
                            {
                                bodies[choice]->setDeclination(stod(input));
                                break;
                            }
                            catch (const std::exception&)
                            {
                                cout << endl << "Некорректное значение" << endl;
                            }
                        }
                    }
                    break;

                case 4:
                    while (true) {
                        cout << "Введите видимую звездную величину: ";
                        cin >> input;
                        if (isDouble(input)) {
                            try
                            {
                                bodies[choice]->setMagnitude(stod(input));
                                break;
                            }
                            catch (const std::exception&)
                            {
                                cout << endl << "Некорректное значение" << endl;
                            }
                        }
                    }
                    break;

                case 5:
                    cout << "Удалить тело? (это навсегда) \n1 - Да \n2 - Нет" << endl;
                    int forIf = autoInt();
                    if (forIf == 1) {

                    }
                    break;

                case 0:
                    mainFlag = false;
                    break;

                default:
                    cout << "Некорректное значение" << endl;
                    break;
                }
                break;
            }
        }
        else {
            cout << "Некорректное значение" << endl;
        }
    }
}


static void addSystem() {

}

static void showSystems(){

}

static void changeDeliteSystems() {

}

static void addMap() {

}

static void rotate(){

}

static void filtMap() {

}

bool thirdLrVar6() {
    setlocale(LC_ALL, "ru_RU.utf8");


    cout << "Карта звездного неба" << endl;
    while (true) {

        cout << endl << "____________________" << endl;
        cout << "Главное меню:" << endl << endl;
        cout << "Введите: " << endl;
        cout << "1. Создать тело" << endl; 
        cout << "2. Просмотреть все тела" << endl;
        cout << "3. Изменить/удалить тело" << endl;
        cout << "4. Создать систему" << endl;
        cout << "5. Просмотреть все системы" << endl;
        cout << "6. Изменить/удалить систему" << endl;
        cout << "7. Создать карту" << endl;
        cout << "8. Повернуть карту" << endl;
        cout << "9. Отфильтровать по яркости" << endl;
        cout << "10. Тестирование " << endl;
        cout << "0. Назад. " << endl;
        cout << "-1. Выход. " << endl;

        int forSwitch = autoInt();
        bool mainFlag = true;

        switch (forSwitch)
        {
        case 1:
            cout << endl;
            addBody();
            break;
        case 2:
            showBodies();
            break;
        case 3:
            changeDeliteBodies();
            break;
        case 4:
            addSystem();
            break;
        case 5:
            showSystems();
            break;
        case 6:
            changeDeliteSystems();
            break;
        case 7:
            addMap();
            break;
        case 8:
            rotate();
            break;
        case 9:
            filtMap();
            break;
        case 10:

            while (mainFlag)
            {
                cout << endl << "____________________" << endl;
                cout << "Тестирование:" << endl << endl;
                cout << "Введите:" << endl;
                cout << "1. Тестирование класса CelestialBody" << endl;
                cout << "2. Тестирование класса CelestialSystem" << endl;
                cout << "3. Тестирование небесной карты" << endl;
                cout << "4. Тестирование всех элементов" << endl;
                cout << "0. Назад" << endl;
                cout << "-1. Выход" << endl;

                int forTest = autoInt();
                switch (forTest)
                {
                case 1:
                    testCelestialBodyClass();
                    cout << endl;
                    break;

                case 2:
                    testCelestialSystemClass();
                    cout << endl;
                    break;

                case 3:
                    testSkyMapClass();
                    cout << endl;
                    break;

                case 4:
                    testCelestialBodyClass();
                    cout << endl;
                    testCelestialSystemClass();
                    cout << endl;
                    testSkyMapClass();
                    cout << endl;
                    break;

                case 0:
                    mainFlag = false;
                    break;

                case -1:
                    return 1;

                default:
                    cout << "Некорректное значение." << endl;
                    break;
                }
            }
            break;

        default:

            cout << "Некорректное значение." << endl;
            break;
        case 0:
            return 0;

        case -1:
            return 1;
        }
    }
}