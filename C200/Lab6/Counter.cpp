#include "Counter.h"
#include <string.h>

// Инициализация статических переменных класса Counter.
Counter* Counter::m_pHead = nullptr;
unsigned int Counter::m_curCounters = 0;

// Конструктор Counter. Создает экземпляр Counter для переданной строки данных.
Counter::Counter(const char* str) : m_nOwners(0) {
    // Выделяем память под строку и копируем переданную строку в выделенную память.
    m_pStr = new char[strlen(str) + 1];
    strcpy_s(m_pStr, strlen(str) + 1, str);

    // Проверяем, существует ли уже счетчик для данной строки.
    Counter* existingCounter = Find(str);
    if (existingCounter) {
        // Если счетчик уже существует, используем его данные и увеличиваем счетчик владельцев.
        delete[] m_pStr;
        m_pStr = existingCounter->m_pStr;
        ++(existingCounter->m_nOwners);
        return;
    }

    // Добавляем новый экземпляр Counter в список.
    if (!m_pHead) {
        m_pHead = this;
    }
    else {
        Counter* current = m_pHead;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = this;
    }
    // Увеличиваем общее количество счетчиков.
    ++m_curCounters;
}

// Деструктор Counter. Освобождает ресурсы, связанные с экземпляром Counter.
Counter::~Counter() {
    // Если количество владельцев стало равным нулю, освобождаем ресурсы.
    if (--m_nOwners == 0) {
        delete[] m_pStr;
        // Удаляем экземпляр из списка.
        Counter* current = m_pHead;
        Counter* previous = nullptr;
        while (current != this) {
            previous = current;
            current = current->pNext;
        }
        if (previous) {
            previous->pNext = pNext;
        }
        else {
            m_pHead = pNext;
        }
        // Уменьшаем общее количество счетчиков и освобождаем память, выделенную под экземпляр.
        delete this;
        --m_curCounters;
    }
}

// Увеличивает количество владельцев данного экземпляра Counter.
void Counter::AddUser() {
    ++m_nOwners;
}

// Уменьшает количество владельцев данного экземпляра Counter.
void Counter::RemoveUser() {
    --m_nOwners;
    // Если количество владельцев стало равным нулю, удаляем экземпляр Counter.
    if (m_nOwners == 0) {
        delete this;
    }
}

// Статический метод для поиска экземпляра Counter по строке данных.
Counter* Counter::Find(const char* str) {
    Counter* current = m_pHead;
    while (current != nullptr) {
        if (strcmp(current->m_pStr, str) == 0) {
            return current;
        }
        current = current->pNext;
    }
    return nullptr;
}