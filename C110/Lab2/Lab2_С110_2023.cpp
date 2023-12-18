
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
#include <chrono>


#define	  stop __asm nop

int _tmain()
{

	//������� 1. 
	//������� � �������� ���������� �������.
	//�������� ��� �������� ������� ������ ���������
	//1. ����������� ���������� �������
	const size_t N = 3;
	const size_t M = 4;

	int ar[N][M] = 
	{
	 {1, 2, 3, 4},
	 {5, 6, 7, 8},
	 {9, 10, 11, 12}
	};


	//���������:
	// ������ �������� ��������� ������� ����� ���� � ������� ������ �������������, 
	// ���� � ������� ���� 
	// 

	void PrintArray(int(&ar)[N][M]); {
		for (size_t i = 0; i < N; ++i) {
			for (size_t j = 0; j < M; ++j) {
				std::cout << ar[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}

//2. ������������� ���������� ������� (��� ����������� �����������)



	//	PrintArray(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);  //�����! ������ ��������- ��� ���������� (!) �������


		//2. ������������� ���������� ������� (��� ����������� �����������)
		//���������:
		// ������ �������� ��������� ������� ����� � ������� ���� 


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


	int nDayTab[2][12] = {
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};


	bool isLeapYear(int year) {
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}


	size_t DayOfYear(size_t day, size_t month, size_t year, int(&nDayTab)[2][12]) {
		size_t numDay = day;

		for (size_t i = 0; i < month - 1; ++i) {
			numDay += nDayTab[isLeapYear(year)][i];
		}

		return numDay;
	}


	void DayOfMonth(size_t numDay, size_t year, int(&nDayTab)[2][12], size_t & day, size_t & month) {
		size_t i = 0;

		while (numDay > nDayTab[isLeapYear(year)][i]) {
			numDay -= nDayTab[isLeapYear(year)][i];
			++i;
		}

		month = i + 1;
		day = numDay;
	}

	size_t day = 15, month = 3, year = 2023;


	size_t numDay = DayOfYear(day, month, year, nDayTab);
	std::cout << "Day of year: " << numDay << std::endl;


	size_t resultDay, resultMonth;
	DayOfMonth(numDay, year, nDayTab, resultDay, resultMonth);
	std::cout << "Day: " << resultDay << ", Month: " << resultMonth << std::endl;

	return 0;

	//��������� ����������������� ����� ������� � ������� ���������� ���������:

	//����� ������� DayOfYear   ����� ��������� ���:

	//size_t day = ..., month = ..., year = ...;
	//size_t numDay = DayOfYear(day, month, year, nDayTab);  //�����! ��������� ��������- ��� ���������� (!) �������


	//�������� ���������� �������� �������� DayOfMonth        //�����! ��������� ��������- ��� ���������� (!) �������
	//...

	stop
		/////////////////////////////////////////////////////////////////////////////
			//������� 3.
			//������� 3�. ������� � ���������� ������ ����������.
			//�������� ������� (���� ��������� VarArgs, �� ������������
			// �������), ������� ��������� ���������� ����� ����������
			// ���� int � ������� �� ������ ����� �������� ���������� �
			// �� ��������.
			// ��������� ����� ������ �������� ������� ��������.
		/*
			int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
			VarArgs(nN1,0);
			VarArgs(nN1,nN2,0);
			VarArgs(nN1,nN2,nN3,nN4,nN5,0);
			stop


			//������� 3�. ������������� ������� 3� � ������� ��������
			// va_start, va_arg, va_end
		*/
		///////////////////////////////////////////////////////////////////
		//���� "������" ��������� ������� ����������� ����������
		//������� 4.1 � ������� ������� scanf ����������� ��� ������������: A,B,C


		//������� 4.2. �������� ������� �������� y=A*x*x + B*x + C
		//��� ��������� x � ��������� -2 �� +2 � ����� 0.5

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


		stop
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

				//������ ��������� �������

				//����� ����������
				int nTotal=...			//���������� ��������� � �������
				Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

				//������ ����������� ����������

				stop
			*/
			/*
			//������� 6�. �� �������� � 6� �������� ���������������
			//������� - SwapDouble � CmpDouble � �������� ������� Sort
			//��� ���������� ������� ������������ ��������.
			*/

			/*
			//������� 6�*. �� �������� � 6� �������� ���������������
			//������� - SwapStr � CmpStr � �������� ������� Sort
			//��� ���������� ������� ���������� �� ������.

			const char* arStr[] = { "QQQ", "SDF", "ABC","Abba", "ENFR","En",. . . };

			//���������:

			//� ������� ������� ����� ������ �����, ���� �������� ����� �������,
				Sort(reinterpret_cast<char*>(&arStr[0])), nTotal, sizeof(???), SwapStr, CmpStr);
			*/
			///////////////////////////////////////////////////////////////////
				/*
				//������� 7. ������� ���������� �� �������.
				//�������� ��������� ������� ����
				//const char* GetString1();
				//const char* GetString2();
				//const char* GetString3();
				//const char* GetString4();
				//const char* GetString5();

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


				*/


				////////////////////////////////////////////////////////////////////////////
					//������� 8*.
					//�������� ���������� ������ (����������� ����������� � ��������
					//���������� ���������), ��������� ��� ����������.
					//�������� �������, ������� ��������� � ������ ����� �������� ������ (!) ��� �������,
					//��� ������ �������� � ������� ��� ���. 
					//���������: ��� ���� ������  ������� ������ �����������!
					//��� �������� �������� �������, ������� ������� �������� ���� ��������� �� �����
				///////////////////////////////////////////////////////////////////////////
				/*********************   �������������� �������   ****************************************************/
				//������� 9 (*)
				// ��������� ������� 8 �� �������� ������
				// �������� ������� ��������� � ����� "������� (���� ������)_8 (��������� ������������ ������ ����)_3.docx"
				//*****************************************************************************************************


					return 0;
				}//main

