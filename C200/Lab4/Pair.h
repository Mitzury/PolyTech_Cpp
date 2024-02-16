#pragma once
#include "MyString.h" 
#include "MyData.h"

class Pair {
private:
    MyString key; // Ключ пары (фамилия сотрудника)
    MyData data; // Данные о сотруднике

public:
    // Конструктор по умолчанию
    Pair();
    // Конструктор с параметрами, инициализирующий ключ и данные
    Pair(const MyString& k, const MyData& d);
    // Метод для получения ключа
    const MyString& getKey() const;
    // Метод для получения данных
    MyData& getData();
    // Перегруженный оператор вывода для класса Pair
    friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
};
