#pragma once

#include "Point.h"
#include "T.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>


// Определение функции printStack
template<typename T>
void printStack(std::stack<T> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
}

// Определение функции printQueue
template<typename T>
void printQueue(std::queue<T> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

// Определение функции printPriorityQueue
template<typename T>
void printPriorityQueue(std::priority_queue<T> pq) {
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
}

// Определение функции printContainer
template<typename Container>
void printContainer(const Container& container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

// Определение функции printPointQueue
void printPointQueue(std::queue<Point*, std::list<Point*>> q) {
    while (!q.empty()) {
        Point* p = q.front();
        std::cout << *p << " ";
        q.pop();
    }
    std::cout << "\n";
}


template <typename Adapter>
void Show(Adapter& c_copy)
{
    while (!c_copy.empty())
    {
        std::cout << c_copy.top() << ' ';
        c_copy.pop();
    }

    std::cout << std::endl;
}
template <typename T, typename Container>
void Show(std::queue<T, Container> c_copy)
{
    while (!c_copy.empty())
    {
        std::cout << c_copy.front() << ' ';
        c_copy.pop();
    }

    std::cout << std::endl;
}
template <typename T>
void Show(const std::vector<T>& v)
{
    typename std::vector<T>::const_iterator it = v.cbegin();

    while (it != v.cend())
    {
        std::cout << *it << ' ';
        ++it;
    }

    std::cout << std::endl;
}