#pragma once
#include <list>
// ����� MyStack2
template <typename T>
class MyStack2 {
private:
   // std::list<T> m_data;
    class Node{
        T data;
        Mode* pNext;
    }
    Node Head;
    size_t m_size;

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
        m_data.clear();
    }

    // ����� ��� ���������� � ����
    void push(const T& value) {
        m_data.push_back(value);
    }

    // ����� ��� ��������� ������� �� �����
    T pop() {
        if (m_data.empty()) {
            throw std::underflow_error("Exception: Stack is empty");
        }
        T result = m_data.back();
        m_data.pop_back();
        return result;
    }

    // ����� ��� ����������� ������������� �����
    bool empty() const {
        return m_data.empty();
    }

    // ���������� ��������� << ��� ������ �������� � �����
    friend std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack) {
        for (const auto& value : stack.m_data) {
            os << value << ' ';
        }
        if (stack.empty())
            os << "MyStack2 is empty";
        os << '\n';
        return os;
    }

    // ���������� ��������� >> ��� ����� �������� �� ������
    friend std::istream& operator>>(std::istream& is, MyStack2<T>& stack) {
        T value;
        while (is >> value) {
            stack.push(value);
        }
        return is;
    }

    MyStack2<T>& operator=(const MyStack2<T>& other) {
        if (this != &other) {
            m_data.clear();
            for (const auto& value : other.m_data) {
                m_data.push_back(value);
            }
        }

        return *this;
    }
};
