#include <string>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <iterator>
#include <memory>

#include "T.h"
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <array>
#include <stack>
#include <queue>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
//������� 1. ���������� ���������� ���������� � ������� constexpr-�������.
//
//���������/�����������: 
//		- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>; (����!)
//		- �� ��� ��������� ����� �������� ����� ������ constexpr � �������, � ��������� �����������
//		  ����� 
//		- ���� �������� ����������� constexpr- ������� - ��� ���������, ���������� �������� ���������
//		  �� ����� ����������

//��������� ��� ����, ��� ���������� ��������� �������� �� ����� ���������� 
// (���� � �������� ��������� ������������ ���������, ��������� ����������� �� ����� ����������).
//	��� �������� ���������� ������� ���������� ������ � ������������, �����������
//	����������� constexpr-�������:
	{	
		cout << endl << "Chapter 1: " << endl;
		// ������� ������������� constexpr-������� ��� ���������� ����������
		// �������� ����������� ������� � ������������, ����������� constexpr-��������
		int ar[factorial(3)];

		// ���������� ���������� �� ����� ���������� � ���������� ���������� � ���������
		constexpr int n = factorial(5); 
		// �������� ����������� ������� � ����������� ��������� �����������
		int ar1[n];

		// �������� ���������� ���������� ��� ���������� m � ������� constexpr-�������
		const int m = 7;
		constexpr int n1 = factorial(m);
		int ar2[n1];

		// ���������� ������������ ���������� constexpr-������� ���������� ��� ������������� � ��������
		constexpr int n2 = factorial(m);
	} 

	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 2a. ������� � ������� ����������������� �������� �� ��������� ������������� ����������
	//� ��������, ��������: ������ "100000000" -> � �������� 256
	//��������� ��������� ����������� �������� 0b
	//����� ����� ����������������� �������� �������� ������ � �������, ��������: 100000000_b
	//������� ������������ ���������������� ������� � ������������ ���������� - const char*

	//��� ��� ���� ���� � ���������, ������� ��������� �������� �� ����� ����������
	// => ���������� ���������������� ������� ����������� constexpr - �������
	//���������/�����������: 
	//		- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>;
	//		- �� ��� ��������� ����� �������� ����� ������ constexpr � �������,
	//		- ������� ����� ���� ����������� (���� �������� ����� ������� - ��� ���������,
	//		  ���������� �������� ��������� ������ ����������� ������� �� ����� ����������)

	{
		cout << endl << "Chapter 2a: " << endl;
		constexpr int num = "100000000"_b;

		std::cout << "Decimal: " << num << std::endl;
		std::cout << "Binary prefix: " << std::hex << "0b" << num << std::endl;

	}

	//������� 2b. ������� � ��������� �������� �������������, ��������: 256 -> "0b100000000"
	//��� ��� ������ ����� ���� ����� �����, �������� � ����� ���������� ������ std::string
	//=> ������������ �������� �� ����� ���� constexpr!
	//���������: ������������ std::bin ���� ��� => �������������� � �������� ������
	//�������� ������ �������
	//���������: ���������� �������� � ����� ���������� ��������� CHAR_BIT - <cstdint>

	{
		cout << endl << "Chapter 2b: " << endl;
		string sBin = 256_toBinStr;
		std::cout << sBin << std::endl;
	}


	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 3. constexpr - ������� 
	//������� ����� (������ ������?) ��� �������� � ��������������� ���������� ��������.
	//� ������ ������ ����:
	//	���������� ��� �������� ������������ � ������������� ��������,
	//	������ ��� ��������� ������� �� ��������
	//	����� ��� �������� - �������� �� ��������� �������� � ��������
	//	�����, ������� �������� ����� �������� ������� ���� � ��������� �������������� ��������:
	//							���� ����������� ���������, �� ��� � ����������
	//							���� ������ ������������ ��������, ���������� �����������
	//							���� ������ ������������� ��������, ���������� ������������

	//��������� ��� ����, ��� ���������� ��������� �������� �� ����� ����������. 

	{
		cout << endl << "Chapter 3: " << endl;
		constexpr Range<int> intRange(0, 100);

		constexpr int minValue = intRange.getMin();
		constexpr int maxValue = intRange.getMax();
		constexpr bool inRange = intRange.isInRange(50);
		constexpr int clampedValue = intRange.clamp(150);

		std::cout << "Min value: " << minValue << std::endl;
		std::cout << "Max value: " << maxValue << std::endl;
		std::cout << "Is 50 in range: " << std::boolalpha << inRange << std::endl;
		std::cout << "Clamped value of 150: " << clampedValue << std::endl;


	}
	/***************************************************************/
