#include <string>       
#include <iostream>   
#include <cstdint>      
#include <algorithm>    
#include <iterator>     
#include <memory>      
#include <bitset>       

#include <vector>       
#include <list>         
#include <deque>       
#include <set>          
#include <array>        
#include <type_traits>  

#include <stack>        
#include <queue>       

#include "MyArray.h"
#include "print.h"
#include "Range.h"

using namespace std;


//������� 1 
constexpr int factorial(int n) {
	// ������� ��� ���������� ���������� ����� n
	return (n <= 1) ? 1 : (n * factorial(n - 1));
}

//������� 2a.
constexpr int operator "" _b(const char* str, size_t) {
	int result = 0;   // ������������� ���������� ��� �������� ����������
	// ����, ������� ��������� �� ������� ������� ������.
	// ������ ����� ���������� ��������� ����� ����� ������ ���������, 
	// � ����� ���������� ������ ����, ������������ ����� ��������� ������� '0' 
	// �� �������� ������� ������.
	while (*str) {    // ���� �� ��������� ����� ������
		result = (result << 1) + (*str++ - '0');  // ��������� ����� ����� �� 1 � ���������� ������ ����
	}
	return result;    // ����������� ����������
}
// �������� 1:
// result = (0 << 1) + (0 - '0') = 0 + 0 = 0
// ������ ���������� "0000101"
// �������� 2:
// result = (0 << 1) + (0 - '0') = 0 + 0 = 0
// ������ ���������� "000101"
// �������� 5:
// result = (0 << 1) + (0 - '0') = 0 + 0 = 0
// ������ ���������� "101"
// �������� 6:
// result = (0 << 1) + (1 - '0') = 0 + 1 = 1
// ������ ���������� "01"
// �������� 7:  ����� �� 1 ������ (������������ ��������� �� 2)
// result = (1 << 1) + (0 - '0') = 2 + 0 = 2
// ������ ���������� "1"
// �������� 8: ����� �� 1 ������ (������������ ��������� �� 2)
// result = (2 << 1) + (1 - '0') = 4 + 1 = 5
// ������ ���������� ""

// 
// ������� 2b.
std::string operator""_toBinStr(unsigned long long num) {
	const int num_bits = sizeof(int) * CHAR_BIT; // ���������� ���������� ��� � ����� �����
	// ����� ������� ��������� ������������� ��������� ������� "0b"
	std::string str = "0b";
	for (int i = num_bits - 1; i >= 0; --i)
		// �������� ��� �� ������� i � ��������� ��� � ������
		str.push_back(((num >> i) & 1) == 1 ? '1' : '0');

	return str;
}

//������� 5
template<typename T1, typename T2>
auto add(T1 a, T2 b) {
	// ������� ��� �������� ���� �������� ��� ����������� ������� � ������� �������� �������

	if constexpr (std::is_same<T1, std::vector<T2>>::value) {
		// ���� ������ �������� �������� �������� � ���������� ���� T2
		for (auto& element : a) {     // ������� ���� ��������� �������
			element += b;             // ���������� ������� ��������� � ������� �������� �������
		}
		return a;   // ����������� ����������� �������
	}
	else {
		return a + b;   // ����������� ���������� �������� ���� ��������
	}
}

//������� 7 
template <typename T>
constexpr auto Smth() {
	// �������, ������������ ������ �������� � ����������� �� ���� T

	if constexpr (std::is_same_v<T, int>) {
		return 1;                        // ���� T - int, ���������� ������������� �������� 1
	}
	else if constexpr (std::is_same_v<T, double>) {
		return 2.2;                      // ���� T - double, ���������� ������������ �������� 2.2
	}
	else if constexpr (std::is_same_v<T, std::string>) {
		return "string_value";           // ���� T - std::string, ���������� ��������� �������� "string_value"
	}
}


