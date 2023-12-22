
/*************************************************************
	������������ ������� �2 ���� �110. �������.
	"������" ��������� ������� ����������� ����������
	��������� �� �������

*************************************************************/
#include <iostream>
#include <tchar.h>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"

typedef const char* (*StringFunction)();

int _tmain()
{
#if 0;
	//������� 1. 
	//������� � �������� ���������� �������.
	//�������� ��� �������� ������� ������ ���������
	//1. ����������� ���������� �������
	//int ar[N][M]; //��������� - ��� � ��� ������ ���� ������ N � M

	//���������:
	// ������ �������� ��������� ������� ����� ���� � ������� ������ �������������, 
	// ���� � ������� ���� 
	// 
	//����� ������� PrintArray   ����� ��������� ���:

//	PrintArray(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);  //�����! ������ ��������- ��� ���������� (!) �������


	//2. ������������� ���������� ������� (��� ����������� �����������)
	//���������:
	// ������ �������� ��������� ������� ����� � ������� ���� 
	int builtInArray[N][M] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

	int builtInArray2[][M] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15,16};

	// ����� ������� ��� ����������� ���������� �������
	std::cout << "Printing Built-in Array:" << std::endl;
	printBuiltInArray(builtInArray2);

	// ��������� � ���������� ������������� �������
	int dynamicRows = 2;
	int dynamicCols = 3;
	int** dynamicArray = new int* [dynamicRows];
	for (int i = 0; i < dynamicRows; ++i) {
		dynamicArray[i] = new int[dynamicCols];
		for (int j = 0; j < dynamicCols; ++j) {
			dynamicArray[i][j] = i * dynamicCols + j + 1;
		}
	}

	// ����� ������� ��� ������������� ���������� �������
	std::cout << "\nPrinting Dynamic Array:" << std::endl;
	printDynamicArray(dynamicArray, dynamicRows, dynamicCols);

	// ������������ ������ ��� ������������� �������
	for (int i = 0; i < dynamicRows; ++i) {
		delete[] dynamicArray[i];
	}
	delete[] dynamicArray;

#endif;
#if 0;

	/////////////////////////////////////////////////////////////////////////////
		//������� 2.
		//�������� ����� ����������� ���������� ������� � �������� ��������� �������.
				//�������� ��� ����������������� ���� ����� �������:
				//1.  ... DayOfYear(...)
				//- ����������� ���� ������ (�����,����� � ��� �������� � �������� ����������)
				//� ���������� ���� ����(������������ ��������)
				//2. ... DayOfMonth(...) - ������� ����������� ���������� ���� ���� � ���� ������
				// (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
				// ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)

				//� �������� ���������� ��� �������� ��������� "���������� - ������������" ���.
				//��� �������� "������������" ���� ����� ����� ������� ������� (isLeepYear)
				//��� ����� ������������ � ������ ������� � �������� ������ �� ���������� ����������
				//������ ������������ ���� ����������� ������� nDayTab

		//��������� ����������������� ����� ������� � ������� ���������� ���������:

		//����� ������� DayOfYear   ����� ��������� ���:

		//size_t day = ..., month = ..., year = ...;
		//size_t numDay = DayOfYear(day, month, year, nDayTab);  //�����! ��������� ��������- ��� ���������� (!) �������


		//�������� ���������� �������� �������� DayOfMonth        //�����! ��������� ��������- ��� ���������� (!) �������
		//...

	//size_t day = 10, month = 2, year = 2023;
	size_t day = 12, month = 12, year = 2000;
	size_t numDay = DayOfYear(day, month, year, nDayTab);

	// ����� ������� DayOfYear
	std::cout << "Day of Year: " << numDay << std::endl;

	size_t resultDay, resultMonth;

	// �������� ���������� �������� �������� DayOfMonth
	DayOfMonth(numDay, year, resultDay, resultMonth, nDayTab);
	std::cout << "Day of Month: " << resultDay << ", Month: " << resultMonth << std::endl;

#endif;
#if 1;
	/////////////////////////////////////////////////////////////////////////////
