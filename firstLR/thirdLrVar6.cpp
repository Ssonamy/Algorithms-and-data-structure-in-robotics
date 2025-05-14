#include <iostream>
#include "functions.h"
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

    // Добавление имени
    cout << "Введите название тела: "; 
    cin >> name;

    manuallyAddedCelestialBody->setName(name);
    cout << "Значение задано успешно!" << endl << endl;

    // Добавиление "яркости"
    while (true) {
        cout << "Введите звездную величину (Для справки - ?): ";
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
                cout << "Некорректное значение!\nУстановлено значение по умолчанию (0)" << endl << endl;
                manuallyAddedCelestialBody->setMagnitude(0);
            }
            break;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
        }
    }
    cout << "Координаты:" << endl << endl;

    // Доабавление превой координаты
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
            cout << "Некорректное значение" << endl << endl;
        }
    }	

    // Добавление второй координаты
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
                cout << "Некорректное значение!\nУстановлено значение по умолчанию (0)" << endl << endl;
               manuallyAddedCelestialBody->setDeclination(0);
            }
            break;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
        }
    }

    cout << "Вывести информацию о этом теле? \n1 - Да\n2 - Нет \n";
    bool infoFlag = true;

    // Цикл выбора выводить инфу или нет
    while (infoFlag) {
        int choice = autoInt();
        switch (choice)
        {
        case 1:
            manuallyAddedCelestialBody->printInfo();
            cout << endl;
            infoFlag = false;
            break;

        case 2:
            infoFlag = false;
            break;

        default:
            cout << "Некорректное значение" << endl << endl;
            break;
        }
    }

    cout << endl << "Сохранить тело? \n1 - Да\n2 - Нет \n";
    bool saveFlag = true;

    // Цикл выбора сохранять или нет
    while (saveFlag) {
        int choice = autoInt();

        switch (choice)
        {
        case 1:
            bodies.push_back(manuallyAddedCelestialBody);
            cout << "Тело добавлено!" << endl << endl;
            saveFlag = false;

            break;
        case 2:
            cout << "Отмена изменений" << endl << endl;
            saveFlag = false;
            break;

        default:
            cout << "Некорректное значение" << endl << endl;
            break;
        }
    }
}

static void showBodies() {
    bool mainFlag = true;

    while (mainFlag) {

        if (bodies.size() == 0) {
            cout << endl << "Не добавлено ни одого тела." << endl;
            cout << "Добавить тело? \nВведите: \n1 - Да \n2 - Нет" << endl;
            int emptyIf = autoInt();
            if (emptyIf == 1) {
                addBody();
                continue;
            }

            else if (emptyIf == 2) {
                mainFlag = false;
                break;
            }
            else {
                cout << "Некорректное значение" << endl;
                continue;
            }

            int i = 1;

            cout << endl << "Сохраненные тела:" << endl;
            for (const auto& body : bodies) {
                cout << i << ". " << body->getName() << endl;
                i++;
            }

            cout << endl << "   Отоброзить подробную информацию? " << endl;
            cout << "Для подробной информации по каждому телу - 0" << endl;
            cout << "Для подробной информации по конкретному телу - его номер" << endl;
            cout << "Для возвращения в меню - -1" << endl;

            int choice = autoInt() - 1;
            i = 1;

            if (choice == -2) {
                mainFlag = false;
            }

            else if (choice == -1) {
                cout << endl;
                for (const auto& body : bodies) {
                    cout << i << ". " << body->getName();
                    body->printInfo();
                    i++;
                    cout << endl << endl;
                }
            }

            else if (static_cast<size_t>(choice) <= bodies.size()) {
                bodies[choice]->printInfo();
                cout << endl;
            }

            else {
                cout << "Некорректное значение" << endl;
            }
        }
    }
}

