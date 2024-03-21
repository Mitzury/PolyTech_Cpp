#pragma once
#include <cstring>

class Counter {
private:
// Указатель на выделенную строку
    char* m_pStr;
// Количество владельцев данного экземпляра класса
    int m_nOwners;
    Counter* pNext;
    int* m_pRefCount;
    static Counter* m_pHead;
    static unsigned int m_curCounters;

public:
// Конструктор класса, принимающий строку в качестве аргумента
    Counter(const char* str);
// Деструктор класса
    ~Counter();
// Методы класса
// Увеличение счетчика владельцев
    void AddUser();
// Уменьшение счетчика владельцев
    void RemoveUser();

// Статический метод для поиска экземпляра класса counter по строке
    static Counter* Find(const char* str);
// Статический метод для получения указателя на первый экземпляр класса counter
    static Counter* GetHead() { return m_pHead; }
// Метод для получения указателя на следующий экземпляр класса counter
    Counter* GetNext() const { return pNext; }
// Статический метод для получения текущего количества экземпляров класса
    static unsigned int GetCurCounters() { return m_curCounters; }
// Метод для получения строки данного экземпляра класса
    char* GetString() const { return m_pStr; }
// Метод для получения количества владельцев данного экземпляра класса
    int GetOwners() const { return m_nOwners; }
// Метод для увеличения счетчика владельцев на единицу
    void IncrementOwners() { ++m_nOwners; }
// Метод для уменьшения счетчика владельцев на единицу
    void DecrementOwners() { --m_nOwners; }
};
