#pragma once
// ����� MyStack
template <typename T, int SIZE>
class MyStack {
public:
    // ��������� �����������
    MyStack() : data_(new T[SIZE]), size_(0) {}

    // ����� ��� ���������� � ����
    void push(const T& value) {
        if (size_ >= SIZE) {
            throw std::runtime_error("Exception: Stack is full");
        }

        data_[size_++] = value;
    }

    // ����� ��� ��������� ������� �� �����
    T pop() {
        if (size_ == 0) {
            throw std::runtime_error("Exception: Stack is empty");
        }

        T value = data_[--size_];
        return value;
    }

    // ������ � ��������� �� �������
    T& operator[](int index) {
        if (index >= size_ || index < 0) {
            throw std::out_of_range("Exception: Index out of range");
        }

        return data_[index];
    }

    // ����� ��� ������ ������� �����
    int size() const {
        return size_;
    }

    // ����� ��� ����������� ������������� �����
    bool empty() const {
        return size_ == 0;
    }

    // ������������ ������ ����� �������������
    ~MyStack() {
        delete[] data_;
    }

private:
    T* data_;
    int size_;

    // ��������������� ��������� << ��� ������ �������� �����
    friend std::ostream& operator<<(std::ostream& os, MyStack<T, SIZE>& stack) {
        for (auto i = 0; i < stack.size_; i++) {
            os << stack[i] << ' ';
        }
        if (stack.empty())
            os << "MyStack is empty";
        os << std::endl;
        return os;
    }

    // ��������������� ��������� << ��� ���������� �������� � ����
    friend MyStack<T, SIZE>& operator<<(MyStack<T, SIZE>& stack, T value) {
        stack.push(value);
        return stack;
    }

    // ��������������� ��������� >> ��� ���������� �������� � ����
    friend std::istream& operator>>(std::istream& is, MyStack<T, SIZE>& stack) {
        T value;
        while (is >> value) {
            stack.push(value);
        }
        return is;
    }

    // ��������������� ��������� >> ��� ������ �������� �� ����� � ����������
    friend MyStack<T, SIZE>& operator>>(MyStack<T, SIZE>& stack, T& arg) {
        arg = stack.pop();
        return stack;
    }
};