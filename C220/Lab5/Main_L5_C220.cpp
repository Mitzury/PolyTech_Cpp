#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>
#include <list>

#include "T.h"
#include "human.h"
#include "Writter.h"

int main() {
	setlocale(LC_ALL, "Ru");
	using namespace std;
	//������� 1. unique_ptr
	{
		//1.� - ���������� ���������� ���������� ���������
		{
			cout << "\t Chapter 1a: " << endl;
			std::vector<std::string*> v = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			//������������ ��� ������
			for (std::string* str : v) {
				// ������������� ������, �� ������� ��������� ���������
				std::cout << *str << std::endl;
			}
			// ����������� ������, ���������� ��� �����
			for (std::string* str : v) {
				delete str;
			}
		}
	//1.b - ������������� ������� 1.�:
		 //���������� ����������� std::unique_ptr: 
		 //����������� ���������� (��������� ��� ������ ������� ������������ std::unique_ptr), 
		 //���������� �������� ���������� �� ����������� ����������� ������� std::string, 
		 //���������������,
		 //� ������������ ��������
		{
			cout << "\t ************** " << endl;
			std::cout << "\t chapter 1b: " << std::endl;
			// ������� ������ ����� ���������� �� ������ std::unique_ptr<std::string>
			std::vector<std::unique_ptr<std::string>> v;
			// �������� ��� ������ ������� ������������ std::unique_ptr � ������� ������ � ������
			v.push_back(std::make_unique<std::string>("aa")); 
			v.push_back(std::make_unique<std::string>("bb"));
			v.push_back(std::make_unique<std::string>("cc")); 

			// ����������� ��� ������
			for (const auto& str : v) {
				// ������������� ������, �� ������� ��������� ����� ���������
				std::cout << *str << std::endl;
			}
			//??? ����������� ����������� ��������� ��������?
			// � ������, ���������� ��� �����, ����� ����������� ������������� ��������� ����� ����������
		}

		{//1.c - ��������� ������� 1.b �������� ����������� �������� ���������� ������
		 //��������� ������� (��������, �������� ��������� �������: "AAA" -> "AAA_1")  
			cout << "\t ************** " << endl;
			std::cout << "\t chapter 1�: " << std::endl;
			// ������� ������ ����� ���������� �� ������ std::unique_ptr<std::string>
			std::vector<std::unique_ptr<std::string>> v;
			// �������� ��� ������ ������� ������������ std::unique_ptr � ������� ������ � ������
			v.push_back(std::make_unique<std::string>("aa"));
			v.push_back(std::make_unique<std::string>("bb"));
			v.push_back(std::make_unique<std::string>("cc"));

			std::cout << "before modify: " << std::endl;
			// ����������� ��� ������
			for (const auto& str : v) {
				// ������������� ������, �� ������� ��������� ����� ���������
				std::cout << *str << std::endl;
			}
			// �������� ���������� ������
			for (auto& str : v) {
				*str += "_1"; // ��������� ������� "_1" � ������ ������
			}
			std::cout << "after modify: " << std::endl;
			// ����������� ��� ������
			for (const auto& str : v) {
				// ������������� ������, �� ������� ��������� ����� ���������
				std::cout << *str << std::endl;
			}
		}
		//1.d - ������������ ������ ��������	
		//�������� unique_ptr, ������� �������� �������� ��� ������������� �������
		//� ���������� std::string
		//� ������� unique_ptr::operator[] ��������� ��������� ������ ����������
		//����� ���������� ������������ ������?
		{
			cout << "\t ************** " << endl;
			cout << "\t Chapter 1d: " << endl;

			// ������� ����� ��������� �� ������ �� ���� ��������� ���� std::string
			std::unique_ptr<std::string[]> arr(new std::string[3]);
			// ��������� ������ ���������� � ������� operator[]
			arr[0] = "Hello";
			arr[1] = "World";
			arr[2] = "!";
			// ������� �������� �������
			for (int i = 0; i < 3; ++i) {
				std::cout << arr[i] << std::endl;
			}
			// ����� ��������� ������������� ����������� ������ ��� ������ �� ������� ���������

		}
		//1.e - ������� ������������ �������� � ���������������� delete-������� (�������)
		//����� �������� ������ ���������� �� ����������� ��������� �������
		//�������� unique_ptr ��� ������ �������
		//���������� ���������������� delete-������� (�������) ��� ����������� 
		//������������ ������
		{
			cout << "\t ************** " << endl;
			cout << "\t Chapter 1e: " << endl;
			string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			// ���������� ���������� ��������� � �������
			size_t n = sizeof(arStrPtr) / sizeof(arStrPtr[0]);
			// ������� ������-�������, ������� ����� ������� �������� �������
			// ��� ������ ���������� � �������� ����������� ��� ������ [] .. [n]?
			// [] : ������ ���������� ������ ��������, ��� ������ - ������� �� ����������� ������� ���������� 
			// �� ����������� ���������. ������ �� ����� ������� � ��������� ���������� ��� ����������, 
			// ����������� ��� � ����.
			// [n] : � ���������� ������� �����������, ��� ������ ����������� ���������� n �� ��������. 
			// ��� ��������, ��� ��� �������� ������ - ������� ��������� ����� ���������� n, 
			// � ������ ������ - ������� ������������ ��� �����.

			auto lambda = [n](std::string* (arStrPtr)[]) {for (size_t i = 0; i < n; ++i) { delete (arStrPtr)[i]; }};
			// ������� ����� ���������, ������� ����� ������� ������ ���������� � ������������ ������-������� ��� ��������
			std::unique_ptr<std::string* [], decltype(lambda)> unique_p(arStrPtr, lambda);
			
			for (int i = 0; i < n; ++i) {
				std::cout << *(unique_p[i]) << std::endl;
			}
		}
		//1.f �������� � ��������� ������, ���������� unique_ptr ��� ���������� �� std::string
		//����������� ��������� copy() ���������� �������� ������� � ������ ������ � ���������� 
		//���� �� ����
		//���������: ������������ ��������� � ������ std::make_move_iterator
		{
			cout << "\t ************** " << endl;
			cout << "\t Chapter 1f: " << endl;
			// ������� ������ unique_ptr<string>
			vector<unique_ptr<string>> vector;

			// ��������� �������� � ������
			vector.push_back(std::unique_ptr<std::string>(new std::string("aa")));
			vector.push_back(std::unique_ptr<std::string>(new std::string("bb")));
			vector.push_back(std::unique_ptr<std::string>(new std::string("��")));
			vector.push_back(std::unique_ptr<std::string>(new std::string("dd")));

			printContainer(vector);
			// ������� ������ unique_ptr<string> ��������, ������ ������� �������
			list<unique_ptr<string>> list; 

			// �������� �������� �� ������� � ������ � ������� move_iterator
			copy(std::make_move_iterator(vector.begin()), std::make_move_iterator(vector.end()), back_inserter(list));

			printContainer(list);

		}
	}
	////////////////////////////////////////////////////////////////////////////////
	//������� 2.shared_ptr + ���������������� delete-������� 

	//����������� ����������� ������ � ���� ������ (�������) �� ������ ���������� 
	//��� ��� ��� "��������" ����� �� ������� ���������� ���� ������ � ���� � ��� �� ����,
	//������� ������������ �� ����������� ������������ ����� � ��� �� �������� ������ ������ =>
	//���������� �������� ��� ������ ��������� �������� shared_ptr
	//�. ������ �������� ������ �������/������� ���� ��� ������
	//�. ��� ��������� �������� ������ �������������� � �������������
	//�. ��������� �������� ��������� ������ ������� ����

	//���������: ����������� ������� ������ ����� � ������� ������� rand()
	//"��������":
	//������� writer1, writer2
	{
	cout << "\t ************** " << endl;
	cout << "\t Chapter 2: " << endl;
	std::shared_ptr<std::ofstream> logFile(new ofstream("log.txt"));
	// ���������, ������� �� ������� ����
	if (!logFile || !logFile->is_open()) {
		std::cerr << "Error: Unable to open file for writing!" << std::endl;
		return 1;
	}
	// ������� "���������"
	std::string writer1 = "Writer 1";
	std::string writer2 = "Writer 2";
	// ������ ���������� ��������
	int iterations = 10;
	// ��������� ��������� ������� ������
	for (int i = 0; i < iterations; ++i) {
		// ��������� ������� ��������, ����� �������� ����� ������
		int randomWriter = rand() % 2;

		// ����� � ���� � ����������� �� ���������� ������
		if (randomWriter == 0) {
			writeToLogFile(logFile, writer1);
		}
		else {
			writeToLogFile(logFile, writer2);
		}
	}
	// ��������� �������� ��������� ����
	logFile->close();

	std::cout << "Writing to file completed successfully!" << std::endl;
	//�������� ����� �������� ��������� ������� ��������� ������ �� "���������" �������� � ����
	//���� �������
	/***************************************************************/
	{
		cout << "\t Chapter 2 ver2: " << endl;
		std::string file("file.txt");
		// ������� ������ shared_ptr, ������� ����� ��������� �������� ������,
		// � �������� ��� ������������� ��������� �� ����� ������ ofstream, ����������� ��������� ����
		std::shared_ptr<std::ofstream> sh1(new std::ofstream(file), Delete(file));
		// ���������� ����� "text1" � ����, ��������� ������������� ��������� sh1
		*sh1 << "sh1" << std::endl;
		// ������� ����� shared_ptr sh2, ����������� �� ��� �� �������� ����
		auto sh2 = sh1;
		// ���������� ����� "text2" � ����, ��������� ������������� ��������� sh2
		*sh2 << "sh2" << std::endl; 
		// ������� ����� shared_ptr sh3, ����������� �� ��� �� �������� ����
		auto sh3 = sh2;
		// ���������� ����� "text3" � ����, ��������� ������������� ��������� sh3
		*sh3 << "sh3" << std::endl; 
		// sh1, sh2 � sh3 ������� �� ������� ���������, ���������� ���������������� ������� ��������
	} 
	// �������������� ����� ofstream ��������
	// ������ ������: ������������� ������������ ����������� ofstream
	{
		std::cout << "\t Chapter 2 (local ofstream): " << std::endl;
		std::string file("file_locgal.txt");
		// ������� ������ ofstream � ���������� � ����
		std::ofstream ofs(file);

		ofs << "sh1" << std::endl;
		ofs << "sh2" << std::endl;
		ofs << "sh3" << std::endl;
		
	}


	}//�������� �����??? �������������� ������������ �������� (�������� �����) ��� ������ �� ������� ���������
	/***************************************************************/
	//������� 3.
	{
		//��� ������ ��������� ���� string
		//�� ���������� ��������� ������ ������ ������������ � ������������ ����������.
		//��������� ���������� ��������������� �������� �) ��� ����������� � �) ��� ��������� �������
		//��������� � �������!
		//� std::set "����������" �� �������� ������� ��� �����, ������� �������� ������ ����� 
		/******************************************************************************************/
		//� std::vector "����������" ������� ��� �����, ������� �������� ������ ����� 
		//������� �� �����
		//������� �����
		//std::vector<std::shared_ptr < std::string>>
		//���� "����������" ������� ��� �����, ������� �� �������� �� �������� ����, �� �������� ����
		//� ������ �������
		cout << "\t ************** " << endl;
		cout << "\t Chapter 3: " << endl;

		std::string strings[] = { "qwerty", "abc", "123", "321", "#$%" };
		const size_t size = sizeof(strings) / sizeof(strings[0]);

		// ������� ������ ���������� �� ������ � �������������� shared_ptr
		std::vector<std::shared_ptr<std::string>> stringPtrs;
		for (size_t i = 0; i < size; i++) {
			stringPtrs.push_back(std::shared_ptr<std::string>(&strings[i], [](std::string*){}));
		}

		//std::set<std::shared_ptr<std::string>> letters; 
		std::vector<std::shared_ptr<std::string>> digits; 
		std::vector<std::shared_ptr<std::string>> nan;

		auto sort = [](const std::shared_ptr<std::string>& a, 
			const std::shared_ptr<std::string>& b) 
			{return *a < *b; }; 

		std::set<std::shared_ptr<std::string>, decltype(sort)> letters(sort);

		for (auto it = stringPtrs.cbegin(); it != stringPtrs.cend(); ++it) {
			if (isDigit(**it)) {
				digits.push_back(*it);
			}
			if (isLetter(**it)) {
				letters.insert(*it);
			}
			if (isOther(**it)) {
				nan.push_back(*it);
			}
			
		}
		std::cout << "Digits:  ";
		printContainer(digits);
		std::cout << "Letters:  ";
		printContainer(letters);
		std::cout << "NaN:  ";
		printContainer(nan);
		size_t sum = 0;
		for (const std::shared_ptr<std::string>& st : digits) {
			sum += stoi(*st);
		}
		std::cout << "Sum= " << sum << "\n";

	}
	/******************************************************************************************/
	//������� 4. 
	{
	//����:
		cout << "\t ************** " << endl;
		cout << "\t Chapter 4: " << endl;
		std::string ar[] = { "my","Hello", "World" };
		std::vector < std::shared_ptr<std::string>> v = { std::make_shared<std::string>("good"), std::make_shared<std::string>("bye") };

	//�) ��������� �������� � ������ ������� ��� ��������� �������, �� ������� �������� �������! 
		// ��������� � ������ ������� ��� ��������� �������, �� ������� �������� �������
		int a;
		a = 1;
		auto lm = [&a](string* ptr) {};

		class functor {
		private:
			int &a;
		public:
			functor() = default;
			functor(int& a) : a(a) { };
				//this->a = a;
			//};
			void operator()(string* ptr) const {};
		};


		for (int i = 0; i < std::size(ar); ++i)
			v.push_back(std::shared_ptr<std::string>(&ar[i], lm));





	//�) ������������� ������ �� �������� � ������� �� �����
		// ��������� ������ �� ��������
		std::sort(v.begin(), v.end(), 
			[](const std::shared_ptr<std::string>& a, const std::shared_ptr<std::string>& b) {
			return *a < *b;
			});
		for (const auto& element : v) {
			std::cout << *element << " ";
		}
		std::cout << std::endl;

		//�) ���������� ���������� ������������ ������
		// ������� ��������������� ������ �� �����
		std::cout << "Sorted Vector:" << std::endl;
		for (const auto& ptr : v) {
			std::cout << *ptr << std::endl;
		}
		v.clear();
		
	}
	/***************************************************************/
		//������� 5. shared_ptr � weak_ptr
		//������� ��������������� ������ ����������� ������ human. � ������ ��������:
		//��� - string
		//�������� �������: ��� ��� ��� ���...
		//�������� - shared_ptr (�������� �� ������ ��������...)
		//���� - ��������� �� weak_ptr (����� �������� ����������� ������������)
		//������ ������ human:
		//����������� - ��� ������������� ����� � ��������
		//����������� �����������, �������� ������������, move ???
		//����������� ����� child() - 
		//				������ ������� ������� � ������� ������� ��� ����������� ��������
		//				+ ������������ ��� ����� ������� � ���������� � ��������
		//������ ����������� ����������� ��������������� ������ ��� ���������� ����������

	{
		//������� ������ � ����-�� ���������� => "����-���� ��� �� ����, ��������, ���� � ���"
		//(�� ���� �� ����� ���� ��� ���� � ��� ����):
		//std::shared_ptr<human> grandM1(new human("Eva"));
		//...
		//� ��� ��������� ���� - child():
		//� � ����� � ���� ������� ���� ����:
		//...

		// ������� "����" � "����" - ������ �������
		cout << "\t ************** " << endl;
		cout << "\t Chapter 5: " << endl;
		shared_ptr<human> Adam(new human("����", false));
		shared_ptr<human> Eva(new human("���"));

		// ������� �� �������
		shared_ptr<human> child1 = human::child("�����", Adam, Eva);
		shared_ptr<human> child2 = human::child("����", Adam, Eva);
		shared_ptr<human> child3 = human::child("���", Adam, Eva);

		shared_ptr<human> Enoh = human::child("����", child3, nullptr);
		shared_ptr<human> Noeh = human::child("���", Enoh, nullptr);
		shared_ptr<human> Sim = human::child("���", Noeh, nullptr);
		shared_ptr<human> Avraam = human::child("������", Sim, nullptr);

		shared_ptr<human> Sara(new human("����"));
		shared_ptr<human> Iisaak = human::child("�����", Avraam, Sara);

		// �������� ��������������� ������ ��� �������
		cout << "���� ������ ���, ���� ����; � ��� ������,\n"
			"� ������ �����, � �������: ��������� � �������� �� �������.\n"
			"� ��� ������ ����� ���, �����. � ��� ����� ������� ����, \n"
			"� ���� ��� ����������� (���.4: 1-2)." << endl;

		Adam->printFamilyTree();

	}

	return 0;
};
