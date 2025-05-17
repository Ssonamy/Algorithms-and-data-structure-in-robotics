#include <iostream>
#include "functions.h"
#include <string>
#include <vector>
#include "tests.h"
#include "CelestialBody.h"
#include <memory>
#include "CelestialSystem.h"
#include "SkyMap.h"

using namespace std;

vector<shared_ptr<CelestialBody>> bodies;
vector<shared_ptr<CelestialSystem>> systems;
vector<shared_ptr<SkyMap>> maps;

// Вспомогательные функции
    // Установление яркости
static void setMagnitude(shared_ptr<CelestialBody> manuallyAddedCelestialBody) {
    string input;

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
            continue;
        }

        else if (isDouble(input)) {
            try {
                manuallyAddedCelestialBody->setMagnitude(stod(input));
                cout << "Значение задано успешно!" << endl;
            }
            catch (const invalid_argument& e) {
                cout << "Некорректное значение!\nУстановлено значение по умолчанию (0)" << endl << endl;
                manuallyAddedCelestialBody->setMagnitude(0);
            }
            break;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
            continue;
        }
    }
}

    // Установление прямого восхождения для тел и систем
static void setRA(shared_ptr<CelestialBody> manuallyAddedCelestialBody) {
    string input;
    
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
            manuallyAddedCelestialBody->setRightAscension(stod(input));
            cout << "Значение задано успешно!" << endl << endl;
            break;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
        }
    }

}

    // Установление склонения для тел и систем
static void setDec(shared_ptr<CelestialBody> manuallyAddedCelestialBody) {
    string input;

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

}

    // Вывод информации по требованию
static void printInfo(shared_ptr<CelestialBody> manuallyAddedCelestialBody) {
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
}

    // Сохранение по требованию
static void save(shared_ptr<CelestialBody> manuallyAddedCelestialBody) {
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

    setMagnitude(manuallyAddedCelestialBody);

    cout << "Координаты:" << endl << endl;

    setRA(manuallyAddedCelestialBody);
    setDec(manuallyAddedCelestialBody);

    cout << "Вывести информацию о этом теле? \n1 - Да\n2 - Нет \n";
    printInfo(manuallyAddedCelestialBody);

    cout << endl << "Сохранить тело? \n1 - Да\n2 - Нет \n";
    save(manuallyAddedCelestialBody);
}

//  Просмотр всех тел
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

