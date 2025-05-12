#include "MyString.h"
#include <iostream>
#include <locale>
#include <windows.h>

void showMenu() {
    std::cout << "\n����:\n";
    std::cout << "1. ������ ������\n";
    std::cout << "2. �������� ������ � ������\n";
    std::cout << "3. ������� ������� �������\n";
    std::cout << "4. �������� ������������� ������� �� ������ ������\n";
    std::cout << "5. �������� ������� ������\n";
    std::cout << "0. �����\n";
    std::cout << "��� �����: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    MyString str;
    int choice;

    do {
        system("cls");
        std::cout << "������� ������: " << str << "\n";
        showMenu();
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "������� ������: ";
            std::cin >> str;
            break;
        }
        case 2: {
            char ch;
            size_t pos;
            std::cout << "������� ������: ";
            std::cin >> ch;
            std::cout << "������� ������� ��� �������: ";
            std::cin >> pos;
            str += std::make_pair(ch, pos);
            break;
        }
        case 3:
            --str;
            break;
        case 4: {
            std::cout << "������� ������ ������: ";
            MyString second;
            std::cin >> second;
            str = str + second;
            break;
        }
        case 5:
            std::cout << "������� ������: " << str << "\n";
            Sleep(1200);
            break;
        case 0:
            std::cout << "�����...\n";
            break;
        default:
            std::cout << "�������� �����.\n";
            Sleep(1000);
        }
    } while (choice != 0);

    return 0;
}
