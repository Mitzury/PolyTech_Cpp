#pragma once
#include "MyString.h"

class MyData {
public:
    // Перечисление для пола
    enum Sex { UNDEF, MALE, FEMALE };
private:
    Sex sex; // Пол сотрудника
    size_t age; // Возраст сотрудника
    MyString job; // Должность сотрудника
    float salary; // Зарплата сотрудника
public:
    // Конструктор, инициализирующий объект класса MyData
    MyData(Sex s, size_t a, const char* j, float sal);

    // Перегруженный оператор вывода для класса MyData
    friend std::ostream& operator<<(std::ostream& os, const MyData& data);
};
