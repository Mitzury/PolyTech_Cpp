#pragma once

#include "Pair.h"
class CppDb {
private:
    Pair* pBase; // ��������� �� ������ ��� (�����������)
    size_t count; // ���������� ��������� � ����
    size_t capacity; // ������� ����
public:
    // ����������� �� ���������
    CppDb();
    // ����������
    ~CppDb();
    // ����������� �����������
    CppDb(const CppDb& other);
    // �������� ������������
    CppDb& operator=(const CppDb& other);
    // ����������� �����������
    CppDb(CppDb&& other);
    // �������� �����������
    CppDb& operator=(CppDb&& other);
    // �������� �������������� ��� ������� � ������ ���������� �� �����
    MyData& operator[](const char* key);
    // ����� �������� ���� ���������� �� ���� �� �����
    int deletePair(const char* key);
    // ����� ��� ���������� ���� ������
    void sort();
    void clear();
    // ������������� �������� ������ ��� ������ Base
    friend std::ostream& operator<<(std::ostream& os, const CppDb& bd);
};