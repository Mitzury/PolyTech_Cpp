//����������� ���������� �������� - STL 
//���������� ����������� ���������� - vector
//���������

#include <iostream>
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

// ������������� ��������� ������� ��� ������� ���������� �� Point
void printVectorOfPointersStats(const vector<Point*>& v) {
	std::cout << "����� ���������� ��� ������� ���������� �� Point:" << std::endl;
	std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Max_size: " << v.max_size() << std::endl;
	std::cout << "���������� (� �������� ����������): ";
	for (vector<Point*>::const_iterator it = v.begin(); it != v.end(); ++it) {
		if (*it != nullptr) {
			std::cout << **it << " "; // �������������� ��������, � ����� ���������
		}
		else {
			std::cout << "null ";
		}
	}
	std::cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	// ��������� ����������� ���������� vector 
	//////////////////////////////////////////////////////////////////////
	//�������� ��������. 
	//�������� ��������� �������:
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 
	{
		// �������� ������� ������� ����� �����
		std::vector<int> vInt;
		// �������� �������
		std::cout << "Chapter 1" << std::endl;
		std::cout << "Size of vInt: " << vInt.size() << std::endl;

		//���������������� ��������� ��������, ��������� - ��� �� ���������
		//���� ���� ��������������, - ���������

		vInt.push_back(1);
		vInt.front() = 1;

		//������� ������� � front() �������� �� ���������� ������� ����� ������������, ��� ��� ������ ������:
	}
	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	//
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.

	{
		std::vector<int> myVector;

		std::cout << "Chapter 1.1" << std::endl;
		for (int i = 0; i < 10; ++i) {
			myVector.push_back(i * 2);
			printVectorInfo(myVector);
		}
	}

	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?
	// ������� ������ ������������ ����� � ��������� �������� 5

	{
		std::vector<double> vDouble1(5);
		// �������� ���������� � �������
		std::cout << "Chapter 1.2" << std::endl;
		printVectorInfo(vDouble1);
	}

	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 

	{
		std::vector<MyString> vecMyString(5, MyString("A"));

		std::cout << "Chapter 3" << std::endl;
		// �������� �������� ��������� ��������� � ������� ������� at()
		try {
			vecMyString.at(2).set("B");
			vecMyString.at(4).set("C");
			vecMyString.at(11).set("C"); // ���������� ���������� out_of_range: invalid vector subscript
			//vecMyString[11].set("X"); // ���������� ���������� out_of_range: invalid vector subscript
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
	}

	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!

	{
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

	}

	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 

	{
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
	}

	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. 
	// ����� ����������� ����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).

	{
		std::vector<Point> vPoint2(5, Point(1, 1));
		std::cout << "Chapter 5" << std::endl;
		// ������� ���������� ������� ��������
		for (const auto& point : vPoint2) {
			std::cout << "x: " << point.x << ", y: " << point.y << std::endl;
		}
	}

	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
	//�) ������������� ����� ��������� �������
	//�) ��� ���������� operator<< ��� Point*

	{
		std::cout << "Chapter 5.1" << std::endl;
		// ������� ������ ���������� �� ������� ���� Point
		std::vector<Point*> vpPoint(5);
		// ������� ������� ���� Point � ��������� ��������� �� ��� � ������
		for (int i = 0; i < 5; ++i) {
			vpPoint[i] = new Point(i + 1, i + 1);
		}
		// �������� << ���������� ��� �������� Point, ���������� ������������� ������� printVectorOfPointersStats ��� ������� ���������� �� Point:
		printVectorOfPointersStats(vpPoint);

	}


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

	{
		std::cout << "Chapter 6" << std::endl;
		std::vector<int> v1;
		std::vector<int> v2;

		v1.reserve(5); // �������������� ������ ��� 5 ���������

		/*
		������������� ������� reserve � ����������� ���������� std::vector �������������, ����� �� ������� ����� ��������� ���������� ���������,
		������� ����� ��������� � �������. �������������� ������ ��������� �������� ������ ������������� ������ ��� ���������� ��������� � ������ ������� push_back.
		��� ����� ���� �������� ������� ��� ������ � �������� �������� ������ ��� � ����������� �������� ����, ��� ������������������ ����� ��������.
		������, � ����� ���������� ������ ������������� reserve �� �������� �����������, ��� ��� �� ��������� ����� 5 ��������� � ������ �� ��������.
		std::vector ������ ����� ������ ��������� ������� � ������������� ����������� ���� ������� �� ���� �������������.
		����� �������, � ������ ������ ����� �������� ��� ������ ������ reserve.
		����� ����, ����� �������, ��� capacity() �� ����������� ����� size(). capacity() ���������� ������� ������ ���������� ������, � �� ����� ��� size() ���������� �����������
		���������� ��������� � �������.*/


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
			std::cout << elem << " " << std::endl;
		}

		std::cout << "Chapter 6.1" << std::endl;
		//!!! shrink_to_fit - ���������� ������� �������.
		//��� ������ ������� �� ����������� ������� ��������� ��������� �������
		//�� size.

		// ���������� ������� ������� v1 �� ��� �������� �������
		v1.shrink_to_fit();

		// ���������� ������� ������� v2 �� ��� �������� �������
		v2.shrink_to_fit();

		// ����� ���������� � ������� �������� ����� ����������
		std::cout << "After shrinking to fit:" << std::endl;
		std::cout << "v1.size() = " << v1.size() << ", v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v2.size() = " << v2.size() << ", v2.capacity() = " << v2.capacity() << std::endl;

	}

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

	{
		std::cout << "Chapter 7" << std::endl;
		int ar[] = { 11, 2, 4, 3, 5 };

		// ������� ������ ��������
		std::vector<std::vector<int>> vv;

		// ��������� ������ �������� � ������������ � �������� ��������
		for (size_t i = 0; i < sizeof(ar) / sizeof(ar[0]); ++i) {
			vv.push_back(std::vector<int>(i + 1, ar[i]));
		}

		// ����� ���������� ������� � ������� ��������� <<
		std::cout << vv << std::endl;
	}

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

	{
		std::cout << "Chapter 7" << std::endl;
		std::vector<char> vChar2 = { 'a', 'b', 'c' };

		insertIfNotExists(vChar2, 'a'); // ������ ���� ���������������
		insertIfNotExists(vChar2, 'q'); // ������ ���� �������� � ������

		// ������� ���������� ������� ����� �������
		printVector(vChar2); // �����: q a b c


		//���������� �������, ������� ������ ��������� ����� �������
		//����� ������ ��������� �������
		//��������� ����������������� ������� - �������� ����� ������ ��������� ������� vChar2 ����� 'W'


		insertBeforeEveryElement(vChar2, 'W'); // ��������� 'W' ����� ������ ���������
		printVector(vChar2); // �����: W q W a W b W c


		//�������� �������, ������� ������ ������� ������ ������������� ������������������.
		//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
		vector<char> vChar3 = { 'q', 'w', 'e', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3' };
		removeConsecutiveDuplicates(vChar3);
		printVector(vChar3); // �����: q w e r t y 1 2 r 3

	}

	///////////////////////////////////////////////////////////////////
	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"

	{
		std::cout << "Chapter 8" << std::endl;
		cout << "�������� �������� ������������������" << endl;
		vector<char> vChar4 = { 'q', 'w', 'e', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3' };
		removeAllDuplicates(vChar4);
		printContainer(vChar4); // ����� ������� �� ����������, ��������: "1 2 3 e q r t w y" 


		///////////////////////////////////////////////////////////////////
		//�������� ����� ������ ����� �������, ����� ��� �������� �����
		//������� ��������� ������ �� ��������� ����� ��������, �� �����������
		//���� �� � �������� �������

		std::cout << "Chapter 9" << std::endl;
		vector<char> originalVector = { 'q', 'w', 'e', 'r', 't', 'y' };
		vector<char> reversedVector(originalVector.rbegin(), originalVector.rend());
		cout << "������������ ������: ";
		printVector(originalVector); // �����: q w e r t y
		cout << "����������� ������: ";
		printVector(reversedVector); // �����: y t r e w q

	}


	///////////////////////////////////////////////////////////////////
	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()

	{
		std::list<Point> ptList1;

		//�������� ������ �������, ������� ����� �������� ��������
		//������ ���������� �� ������. ��������� ������ ������� �� �����������
		//vector � list. ��������� - �������� �� ������� ��� ����������.
		//�������� ����� �� ������� "�����������" - reverse()

		ptList1.push_back(Point(1, 1));
		ptList1.push_front(Point(2, 2));
		ptList1.insert(++ptList1.begin(), Point(3, 3));
		// ����� ��������� ptList1
		printContainer(ptList1);

		ptList1.reverse();
		std::cout << "After reversing ptList1:" << std::endl;
		printContainer(ptList1);

		//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
		//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
		//�� � �������� ������� 

		std::vector<Point> points = { Point(4, 4), Point(5, 5), Point(6, 6) };
		std::list<Point> ptList2(points.rbegin(), points.rend());
		// ����� ��������� ptList2
		printContainer(ptList2);

		//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
		//�� �����������.
		//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
		//�������� ����������

				// ���������� ������� ptList1 � ptList2 �� �����������
		ptList1.sort();
		ptList2.sort();

		// ����� ��������������� �������
		std::cout << "After sorting ptList1:" << std::endl;
		printContainer(ptList1);
		std::cout << "After sorting ptList2:" << std::endl;
		printContainer(ptList2);

		//���������� ��������������� ������ - merge(). ����������: ���
		//��� ���� ���������� � ������ �������.
		// list1 ������ �������� ������������ � ��������������� ������, � list2 ���������� ������
		ptList1.merge(ptList2);

		std::cout << "Print ptList1 after merge" << std::endl;
		printContainer(ptList1);
		std::cout << "Print ptList2 after merge" << std::endl;
		printContainer(ptList2);

	}

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?

	{
		list<int> myList = { 1, 2, 3, 4, 5 };
		myList.remove(3); // ������� ��� ��������� ����� 3 �� ������

		//���������� �������� �� ������, ���������������� ��������� �������:
		//����� �� ��������� ������������ - remove_if(). 

		list<int> myList_1 = { -1, 2, -3, 4, -5 };
		// ������� ��� �������� ������, ������� ������ ����
		myList_1.remove_if(isNegative);

		//���������� �� ������ ������ ������������� ������ - unique(). 

		list<int> myList_2 = { 1, 2, 2, 3, 3, 3, 4, 4, 5 };
		myList_2.unique(); // ������� ������ ������������� ���������, ������ ���������� {1, 2, 3, 4, 5}

	}

	///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque
	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������

	{
		std::deque<Point> pointDeque;
		// �������� ������� � ���������� ���� Point
		std::vector<Point> points_1 = { Point(1, 1), Point(2, 2), Point(3, 3) };
		pointDeque.assign(points_1.begin(), points_1.end());

		// ���������� deque ������� ��������� ������� � ������� assign
		pointDeque.assign(points_1.begin(), points_1.end());

		// ����� �������� ��������� �� ������ � ������� ������� �������
		printContainer(pointDeque);

	}

	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'
	// ������� 2: �������� ������� deque � ���������� ���� Point
	{
		std::deque<Point> pointDeque;

		// �������� ������� � ���������� ���� Point
		std::vector<Point> points_2 = { Point(1, 1), Point(2, 2), Point(3, 3) };

		// ���������� deque ������� ��������� ������� � ������� assign
		pointDeque.assign(points_2.begin(), points_2.end());

		// ����� �������� ��������� �� ������ � ������� ������� �������
		//printContainer(pointDeque, "pointDeque");

		std::deque<MyString> myDeque;

		// ���������� deque ���������� � ������� push_back(), push_front(), insert()
		myDeque.push_back(MyString("Apple"));
		myDeque.push_back(MyString("Banana"));
		myDeque.push_back(MyString("Carrot"));
		myDeque.push_front(MyString("Ant"));
		myDeque.push_front(MyString("Apricot"));
		myDeque.insert(myDeque.begin() + 2, MyString("Avocado"));

		// ����� ����������� deque
		std::cout << "Deque contents before erasing:" << std::endl;
		for (const auto& str : myDeque) {
			std::cout << str.get() << std::endl;
		}
		std::cout << std::endl;

		// �������� ��������� �� deque, � ������� ������� ���������� � 'A' ��� 'a'
		auto it = myDeque.begin();
		while (it != myDeque.end()) {
			if (it->get()[0] == 'A' || it->get()[0] == 'a') {
				it = myDeque.erase(it);
			}
			else {
				++it;
			}
		}

		// ����� ����������� deque ����� ��������
		std::cout << "Deque contents after erasing:" << std::endl;
		for (const auto& str : myDeque) {
			std::cout << str.get() << std::endl;
		}
	}
	return 0;
};