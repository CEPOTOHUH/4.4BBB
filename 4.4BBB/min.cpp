#include "MyString.h"
#include <iostream>
#include <locale>
#include <windows.h> 

void clearInputBuffer() {
    char c;
    while (std::cin.get(c) && c != '\n');
}

void showMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Ввести строку\n";
    std::cout << "2. Вставить символ в строку\n";
    std::cout << "3. Удалить ведущие пробелы\n";
    std::cout << "4. Добавить вторую строку к текущей\n";
    std::cout << "5. Показать текущую строку\n";
    std::cout << "0. Выход\n";
    std::cout << "Ваш выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    MyString str;
    MyString second;

    int choice;

    do {
        std::cout << "Текущая строка: \"" << str << "\"\n";
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Некорректный ввод. Пожалуйста, введите число.\n";
            std::cin.clear();
            clearInputBuffer();
            Sleep(1000);
            continue;
        }
        clearInputBuffer();

        switch (choice) {
        case 1: {
            char buffer[8192]; 
            std::cout << "Введите строку: ";
            std::cin.getline(buffer, sizeof(buffer));
            str = MyString(buffer); 
            std::cout << "Строка успешно введена.\n";
            break;
        }
        case 2: {
            char ch;
            size_t pos;
            std::cout << "Введите символ для вставки (один символ): ";
            ch = std::cin.get();
            clearInputBuffer();

            bool validInput = false;
            do {
                std::cout << "Введите позицию для вставки (0 или больше): ";
                std::cin >> pos;
                if (std::cin.fail()) {
                    std::cout << "Некорректный ввод. Введите целое неотрицательное число.\n";
                    std::cin.clear();
                    clearInputBuffer();
                }
                else {
                    validInput = true;
                }
            } while (!validInput);
            clearInputBuffer();

            str += std::make_pair(ch, pos); 
            std::cout << "Символ '" << ch << "' вставлен на позицию " << pos << ".\n";
            break;
        }
        case 3:
            --str;
            std::cout << "Ведущие пробелы удалены.\n";
            break;
        case 4: {
            char buffer[8192];
            std::cout << "Введите вторую строку для добавления: ";
            std::cin.getline(buffer, sizeof(buffer));
            second = MyString(buffer); 
            str = str + second;
            std::cout << "Вторая строка добавлена.\n";
            break;
        }
        case 5:
            break;
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            Sleep(1000);
        }
        if (choice != 0 && choice != 5) {
            Sleep(1000);
        }
    } while (choice != 0);

    return 0;
}
