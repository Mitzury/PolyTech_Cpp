#include "Node.h"
Node::Node() : pPrev(nullptr), pNext(nullptr), m_Data(0,0,0) {}

Node::Node(const Circle& circle, Node* prevNode, Node* nextNode)
    : m_Data(circle), pPrev(prevNode), pNext(nextNode) {}

Node::~Node() {}