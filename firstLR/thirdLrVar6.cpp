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

// Объявление функций заранее, чтоб ничего не ломалось
static void addBody();
static void addSystem();
static void addMap();

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
            catch (invalid_argument) {
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



    // Изменение имени
static void changeName(shared_ptr<CelestialBody> selectedEntity) {
    string input;

    cout << "Введите название: ";
    cin >> input;

    selectedEntity->setName(input);
    cout << "Название успешно изменено" << endl;
}

    // Изменение прямого восхождения
static void changeRA(shared_ptr<CelestialBody> selectedEntity) {
    string input;

    cout << "Введите прямое восхождение: ";
    cin >> input;
    if (isDouble(input)) {
        selectedEntity->setRightAscension(stod(input));
        cout << "Прямое восхождение успешно изменено" << endl;
    }
    else {
        cout << "Некорректное значение" << endl;
    }
}

    // Изменение склонения
static void changeDec(shared_ptr<CelestialBody> selectedEntity) {
    string input;

    cout << "Введите склонение: ";
    cin >> input;

    if (isDouble(input)) {
        try {
            selectedEntity->setDeclination(stod(input));
            cout << "Склонение успешно изменено" << endl;

        }
        catch (const exception&) {
            cout << "Некорректное значение\nИзменения не были применены." << endl;
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

    // Вывод всех экземпляров
template<typename T>
static void printAll(const vector<shared_ptr<T>>& items) {
    int i = 1;
    cout << endl;
    for (const auto& item : items) {
        cout << i << ". " << item->getName() << endl;
        ++i;
    }
}

    // Вывод всех экземпляров с выводом их информации
template<typename T>
static void printAllInDetail(const vector<shared_ptr<T>>& items) {
    int i = 1;

    cout << endl;
    for (const auto& item : items) {
        cout << endl << i << ". " << item->getName() << endl;
        item->printInfo();
        i++;
        cout << endl;
    }

}

    // Меню что показать
static void printShowMenu(string type) {
    cout << endl << "Введите: " << endl;
    if (type == "body") {
        cout << "0. Для подробной информации по каждому телу" << endl;
        cout << "Номер тела. Для подробной информации по этому телу" << endl;
    }
    else if (type == "system") {
        cout << "0. Для подробной информации по каждой системе" << endl;
        cout << "Номер системы. Для подробной информации по этой системе" << endl;
    }
    else if (type == "map") {
        cout << "0. Для подробной информации по каждой карте" << endl;
        cout << "Номер карты. Для подробной информации по этой карте" << endl;
    }
    cout << "-1. Для возвращения в меню" << endl;
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



    // Добавление если не найдено экземпляров
static void additionalAdding(string type) {
    bool mainFlag = true;

    while (mainFlag) {
        if (type == "body") {
            cout << endl << "Не добавлено ни одого тела." << endl;
            cout << "Добавить тело? \nВведите: \n1 - Да \n2 - Нет" << endl;
        }

        else if (type == "system") {
            cout << endl << "Не добавлено ни одной системы." << endl;
            cout << "Добавить систему? \nВведите: \n1 - Да \n2 - Нет" << endl;
        }

        else if (type == "map"){
            cout << endl << "Не добавлено ни одной карты." << endl;
            cout << "Добавить карту? \nВведите: \n1 - Да \n2 - Нет" << endl;
        }

        int emptyIf = autoInt();

        if (emptyIf == 1 && type == "body") {
            cout << endl;
            addBody();
            break;
        }

        else if(emptyIf == 1 && type == "system") {
            cout << endl;
            addSystem();
            break;
        }

        else if (emptyIf == 1 && type == "map") {
            cout << endl;
            addMap();
            break;
        }

        else if (emptyIf == 2) {
            cout << endl;
            mainFlag = false;
            break;
        }
            
        else {
            cout << "Некорректное значение" << endl;
            continue;
        }
        
    }
}

    // Добавление если найдены экзепляры системы
static int addingSaved(shared_ptr<CelestialSystem> selectedSystem) {
    bool addFlag = true;

    while (addFlag) {
        vector<shared_ptr<CelestialBody>> availableBodies;

        for (const auto& body : bodies) {
            if (!selectedSystem->isBodyInSystemByName(body->getName())) {
                availableBodies.push_back(body);
            }
        }

        if (availableBodies.empty()) {
            cout << "Нет тел, доступных для добавления.\n" << endl;
            return 0;
        }

        cout << "Добавить сохраненное тело?\nВведите:\n1 - Да\n2 - Нет" << endl;
        int addIf = autoInt();
        cout << endl;

        if (addIf == 1) {
            printAll(availableBodies);

            cout << endl << "Введите номер тела для добавления" << endl;
            int addIndex = autoInt();
            cout << endl;

            if (addIndex > 0 && static_cast<size_t>(addIndex) <= availableBodies.size()) {
                shared_ptr<CelestialBody> selectedBody = availableBodies[addIndex - 1];
                selectedSystem->addBody(selectedBody);
                cout << "Выбранное тело \"" << selectedBody->getName() << "\" успешно добавлено!" << endl << endl;
            }
            else {
                cout << "Некорректное значение." << endl << endl;
            }
        }

        else if (addIf == 2) {
            return 0;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
            break;
        }
    }
    return 1;
}

    // Перегрузка для карты
static int addingSaved(shared_ptr<SkyMap> selecetedMap) {
    bool addFlag = true;

    while (addFlag) {
        vector<shared_ptr<CelestialSystem>> availableSystems;

        for (const auto& system : systems)
            if (!selecetedMap->isSystemInMapByName(system->getName())) {
                availableSystems.push_back(system);
            }


        if (availableSystems.empty()) {
            cout << "Нет систем, доступных для добавления.\n" << endl;
            return 0;
        }


        cout << "Добавить сохраненную систему? \nВведите: \n1 - Да \n2 - Нет" << endl;
        int addIf = autoInt();
        cout << endl;

        if (addIf == 1) {
            printAll(availableSystems);

            cout << endl << "Введите номер системы для добавления" << endl;
            int addIndex = autoInt();
            cout << endl;

            if (static_cast<size_t>(addIndex) <= availableSystems.size() && addIndex > 0) {
                shared_ptr<CelestialSystem> selectedSystem = availableSystems[addIndex - 1];
                selecetedMap->addSystem(selectedSystem);
                cout << "Выбранная система \"" << selectedSystem->getName() << "\" успешно добавлено!" << endl << endl;

            }
            else {
                cout << "Некорректное значение." << endl << endl;
            }
        }

        else if (addIf == 2) {
            return 0;
        }

        else {
            cout << "Некорректное значение." << endl << endl;
        }
    }
    return 1;
}

static void autoAddingMap(){
    // Если нет карт, добавить или выйти
    if (maps.size() == 0) {
        additionalAdding("map");
        if (maps.size() <= 0) {
            return;
        }

    }
    // Для выбора карты 
    if (maps.size() > 0) {
        cout << endl << "Сохраненные карты:" << endl;
        printAll(maps);
    }

    cout << endl << "Введите номер карты (0 для выхода в меню). ";
}

    // Перегрузка для тел
static void deletingCelestials(shared_ptr<CelestialBody> selectedEntity, int choice) {
    cout << "Удалить тело? (это навсегда)\n1 - Да\n2 - Нет" << endl;
    bool deleteFlag = true;

    while (deleteFlag) {
    int confirm = autoInt();

        if (confirm == 1) {
            // Удаление из всех систем
            for (auto& system : systems) {
                system->removeBody(selectedEntity);
            }

            // Удаление из глобального списка тел
            bodies.erase(bodies.begin() + (choice - 1));
            cout << "Тело удалено.\n" << endl;
            deleteFlag = false;
        }
        else if (confirm == 2) {
            break;
        }
        else {
            cout << "Некорректное значение" << endl << endl;
            continue;

        }
    }
} 

    // Перегрузка для систем
static void deletingCelestials(shared_ptr<CelestialSystem> selectedEntity, int choice) {
    cout << "Удалить систему? (это навсегда)\n1 - Да\n2 - Нет" << endl;
    bool deleteFlag = true;

    while (deleteFlag) {

        int confirm = autoInt();
        if (confirm == 1) {
            // Удаление из всех карт
            for (auto& map : maps) {
                map->removeSystemByPointer(selectedEntity);
            }

            // Удаление из глобального списка систем
            systems.erase(systems.begin() + (choice - 1));
            cout << "Система удалена.\n" << endl;
            deleteFlag = false;
            break;
        }

        if (confirm == 2) {
            break;
        }

        else {
            cout << "Некорректное значение" << endl << endl;
            continue;
        }
    }
}




    // Работа с выбраным телом
static int changeParamsDeleteBody(int choice) {
    bool mainFlag = true;
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
            changeName(selectedBody);   // Имя
            break;

        case 2:
            changeRA(selectedBody);     // Прямое восхожденине
            break;

        case 3:
            changeDec(selectedBody);    // Склонение
            break;

            // Нет смысла выносить функцию
        case 4: {
            cout << "Введите видимую звездную величину: ";
            cin >> input;
            if (isDouble(input)) {
                try {
                    selectedBody->setMagnitude(stod(input));
                    cout << "Видимая звездная величина успешно изменена" << endl;

                }
                catch (exception) {
                    cout << "Некорректное значение\nИзменения не были применены." << endl;

                }
            }
            else {
                cout << "Некорректное значение." << endl;
            }
            break;
        }

              // Также нет смысла выносить
        case 5:
            deletingCelestials(selectedBody, choice);
            mainFlag = false;
            break;

        case 0:
            mainFlag = false;
            break;

        case -1:
            return 0; // Выбор тела

        default:
            cout << "Некорректное значение" << endl;
            break;
        }
    }
    return 1;
}

static int changeParamsDeleteSystem(int choice) {
    bool mainFlag = true;
    shared_ptr<CelestialSystem> selectedSystem = systems[choice - 1];
    const auto& bodiesInSystem = selectedSystem->getMembers();

    while (mainFlag) {
        bool secondFlag = true;
        cout << "\nВыбраная система: " << selectedSystem->getName() << endl;
        cout << "Введите: " << endl;
        cout << "1. Изменить название" << endl; // одинаково
        cout << "2. Изменить прямое восхождение" << endl;   // одинаково
        cout << "3. Изменить склонение" << endl;    // одинаково
        cout << "4. Удалить систему" << endl;
        cout << "5. Удалить тело из системы" << endl;
        cout << "6. Добавить тело" << endl;
        cout << "0. Выбор системы" << endl;
        cout << "-1. Выход в меню" << endl;

        int forSwitch = autoInt();
        cout << endl;
        string input;

        switch (forSwitch) {
        case 1:
            changeName(selectedSystem);     // Имя
            break;

        case 2:
            changeRA(selectedSystem);       // Прямое восхождение
            break;

        case 3:
            changeDec(selectedSystem);      // Склонение
            break;

        case 4: 
            deletingCelestials(selectedSystem, choice);
            mainFlag = false;
            break;

        case 5:
            if (bodiesInSystem.size() == 0) {
                cout << "В системе нет тел" << endl;
                break;
            }

            while (secondFlag) {
                cout << "Сохраненные тела:" << endl;
                printAll(bodiesInSystem);
                cout << "Введите номер тела (0 - отмена) . ";

                int deleter = autoInt() - 1;
                if (static_cast<size_t>(deleter) <= bodiesInSystem.size() - 1) {
                    cout << "Выбранное тело: " << bodiesInSystem[deleter]->getName() << " удалено" << endl;
                    selectedSystem->removeBody(bodiesInSystem[deleter]);
                    break;
                }

                else if (deleter == -1) {
                    secondFlag = false;
                    break;
                }

                else {
                    cout << "Некорректное значение " << endl;
                }
            }
            break;

        case 6:
            secondFlag = true;

            while (secondFlag) {
                if (bodies.size() == 0) {
                    additionalAdding("body");
                    if (bodies.size() <= 0) {
                        break;
                    }
                    selectedSystem->addBody(bodies.back());
                    break;
                }

                else {
                    int output = addingSaved(selectedSystem);

                    if (output == 0) {
                        break;
                    }

                }
            }
            break;

        case -1:
            return 0;

        case 0:
            secondFlag = false;
            break;

        default:
            cout << "Некорректное значение" << endl;
            break;
        }
    }
    return 1;
}




// Основные функции:
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

    // Просмотр всех тел
static void showBodies() {
    bool mainFlag = true;

    while (mainFlag) {

        if (bodies.size() == 0) {
            additionalAdding("body");
            if (bodies.size() <= 0) {
                break;
            }
        }

        cout << endl << "Сохраненные тела:" << endl;
        printAll(bodies);

        printShowMenu("body");
        int choice = autoInt() - 1;

        if (choice == -2) {
            mainFlag = false;
        }

        else if (choice == -1) {
            printAllInDetail(bodies);
        }

        else if (static_cast<size_t>(choice) <= bodies.size() - 1) {
            bodies[choice]->printInfo();
            cout << endl;
        }

        else {
            cout << endl << "Некорректное значение" << endl;
            
        }
    }
}

//  Изменеие/удаление тел
static void changeDeliteBodies() {
    bool mainFlag = true;

    while (mainFlag) {

        // Если нет тел, добавить или выйти
        if (bodies.size() == 0) {
            additionalAdding("body");
            
            if (bodies.size() <= 0) {
                break;
            }
        }

        // Варианты выбора
        cout << endl << "Список тел:" << endl;
        printAll(bodies);

        cout << endl << "Введите номер тела (0 для выхода в меню). ";
        int choice = autoInt();

        // Выход
        if (choice == 0) {
            mainFlag = false;
        }

        else if (choice > 0 && static_cast<size_t>(choice) <= bodies.size()) {
            int output = changeParamsDeleteBody(choice);
            if (output == 0) {
                mainFlag = false;
                break;
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
            additionalAdding("body");
            if (bodies.size() <= 0) {
                break;
            }
            manuallyAddedCelestialSystem->addBody(bodies.back());
            break;
        }

        else {
            int output = addingSaved(manuallyAddedCelestialSystem);
            if (output == 0) {
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
            additionalAdding("system");
            continue;
        }
        
        if (systems.size() > 0) {
            cout << endl << "Сохраненные системы:" << endl;
            printAll(systems);

            printShowMenu("system");
            int choice = autoInt() - 1;

            if (choice == -2) {
                mainFlag = false;
            }

            else if (choice == -1) {
                cout << endl;
                printAllInDetail(systems);
                continue;
            }

            else if (static_cast<size_t>(choice) <= systems.size() - 1) {
                systems[choice]->printInfo();
                cout << endl;
                continue;
            }

            else {
                cout << "Некорректное значение" << endl;
            }
        }
        else { break; }
    }
}

    // Изменение/удаление систем
static void changeDeliteSystems() {
    bool mainFlag = true;

    while (mainFlag) {

        // Если нет систем, добавить или выйти
        if (systems.size() == 0) {
            additionalAdding("system");

            if (systems.size() > 0) {
                continue;
            }
            else {
                break;
            }
        }

        if (systems.size() > 0) {
            cout << endl << "Сохраненные системы:" << endl;
            printAll(systems);
        }

        cout << endl << "Введите номер системы (0 для выхода в меню). ";
        int choice = autoInt();

        // Работа с выбраным телом
        if (choice == 0) {
            return;
        }

        else if (static_cast<size_t>(choice) <= systems.size()) {
            int output = changeParamsDeleteSystem(choice);
            if (output == 0) {
                mainFlag = false;
                break;
            }
        }

        else {
            cout << "Некоррректное значение" << endl;
        }
    }
}




    // Создание карты
static void addMap() {
    string input;
    auto manuallyAddedSkyMap = std::make_shared<SkyMap>();

    cout << "Создание карты:" << endl << endl;

    cout << "Введите название карты: ";
    cin >> input;
    manuallyAddedSkyMap->setName(input);


    // Добавление тел в систему
    bool addFlag = true;
    while (addFlag) {
        if (systems.size() == 0) {
            additionalAdding("system");
            if (systems.size() <= 0) {
                break;
            }
            manuallyAddedSkyMap->addSystem(systems.back());
            break;

        }

        else {

            int output = addingSaved(manuallyAddedSkyMap);

            if (output == 0) {
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
            cout << endl << endl;
            manuallyAddedSkyMap->printInfo();
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

    // Отображение всех карт
static void showMaps() {
    bool mainFlag = true;

    while (mainFlag) {

        if (maps.size() == 0) {
            additionalAdding("map");
            continue;
        }

        if (maps.size() > 0) {
            cout << endl << "Сохраненные карты:" << endl;
            printAll(maps);

            printShowMenu("map");
            int choice = autoInt() - 1;

            if (choice == -2) {
                mainFlag = false;
            }

            else if (choice == -1) {
                cout << endl;
                printAllInDetail(maps);
                continue;
            }

            else if (static_cast<size_t>(choice) <= maps.size() - 1) {
                maps[choice]->printInfo();
                cout << endl;
                continue;
            }

            else {
                cout << "Некорректное значение" << endl;
            }
        }
        else { break; }
    }

}

    // Добавление системы на карту
static void addSystemsToMap() {
    bool mainFlag = true;

    autoAddingMap();

    while (mainFlag) {
        bool secondFlag = true;
        int choice = autoInt();

        if (choice == 0) {
            return;
        }

        else if (static_cast<size_t>(choice) <= maps.size()) {
            shared_ptr<SkyMap> selectedMap = maps[choice - 1];

            while (secondFlag) {
                if (systems.size() == 0) {
                    additionalAdding("system");
                    if (systems.size() <= 0) {
                        break;
                    }
                    selectedMap->addSystem(systems.back());
                    break;
                }
                else {
                    int output = addingSaved(selectedMap);

                    if (output == 0) {
                        break;
                    }
                }
            }
        }
    }
}

    // Поворот карты
static void rotate() {
    autoAddingMap();
    if (maps.size() == 0) {
        return;
    }

    bool mainFlag = true; 

    while (mainFlag) {

        int choice = autoInt();

        if (choice == 0) {
            return;
        }

        else if (static_cast<size_t>(choice) <= maps.size()) {
            shared_ptr<SkyMap> selectedMap = maps[choice - 1];
            auto copiedMap = selectedMap->deepCopy();
            maps.push_back(copiedMap);

            cout << "Введите на сколько градусов повернуть карту" << endl;
            int degrees = autoInt();

            copiedMap->rotateMap(degrees);

            cout << "Обновленные значения:" << endl;
            copiedMap->printInfo();
        }
    }
}

    // Фильтрация по яркости
static void filtMap() {
    autoAddingMap();
    if (maps.size() == 0) {
        return;
    }
    bool mainFlag = true;

    while (mainFlag) {

        int choice = autoInt();

        if (choice == 0) {
            return;
        }

        else if (static_cast<size_t>(choice) <= maps.size()) {
            shared_ptr<SkyMap> selectedMap = maps[choice - 1];

            cout << "Введите значение яркости." << endl;
            double filtring = autoDouble();
            auto copiedMap = selectedMap->filterByMagnitude(filtring);
            maps.push_back(copiedMap);
            copiedMap->printInfo();
            cout << endl;
            break;
        }
    }
}



// Так называемый мэйн
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
        cout << "8. Посмотреть все карты" << endl;
        cout << "9. Добавить систему на карту" << endl;
        cout << "10. Повернуть карту" << endl;
        cout << "11. Отфильтровать по яркости" << endl;
        cout << "12. Тестирование " << endl;
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
            showMaps();
            break;
        case 9:
            cout << endl;
            addSystemsToMap();
            break;
        case 10:
            cout << endl;
            rotate();
            break;
        case 11:
            cout << endl;
            filtMap();
            break;

        // Блок тестирования 
        case 12:
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
        // Назад
        case 0:
            return 0;
        // Выход
        case -1:
            return 1;
        }
    }
}