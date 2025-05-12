#pragma once
#include <iostream>

class MyString {
private:
    char* data;
    size_t length;

    bool isSpace(char c) const;
    void copyFrom(const MyString& other);
    void moveFrom(MyString&& other);
    void free();

public:
    MyString();                              // Конструктор по умолчанию
    MyString(const char* str);              // Конструктор с параметром
    MyString(const MyString& other);        // Копирующий конструктор
    MyString(MyString&& other);             // Перемещающий конструктор
    MyString& operator=(const MyString& other); // Оператор копирующего присваивания
    MyString& operator=(MyString&& other);      // Оператор перемещающего присваивания
    ~MyString();                            // Деструктор

    MyString& operator+=(std::pair<char, size_t> p);  // Вставка символа
    MyString& operator--();                          // Удаление ведущих пробелов
    MyString operator+(const MyString& other) const;  // Сложение строк

    friend std::ostream& operator<<(std::ostream& out, const MyString& str);
    friend std::istream& operator>>(std::istream& in, MyString& str);
};

