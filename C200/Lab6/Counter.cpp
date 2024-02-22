#include "Counter.h"
#include <iostream>
#include <cstring>

Counter* Counter::m_pHead = nullptr;
unsigned int Counter::m_curCounters = 0;

Counter::Counter(const char* str) : m_nOwners(1), pNext(nullptr) {
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);
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
    delete[] m_pStr;
    --m_curCounters;
}

void Counter::AddUser() {
    ++m_nOwners;
}

void Counter::RemoveUser() {
    --m_nOwners;
    if (m_nOwners == 0) {
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
    }
}