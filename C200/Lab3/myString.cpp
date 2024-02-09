#include "myString.h"
#include <cstring>
#include <iostream>

MyString::MyString() : m_str(nullptr) {
    std::cout << "Default constructor called" << std::endl;
}

MyString::MyString(const char* str) {
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
    std::cout << "Constructor called" << std::endl;
}

MyString::MyString(const MyString& other) {
    m_str = new char[strlen(other.m_str) + 1];
    strcpy(m_str, other.m_str);
    std::cout << "Copy constructor called" << std::endl;
}

MyString::~MyString() {
    delete[] m_str;
    std::cout << "Destructor called" << std::endl;
}

const char* MyString::GetString() const {
    return m_str;
}

void MyString::SetNewString(const char* newStr) {
    delete[] m_str;
    m_str = new char[strlen(newStr) + 1];
    strcpy(m_str, newStr);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] m_str;

        m_str = new char[strlen(other.m_str) + 1];
        strcpy(m_str, other.m_str);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& myString) {
    os << "contents: \"" << myString.m_str << "\"";
    return os;
}

MyString MyString::operator+(const MyString& other) const {
    MyString result;
    result.m_str = new char[strlen(m_str) + strlen(other.m_str) + 1];
    strcpy(result.m_str, m_str);
    strcat(result.m_str, other.m_str);
    return result;
}

MyString& MyString::operator+=(const MyString& other) {
    char* newStr = new char[strlen(m_str) + strlen(other.m_str) + 1];
    strcpy(newStr, m_str);
    strcat(newStr, other.m_str);

    delete[] m_str;
    m_str = newStr;

    return *this;
}

MyString& MyString::operator++() {
    for (size_t i = 0; i < strlen(m_str); ++i) {
        if (islower(m_str[i])) {
            m_str[i] = toupper(m_str[i]);
        }
    }
    return *this;
}

MyString MyString::operator--(int) {
    MyString temp(*this);
    for (size_t i = 0; i < strlen(m_str); ++i) {
        if (isupper(m_str[i])) {
            m_str[i] = tolower(m_str[i]);
        }
    }
    return temp;
}