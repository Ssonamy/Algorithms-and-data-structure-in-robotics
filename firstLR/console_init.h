#pragma once

#define NOMINMAX
#include <windows.h>
#include <clocale>
#include <iostream>

inline void initConsole() {
    // Установка кодировки ввода/вывода (UTF-8)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Установка локали для корректного отображения языка
    setlocale(LC_ALL, "ru_RU.utf8");
}
