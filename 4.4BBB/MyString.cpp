#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <cstring>
#include <utility>

bool MyString::isSpace(char c) const {
    return (c == ' ');
}

void MyString::copyFrom(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
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
    if (!str) {
        data = new char[1] {'\0'};
        length = 0;
        return;
    }
    length = std::strlen(str);
    data = new char[length + 1];
    std::strcpy(data, str);
}

MyString::MyString(const MyString& other) {
    copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept {
    moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        free();
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

    const size_t MAX_ALLOWED_OFFSET = 1024;
    if (pos > length + MAX_ALLOWED_OFFSET) {
        pos = length + MAX_ALLOWED_OFFSET;
    }

    size_t newLength = (pos >= length) ? pos + 1 : length + 1;

    if (newLength < pos) { 
        newLength = pos; 
    }

    char* newData = new char[newLength + 1];

    for (size_t i = 0; i < pos; ++i) {
        if (i < length) {
            newData[i] = data[i];
        }
        else {
            newData[i] = ' ';
        }
    }

    newData[pos] = c;

    if (pos < length) {
        for (size_t i = pos; i < length; ++i) {
            newData[i + 1] = data[i];
        }
    }

    newData[newLength] = '\0';

    free();
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
        free();
        data = newData;
        length = newLength;
    }
    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    size_t resultLength;
    if (this->length > other.length) {
        resultLength = this->length;
    }
    else {
        resultLength = other.length;
    }

    char* newStrData = new char[resultLength + 1];
    for (size_t i = 0; i < this->length; ++i) {
        newStrData[i] = this->data[i];
    }
    for (size_t i = this->length; i < resultLength; ++i) {
        newStrData[i] = '\0'; 
    }
    for (size_t i = 0; i < other.length; ++i) {
        newStrData[i] = other.data[i];
    }

    newStrData[resultLength] = '\0'; 

    MyString result(newStrData);
    delete[] newStrData;

    return result;
}

std::ostream& operator<<(std::ostream& out, const MyString& str) {
    if (str.data) {
        out << str.data;
    }
    else {
        out << "";
    }
    return out;
}

std::istream& operator>>(std::istream& in, MyString& str) {
    char buffer[8192];
    in.getline(buffer, sizeof(buffer));
    str = MyString(buffer);
    return in;
}
    return in;
}
