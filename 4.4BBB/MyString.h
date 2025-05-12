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
    MyString();                              // ����������� �� ���������
    MyString(const char* str);              // ����������� � ����������
    MyString(const MyString& other);        // ���������� �����������
    MyString(MyString&& other);             // ������������ �����������
    MyString& operator=(const MyString& other); // �������� ����������� ������������
    MyString& operator=(MyString&& other);      // �������� ������������� ������������
    ~MyString();                            // ����������

    MyString& operator+=(std::pair<char, size_t> p);  // ������� �������
    MyString& operator--();                          // �������� ������� ��������
    MyString operator+(const MyString& other) const;  // �������� �����

    friend std::ostream& operator<<(std::ostream& out, const MyString& str);
    friend std::istream& operator>>(std::istream& in, MyString& str);
};

