#pragma once

struct Deleter {
	template<typename T>
	void operator()(T* ptr) const {
		if (ptr) {
			delete ptr;
			ptr = nullptr;
		}
	}
};


void writeToLogFile(std::shared_ptr<std::ofstream> file, const std::string& data) {
	if (file && file->is_open()) {
		*file << data << std::endl;
	}
}


// Задание 3.
// Обертка для строки, содержащей только буквы
struct AlphabeticalString {
	std::string value;
	// Конструктор, принимающий строку
	AlphabeticalString(const std::string& str) : value(str) {}
	// Оператор сравнения для сортировки по алфавиту
	bool operator<(const AlphabeticalString& other) const {
		return value < other.value;
	}
};

// Обертка для строки, содержащей только цифры
struct NumericString {
	std::string value;
	// Конструктор, принимающий строку
	NumericString(const std::string& str) : value(str) {}
	// Метод для вычисления суммы цифр в строке
	int sumDigits() const {
		int sum = 0;
		for (char ch : value) {
			if (std::isdigit(ch)) {
				sum += ch - '0';
			}
		}
		return sum;
	}
};