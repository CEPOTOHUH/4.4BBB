#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <cstring>

bool MyString::isSpace(char c) const {
    return (c == ' ');
}

void MyString::copyFrom(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    for (size_t i = 0; i <= length; ++i)
        data[i] = other.data[i];
}

void MyString::moveFrom(MyString&& other) {
    data = other.data;
    length = other.length;
    other.data = nullptr;
    other.length = 0;
}

void MyString::free() {
    delete[] data;
    data = nullptr;
    length = 0;
}

MyString::MyString() : data(new char[1] {'\0'}), length(0) {}

MyString::MyString(const char* str) {
    length = std::strlen(str);
    data = new char[length + 1];
    std::strcpy(data, str);
}

MyString::MyString(const MyString& other) {
    copyFrom(other);
}

MyString::MyString(MyString&& other) {
    moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) {
    if (this != &other) {
        //free();
        moveFrom(std::move(other));
    }
    return *this;
}

MyString::~MyString() {
    free();
}

MyString& MyString::operator+=(std::pair<char, size_t> p) {
    char c = p.first;
    size_t pos = p.second;

    size_t newLength = (pos > length) ? pos + 1 : length + 1;
    char* newData = new char[newLength + 1];

    for (size_t i = 0; i < pos; ++i) {
        if (i < length)
            newData[i] = data[i];
        else
            newData[i] = ' ';
    }

    newData[pos] = c;

    for (size_t i = pos; i < length; ++i)
        newData[i + 1] = data[i];

    newData[newLength] = '\0';

    delete[] data;
    data = newData;
    length = newLength;

    return *this;
}

MyString& MyString::operator--() {
    size_t index = 0;
    while (index < length && isSpace(data[index]))
        index++;
    if (index > 0) {
        size_t newLength = length - index;
        char* newData = new char[newLength + 1];
        for (size_t i = 0; i < newLength; ++i)
            newData[i] = data[i + index];
        newData[newLength] = '\0';
        delete[] data;
        data = newData;
        length = newLength;
    }
    return *this;
}

MyString MyString::operator+(const MyString& other) const {

    int sizemax = this->length > other.length ? this->length : other.length;
    int sizemin = this->length < other.length ? this->length : other.length;
    char* newstr = new char[sizemax];

    for (int i = 0;i < sizemin;i++) {
        newstr[i] = other.data[i];
    }

    for (int i = sizemin;i < sizemax;i++)
        newstr[i] = data[i];
  
    newstr[sizemax] = '\0';

    MyString newmy(newstr);

    return newmy;
}


std::ostream& operator<<(std::ostream& out, const MyString& str) {
    out << str.data;
    return out;
}

std::istream& operator>>(std::istream& in, MyString& str) {
    char buffer[1024];
    in.ignore(10000, '\n');
    in.getline(buffer, 1024);
    str = MyString(buffer);
    return in;
}
