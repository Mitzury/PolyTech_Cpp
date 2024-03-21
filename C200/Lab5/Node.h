#pragma once
#include "Circle.h"
using namespace std;
// ����� ���� �����
class Node {
public:
    Circle data;
    Node* next;
    Node* prev;

    // ����������� ����, ��������� � ���� ������ �� ������ ������ Circle 
    Node(const Circle& data) : data(data), next(nullptr), prev(nullptr) {}
};