static void changeDeliteBodies(std::vector<std::shared_ptr<CelestialBody>>& bodies,
    std::vector<std::shared_ptr<CelestialSystem>>& systems) {
    bool mainFlag = true;

    while (mainFlag) {
        if (bodies.size() == 0) {
            cout << endl << "Не добавлено ни одого тела." << endl;
            cout << "Добавить тело? \nВведите: \n1 - Да \n2 - Нет" << endl;
            int emptyIf = autoInt();
            if (emptyIf == 1) {
                addBody();
                continue;
            }

            else if (emptyIf == 2) {
                mainFlag = false;
                break;
            }
            else {
                cout << "Некорректное значение" << endl;
                continue;
            }

        }
        cout << endl << "Список тел:" << endl;
        int i = 1;
        for (const auto& body : bodies) {
            cout << i << ". " << body->getName() << endl;
            i++;
        }

        cout << endl << "Введите номер тела (0 для выхода в меню). ";
        int choice = autoInt();

        if (choice == 0) {
            mainFlag = false;
        }
        else if (choice > 0 && static_cast<size_t>(choice) <= bodies.size()) {
            shared_ptr<CelestialBody> selectedBody = bodies[choice - 1];

            while (mainFlag) {
                cout << "\nВыбрано тело: " << selectedBody->getName() << endl;
                cout << "Введите: " << endl;
                cout << "1. Изменить название" << endl;
                cout << "2. Изменить прямое восхождение" << endl;
                cout << "3. Изменить склонение" << endl;
                cout << "4. Изменить видимую звездную величину" << endl;
                cout << "5. Удалить тело" << endl;
                cout << "0. Выбор тела" << endl;
                cout << "-1. Выход в меню" << endl;

                int forSwitch = autoInt();
                cout << endl;
                string input;

                switch (forSwitch) {
                case 1:
                    cout << "Введите название: ";
                    cin >> input;
                    selectedBody->setName(input);
                    cout << "Название успешно изменено" << endl;
                    break;

                case 2:
                    cout << "Введите прямое восхождение: ";
                    cin >> input;
                    if (isDouble(input)) {
                        selectedBody->setRightAscension(stod(input));
                        cout << "Прямое восхождение успешно изменено" << endl;
                    }
                    else {
                        cout << "Некорректное значение" << endl;
                    }
                    break;

                case 3:
                    cout << "Введите склонение: ";
                    cin >> input;
                    if (isDouble(input)) {
                        try {
                            selectedBody->setDeclination(stod(input));
                            cout << "Склонение успешно изменено" << endl;

                        }
                        catch (const exception&) {
                            cout << "Некорректное значение\nИзменения не были применены." << endl;
                        }
                    }
                    break;

                case 4:
                    cout << "Введите видимую звездную величину: ";
                    cin >> input;
                    if (isDouble(input)) {
                        try {
                            selectedBody->setMagnitude(stod(input));
                            cout << "Видимая звездная величина успешно изменена" << endl;

                        }
                        catch (const exception&) {
                            cout << "Некорректное значение\nИзменения не были применены." << endl;

                        }
                    }
                    break;

                case 5: {
                    cout << "Удалить тело? (это навсегда)\n1 - Да\n2 - Нет" << endl;
                    int confirm = autoInt();
                    if (confirm == 1) {
                        // Удаление из всех систем
                        for (auto& system : systems) {
                            system->removeBody(selectedBody);
                        }

                        // Удаление из глобального списка тел
                        bodies.erase(bodies.begin() + (choice - 1));
                        cout << "Тело удалено.\n" << endl;
                        mainFlag = false;
                    }
                    break;
                }

                case -1:
                    mainFlag = false;
                    break;

                default:
                    cout << "Некорректное значение" << endl;
                    break;
                }
            }
        }
        else {
            cout << "Некорректное значение" << endl;
        }
    }
}

