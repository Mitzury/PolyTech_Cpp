//����������� ���������� �������� - STL 
//���������� ����������� ���������� - vector
//���������

#include <vector>
#include "MyString.h"
#include "Point.h"
#include "T.h"
#include <list>
#include <deque>

#pragma warning(disable: 4786)

// ����������� ������� stop ��� ��������� ���������
#define	  stop __asm nop

using namespace std;

std::string removeRepeatingSequences(const std::string& str) {
	std::string result;

	// �������� �� ������ � ��������� � �������������� ������ ������ �������, ������� �� �������� ��������������
	for (size_t i = 0; i < str.size(); ++i) {
		// ���� ������� ������ �� ��������� � ���������� ��� ���� ��� ������ ������, ��������� ��� � ���������
		if (i == 0 || str[i] != str[i - 1]) {
			result += str[i];
		}
	}

	return result;
}

int main()
{
setlocale(LC_ALL, "Russian");
// ��������� ����������� ���������� vector 
//////////////////////////////////////////////////////////////////////
//�������� ��������. 

//�������� ��������� �������:
//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
//��� ��� ������ �������. 


	// �������� ������� ������� ����� �����
	std::vector<int> vInt;
	// �������� �������
	std::cout << "Chapter 1" << std::endl;
	std::cout << "Size of vInt: " << vInt.size() << std::endl; 
	

//���������������� ��������� ��������, ��������� - ��� �� ���������
//���� ���� ��������������, - ���������

	//vInt.front()=1;
	//������� ������� � front() �������� �� ���������� ������� ����� ������������, ��� ��� ������ ������:


//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
//size(), capacity(), max_size() � �������� �������� ���������. 
//
//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
//������� ��� "���������" � �������� ��������� �� �������.

	std::vector<int> myVector;

	std::cout << "Chapter 1.1" << std::endl;
	for (int i = 0; i < 10; ++i) {
		myVector.push_back(i * 2);
		printVectorInfo(myVector);
	}


//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
//��������� ��������� � ������� ���������� ���� �������. ��� �����
//������������������� �������� �������?

	// ������� ������ ������������ ����� � ��������� �������� 5
	std::vector<double> vDouble1(5);

	// �������� ���������� � �������
	std::cout << "Chapter 2" << std::endl;
	printVectorInfo(vDouble1);

//������ �������� ���� MyString � ��������� �������� - 5 ���������
//� �������������� ������� �������� ������� "A"
//C ������� ������� at() � ����� � ������� ���������
//�������������� []  �������� �������� �����-���� ���������.
//���������� "�����" �� ������� ������� � ������� at() �
//� ������� []. 

	
	std::vector<MyString> vecMyString(5, MyString("A"));

	std::cout << "Chapter 3" << std::endl;
	// �������� �������� ��������� ��������� � ������� ������� at()
	try {
		vecMyString.at(2).set("B");
		vecMyString.at(4).set("C");
		vecMyString.at(11).set("C");
	}
	catch (const std::out_of_range& e) {
		std::cerr << "���������� ���������� out_of_range: " << e.what() << std::endl;
	}

	// �������� �������� �������� � ������� ��������� �������������� []
	vecMyString[0].set("X");

	// ��������� ���������� � ��������� �� ��������� �������
	try {
		vecMyString.at(10).set("D");
	}
	catch (const std::out_of_range& e) {
		std::cerr << "���������� ���������� out_of_range: " << e.what() << std::endl;
	}

	// �������� �������� ���� ��������� �������
	for (const auto& elem : vecMyString) {
		std::cout << elem.get() << std::endl;
	}


//������ ������������ - vDouble3, ������� �������� ������ ���������
// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
//����� ������� � �������������������!

	std::cout << "Chapter 4" << std::endl;
	const int size = 5;
	double dMas[size];
	for (int i = 0; i < size; ++i) {
		dMas[i] = i * 1.1; // ������������ ������������� �������� �������
	}

	// ������� ������ vDouble3, ������� �������� ������ ��������� ������� dMas
	std::vector<double> vDouble3(dMas, dMas + size);

	// �������� �������� ��������� ������� vDouble3
	std::cout << "Values in vDouble3: ";
	for (const auto& elem : vDouble3) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;


//������ ������������ - vDouble4, ������� �������� ������ ���������
// [2,5) ������� vDouble3. 

	std::vector<double> vDouble3_1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	// ������� ������ vDouble4, ������� �������� ������ ��������� � ��������� �� 2 �� 4 ������� vDouble3
	std::vector<double> vDouble4(vDouble3_1.begin() + 2, vDouble3_1.begin() + 5);

	std::cout << "Chapter 4.1" << std::endl;
	// �������� �������� ��������� ������� vDouble4
	std::cout << "Values in vDouble4: ";
	for (const auto& elem : vDouble4) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;


	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).

	std::vector<Point> vPoint2(5, Point(1, 1));

	std::cout << "Chapter 5" << std::endl;
	// ������� ���������� ������� ��������
	for (const auto& point : vPoint2) {
		std::cout << "x: " << point.x << ", y: " << point.y << std::endl;
	}


