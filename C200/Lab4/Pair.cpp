#include "Pair.h"

Pair::Pair() : key(""), data(MyData(MyData::UNDEF, 0, "", 0)) {
    // ����������� �� ��������� �������������� ���� ������ ������� � ������ ���������� �� ���������
}
Pair::Pair(const MyString& k, const MyData& d) : key(k), data(d) {
    // ����������� � ����������� �������������� ���� ���������� ������� � ������ ���������� �������� MyData
}
const MyString& Pair::getKey() const {
    return key; // ���������� ���� ����
}
MyData& Pair::getData() {
    return data; // ���������� ������ ����
}
std::ostream& operator<<(std::ostream& os, const Pair& pair) {
    os << "Key: " << pair.key << ", Data: " << pair.data; // ������� ���� � ������ ���� � ����� ������
    return os; // ���������� ������ �� ����� ������
}