//������� 3.
	//������� 3�. ������� � ���������� ������ ����������.
	//�������� ������� (���� ��������� VarArgs, �� ������������
	// �������), ������� ��������� ���������� ����� ����������
	// ���� int � ������� �� ������ ����� �������� ���������� �
	// �� ��������.
	// ��������� ����� ������ �������� ������� ��������.

	int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
	VarArgs(nN1,0);
	VarArgs(nN1,nN2,0);
	VarArgs(nN1,nN2,nN3,nN4,nN5,0);



	//������� 3�. ������������� ������� 3� � ������� ��������
	// va_start, va_arg, va_end

	VarArgs_1(nN1, nN2, nN3, nN4, nN5, 0);

#endif;
#if 0;
	///////////////////////////////////////////////////////////////////
	//���� "������" ��������� ������� ����������� ����������
	//������� 4.1 � ������� ������� scanf ����������� ��� ������������: A,B,C


	//������� 4.2. �������� ������� �������� y=A*x*x + B*x + C
	//��� ��������� x � ��������� -2 �� +2 � ����� 0.5

	double A, B, C;

	// ������� 4.1: ���� ������������� A, B � C
	inputCoefficients(A, B, C);

	// ������� 4.2: ����� ������� ��������
	printTable(A, B, C);


#endif;
#if 1;
	///////////////////////////////////////////////////////////////////
	//���� ��������� �� �������

	//������� 5. ��������� �� �������. "�����������".
	//�������� �������:
	//1)Sum - ��������� ��� �������� double � ���������� �����
	//���� ��������
	//2)Sub- ��������� ��� �������� double � ���������� ��������
	//���� ��������
	//3)Mul - *
	//4)Div - /
	//5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
	//		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
	//		��������� 2: ����������� ���������� ������������� ��������� �������������
	//		��������� ���� �������, � ��� ����������� ������������ ��������� �� 
	//		double pow(double, double);

	//������������ ������������	��������� �����������:
	//���� ������������ ����� ������������ �������� ������ ������������,
	//�� ����� ������� ��� �������� � ���� ��������
	//� �� �������� ���������. ��������� ��������� ����������� ������
	//��������������� ����� ������� �� ���������.
	//������������� ����������� ����� ������������������ ����� ��������

	char operation;
	double operand1, operand2;
	double result;


	double (*operationFunction)(double, double) = nullptr;

	do {
		std::cout << "Enter two values and an operation (+, -, *, /, ^): ";
		std::cin >> operand1 >> operand2 >> operation;


		switch (operation) {
		case '+':
			operationFunction = &Sum;
			break;
		case '-':
			operationFunction = &Sub;
			break;
		case '*':
			operationFunction = &Mul;
			break;
		case '/':
			operationFunction = &Div;
			break;
		case '^':
			operationFunction = &Power;
			break;
		default:
			std::cout << "Invalid operation. Try again." << std::endl;
			continue;
		}


		result = operationFunction(operand1, operand2);

		std::cout << "Result: " << result << std::endl;

		std::cout << "Do you want to continue? (y/n): ";
		char choice;
		std::cin >> choice;
		if (choice != 'y' && choice != 'Y') {
			break;
		}
	} while (true);


