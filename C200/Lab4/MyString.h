#pragma once
#include <iostream>

class MyString {
private:
    char* m_str; // Указатель на массив символов 

public:
    MyString(const char* s = ""); // Конструктор, принимающий C-style строку (по умолчанию пустая строка)
    MyString(const MyString& other); // Конструктор копирования
    ~MyString(); // Деструктор
    MyString& operator=(const MyString& other); // Оператор присваивания
    bool operator==(const char* s) const; // Оператор сравнения с C-style строкой
    bool operator>(const MyString& other) const; // Оператор "больше" для строк
    bool operator<(const MyString& other) const; // Оператор "меньше" для строк
    bool operator==(const MyString& other) const; // Оператор сравнения строк
    friend std::ostream& operator<<(std::ostream& os, const MyString& str); // Перегруженный оператор вывода
};