#pragma once

//������� 8 
template<typename T, size_t size>
class MyArray {
	T ar[size];   // ������ ��� �������� ��������� ���� T

public:
	MyArray(const T* arr = nullptr) {
		// ����������� ������
		if (arr) {
			std::memcpy(ar, arr, size * sizeof(T));  // ����������� �������� �� ����������� �������
		}
		else {
			for (size_t i = 0; i < size; ++i) {
				ar[i] = T();   // ������������� �������� ������� ��������� �� ���������
			}
		}
	}
	T& operator[](size_t index) {
		// ���������� ��������� [] ��� ������� � ��������� �������
		return ar[index];   // ����������� ������ �� ������� ������� �� ���������� �������
	}

	const T& operator[](size_t index) const {
		// ���������� ��������� [] ��� ������� � ��������� ������� (����������� ������)
		return ar[index];   // ����������� ����������� ������ �� ������� ������� �� ���������� �������
	}

	size_t getSize() const {
		// ����� ��� ��������� ������� �������
		return size;   // ����������� ������� �������
	}

	void print() const {
		// ����� ��� ������ ��������� �������
		for (size_t i = 0; i < size; ++i) {
			std::cout << ar[i] << " ";   // ������ ������� �������� �������
		}
		std::cout << std::endl;   // ������� �� ����� ������
	}
};


template<typename T, size_t size>
MyArray<T, size> makeMyArray(std::initializer_list<T> initList) {
	// ������� ��� �������� ������� MyArray �� ������ �������������
	MyArray<T, size> result;   // �������� ������� MyArray
	size_t i = 0;
	for (const T& element : initList) {
		// ������� ��������� ������ �������������
		if (i >= size) break;   // ���������� �����, ���� ��������� ������������ ������ �������
		result[i++] = element;  // ���������� �������� ������� ��������� �� ������ �������������
	}
	return result;   // ����������� ���������� ������� MyArray
}