#endif;
#if 1;
	///////////////////////////////////////////////////////////////////
		//������� 6. ��������� �� ������� � �������� ���������.
		//���� ��������� ������� ���������� ����� �������� - Sort.
		//������� ��������� ��������� ���������:
		//1) ��������� �� ������ ����������� �������
		//2) ���������� ����������� ���������
		//3) ������ �������� � ������
		//4) ��������� �� ������� ������������ ���������
		//5) ��������� �� ������� ��������� ���������

		//6a. �������� ������� ������������ ���� ����� �������� -
		// SwapInt, ������� ��������� ��� void ��������� � 
		//������ �������� �������

		//�������� ������� ��������� ���� ����� �������� -
		// CmpInt, ������� ��������� ��� void ��������� �
		//���������� int ��������� ���������: 
		//<0 - ������ ������� ������, ��� ������
		//=0 - �����
		//>0 - ������ ������� ������, ��� ������
		/*
			int nAr[]=...	//������ ��� ����������
		*/
			int nAr[] = { 4, 2, 8, 1, 66, 5 };
			int nArSize = sizeof(nAr) / sizeof(nAr[0]);
			//������ ��������� �������
			std::cout << "Original array: ";
			for (int i = 0; i < nArSize; ++i) {
				std::cout << nAr[i] << " ";
			}
			std::cout << std::endl;
			//����� ����������
			Sort(reinterpret_cast<char*>(&nAr[0]), nArSize, sizeof(int), SwapInt, CmpInt);
			//������ ����������� ����������
			std::cout << "Sorted array: ";
			for (int i = 0; i < nArSize; ++i) {
				std::cout << nAr[i] << " ";
			}
			std::cout << std::endl;

		/*
		//������� 6�. �� �������� � 6� �������� ���������������
		//������� - SwapDouble � CmpDouble � �������� ������� Sort
		//��� ���������� ������� ������������ ��������.
		*/
			double dAr[] = { 4.2, 2.1, 8.5, 1.7, 6.3 };
			int dArSize = sizeof(dAr) / sizeof(dAr[0]);

			std::cout << "\nOriginal double array: ";
			for (int i = 0; i < dArSize; ++i) {
				std::cout << dAr[i] << " ";
			}
			std::cout << std::endl;

			Sort(reinterpret_cast<char*>(&dAr[0]), dArSize, sizeof(double), SwapDouble, CmpDouble);

			std::cout << "Sorted double array: ";
			for (int i = 0; i < dArSize; ++i) {
				std::cout << dAr[i] << " ";
			}
			std::cout << std::endl;


		/*
		//������� 6�*. �� �������� � 6� �������� ���������������
		//������� - SwapStr � CmpStr � �������� ������� Sort
		//��� ���������� ������� ���������� �� ������.
		*/

		const char* arStr[] = { "QQQ", "SDF", "ABC", "Abba", "ENFR", "En" };
		std::cout << "\nOriginal string array: ";
		for (const char* str : arStr) {
			std::cout << str << " ";
		}
		std::cout << std::endl;


		Sort(reinterpret_cast<char*>(&arStr[0]), 6, sizeof(const char*), SwapStr, CmpStr);


		std::cout << "Sorted string array: ";
		for (const char* str : arStr) {
			std::cout << str << " ";
		}
		std::cout << std::endl;


		//���������:

		//� ������� ������� ����� ������ �����, ���� �������� ����� �������,
		//	Sort(reinterpret_cast<char*>(&arStr[0])), nTotal, sizeof(???), SwapStr, CmpStr);
		
#endif;
#if 0;
	///////////////////////////////////////////////////////////////////
		/*
		//������� 7. ������� ���������� �� �������.
		//�������� ��������� ������� ����
		//const char* GetString1();
		//const char* GetString2();
		//const char* GetString3();
		//const char* GetString4();
		//const char* GetString5();
		*/
	
		//		...., ������ �� ������� ���������� ��������� �� ���� ������
		//(��������� - ����� ����� �� ������ ����� ���������� �� �������)

		// ��� ������������ ��� ���� �������.
		//���������:
		//1) ��� �� ��� ���������, ���� ���, �� ��� ��������� ��������������
		//2) ����� ���� ��������� �����-�� �������������� ��������

		//�������� � ������������������ ������ ���������� �� �������
		//GetString1,GetString2...
		//������� ����� �������, ������� �� ������ �������:
			int n;
		//�������� �������
		//������������ ���������
		StringFunction stringFunctions[] = {
			GetString1,
			GetString2,
			GetString3,
			GetString4,
			GetString5
		};


	std::cout << "Enter the number of the function you want to call (1-5): ";
	std::cin >> n;


	if (n < 1 || n > 5) {
		std::cout << "Invalid input. Exiting." << std::endl;
		return 1;
	}


	const char* result = stringFunctions[n - 1]();


	std::cout << "Result: " << result << std::endl;

#endif;
	return 0;
}
