#pragma once
#include "Node.h"
#include <vector>
#include <fstream>

class List {
private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    size_t size;

    void quickSort(std::vector<Circle>& arr, int low, int high);
    int partition(std::vector<Circle>& arr, int low, int high);

public:
    List();
    void addToTail(const Circle& circle);
    void addToHead(const Circle& circle);
    void remove(const Circle& circle);
    void removeAll(const Circle& circle);
    void sortList();

    List(const List& other);
    List& operator=(const List& other);
    List(List&& other) noexcept;
    List& operator=(List&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const List& list);
    friend std::istream& operator>>(std::istream& is, List& list);
};