int main() {
	//////////////////////////////////////////////////////////////////////////////////////////////
		//������� 1. ���������� ���������� ���������� � ������� constexpr-�������.
		//
		//���������/�����������: 
		//		- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>; (����!)
		//		- �� ��� ��������� ����� �������� ����� ������ constexpr � �������, � ��������� �����������
		//		  ����� 
		//		- ���� �������� ����������� constexpr- ������� - ��� ���������, ���������� �������� ���������
		//		  �� ����� ����������

		//��������� ��� ����, ��� ���������� ��������� �������� �� ����� ���������� (���� � ��������
		//				��������� ������������ ���������, ��������� ����������� �� ����� ����������).
		//				��� �������� ���������� ������� ���������� ������ � ������������, �����������
		//				����������� constexpr-�������:

	{	//��������:
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
		int num = "000000101"_b;  // ����������� �������� ������ � �����
		std::cout << "Decimal: " << num << std::endl;  // ����� ����� � ���������� ������� ���������
		std::cout << "Binary prefix: " << std::hex << "0b" << num << std::endl;  // ����� ����� � �������� ������� ��������� � ��������� "0b"
	}
	//������� 2b. ������� � ��������� �������� �������������, ��������: 256 -> "0b100000000"
	//��� ��� ������ ����� ���� ����� �����, �������� � ����� ���������� ������ std::string
	//=> ������������ �������� �� ����� ���� constexpr!
	//���������: ������������ std::bin ���� ��� => �������������� � �������� ������
	//�������� ������ �������
	//���������: ���������� �������� � ����� ���������� ��������� CHAR_BIT - <cstdint>
	{
		cout << endl << "Chapter 2b: " << endl;
		std::string sBin = 256_toBinStr;  // ����������� ����� 256 � ��� �������� ������������� � ���� ������
		std::cout << sBin << std::endl;   // ����� ��������� ������������� ����� 256

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
		constexpr Range<int> intRange(0,100);   // �������� ������� ������ Range � ���������� �� 0 �� 100 ��� ���� int

		constexpr int minValue = intRange.getMin();   // ��������� ������������ �������� �� ���������
		constexpr int maxValue = intRange.getMax();   // ��������� ������������� �������� �� ���������
		constexpr bool inRange = intRange.isInRange(50);   // ��������, ��������� �� �������� 50 � ���������
		constexpr int clampedValue = intRange.clamp(150);  // "�������" �������� 150 � �������� ���������

		std::cout << "Min value: " << minValue << std::endl;   // ����� ������������ �������� ���������
		std::cout << "Max value: " << maxValue << std::endl;   // ����� ������������� �������� ���������
		std::cout << "Is 50 in range: " << std::boolalpha << inRange << std::endl;  // ����� ���������� �������� �� �������������� �������� 50 ���������
		std::cout << "Clamped value of 150: " << clampedValue << std::endl;   // ����� "��������" �������� 150 � �������� ���������
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
		vector<int> vec = { 1, 2, 3, 4, 5 };                         // �������� ������� � ������ �������
		list<double> lst = { 1.1, 2.2, 3.3, 4.4, 5.5 };              // �������� ����������� ������ � ������������� �������
		deque<std::string> deq = { "one", "two", "three" };          // �������� ���� �� ��������
		set<char> st = { 'a', 'b', 'c' };                            // �������� ��������� ��������
		array<float, 3> arr = { 1.1f, 2.2f, 3.3f };                 // �������� ������� � ������������� �������
		int arr2[] = { 1, 2, 3, 4, 5 };                              // �������� �������� ������� � ������ �������

		printSequence(vec);                                         // ����� ��������� �������
		printSequence(lst);                                         // ����� ��������� ������
		printSequence(deq);                                         // ����� ��������� ����
		printSequence(st);                                          // ����� ��������� ���������
		printSequence(arr);                                         // ����� ��������� �������
		printSequence(arr2);                                        // ����� ��������� �������� �������

	}
	/***************************************************************/
	//������� 5.
		/* ���������� ������ ������� �������� ���� ��������.
		���� ������ ��������� �������� ��������, �� ��� �������� ������� ����� ��������� �� �������� ������� ���������. ��� ���� �������� ������� � ������ �������� ������ ���� ������ � ���� �� ����.
		���������: if constexpr, is_same
		*/
	{
		cout << endl << "Chapter 5: " << endl;
		std::vector<int> vec = { 1, 2, 3, 4, 5 };   // �������� ������� � ������ �������
		int scalar = 10;                            // ��������� �������� ��� ��������

		auto result_vec = add(vec, scalar);         // �������� ������� � ������ ��������� �������
		for (auto element : result_vec) {           // ������� ����������
			std::cout << element << " ";            // ����� ������� �������� ����������
		}
		std::cout << std::endl;                     // ������� �� ����� ������

		int x = 5, y = 7;                           // �������� ���� ����� �����
		auto result_scalar = add(x, y);             // �������� ���� �����
		std::cout << result_scalar << std::endl;     // ����� ���������� ��������

	}
	/***************************************************************/
//������� 6.
	/* 	���������� ������ ������� ������ �� ������ �������� ��������� ������ �������� (stack, queue, priority_queue)
	���������: if constexpr, is_same
	������������� ����� ��������, ���� � �������� �������� ���������.
	*/
	{
		cout << endl << "Chapter 6: " << endl;
		std::stack<int> intStack;              // �������� ����� � ������ �������
		intStack.push(1);                      // ���������� �������� � ����
		intStack.push(2);                      // ���������� �������� � ����
		intStack.push(3);                      // ���������� �������� � ����
		std::cout << "Stack: ";                // ����� ��������� � ���� ��������� ������
		printAdapter(intStack);                // ����� ��������� �����

		std::queue<double> doubleQueue;        // �������� ������� � ������������� �������
		doubleQueue.push(1.1);                 // ���������� �������� � �������
		doubleQueue.push(2.2);                 // ���������� �������� � �������
		doubleQueue.push(3.3);                 // ���������� �������� � �������
		std::cout << "Queue: ";                // ����� ��������� � ���� ��������� ������
		printAdapter(doubleQueue);             // ����� ��������� �������

		std::priority_queue<int> priorityQueue;
		priorityQueue.push(3);
		std::cout << "Priority Queue: ";
		printAdapter(priorityQueue);

	}
	/***************************************************************/
//������� 7.
	/* 	���������� ������ constexpr ������� Smth(), ������� ������ ���������� �������� ������� ����
	���������: constexpr, if constexpr
	*/
	//constexpr int res1 = /*<����� Smth()>;*/ //res1 = 1
	//constexpr double res2 = /*<����� Smth()>; */ //res2 = 2.2
	//  /*constexpr???*/ std::string res3 = /*<����� Smth()>; */ //res3 = "abc"
	{
		cout << endl << "Chapter 7: " << endl;
		constexpr int res1 = Smth<int>();              // ����� ������� Smth ��� ���� int
		constexpr double res2 = Smth<double>();        // ����� ������� Smth ��� ���� double
		std::string res3 = Smth<std::string>();        // ����� ������� Smth ��� ���� std::string

		std::cout << "res1: " << res1 << "\n";         // ����� ���������� ��� ���� int
		std::cout << "res2: " << res2 << "\n";         // ����� ���������� ��� ���� double
		std::cout << "res3: " << res3 << "\n";         // ����� ���������� ��� ���� std::string

	}
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
		
		//��������� ���������� ����������������� ����������� �������� �������������.
			{
				MyArray<int, 5> ar1;//MyArray<int,5>
				MyArray<char, 5> ar2{"ABCqwerty"};//MyArray<char,5>
				MyArray ar3{"ABC"}; //MyArray<char,4>
				int ar[] = { 1,2,3 };
				MyArray ar4{ ar };
			}
		
	{
		cout << endl << "Chapter 8: " << endl;
		MyArray<int, 5> ar1; //MyArray<int,5>
		MyArray<char, 5> ar2{ "ABCqwerty" };//MyArray<char,5>
		MyArray<char, 4> ar3{ "abc" };
		int ar[] = { 1,2,3 };
		MyArray<int, 3> ar4{ ar };

		ar1.print();                                             // ����� ��������� ������� MyArray ar1
		ar2.print();                                             // ����� ��������� ������� MyArray ar2
		ar3.print();                                             // ����� ��������� ������� MyArray ar3
		ar4.print();                                             // ����� ��������� ������� MyArray ar4

		std::cout << "Size of ar4: " << ar4.getSize() << std::endl;            // ����� ������� ������� MyArray ar4
		std::cout << "Element at index 1 of ar4: " << ar4[1] << std::endl;     // ����� �������� � �������� 1 ������� MyArray ar4

	}

	return 0;
}
