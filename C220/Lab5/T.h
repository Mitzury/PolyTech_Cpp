#pragma once

// ������� ��� ��������, �������� �� �������� ������
bool isDigit(const std::string& st)
{
	for (char a : st)
		if (!isdigit(a))
			return false;
	return true;
}

bool isLetter(const std::string& st)
{
	for (char a : st)
		if (!isalpha(a))
			return false;
	return true;
}
// �������, ������� ���������, �������� �� ������ �� ������ � �� ������
bool isOther(const std::string& st) {
	for (char a : st) {
		// ���������, �� �������� �� ������ ������ ��� ������
		if (!isalpha(a) && !isdigit(a)) {
			return true;
		}
	}
	return false;
}
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
//// ������� 3.
//bool isAlphaString(const std::shared_ptr<std::string>& str) {
//	return std::all_of(str->begin(), str->end(), [](unsigned char c) { return std::isalpha(c); });
//}
//bool isDigitString(const std::shared_ptr<std::string>& str) {
//	return std::all_of(str->begin(), str->end(), [](unsigned char c) { return std::isdigit(c); });
//}
//bool isOtherString(const std::shared_ptr<std::string>& str) {
//	return std::none_of(str->begin(), str->end(), [](unsigned char c) { return std::isalnum(c); });
//}

class Delete {
	std::string file;
public:
	Delete(const std::string& s) : file(s) { }
	void operator()(std::ofstream* p){
		p->close();
		delete p;
	}
};
