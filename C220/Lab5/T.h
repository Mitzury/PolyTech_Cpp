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


// ������� 3.
// ������� ��� ������, ���������� ������ �����
struct AlphabeticalString {
	std::string value;
	// �����������, ����������� ������
	AlphabeticalString(const std::string& str) : value(str) {}
	// �������� ��������� ��� ���������� �� ��������
	bool operator<(const AlphabeticalString& other) const {
		return value < other.value;
	}
};

// ������� ��� ������, ���������� ������ �����
struct NumericString {
	std::string value;
	// �����������, ����������� ������
	NumericString(const std::string& str) : value(str) {}
	// ����� ��� ���������� ����� ���� � ������
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