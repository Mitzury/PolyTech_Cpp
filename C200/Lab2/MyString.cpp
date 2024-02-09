#include <string>
#include "myString.h"
#include <iostream>
using namespace std;

// Конструктор (MyString::MyString(const char* str)): Выделяет динамическую память для хранения строки str и копирует ее в эту память.
MyString::MyString(const char* str) {
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
    std::cout << "Constructor called" << std::endl;
}
// Копирующий конструктор: MyString(const MyString& other) - создает копию строки из другого объекта MyString, 
// также выделяя новую динамическую память.
MyString::MyString(const MyString& other) {
    m_str = new char[strlen(other.m_str) + 1];
    strcpy(m_str, other.m_str);
    std::cout << "Copy constructor called" << std::endl;
}
// Деструктор (MyString::~MyString()): Освобождает выделенную динамическую память при уничтожении объекта.
MyString::~MyString() {
    delete[] m_str;
    std::cout << "Destructor called" << std::endl;
}
// Метод GetString() const: возвращает указатель на строку.
const char* MyString::GetString() const {
    return m_str;
}
// Метод SetNewString(const char* newStr): изменяет содержимое строки, освобождает старую динамическую память и выделяет новую для новой строки.
void MyString::SetNewString(const char* newStr) {
    delete[] m_str;
    m_str = new char[strlen(newStr) + 1];
    strcpy(m_str, newStr);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] m_str;

        if (other.m_str != nullptr) {
            m_str = new char[std::strlen(other.m_str) + 1];
            std::strcpy(m_str, other.m_str);
        }
        else {
            m_str = nullptr;
        }
    }

    return *this;
}

MyString& MyString::operator+(const MyString& other) const {
    char* resultStr = new char[std::strlen(m_str) + std::strlen(other.m_str) + 1];
    std::strcpy(resultStr, m_str);
    std::strcat(resultStr, other.m_str);

    MyString result(resultStr);
    delete[] resultStr;

    return result;
}

