#pragma once
// Класс MyStack
template <typename T, int SIZE>
class MyStack {
public:
    // Дефолтный конструктор
    MyStack() : data_(new T[SIZE]), size_(0) {}

    // Метод для добавления в стэк
    void push(const T& value) {
        if (size_ >= SIZE) {
            throw std::runtime_error("Exception: Stack is full");
        }

        data_[size_++] = value;
    }

    // Метод для получения объекта из стэка
    T pop() {
        if (size_ == 0) {
            throw std::runtime_error("Exception: Stack is empty");
        }

        T value = data_[--size_];
        return value;
    }

    // Доступ к элементам по индексу
    T& operator[](int index) {
        if (index >= size_ || index < 0) {
            throw std::out_of_range("Exception: Index out of range");
        }

        return data_[index];
    }

    // Метод для вывода размера стэка
    int size() const {
        return size_;
    }

    // Метод для определения наполненности стэка
    bool empty() const {
        return size_ == 0;
    }

    // Освобождение памяти после использования
    ~MyStack() {
        delete[] data_;
    }

private:
    T* data_;
    int size_;

    // Переопределение оператора << для вывода объектов стэка
    friend std::ostream& operator<<(std::ostream& os, MyStack<T, SIZE>& stack) {
        for (auto i = 0; i < stack.size_; i++) {
            os << stack[i] << ' ';
        }
        if (stack.empty())
            os << "MyStack is empty";
        os << std::endl;
        return os;
    }

    // Переопределение оператора << для добавления объектов в стэк
    friend MyStack<T, SIZE>& operator<<(MyStack<T, SIZE>& stack, T value) {
        stack.push(value);
        return stack;
    }

    // Переопределение оператора >> для добавления объектов в стэк
    friend std::istream& operator>>(std::istream& is, MyStack<T, SIZE>& stack) {
        T value;
        while (is >> value) {
            stack.push(value);
        }
        return is;
    }

    // Переопределение оператора >> для вывода объектов из стэка в переменную
    friend MyStack<T, SIZE>& operator>>(MyStack<T, SIZE>& stack, T& arg) {
        arg = stack.pop();
        return stack;
    }
};