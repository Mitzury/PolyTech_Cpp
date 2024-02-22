#pragma once
#include "Circle.h" // Подключаем заголовочный файл Circle.h, который содержит объявление класса Circle


class Node {
public:
    Circle data; // Данные, хранящиеся в узле списка
    std::shared_ptr<Node> next; // Указатель на следующий узел списка
    std::shared_ptr<Node> prev; // Указатель на предыдущий узел списка

    Node(const Circle& data); // Конструктор узла списка, инициализирующий данные узла
};
