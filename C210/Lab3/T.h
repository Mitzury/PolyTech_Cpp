#pragma once
#include <algorithm>



// ��������� ������� ��� ������ ���������� � �������
template <typename T>
void printVectorInfo(const std::vector<T>& vec) {
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	std::cout << "Max Size: " << vec.max_size() << std::endl;
	std::cout << "Elements: ";
	for (const auto& elem : vec) {
		std::cout << elem << " ";
	}
	std::cout << std::endl << std::endl;
}

template<typename T>
void insertIfNotExists(std::vector<T>& vec, const T& value) {
	// ���������, ���� �� �������� � �������
	if (std::find(vec.begin(), vec.end(), value) == vec.end()) {
		// ���� �������� ���, ��������� ��� � ������ �������
		vec.insert(vec.begin(), value);
	}
}

template<typename T>
void removeDuplicates(std::vector<T>& vec) {
	// ��������� ������
	std::sort(vec.begin(), vec.end());
	// ���������� std::unique() ��� ����������� ���� ������������� ��������� � ����� �������
	auto last = std::unique(vec.begin(), vec.end());
	// ���������� ����� erase() ��� �������� ���� ����������
	vec.erase(last, vec.end());
}

// ������ ������� ��� ������ ��������� ������ ���������� �� ������
template<typename Container>
void printContainer(const Container& cont, const std::string& contName) {
	std::cout << "Container type: " << typeid(Container).name() << std::endl;
	std::cout << "Container name: " << contName << std::endl;
	std::cout << "Container elements: ";
	for (const auto& elem : cont) {
		std::cout << elem << " ";
	}
	std::cout << std::endl << std::endl;
}


// �������-�������� ��� �������� ��������� ������ ����
bool isNegative(int x) {
	return x < 0;
}

// ���������� ��������� ������ ��� ������� ��������
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& vv) {
	for (std::vector<std::vector<int>>::const_iterator row = vv.begin(); row != vv.end(); ++row) {
		for (std::vector<int>::const_iterator val = row->begin(); val != row->end(); ++val) {
			os << *val << " ";
		}
		os << std::endl;
	}
	return os;
}