#include <string>
#include "myString.h"
#include <iostream>
using namespace std;



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