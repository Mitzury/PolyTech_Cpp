#pragma once

// Функтор для удаления элементов из массива указателей
struct ArrayDeleter {
	template<typename T>
	void operator()(T* ptr) const {
		delete ptr;
	}
};


// 1.e
template<typename T>
void printContainer(const T& container) {
	std::cout << "Container: ";
	for (const auto& element : container) {
		std::cout << *element << " ";
	}
	std::cout << std::endl;
}


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

class Delete {
	std::string file;
public:
	Delete(const std::string& s) : file(s) { }
	void operator()(std::ofstream* p){
		p->close();
		delete p;
	}
};

int calculateDigitsSum(const std::string& str) {
	int sum = 0;
	for (char c : str) {
		if (std::isdigit(c)) {
			sum += c - '0';
		}
	}
	return sum;
}

// или создать функтор
class Functor {
public:
	Functor() {}
	void operator()(std::string*) const {}
};

//сделать делетер лябмдой