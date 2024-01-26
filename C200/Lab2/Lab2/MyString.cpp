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
