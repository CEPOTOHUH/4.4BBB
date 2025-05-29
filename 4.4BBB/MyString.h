#pragma once
#include <iostream>
#include <utility>

class MyString {
private:
    char* data;
    size_t length;

    bool isSpace(char c) const;
    void copyFrom(const MyString& other);
    void moveFrom(MyString&& other);
    void free();

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    ~MyString();

    MyString& operator+=(std::pair<char, size_t> p);
    MyString& operator--();
    MyString operator+(const MyString& other) const;

    friend std::ostream& operator<<(std::ostream& out, const MyString& str);
    friend std::istream& operator>>(std::istream& in, MyString& str);
};