//������ ���������� �� Point - vpPoint � ��������� �������� 5
//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point

//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
//�) ������������� ����� ��������� �������
//�) ��� ���������� operator<< ��� Point*
	std::cout << "Chapter 5.1" << std::endl;
	{
		// ������� ������ ���������� �� ������� ���� Point
		std::vector<Point*> vpPoint(5);

		// ������� ������� ���� Point � ��������� ��������� �� ��� � ������
		for (int i = 0; i < 5; ++i) {
			vpPoint[i] = new Point(i + 1, i + 1);
		}

		// ������� �������� ��������, �� ������� ��������� �������� �������
		for (const auto& point : vpPoint) {
			std::cout << point << std::endl;
		}

		// ����������� ������, ���������� ��� ������� Point
		for (auto& point : vpPoint) {
			delete point;
		}

	}//����� �������������� �������� ����� ����������� ��� ������ �������?


///////////////////////////////////////////////////////////////////////
//�������������� ������.
//���������, ������ �� ����� ����������� ���� ��������?
		/*
		{
		size_t n=...
		vector<int> v(n);
		v.resize(n/2);
		if(v.capacity() == n) //true?
		}
		*/
		// ��� ����������� ����� ��������, ���� ������ v ����� ������ resize(n / 2) �� �������� ���� �������. 
		// �����, ���� ������� ������� �� �������� ����� ���������� �������, �� ��� �� ������ �������������, 
		// ��� ��� ������ ����� ����������� ���� �������� � ������ ����� ������, ���� ������� �� ������� ��� ����������.

		/*
		{
		int n=...
		size_t m=...
		vector<int> v(n);
		v.reserve(m);
		if(v.capacity() == m) //true?
		}
		*/
		// ��� ����������� ����� ������, ���� ����� ������ reserve(m) ������� ������� v ������������� ����� m.

		/*
		{
		vector<int> v(3,5);
		v.resize(4,10); //��������?
		v.resize(5); //��������?
		}
		*/
		//����� ���������� ����� ����� ���� v ����� ��������� �������� [5, 5, 5, 10, 0].
		

