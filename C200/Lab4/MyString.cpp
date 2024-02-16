#include "MyString.h"
#include <cstring>

// Конструктор, принимающий C-style строку
MyString::MyString(const char* s) {
    // Выделяем память под новую строку и копируем содержимое из переданной строки
    m_str = new char[strlen(s) + 1]; // Выделяем достаточно памяти для хранения строки и символа завершения '\0'
    strcpy(m_str, s); // Копируем содержимое строки s в выделенную память
}

// Конструктор копирования
MyString::MyString(const MyString& other) {
    // Выделяем память под новую строку и копируем содержимое из строки other
    m_str = new char[strlen(other.m_str) + 1];
    strcpy(m_str, other.m_str);
}

// Деструктор
MyString::~MyString() {
    delete[] m_str; // Освобождаем выделенную память при удалении объекта
}

// Оператор присваивания
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) { // Проверяем, что объекты не совпадают
        delete[] m_str; // Освобождаем старую память
        m_str = new char[strlen(other.m_str) + 1]; // Выделяем новую память
        strcpy(m_str, other.m_str); // Копируем содержимое из другой строки
    }
    return *this; // Возвращаем ссылку на текущий объект
}

// Оператор сравнения с C-style строкой
bool MyString::operator==(const char* s) const {
    return strcmp(m_str, s) == 0; // Сравниваем содержимое строки с переданной C-style строкой
}

// Оператор "больше" для строк
bool MyString::operator>(const MyString& other) const {
    return strcmp(m_str, other.m_str) > 0; // Сравниваем содержимое текущей строки с переданной строкой
}

// Оператор "меньше" для строк
bool MyString::operator<(const MyString& other) const {
    return strcmp(m_str, other.m_str) < 0; // Сравниваем содержимое текущей строки с переданной строкой
}

// Оператор сравнения строк
bool MyString::operator==(const MyString& other) const {
    return strcmp(m_str, other.m_str) == 0; // Сравниваем содержимое текущей строки с переданной строкой
}

// Перегруженный оператор вывода
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.m_str; // Выводим содержимое строки в поток вывода
    return os; // Возвращаем ссылку на поток вывода
}