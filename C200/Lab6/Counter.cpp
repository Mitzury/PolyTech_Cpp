#include "Counter.h"
#include <string.h>

Counter* Counter::m_pHead = nullptr;
unsigned int Counter::m_curCounters = 0;

Counter::Counter(const char* str) : m_nOwners(0) {
    m_pStr = new char[strlen(str) + 1];
    strcpy_s(m_pStr, strlen(str) + 1, str);



    Counter* existingCounter = Find(str);
    if (existingCounter) {
        delete[] m_pStr;
        m_pStr = existingCounter->m_pStr;
        ++(existingCounter->m_nOwners);
        return;
    }


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
    ++m_curCounters;
}

Counter::~Counter() {
    if (--m_nOwners == 0) {
        delete[] m_pStr;

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
        delete this;
        --m_curCounters;
    }
}

void Counter::AddUser() {
    ++m_nOwners;
}

void Counter::RemoveUser() {
    --m_nOwners;
    if (m_nOwners == 0) {
        delete this;
    }
}

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