//�������� ��� "������" ������� � ����������
//������ (�� ������ � ���� �� ����) ����. 
//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
//��� ���������� � ������� push_back.
//������ ������ ������ ��������� ���������� ����������� push_back.
//�������� ������, ������� �������� � �������� ���������

		std::cout << "Chapter 6" << std::endl;
		std::vector<int> v1;
		std::vector<int> v2;

		v1.reserve(5); // �������������� ������ ��� 5 ���������

		// ���������� ������� ������� ���������� � ������� push_back
		for (int i = 0; i < 5; ++i) {
			v1.push_back(i * 2);
		}

		// ���������� ������� ������� ���������� � ������� push_back
		for (int i = 0; i < 5; ++i) {
			v2.push_back(i * 3);
		}

		// ����� ���������� � ������ �������
		std::cout << "v1.size() = " << v1.size() << ", v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1 elements: ";
		for (const auto& elem : v1) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;

		// ����� ���������� � ������ �������
		std::cout << "v2.size() = " << v2.size() << ", v2.capacity() = " << v2.capacity() << std::endl;
		std::cout << "v2 elements: ";
		for (const auto& elem : v2) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;



		//!!! shrink_to_fit - ���������� ������� �������.
		//��� ������ ������� �� ����������� ������� ��������� ��������� �������
		//�� size.

		// ���������� ������� ������� v1 �� ��� �������� �������
		v1.shrink_to_fit();

		// ���������� ������� ������� v2 �� ��� �������� �������
		v2.shrink_to_fit();

		std::cout << "Chapter 6.1" << std::endl;
		// ����� ���������� � ������� �������� ����� ����������
		std::cout << "After shrinking to fit:" << std::endl;
		std::cout << "v1.size() = " << v1.size() << ", v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v2.size() = " << v2.size() << ", v2.capacity() = " << v2.capacity() << std::endl;


		//�������� "����������� �������" - ������� ��������
		//����� ���������� ������ int ar[] = {11,2,4,3,5};
		//�������� ������ �������� ��������� �������:
		//������ vv[0] - �������� 11 ��������� �� ��������� 11
		//vv[1] - �������� 2,2
		//vv[2] - �������� 4,4,4,4
		//...
		//������������ ���������� ������ ����������� ������� �� �������
		//� �������:

		//std::cout<<vv<<std::endl;

		std::cout << "Chapter 7" << std::endl;
		int ar[] = { 11, 2, 4, 3, 5 };

		// ������� ������ ��������
		std::vector<std::vector<int>> vv;

		// ��������� ������ �������� � ������������ � �������� ��������
		for (size_t i = 0; i < sizeof(ar) / sizeof(ar[0]); ++i) {
			vv.push_back(std::vector<int>(i + 1, ar[i]));
		}

		// ������� ���������� ���������� ������� �� �������
		for (const auto& innerVec : vv) {
			for (const auto& element : innerVec) {
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}

	stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//������� �������� ������������������ insert().
//���������� �������, ������� ������ ��������� ����� �������
//� ������ ������� ������ ��� �������, ��� � ������� ������
//�������� ��� ���.
//��������� ����������������� ������� - � ������ vChar2 �������� � ������ ������� ������ ������ ���
//�������, ��� � ������� ������ ������� ��� ���.
//��������: vChar2 - abc 
//��� ������� �������� 'a' ������� ������ ���� ���������������
//��� ������� �������� 'q' vChar2 - qabc 

//���������� �������, ������� ������ ��������� ����� �������
//����� ������ ��������� �������
//��������� ����������������� ������� - �������� ����� ������ ��������� ������� vChar2 ����� 'W'


		std::cout << "Chapter 7" << std::endl;
		std::vector<char> vChar2 = { 'a', 'b', 'c' };

		insertIfNotExists(vChar2, 'a');

		insertIfNotExists(vChar2, 'q');

		// ������� ���������� ������� ����� �������
		for (const auto& elem : vChar2) {
			std::cout << elem;
		}
		std::cout << std::endl;


///////////////////////////////////////////////////////////////////
//�������� �������, ������� ������ ������� ������ ������������� ������������������.
//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"

		std::cout << "Chapter 8" << std::endl;

		std::string input = "qwerrrrty12222r3";
		std::string result = removeRepeatingSequences(input);

		std::cout << "Before: " << input << std::endl;
		std::cout << "After: " << result << std::endl;



		stop

///////////////////////////////////////////////////////////////////

//�������� �������� ������������������ erase()
//�������� ������� �������� �� ������ ������� ���� ������ 
//��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"

		std::cout << "Chapter 9" << std::endl;
		std::vector<char> vChar = { 'q', 'w', 'e', 'r', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3' };

		// �������� ���������� �� �������
		removeDuplicates(vChar);

		// ������� ���������� ������� ����� �������� ����������
		for (const auto& elem : vChar) {
			std::cout << elem;
		}
		std::cout << std::endl;


///////////////////////////////////////////////////////////////////
//�������� ����� ������ ����� �������, ����� ��� �������� �����
//������� ��������� ������ �� ��������� ����� ��������, �� �����������
//���� �� � �������� �������

		std::cout << "Chapter 9" << std::endl;
		std::vector<int> originalVec = { 1, 2, 3, 4, 5 };
		// ������� ����� ������ � ���������� � �������� �������
		std::vector<int> reversedVec(originalVec.rbegin(), originalVec.rend());
		// ������� ���������� ������ �������
		std::cout << "Reversed vector:" << std::endl;
		for (const auto& elem : reversedVec) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;


///////////////////////////////////////////////////////////////////
//������� 1. ������. ��������, ����������� ��� �������.
//�������� ������ ������ �� ��������� Point - ptList1 � ���������
//��� ���������� � ������� ������� push_back(),
//push_front, insert()


//�������� ������ �������, ������� ����� �������� ��������
//������ ���������� �� ������. ��������� ������ ������� �� �����������
//vector � list. ��������� - �������� �� ������� ��� ����������.
//�������� ����� �� ������� "�����������" - reverse()

//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
//�� � �������� ������� 



//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
//�� �����������.
//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
//�������� ����������


stop

//���������� ��������������� ������ - merge(). ����������: ���
//��� ���� ���������� � ������ �������.

stop

//���������� �������� �� ������ - remove()
//��������� �� ������ ������� � ������������ ���������.
//���������: ��� ������ ���� ����������� � ������ Point?


//���������� �������� �� ������, ���������������� ��������� �������:
//����� �� ��������� ������������ - remove_if(). 


//���������� �� ������ ������ ������������� ������ - unique(). 

stop

///////////////////////////////////////////////////////////////////
//������� 2.������� � ����� ������� - ��������� deque

//�������� ������ deque � ���������� ���� Point. � �������
//assign ��������� deque ������� ��������� �������. � �������
//�������������� ���� � ���������� ������� �������������� �������
//�������� �������� ��������� �� ������



//�������� deque � ���������� ���� MyString. ��������� ��� ����������
//� ������� push_back(), push_front(), insert()
//� ������� erase ������� �� deque ��� ��������, � ������� �������
//���������� � 'A' ��� 'a'


		return 0;
}