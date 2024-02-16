#include "CppDb.h"
#include <cstring>
// ����������� �� ���������
CppDb::CppDb() : pBase(nullptr), count(0), capacity(0) {}

// ����������
CppDb::~CppDb() {
    delete[] pBase; // ����������� ������, ���������� ��� ������� ���
}

// ����������� �����������
CppDb::CppDb(const CppDb& other) : count(other.count), capacity(other.capacity) {
    // ������� ����� ������ ��� ������ �� �������, ��� � ����������� �������
    pBase = new Pair[capacity];
    // �������� ������ ���� �� ������� ������� � ����� ������
    for (size_t i = 0; i < count; ++i) {
        pBase[i] = other.pBase[i];
    }
}

// �������� ������������
CppDb& CppDb::operator=(const CppDb& other) {
    if (this != &other) { // ���������, �� �������� �� ������ ����� �����
        delete[] pBase; // ����������� ������� ������
        count = other.count; // �������� ���������� ���
        capacity = other.capacity; // �������� �������
        // �������� ����� ������ ��� ������ ��� ������ �� �������, ��� � ����������� �������
        pBase = new Pair[capacity];
        // �������� ������ ���� �� ������� ������� � ����� ������
        for (size_t i = 0; i < count; ++i) {
            pBase[i] = other.pBase[i];
        }
    }
    return *this; // ���������� ������ �� ������� ������
}

// �������� �������������� ��� ������� � ������ ���������� �� �����
MyData& CppDb::operator[](const char* key) {
    for (size_t i = 0; i < count; ++i) {
        if (pBase[i].getKey() == key) { // ���� ������ ����
            return pBase[i].getData(); // ���������� ������ �� �����
        }
    }
    // ���� ���� �� ������, ��������� ����� ���� � ����
    if (count >= capacity) { // ���������, ��������� �� ������ ������� ����
        // ����������� ������� ���� � ��� ���� (��� �������� � 1, ���� ���� �����)
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Pair* newPBase = new Pair[newCapacity]; // ������� ����� ������ ���
        // �������� ������������ ���� � ����� ������
        for (size_t i = 0; i < count; ++i) {
            newPBase[i] = pBase[i];
        }
        delete[] pBase; // ����������� ������, ���������� ��� ������� �������
        pBase = newPBase; // ����������� ��������� �� ����� ������
        capacity = newCapacity; // ��������� ������� ����
    }
    // ��������� ����� ���� � ���� � ���������� ������ ���� ����
    pBase[count++] = Pair(MyString(key), MyData(MyData::UNDEF, 0, "", 0));
    return pBase[count - 1].getData();
}

// ����� �������� ���� ���������� �� ���� �� �����
int CppDb::deletePair(const char* key) {
    for (size_t i = 0; i < count; ++i) {
        if (pBase[i].getKey() == key) { // ���� ������ ����
            // ������� ���� � ��������� ������, ������� ��
            for (size_t j = i; j < count - 1; ++j) {
                pBase[j] = pBase[j + 1]; // �������� ��������� ���� �� ���� ������� �����
            }
            --count; // ��������� ���������� ���
            return 0; // ���������� �������� ��������� ��������
        }
    }
    return -1; // ���������� ��� ������, ���� ���� � ��������� ������ �� �������
}

// ������������� �������� ������ ��� ������ ����
std::ostream& operator<<(std::ostream& os, const CppDb& bd) {
    for (size_t i = 0; i < bd.count; ++i) {
        os << bd.pBase[i] << std::endl; // ������� ������ ���� � ����� ������ � ��������� ������
    }
    return os; // ���������� ����� ������
}

// ����������� �����������
CppDb::CppDb(CppDb&& other) : pBase(nullptr), count(0), capacity(0) {
    *this = std::move(other); // �������� �������� �����������
}

// �������� �����������
CppDb& CppDb::operator=(CppDb&& other) {
    if (this != &other) { // ���������, �� �������� �� ������ ����� �����
        delete[] pBase; // ����������� ������� ������
        pBase = other.pBase; // ���������� ��������� �� ����� ������ ���
        count = other.count; // ���������� ���������� ���
        capacity = other.capacity; // ���������� �������
        other.pBase = nullptr; // ������������� ��������� � �������-��������� � nullptr
        other.count = 0; // ���������� ���������� ��� � �������-���������
        other.capacity = 0; // ���������� ������� � �������-���������
    }
    return *this; // ���������� ������ �� ������� ������
}

// ����� ��� ���������� ���� ������
void CppDb::sort() {
    for (size_t i = 1; i < count; ++i) { // �������� �� ���� ��������� ���� (������� � ������� 1)
        Pair keyPair = pBase[i]; // ���������� ������� ����
        size_t j = i; // ���������� ������� ������
        while (j > 0 && pBase[j - 1].getKey() > keyPair.getKey()) { // ���� ���������� ���� ������ ��������
            pBase[j] = pBase[j - 1]; // �������� ���������� ���� ������
            --j; // ��������� ������
        }
        pBase[j] = keyPair; // �������� ����������� ���� �� ���������� �������
    }
}