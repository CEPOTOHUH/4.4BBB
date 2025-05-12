#include "MyString.h"
#include <iostream>
#include <locale>
#include <windows.h>

void showMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Ввести строку\n";
    std::cout << "2. Вставить символ в строку\n";
    std::cout << "3. Удалить ведущие пробелы\n";
    std::cout << "4. Добавить отсутствующие символы из второй строки\n";
    std::cout << "5. Показать текущую строку\n";
    std::cout << "0. Выход\n";
    std::cout << "Ваш выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    MyString str;
    int choice;

    do {
        system("cls");
        std::cout << "Текущая строка: " << str << "\n";
        showMenu();
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Введите строку: ";
            std::cin >> str;
            break;
        }
        case 2: {
            char ch;
            size_t pos;
            std::cout << "Введите символ: ";
            std::cin >> ch;
            std::cout << "Введите позицию для вставки: ";
            std::cin >> pos;
            str += std::make_pair(ch, pos);
            break;
        }
        case 3:
            --str;
            break;
        case 4: {
            std::cout << "Введите вторую строку: ";
            MyString second;
            std::cin >> second;
            str = str + second;
            break;
        }
        case 5:
            std::cout << "Текущая строка: " << str << "\n";
            Sleep(1200);
            break;
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор.\n";
            Sleep(1000);
        }
    } while (choice != 0);

    return 0;
}
