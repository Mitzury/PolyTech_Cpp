#pragma once
// класс MyStack
template <typename T, int SIZE>
class MyStack {
public:
    // Дефолтный конструктор
    MyStack() :size_(0), data_() {}

    // Метод добавления в стэк
    void push(const T& value) {
        if (size_ >= SIZE) {
            throw std::runtime_error("Exception: Stack is full");
        }

        data_[size_++] = value;
    }

    // Метод удаления из стэка
    T pop() {
        if (size_ == 0) {
            throw std::runtime_error("Exception: Stack is empty");
        }

        T value = data_[--size_];
        return value;
    }

    // Индексатор для доступа к элементам по индексу
    T& operator[](int index) {
        if (index >= size_ || index < 0) {
            throw std::out_of_range("Exception: Index out of range");
        }

        return data_[index];
    }

    // Метод, возвращающий количество элементов в стэке
    int size() const {
        return size_;
    }

    // Метод для определения наполненности стэка
    bool empty() const {
        return size_ == 0;
    }

    // Деконструктор
    ~MyStack() { }

private:
    T data_[SIZE];
    int size_;

    // Перегрузка оператора << для вывода значений в поток
    friend std::ostream& operator<<(std::ostream& os, MyStack<T, SIZE>& stack) {
        for (auto i = 0; i < stack.size_; i++) {
            os << stack[i] << ' ';
        }
        if (stack.empty())
            os << "MyStack is empty";
        os << std::endl;
        return os;
    }

    // Перегрузка оператора << для добавления значений 
    friend MyStack<T, SIZE>& operator<<(MyStack<T, SIZE>& stack, T value) {
        stack.push(value);
        return stack;
    }

    // Перегрузка оператора >> для ввода значений из потока
    friend std::istream& operator>>(std::istream& is, MyStack<T, SIZE>& stack) {
        T value;
        while (is >> value) {
            stack.push(value);
        }
        return is;
    }

    // Перегрузка оператора >> для вывода значений в аргумент
    friend MyStack<T, SIZE>& operator>>(MyStack<T, SIZE>& stack, T& arg) {
        arg = stack.pop();
        return stack;
    }
};