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
    List(List&& other);
    // �������� ������������ �����������
    List& operator=(List&& other);

    // ����������� �����������
    List(const List& other);

    // �������� ������������ �����������
    List& operator=(const List& other);


    void Reverse();

    // ����� ���������� ���� � ����� ������
    void AddToTail(const Circle& data);
    // ����� ���������� ���� � ������ ������
    void AddToHead(const Circle& data);


    void InsertBefore(const Circle& newCircle, const Circle& existingCircle);
    void InsertAfter(const Circle& newCircle, const Circle& existingCircle);


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