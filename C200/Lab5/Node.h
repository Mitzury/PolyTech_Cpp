#pragma once
#include "Circle.h"
#include <memory>

class Node {
public:
    Circle data;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;

    Node(const Circle& data);
};
