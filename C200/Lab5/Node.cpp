#include "Node.h"

// Определение конструктора класса Node, инициализирующего данные узла и указатели на следующий и предыдущий узлы списк
Node::Node(const Circle& data) : data(data), next(nullptr), prev(nullptr) {}