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
bool isAlphaString(const std::shared_ptr<std::string>& str) {
	return std::all_of(str->begin(), str->end(), [](unsigned char c) { return std::isalpha(c); });
}
bool isDigitString(const std::shared_ptr<std::string>& str) {
	return std::all_of(str->begin(), str->end(), [](unsigned char c) { return std::isdigit(c); });
}
bool isOtherString(const std::shared_ptr<std::string>& str) {
	return std::none_of(str->begin(), str->end(), [](unsigned char c) { return std::isalnum(c); });
}

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


void NotDeleter(std::string* p) {} 
