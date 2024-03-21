#pragma once
#include "Node.h"
#include <string>
using namespace std;
// ����� ����������� ������
class List {
private:
    Node* head;
    Node* tail;

public:
    // ������ �����������
    List() : head(nullptr), tail(nullptr) {}
    // ������� ������ ����� ������������ ������
    ~List();


    // ����������� �����������
    List(List&& other) : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }
    // �������� ������������ �����������
    List& operator=(List&& other);

    // ����������� �����������
    List(const List& other);

    // �������� ������������ �����������
    List& operator=(const List& other);


    // ����� ���������� ���� � ����� ������
    void AddToTail(const Circle& data);
    // ����� ���������� ���� � ������ ������
    void AddToHead(const Circle& data);
    // ����� �������� ������ ����, ���� ������� ��������� � ������
    void Remove(const Circle& data);
    // ����� �������� ���� ���, ���� ������� ��������� � ������
    void RemoveAll(const Circle& data);
    // ���������� ����� �� ������� ������
    void SortList();


    // �����, ��������� ���������� ������, � ������� ������ � ������� ������� ������ ��������
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    // �����, ����������� �� ������������ ������ ������ ���������� ������
    friend std::istream& operator>>(std::istream& is, List& list);
};