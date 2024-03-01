#include "Circle.h"

class Node {
public:
    Node* pPrev; // ��������� �� ���������� �������
    Node* pNext; // ��������� �� ��������� �������
    Circle m_Data;

    Node();
    Node(const Circle& circle, Node* prevNode = nullptr, Node* nextNode = nullptr);
    ~Node();
};