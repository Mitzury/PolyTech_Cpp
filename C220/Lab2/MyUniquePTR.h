#pragma once

// Шаблон класса MyUniquePTR
template <typename T>
class MyUniquePTR {
private:
    T* ptr;
public:
    // Конструктор
    explicit MyUniquePTR(T* p = nullptr) : ptr(p) {}

    // Деструктор
    ~MyUniquePTR() {
        delete ptr;
    }

    // Конструктор копирования отключен
    MyUniquePTR(const MyUniquePTR& other) = delete;
    // Оператор присваивания отключен
    MyUniquePTR& operator=(const MyUniquePTR& other) = delete;

    // Перемещающий конструктор
    MyUniquePTR(MyUniquePTR&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    // Перемещающий оператор присваивания
    MyUniquePTR& operator=(MyUniquePTR&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    // Оператор разыменования
    T& operator*() const {
        return *ptr;
        // if null
    }
    // Оператор доступа к членам объекта
    T* operator->() const {
        return ptr;
    }
    // Оператор проверки наличия объекта
    explicit operator bool() const {
        return ptr != nullptr;
    }
    // Метод сброса указателя
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
    // Получить необработанный указатель
    T* get() const {
        return ptr;
    }
};