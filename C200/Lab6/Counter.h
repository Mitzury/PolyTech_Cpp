#pragma once
#include <cstring>

class Counter {
private:
    char* m_pStr;
    int m_nOwners;
    Counter* pNext;
    int* m_pRefCount;

    static Counter* m_pHead;
    static unsigned int m_curCounters;


public:
    Counter(const char* str);
    ~Counter();
    void AddUser();
    void RemoveUser();

    static Counter* Find(const char* str);
    static Counter* GetHead() { return m_pHead; }
    Counter* GetNext() const { return pNext; }
    static unsigned int GetCurCounters() { return m_curCounters; }
    char* GetString() const { return m_pStr; }
    int GetOwners() const { return m_nOwners; }
    void IncrementOwners() { ++m_nOwners; }
    void DecrementOwners() { --m_nOwners; }
};