//������� 4.
	/*
	���������� ������ ������� ��� ������ ����� ������������������� (vector, list, deque, set � ����������� �������), ������� ����� ���������:
	�	��� ������� ������ ����,
	�	��� � ��������� �� ������� ������ ���� (��������� ������������� ����������� => � ���� ������ ������� �������� �������� �� ������)
	���������: if constexpr
	*/
	{
		cout << endl << "Chapter 4: " << endl;
		vector<int> vec = { 1, 2, 3, 4, 5 };
		list<double> lst = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		deque<std::string> deq = { "one", "two", "three" };
		set<char> st = { 'a', 'b', 'c' };
		array<float, 3> arr = { 1.1f, 2.2f, 3.3f };
		int arr2[] = { 1, 2, 3, 4, 5 };

		printSequence(vec);
		printSequence(lst);
		printSequence(deq);
		printSequence(st);
		printSequence(arr);
		printSequence(arr2);
	}
	/***************************************************************/
	//������� 5.
		/* ���������� ������ ������� �������� ���� ��������.
		���� ������ ��������� �������� ��������, �� ��� �������� ������� ����� ��������� 
		�� �������� ������� ���������. 
		��� ���� �������� ������� � ������ �������� ������ ���� ������ � ���� �� ����.
		���������: if constexpr, is_same
		*/
	{
		cout << endl << "Chapter 5: " << endl;
		std::vector<int> vec = { 1, 2, 3, 4, 5 };
		int scalar = 10;

		auto result_vec = add(vec, scalar);
		for (auto element : result_vec) {
			std::cout << element << " ";
		}
		std::cout << std::endl;

		int x = 5, y = 7;
		auto result_scalar = add(x, y);
		std::cout << result_scalar << std::endl;
	}


	/***************************************************************/
//������� 6.
	/* 	���������� ������ ������� ������ �� ������ �������� ��������� ������ �������� (stack, queue, priority_queue)
	���������: if constexpr, is_same
	������������� ����� ��������, ���� � �������� �������� ���������.
	*/
	{
		std::stack<int> intStack;
		intStack.push(1);
		intStack.push(2);
		intStack.push(3);
		std::cout << "Stack: ";
		printAdapter(intStack);

		std::queue<double> doubleQueue;
		doubleQueue.push(1.1);
		doubleQueue.push(2.2);
		doubleQueue.push(3.3);
		std::cout << "Queue: ";
		printAdapter(doubleQueue);
	}

	/***************************************************************/
//������� 7.
	/* 	���������� ������ constexpr ������� Smth(), ������� ������ ���������� �������� ������� ����
	���������: constexpr, if constexpr
	*/
	//constexpr int res1 = /*<����� Smth()>;*/ //res1 = 1
	//constexpr double res2 = /*<����� Smth()>; */ //res2 = 2.2
	//  /*constexpr???*/ std::string res3 = /*<����� Smth()>; */ //res3 = "abc"


	//***************************************************************/
	//������� 8.

		/*���������������� deduction guide � ��� ������ ����� ���������� �������
		����� ������ ������, ������� ������������� ���������� ������������ ������ ���������
		����������� � ���������� ������ ����. */
		/*
		template<typename T, size_t size> class MyArray
			{
				T ar[size]; //��� ���������� ������������� ��������� �������� ���� �� ��������� �����?
				�
				public:
				MyArray(const T*[, �������� ������ ���������]);


			};

		*/
		/*
		//��������� ���������� ����������������� ����������� �������� �������������.
			{
				MyArray<int, 5> ar1;//MyArray<int,5>
MyArray<char, 5> ar2{"ABCqwerty"};//MyArray<char,5>

				MyArray ar3{"ABC"}; //MyArray<char,4>

int ar[] = { 1,2,3 };
				MyArray ar4{ ar };

			}
		*/


}
