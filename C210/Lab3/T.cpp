#include "T.h"

template <typename T>
void printVectorOfPointersStats(const std::vector<T*>& v) {
	std::cout << "Вывод информации для вектора указателей на объекты типа " << typeid(T).name() << ":\n";
	std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Max_size: " << v.max_size() << std::endl;
	std::cout << "Содержимое (в качестве указателей): ";
	for (const auto* ptr : v) {
		if (ptr != nullptr) {
			std::cout << *ptr << " "; // Разыменовываем указатель для вывода объекта
		}
		else {
			std::cout << "null ";
		}
	}
	std::cout << "\n\n";
};