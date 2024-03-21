#pragma once
#include "Circle.h"
using namespace std;
// класс ноды листа
class Node {
public:
    Circle data;
    Node* next;
    Node* prev;

    // конструктор ноды, принимает в себя ссылку на объект класса Circle 
    Node(const Circle& data) : data(data), next(nullptr), prev(nullptr) {}
};