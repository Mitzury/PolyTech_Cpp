#include "Circle.h"

class Node {
public:
    Node* pPrev; // указатель на предыдущий элемент
    Node* pNext; // указатель на следующий элемент
    Circle m_Data;

    Node();
    Node(const Circle& circle, Node* prevNode = nullptr, Node* nextNode = nullptr);
    ~Node();
};