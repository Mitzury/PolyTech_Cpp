#pragma once

//������� 8 
template<typename T, size_t size>
class MyArray {
	T ar[size]{};   // ������ ��� �������� ��������� ���� T

public:
	MyArray() = default;
	MyArray(const T* p)
	{
		for (size_t i = 0; i < size; i++)
		{
			ar[i] = p[i];
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