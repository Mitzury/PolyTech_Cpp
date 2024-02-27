#include "myString.h"
#include "Counter.h"
#include <cstring>
#include <algorithm>

MyString::MyString() : m_str(nullptr) {}

MyString::MyString(const char* str) {
    size_t len = strlen(str) + 1;
    m_str = new char[len];
    strcpy_s(m_str, len, str);
    Counter* counter = new Counter(str);
    counter->AddUser();
}
void MyString::AddUser() {
    m_counter->IncrementOwners();
}

MyString::MyString(const MyString& other) {
    size_t len = strlen(other.m_str) + 1;
    m_str = new char[len];
    strcpy_s(m_str, len, other.m_str);
    Counter* counter = new Counter(m_str);
    counter->AddUser();
}


MyString::~MyString() {
    delete[] m_str;
}

const char* MyString::GetString() const {
    return m_str;
}

void MyString::SetNewString(const char* newStr) {
    delete[] m_str;
    size_t len = strlen(newStr) + 1;
    m_str = new char[len];
    strcpy_s(m_str, len, newStr);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] m_str;
        size_t len = strlen(other.m_str) + 1;
        m_str = new char[len];
        strcpy_s(m_str, len, other.m_str);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& myString) {
    os << myString.m_str;
    return os;
}

MyString MyString::operator+(const MyString& other) const {
    MyString result;
    size_t len = strlen(m_str) + strlen(other.m_str) + 1;
    result.m_str = new char[len];
    strcpy_s(result.m_str, len, m_str);
    strcat_s(result.m_str, len, other.m_str);
    return result;
}

MyString& MyString::operator+=(const MyString& other) {
    size_t len = strlen(m_str) + strlen(other.m_str) + 1;
    char* newStr = new char[len];
    strcpy_s(newStr, len, m_str);
    strcat_s(newStr, len, other.m_str);
    delete[] m_str;
    m_str = newStr;
    return *this;
}

MyString& MyString::operator++() {
    for (size_t i = 0; i < strlen(m_str); ++i) {
        if (islower(m_str[i])) {
            m_str[i] = toupper(m_str[i]);
        }
    }
    return *this;
}

MyString MyString::operator--(int) {
    MyString temp(*this);
    for (size_t i = 0; i < strlen(m_str); ++i) {
        if (isupper(m_str[i])) {
            m_str[i] = tolower(m_str[i]);
        }
    }
    return temp;
}


void MyString::changeCase() {
    Counter* current = Counter::GetHead();
    while (current != nullptr) {
        char* str = current->GetString();
        while (*str) {
            *str = islower(*str) ? toupper(*str) : tolower(*str);
            str++;
        }
        current = current->GetNext();
    }
}

bool compareStrings(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

void MyString::printAlph() {
    char** tempStrings = new char* [Counter::GetCurCounters()];
    Counter* current = Counter::GetHead();
    int i = 0;
    while (current != nullptr) {
        tempStrings[i++] = current->GetString();
        current = current->GetNext();
    }

    std::sort(tempStrings, tempStrings + Counter::GetCurCounters(), compareStrings);

    for (int i = 0; i < Counter::GetCurCounters(); ++i) {
        std::cout << tempStrings[i] << std::endl;
    }

    delete[] tempStrings;
}

void MyString::print() {
    Counter* current = Counter::GetHead();
    while (current != nullptr) {
        std::cout << "String: " << current->GetString() << ", Owners: " << current->GetOwners() << std::endl;
        current = current->GetNext();
    }
}