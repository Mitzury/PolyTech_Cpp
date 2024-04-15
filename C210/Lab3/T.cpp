#include "T.h"

template <typename T>
void printVectorOfPointersStats(const std::vector<T*>& v) {
	std::cout << "����� ���������� ��� ������� ���������� �� ������� ���� " << typeid(T).name() << ":\n";
	std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Max_size: " << v.max_size() << std::endl;
	std::cout << "���������� (� �������� ����������): ";
	for (const auto* ptr : v) {
		if (ptr != nullptr) {
			std::cout << *ptr << " "; // �������������� ��������� ��� ������ �������
		}
		else {
			std::cout << "null ";
		}
	}
	std::cout << "\n\n";
};