#pragma once

// ������ ������ MyUniquePTR
template <typename T>
class MyUniquePTR {
private:
    T* ptr;
public:
    // �����������
    explicit MyUniquePTR(T* p = nullptr) : ptr(p) {}

    // ����������
    ~MyUniquePTR() {
        delete ptr;
    }

    // ����������� ����������� ��������
    MyUniquePTR(const MyUniquePTR& other) = delete;
    // �������� ������������ ��������
    MyUniquePTR& operator=(const MyUniquePTR& other) = delete;

    // ������������ �����������
    MyUniquePTR(MyUniquePTR&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    // ������������ �������� ������������
    MyUniquePTR& operator=(MyUniquePTR&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    // �������� �������������
    T& operator*() const {
        return *ptr;
        // if null
    }
    // �������� ������� � ������ �������
    T* operator->() const {
        return ptr;
    }
    // �������� �������� ������� �������
    explicit operator bool() const {
        return ptr != nullptr;
    }
    // ����� ������ ���������
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
    // �������� �������������� ���������
    T* get() const {
        return ptr;
    }
};