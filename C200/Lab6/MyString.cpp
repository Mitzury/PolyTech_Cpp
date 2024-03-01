#include "myString.h"
#include "Counter.h"
#include <cstring>
#include <algorithm>

// Конструктор по умолчанию инициализирует указатель на строку как nullptr.
MyString::MyString() : m_str(nullptr) {}

// Конструктор, создающий строку из переданной строки и создающий для нее счетчик ссылок.
MyString::MyString(const char* str) {
    size_t len = strlen(str) + 1;
    m_str = new char[len];
    strcpy_s(m_str, len, str);
    Counter* counter = new Counter(str);
    counter->AddUser();
}

// Метод для увеличения количества владельцев строки.
void MyString::AddUser() {
    m_counter->IncrementOwners();
}

// Конструктор копирования, копирующий переданную строку и увеличивающий количество владельцев.
MyString::MyString(const MyString& other) {
    size_t len = strlen(other.m_str) + 1;
    m_str = new char[len];
    strcpy_s(m_str, len, other.m_str);
    Counter* counter = new Counter(m_str);
    counter->AddUser();
}

// Деструктор, освобождающий память, выделенную под строку.
MyString::~MyString() {
    delete[] m_str;
}

// Метод для получения указателя на строку.
const char* MyString::GetString() const {
    return m_str;
}

// Метод для установки новой строки.
void MyString::SetNewString(const char* newStr) {
    delete[] m_str;
    size_t len = strlen(newStr) + 1;
    m_str = new char[len];
    strcpy_s(m_str, len, newStr);
}

// Перегруженный оператор присваивания.
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] m_str;
        size_t len = strlen(other.m_str) + 1;
        m_str = new char[len];
        strcpy_s(m_str, len, other.m_str);
    }
    return *this;
}

// Перегруженный оператор вывода.
std::ostream& operator<<(std::ostream& os, const MyString& myString) {
    os << myString.m_str;
    return os;
}

// Перегруженный оператор сложения строк.
MyString MyString::operator+(const MyString& other) const {
    MyString result;
    size_t len = strlen(m_str) + strlen(other.m_str) + 1;
    result.m_str = new char[len];
    strcpy_s(result.m_str, len, m_str);
    strcat_s(result.m_str, len, other.m_str);
    return result;
}

// Перегруженный оператор добавления строк.
MyString& MyString::operator+=(const MyString& other) {
    size_t len = strlen(m_str) + strlen(other.m_str) + 1;
    char* newStr = new char[len];
    strcpy_s(newStr, len, m_str);
    strcat_s(newStr, len, other.m_str);
    delete[] m_str;
    m_str = newStr;
    return *this;
}

// Перегруженный оператор инкремента (префиксной формы).
MyString& MyString::operator++() {
    for (size_t i = 0; i < strlen(m_str); ++i) {
        if (islower(m_str[i])) {
            m_str[i] = toupper(m_str[i]);
        }
    }
    return *this;
}

// Перегруженный оператор декремента (постфиксной формы).
MyString MyString::operator--(int) {
    MyString temp(*this);
    for (size_t i = 0; i < strlen(m_str); ++i) {
        if (isupper(m_str[i])) {
            m_str[i] = tolower(m_str[i]);
        }
    }
    return temp;
}

// Статический метод для изменения регистра всех символов во всех строках.
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

// Функция для сравнения строк.
bool compareStrings(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

// Статический метод для вывода всех строк в алфавитном порядке.
void MyString::printAlph() {
    // Создаем временный массив указателей на строки.
    char** tempStrings = new char* [Counter::GetCurCounters()];
    Counter* current = Counter::GetHead();
    int i = 0;
    // Заполняем временный массив указателями на строки из счетчиков.
    while (current != nullptr) {
        tempStrings[i++] = current->GetString();
        current = current->GetNext();
    }
    // Сортируем массив указателей на строки.
    std::sort(tempStrings, tempStrings + Counter::GetCurCounters(), compareStrings);
    // Выводим отсортированные строки.
    for (int i = 0; i < Counter::GetCurCounters(); ++i) {
        std::cout << tempStrings[i] << std::endl;
    }
    // Освобождаем память, выделенную под временный массив.
    delete[] tempStrings;
}
// Статический метод для вывода информации о текущем состоянии строк и счетчиков.
void MyString::print() {
    Counter* current = Counter::GetHead();
    while (current != nullptr) {
        std::cout << "String: " << current->GetString() << ", Owners: " << current->GetOwners() << std::endl;
        current = current->GetNext();
    }
}