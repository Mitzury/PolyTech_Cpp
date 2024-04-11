#pragma once
#include <iostream>

class MyString {
private:
    char* m_data;
    int m_length;

public:
    MyString() : m_data(nullptr), m_length(0) {} // Дефолтный конструктор

    // Конструктор для строки
    MyString(const char* str) {
        m_length = std::strlen(str);
        m_data = new char[m_length + 1];
        std::strcpy(m_data, str);
    }

    //перегрузка метода присваивания для эффективного выполнения шаблонизированного метода Swap()
    MyString& operator=(const MyString& other) {
        if (this != &other) { // Проверка на самоприсваивание
            m_length = other.m_length;
            m_data = new char[m_length + 1];
            std::strcpy(m_data, other.m_data);
        }
        return *this;
    }

    // Перегрузка оператора << для вывода строки 
    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str.m_data;
        return os;
    }
};