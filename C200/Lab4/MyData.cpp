#include "MyData.h"

// ����������� ������������ ������ MyData
MyData::MyData(Sex s, size_t a, const char* j, float sal) : sex(s), age(a), job(j), salary(sal) {}
// � ������������ ���������������� ����� ������ ������ MyData ���������� ���������� ������������

// ����������� �������������� ��������� ������
std::ostream& operator<<(std::ostream& os, const MyData& data) {
    // �������� ������ ������� ���������� � ���������� � ����� ������
    os << "Sex: " << data.sex << ", Age: " << data.age << ", Job: " << data.job << ", Salary: " << data.salary;
    return os; // ���������� ������ �� ����� ������
}