// Изменеие/удаление тел
static void changeDeliteBodies() {
    bool mainFlag = true;

    while (mainFlag) {

        // Если нет тел, добавить или выйти
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

        // Варианты выбора
        cout << endl << "Список тел:" << endl;
        int i = 1;
        for (const auto& body : bodies) {
            cout << i << ". " << body->getName() << endl;
            i++;
        }

        cout << endl << "Введите номер тела (0 для выхода в меню). ";
        int choice = autoInt();

        // Работа с выбраным телом
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

                case 0:
                    continue;

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

// Добавление системы
static void addSystem() {
    string name, input;
    auto manuallyAddedCelestialSystem = std::make_shared<CelestialSystem>();

    cout << "Создание системы:" << endl << endl;

    // Добавление имени
    cout << "Введите название системы: ";
    cin >> name;

    manuallyAddedCelestialSystem->setName(name);
    cout << "Значение задано успешно!" << endl << endl;

    cout << "Координаты:" << endl << endl;

    setRA(manuallyAddedCelestialSystem);

    setDec(manuallyAddedCelestialSystem);

    // Добавление тел в систему
    bool addFlag = true;
    while (addFlag) {
        if (bodies.size() == 0) {
            cout << endl << "Не добавлено ни одого тела." << endl;
            cout << "Добавить тело? \nВведите: \n1 - Да \n2 - Нет" << endl;
            int emptyIf = autoInt();
            if (emptyIf == 1) {
                size_t oldSize = bodies.size();
                addBody();

               
                if (bodies.size() > oldSize) {
                    manuallyAddedCelestialSystem->addBody(bodies.back());
                }
                else {
                    cout << "Тело не было добавлено. Повторите попытку." << endl;
                }
                addFlag = false;
                break;
            }

            else if (emptyIf == 2) {
                cout << endl;
                addFlag = false;
                break;
            }

            else {
                cout << "Некорректное значение" << endl;
                break;
            }
        }

        else {
            cout << "Добавить сохраненное тело? \nВведите: \n1 - Да \n2 - Нет" << endl;
            int addIf = autoInt();
            cout << endl;

            if (addIf == 1) {
                int i = 1;
                cout << "Список тел:" << endl;
                for (const auto& body : bodies) {
                    cout << i << ". " << body->getName() << endl;
                    i++;
                }
                cout << endl << "Введите номер тела для добавления" << endl;
                int addIndex = autoInt();
                cout << endl;

                if (static_cast<size_t>(addIndex) <= bodies.size() && addIndex > 0){
                    shared_ptr<CelestialBody> selectedBody = bodies[addIndex - 1];
                    if (not(manuallyAddedCelestialSystem->isBodyInSystemByName(selectedBody->getName()))) {
                        cout << "Выбранное тело " << selectedBody->getName() << " успешно добавлено!" << endl << endl;
                    }
                        manuallyAddedCelestialSystem->addBody(selectedBody);
                }

                else {
                    cout << "Некорректное значение." << endl << endl;
                }
            }

            else if (addIf == 2) {
                addFlag = false;
                break;
            }

            else{
                cout << "Некорректное значение" << endl << endl;
                break;
            }
        }
    }
    
    cout << "Вывести информацию о этой системе? \n1 - Да\n2 - Нет \n";
    printInfo(manuallyAddedCelestialSystem);

    bool saveFlag = true;

    cout << endl << "Сохранить систему? \n1 - Да\n2 - Нет \n";

    // Цикл выбора сохранять или нет
    while (saveFlag) {
        int choice = autoInt();

        switch (choice) {
        case 1:
            systems.push_back(manuallyAddedCelestialSystem);
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

// Отображение всех систем + информации по запросу
static void showSystems() {
    bool mainFlag = true;

    while (mainFlag) {

        if (systems.size() == 0) {
            cout << endl << "Не добавлено ни одной системы." << endl;
            cout << "Добавить систему? \nВведите: \n1 - Да \n2 - Нет" << endl;
            int emptyIf = autoInt();
            if (emptyIf == 1) {
                addSystem();
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
        int i = 1;

        cout << endl << "Сохраненные системы:" << endl;
        for (const auto& system : systems) {
            cout << i << ". " << system->getName() << endl;
            i++;
        }

        cout << endl << "   Отоброзить подробную информацию? " << endl;
        cout << "Для подробной информации по каждой системе - 0" << endl;
        cout << "Для подробной информации по конкретной системе - её номер" << endl;
        cout << "Для возвращения в меню - -1" << endl;

        int choice = autoInt() - 1;
        i = 1;

        if (choice == -2) {
            mainFlag = false;
        }

        else if (choice == -1) {
            cout << endl;
            for (const auto& system : systems) {
                cout << i << ". " << system->getName() << endl;
                system->printInfo();
                i++;
                cout << endl << endl;
            }
        }

        else if (static_cast<size_t>(choice) <= systems.size()) {
            systems[choice]->printInfo();
            cout << endl;
        }

        else {
            cout << "Некорректное значение" << endl;
        }
    }
}

// Изменение/удаление систем
static void changeDeliteSystems() {
    bool mainFlag = true;

    while (mainFlag) {
        bool secondFlag = true;
        bool thirdFlag = true;

        // Если нет систем, добавить или выйти
        if (systems.size() == 0) {
            cout << endl << "Не добавлено ни одной системы." << endl;
            cout << "Добавить систему? \nВведите: \n1 - Да \n2 - Нет" << endl;
            int emptyIf = autoInt();
            if (emptyIf == 1) {
                addSystem();
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

        // Варианты выбора
        cout << endl << "Список систем:" << endl;
        int i = 1;
        for (const auto& system : systems) {
            cout << i << ". " << system->getName() << endl;
            i++;
        }

        cout << endl << "Введите номер системы (0 для выхода в меню). ";
        int choice = autoInt();

        // Работа с выбраным телом
        if (choice == 0) {
            mainFlag = false;
        }
        else if (choice > 0 && static_cast<size_t>(choice) <= systems.size()) {
            shared_ptr<CelestialSystem> selectedSystem = systems[choice - 1];
            const auto bodiesInSystem = selectedSystem->getMembers();

            while (secondFlag) {
                cout << "\nВыбраная система: " << selectedSystem->getName() << endl;
                cout << "Введите: " << endl;
                cout << "1. Изменить название" << endl;
                cout << "2. Изменить прямое восхождение" << endl;
                cout << "3. Изменить склонение" << endl;
                cout << "4. Удалить систему" << endl;
                cout << "5 .Удалить тело из системы" << endl;
                cout << "6. Добавить тело" << endl;
                cout << "0. Выбор системы" << endl;
                cout << "-1. Выход в меню" << endl;

                int forSwitch = autoInt();
                cout << endl;
                string input;

                switch (forSwitch) {
                case 1:
                    cout << "Введите название: ";
                    cin >> input;
                    selectedSystem->setName(input);
                    cout << "Название успешно изменено" << endl;
                    break;

                case 2:
                    cout << "Введите прямое восхождение: ";
                    cin >> input;
                    if (isDouble(input)) {
                        selectedSystem->setRightAscension(stod(input));
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
                            selectedSystem->setDeclination(stod(input));
                            cout << "Склонение успешно изменено" << endl;

                        }
                        catch (const exception&) {
                            cout << "Некорректное значение\nИзменения не были применены." << endl;
                        }
                    }
                    break;

                case 4: {
                    cout << "Удалить систему? (это навсегда)\n1 - Да\n2 - Нет" << endl;
                    int confirm = autoInt();
                    if (confirm == 1) {
                        // Удаление из всех систем
                        for (auto& map : maps) {
                            map->removeSystemByPointer(selectedSystem);
                        }

                        // Удаление из глобального списка тел
                        systems.erase(systems.begin() + (choice - 1));
                        cout << "Система удалена.\n" << endl;
                        secondFlag = false;
                        break;
                    }
                    if (confirm == 2) {
                        break;
                    }
                    else{
                        cout << "Некорректное значение" << endl;
                    }
                    break;
                }

                case 5:
                    while (thirdFlag) {
                        cout << "Сохраненные тела:" << endl;
                        for (auto& body : bodiesInSystem) {
                            cout << body->getName() << endl;
                        }
                        cout << "Введите номер тела (0 - отмена) . ";

                        choice = autoInt() - 1;
                        if (static_cast<size_t>(choice) <= bodiesInSystem.size() && choice > 0) {
                            cout << "Выбранное тело: " << bodiesInSystem[choice]->getName() << endl;
                            selectedSystem->removeBody(bodiesInSystem[choice]);
                            break;
                        }
                        else if (choice == 0) {
                            thirdFlag = false;
                            break;
                        }
                        else {
                            cout << "Некорректное значение " << endl;
                        }
                    }
                    break;

                case 6:
                    thirdFlag = true;
                    while (thirdFlag) {
                        if (bodies.size() == 0) {
                            cout << endl << "Не добавлено ни одого тела." << endl;
                            cout << "Добавить тело? \nВведите: \n1 - Да \n2 - Нет" << endl;
                            int emptyIf = autoInt();
                            if (emptyIf == 1) {
                                size_t oldSize = bodies.size();
                                addBody();


                                if (bodies.size() > oldSize) {
                                    selectedSystem->addBody(bodies.back());
                                }
                                else {
                                    cout << "Тело не было добавлено. Повторите попытку." << endl;
                                }
                                thirdFlag = false;
                                break;
                            }

                            else if (emptyIf == 2) {
                                cout << endl;
                                thirdFlag = false;
                                break;
                            }

                            else {
                                cout << "Некорректное значение" << endl;
                                break;
                            }
                        }

                        else {
                            cout << "Добавить сохраненное тело? \nВведите: \n1 - Да \n2 - Нет" << endl;
                            int addIf = autoInt();
                            cout << endl;

                            if (addIf == 1) {
                                cout << "Список тел:" << endl;
                                for (const auto& body : bodies) {
                                    int i = 1;
                                    i++;
                                    cout << i << ". " << body->getName() << endl;
                                }
                                cout << endl << "Введите номер тела для добавления" << endl;
                                int addIndex = autoInt();
                                cout << endl;

                                if (static_cast<size_t>(addIndex) <= bodies.size() && addIndex > 0) {
                                    shared_ptr<CelestialBody> selectedBody = bodies[addIndex - 1];
                                    if (not(selectedSystem->isBodyInSystemByName(selectedBody->getName()))) {
                                        cout << "Выбранное тело " << selectedBody->getName() << " успешно добавлено!" << endl << endl;
                                    }
                                    selectedSystem->addBody(selectedBody);
                                }

                                else {
                                    cout << "Некорректное значение." << endl << endl;
                                }
                            }

                            else if (addIf == 2) {
                                thirdFlag = false;
                                break;
                            }

                            else {
                                cout << "Некорректное значение" << endl << endl;
                                break;
                            }
                        }
                    }
                    break;
                case -1:
                    secondFlag = false;
                    continue;

                case 0:
                    secondFlag = false;
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

static void addMap() {
    string input;
    auto manuallyAddedSkyMap = std::make_shared<SkyMap>();

    cout << "Создание карты:" << endl << endl;

    // Добавление тел в систему
    bool addFlag = true;
    while (addFlag) {
        if (systems.size() == 0) {
            cout << endl << "Не добавлено ни одной системы." << endl;
            cout << "Добавить систему? \nВведите: \n1 - Да \n2 - Нет" << endl;
            int emptyIf = autoInt();
            if (emptyIf == 1) {
                size_t oldSize = systems.size();
                addSystem();


                if (systems.size() > oldSize) {
                    manuallyAddedSkyMap->addSystem(systems.back());
                }
                else {
                    cout << "Система не была добавлена. Повторите попытку." << endl;
                }
                addFlag = false;
                break;
            }

            else if (emptyIf == 2) {
                cout << endl;
                addFlag = false;
                break;
            }

            else {
                cout << "Некорректное значение" << endl;
                break;
            }
        }

        else {
            cout << "Добавить сохраненную систему? \nВведите: \n1 - Да \n2 - Нет" << endl;
            int addIf = autoInt();
            cout << endl;

            if (addIf == 1) {
                int i = 1;
                cout << "Список систем:" << endl;
                for (const auto& system : systems) {
                    cout << i << ". " << system->getName() << endl;
                    i++;
                }
                cout << endl << "Введите номер тела для добавления" << endl;
                int addIndex = autoInt();
                cout << endl;

                if (static_cast<size_t>(addIndex) <= systems.size() && addIndex > 0) {
                    shared_ptr<CelestialSystem> selectedSystem = systems[addIndex - 1];
                    if (not(manuallyAddedSkyMap->isSystemInSystemByName(selectedSystem->getName()))) {
                        cout << "Выбранное тело " << selectedSystem->getName() << " успешно добавлено!" << endl << endl;
                    }
                    manuallyAddedSkyMap->addSystem(selectedSystem);
                }

                else {
                    cout << "Некорректное значение." << endl << endl;
                }
            }

            else if (addIf == 2) {
                addFlag = false;
                break;
            }

            else {
                cout << "Некорректное значение" << endl << endl;
                break;
            }
        }
    }

    bool infoFlag = true;

    // Цикл выбора выводить инфу или нет
    while (infoFlag) {
        cout << "Вывести информацию о этой карте? \n1 - Да\n2 - Нет \n";
        int choice = autoInt();
        switch (choice)
        {
        case 1: //Выводить
            cout << endl;
            manuallyAddedSkyMap->printAll();
            cout << endl;
            infoFlag = false;
            break;

        case 2: // Не выводить
            infoFlag = false;
            break;

        default:
            cout << "Некорректное значение" << endl << endl;
            break;
        }
    }

    bool saveFlag = true;

    // Цикл выбора сохранять или нет
    while (saveFlag) {
        cout << endl << "Сохранить карту? \n1 - Да\n2 - Нет \n";
        int choice = autoInt();

        switch (choice) {
        case 1:
            maps.push_back(manuallyAddedSkyMap);
            cout << "Система добавлена!" << endl << endl;
            saveFlag = false;

            break;
        case 2:  // Где то тут ошибка 
            cout << "Отмена изменений" << endl << endl;
            saveFlag = false; // Вероятно тут
            break;

        default:
            cout << "Некорректное значение" << endl << endl;
            break;
        }
    }
}

static void rotate(){
    cout << "Введите на сколько градусов повернуть карту" << endl;
    int degrees = autoInt();
    const auto& map = maps[0];

    map->rotateMap(degrees);

    cout << "Обновленные значения:" << endl;
    map->printAll();
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
            changeDeliteBodies();
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

        // Блок тестирования 
        case 10:
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