static void addSystem() {
    string name, input;
    auto manuallyAddedCelestialSystem = std::make_shared<CelestialSystem>();

    cout << "Создание системы:" << endl << endl;

    // Добавление имени
    cout << "Введите название системы: ";
    cin >> name;

    manuallyAddedCelestialSystem->setName(name);
    cout << "Значение задано успешно!" << endl << endl;

    // Добавиление "яркости"
    while (true) {
        cout << "Введите звездную величину (Для справки - ?): ";
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
                manuallyAddedCelestialSystem->setMagnitude(stod(input));
                cout << "Значение задано успешно!" << endl;
            }
            catch (invalid_argument) {
                cout << "Некорректное значение!\nУстановлено значение по умолчанию (0)" << endl << endl;
                manuallyAddedCelestialSystem->setMagnitude(0);
            }
            break;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
        }
    }

    cout << "Координаты:" << endl << endl;

    // Доабавление превой координаты
    while (true) {
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
            manuallyAddedCelestialSystem->setRightAscension(stod(input));
            cout << "Значение задано успешно!" << endl << endl;
            break;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
        }
    }

    // Добавление второй координаты
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
                manuallyAddedCelestialSystem->setDeclination(stod(input));
                cout << "Значение задано успешно!" << endl << endl;
            }
            catch (invalid_argument) {
                cout << "Некорректное значение!\nУстановлено значение по умолчанию (0)" << endl << endl;
                manuallyAddedCelestialSystem->setDeclination(0);
            }
            break;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
        }
    }

    cout << "Вывести информацию о этой системе? \n1 - Да\n2 - Нет \n";
    bool infoFlag = true;
    
    // Цикл выбора выводить инфу или нет
    while (infoFlag) {
        int choice = autoInt();
        switch (choice)
        {
        case 1:
            manuallyAddedCelestialSystem->printInfo();
            cout << endl;
            infoFlag = false;
            break;

        case 2:
            infoFlag = false;
            break;

        default:
            cout << "Некорректное значение" << endl << endl;
            break;
        }
    }

    cout << endl << "Сохранить систему? \n1 - Да\n2 - Нет \n";
    bool saveFlag = true;

    // Цикл выбора сохранять или нет
    while (saveFlag) {
        int choice = autoInt();

        switch (choice)
        {
        case 1:
            bodies.push_back(manuallyAddedCelestialSystem);
            cout << "Система добавлена!" << endl << endl;
            saveFlag = false;

            break;
        case 2:
            cout << "Отмена изменений" << endl << endl;
            saveFlag = false;
            break;

        default:
            cout << "Некорректное значение" << endl << endl;
            break;
        }
    }
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
    cout << "Карта звездного неба" << endl;

    while (true) {

        cout << "____________________" << endl;
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
            cout << endl;
            changeDeliteBodies(bodies, systems);
            break;
        case 4:
            cout << endl;
            addSystem();
            break;
        case 5:
            cout << endl;
            showSystems();
            break;
        case 6:
            cout << endl;
            changeDeliteSystems();
            break;
        case 7:
            cout << endl;
            addMap();
            break;
        case 8:
            cout << endl;
            rotate();
            break;
        case 9:
            cout << endl;
            filtMap();
            break;
        case 10:

            cout << "в тесты вошли";

            while (mainFlag)
            {
                cout << "____________________" << endl;
                cout << "Тестирование:" << endl << endl;
                cout << "Введите:" << endl;
                cout << "1. Тестирование класса CelestialBody" << endl;
                cout << "2. Тестирование класса CelestialSystem" << endl;
                cout << "3. Тестирование небесной карты" << endl;
                cout << "4. Тестирование всех элементов" << endl;
                cout << "0. Назад" << endl;
                cout << "-1. Выход" << endl << endl;

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
                    //testSkyMapClass();
                    cout << endl;
                    break;

                case 4:
                    testCelestialBodyClass();
                    cout << endl;
                    testCelestialSystemClass();
                    cout << endl;
                    //testSkyMapClass();
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