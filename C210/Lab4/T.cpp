#include "T.h"

// Определение функции printStack
template<typename T>
void printStack(std::stack<T> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
};