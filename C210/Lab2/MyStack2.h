#include "List.h"

// Класс MyStack2
template <typename T>
class MyStack2 {

    /*class Node{

        Node *pNext;
        T data;

    }
    Node  Head;
    size_t m_size;*/


public:

    MyStack2() {
        m_data = {};
    }

    MyStack2(MyStack2&& other) {
        m_data = std::move(other.m_data);
    }

    MyStack2& operator=(MyStack2&& other) {
        m_data = std::move(other.m_data);
        return *this;
    }

    MyStack2(const MyStack2& other) {
        m_data = other.m_data;
    }

    ~MyStack2() {
        m_data.~List();
    }

    // Метод для добавления в стэк
    void push(const T& value) {
        m_data.AddToTail(value);
    }

    // Метод для получения объекта из стэка
    T pop() {
        if (m_data.empty()) {
            throw std::underflow_error("Exception: Stack is empty");
        }
        T result = m_data.GetLast();
        m_data.RemoveLast();
        return result;
    }

    // Метод для определения наполненности стэка
    bool empty() const {
        return m_data.empty();
    }



    MyStack2<T>& operator=(const MyStack2<T>& other) {
        if (this != &other) {
            m_data.clear();
            m_data = other.m_data;
        }

        return *this;
    }

private:
    List<T> m_data;

    // Перегрузка оператора << для вывода значений в поток
    friend std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack) {
        if (stack.empty())
        {
            os << "MyStack2 is empty\n";
            return os;
        }
        os << stack.m_data;
        return os;
    }

    // Перегрузка оператора >> для ввода значений из потока
    friend std::istream& operator>>(std::istream& is, MyStack2<T>& stack) {
        T value;
        while (is >> value) {
            stack.push(value);
        }
        return is;
    }
};