#pragma once

#include "Pair.h"
class CppDb {
private:
    Pair* pBase; // Указатель на массив пар (сотрудников)
    size_t count; // Количество элементов в базе
    size_t capacity; // Емкость базы
public:
    // Конструктор по умолчанию
    CppDb();
    // Деструктор
    ~CppDb();
    // Конструктор копирования
    CppDb(const CppDb& other);
    // Оператор присваивания
    CppDb& operator=(const CppDb& other);
    // Конструктор перемещения
    CppDb(CppDb&& other);
    // Оператор перемещения
    CppDb& operator=(CppDb&& other);
    // Оператор индексирования для доступа к данным сотрудника по ключу
    MyData& operator[](const char* key);
    // Метод удаления пары сотрудника из базы по ключу
    int deletePair(const char* key);
    // Метод для сортировки базы данных
    void sort();
    void clear();
    // Перегруженный оператор вывода для класса Base
    friend std::ostream& operator<<(std::ostream& os, const CppDb& bd);
};