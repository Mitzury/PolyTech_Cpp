/*************************************************************
	������������ ������� �3. ��������� �������������.
							���������.
*************************************************************/

#include <iostream>
#include <tchar.h>
#include <cmath>
#include "stdafx.h"

#include "1.h"

#ifdef _DEBUG
#include "1.h"
#else
#include "2.h"
#endif

#define LENGTH(r) (2.0 * M_PI * (r))


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define MAX(A, B) ((A) > (B) ? (A) : (B))

#define	  stop __asm nop	//� ������� ��������� ������������� ������
							//����������������

int _tmain()
{
	// ********************************************************
		//������� 1. ��������� �������������

		//1.1. ������������� "��������������" �������� ����������� ����������:
		//� ������������ ����� <cmath> (������� � ���� ������� �������� ������
		//���� math.h) ���������� ����� ������������ ��������������
		//���������, �������� M_PI. �������������� ���� ���������� ���
		//���������� ����� ����������.
		//�������� ��������: ����������� �������� � ���� ������� ���� ���������
		//� ��������� �������� ����������. ��� ���, ����� ����������� �������������
		//�����, ��������� �������???
	// *******************************************************

	double radius = 5.0;
	double circumference = 2.0 * M_PI * radius;

	std::cout << "����� ����������: " << circumference << std::endl;


	//1.2.������� � �����������.
	//1.2.1 �������� ���� ���������������� LENGHT ������� ��������� ����� ����������.
	// ������������� ���������� ������ ��� ��������� ��������:
	{
		float l1 = LENGTH(1 + 2);   // ������ ���� 18.8495
		float l2 = 1 / LENGTH(2);   // ������ ���� 0.07957

		std::cout << "����� ���������� 1: " << l1 << std::endl;
		std::cout << "����� ���������� 2: " << l2 << std::endl;
		stop
	}
	// *******************************************************

		//1.2.2 (B) ���������� ������ MAX(A, B)  ��� ���������� �'�������
		//�������� �� ����.
#define MAX(A, B) ((A) > (B) ? (A) : (B))

	//����������� ������ ��������� �������. ������� �� ����������
	//�������� ���������� k, i, j. ��������� ���������.
	//������������ ������ �������� �������.
	//�������� ������, ����� �������� �������� �������� ����������

	int i = 10, j = 12, k;
	k = MAX(i, j);        // i=10 j=12 k=12
	k = MAX(j, i) * 2;    // i=10 j=12 k=24
	k = MAX(j, i + 3);      // i=10 j=12 k=15
	k = MAX(i--, j++);    // i=9  j=13 k=12
	//���� ������� ������� �� ������� �������� �������, ��� ��� ������ ��������� A � B �������� � ������� ������, � �������� ++ � -- ����������� ������ � i � j, ��������������.

	//������ ���������� ����� ������������, � � ������ MAX(i--, j++), i ����������� �� 9, � j ������������� �� 13, � k ��������������� � ������������ �������� ����� 9 � 13, ��� ����� 13.


// *******************************************************

	//1.2.3 ���������� ������ EXCHANGE(X, Y)  ��� ������������
	//���� �������� ���� int � ������ �������. ��������� ��� ������������
	//���������. ���������, ��� ����� ������ ����������������, ����
	//�������������� �������� ������� ����???

#define EXCHANGE(X, Y) do { int temp = X; X = Y; Y = temp; } while (0)

	int x1 = 1, y1 = -1;
	EXCHANGE(x1, y1);  // x1=-1, y1=1

	int x2 = 100, y2 = -100;
	EXCHANGE(x2, y2);  // x2=-100, y2=100
	//���� ������ ���������� ��������� ���������� temp, ����� �������� �������� X � Y. �������� ��������, ��� ���� ������ ��������� ��� ������ ����������� ������ �������������� ����.

// *******************************************************


	//1.3. ��������� �������� ����������
	//�������� ��������� ��������, ����������, �����
	//�������� ��������� ���������� iNN. ��� ����� �������
	//��� ����, ����� ��������� ��� ����� 0? 1? 2?
#define NNN
#define MMM
#define LENGTH(r) (2.0 * M_PI * (r))

	int iNN;
#if defined NNN && defined MMM
	iNN = 0;
#elif defined MMM
	iNN = 1;
#elif defined NNN
	iNN = 2;
#else
	iNN = -1;
#endif
	stop


		// *******************************************************

			//������� 1.4. ��������� � Project -> Properties -> ���������� ������
			//- Property Pages -> C\C++  -> Preprocessor -> Preprocessor definitions.
			//� ������ ��������� ������ � ����������� �� ������ ������ �������
			//(Debug ��� Release) ����� ���� ���������� � ������� ����� /D
			//��� _DEBUG. � ������� �������� ��������
			//���������� �������� �������� ����, ������� � ����������� �� ����
			//������ ������� � ������� cout ������ ����� �� �������. ���������
			//��� ������ ������� ������.

			//�����
			//��� ������ Debug � �������� ���������� ������� �������
			//���� �� ����� ��������� ���������� ��
			//����� �����, ������ ������ � �������� ������, ���� � ������� 
			//���������� �����, ����������� ������ ������� ������,
			//� ����� ��� �������, ���������� ������ ������.

			//��� ������ Release ������ ���� ������ �������� ������
			//"Release configuration!"

#ifdef DEBUG
#define DEBUG_INFO \
	std::cout << "Debug configuration!" << std::endl \
	<< "File: " << __FILE__ << std::endl \
	<< "Line: " << __LINE__ << std::endl \
	<< "Function: " << __func__ << std::endl \
	<< "Compilation date and time: " << __DATE__ << " " << __TIME__ << std::endl;
#else
#define DEBUG_INFO std::cout << "Release configuration!" << std::endl;
#endif

	//���������: ��� ��������� ������ ���������� ������� � online �������
	//(Help -> View Help), �������� ���� C++ � � ���� ������ ������� 
	//��������� �������� �����: Predefined Macros
	// ��� �������� �� ������: https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-160




// *******************************************************
	{
		//������� 1.5  �������� ��������������� �������������� _UNICODE � ���������
			//����������� ������������� <tchar.h>, ��������� � ����������������� ����������,
			//������� ����� ����������� ��� ������������, ��� � ����������� ��� 
			//��������� ��������� ������.
			//� ������� ��������� ��������� ��������� (���������� �������� � 10-���� � 16-���� ������� ���������).

		//���������: ��� ����, ����� ��������� ������ �� ������ �  ��������� ����������, ����:
			//1)������� Project -> Properties. ����� ������� ���������� ������  Property Pages  
			//2)Configuration Properties -> Advansed-> Advansed Properties -> Character Set
			//3) ���������� ���� "Use Unicode Character Set", ���� ��������� Unicode
			//4) ���������� ���� "Not Set", ���� ���������  ������ � ������������� ���������.
			// 
	//���������:  � ��������� 4 ������ �� ���� ������� ������� ���������, ������ �������� ����������� 
	// � ������������ ������� �������� ����� �������� � 10-���� � 16-���� ������� ���������

		TCHAR ch1 = __T('A'); // ch1=65 (0x41)
		size_t s1 = sizeof(ch1); // s1=2 (� Unicode ������������ 2 ����� �� ������)
		TCHAR ch2 = __T('�'); // ch2=1060 (0x424) � Unicode
		TCHAR ch3 = '�'; // ch3=1060 (0x424) � Unicode
		// ����� ����������� � �������
		std::wcout << L"ch1=" << ch1 << L" s1=" << s1 << L" ch2=" << ch2 << L" ch3=" << ch3 << std::endl;
	}
	// *******************************************************
	{
		//������� 1.6
		//�������� ���� ��������������.
		//������� ������ � ���� ������� ���. ������ ��� �� �����.
		// ������� ������������ ��� ���������� � �������� �������� ����� ��������������

		//� ������ ����� ������������ ������ ����� ��������� ��������� �������������, 
		//������������ ������������ ����� � ��������� ������������ ���� � ������� ���� ��������������.
		//�� ��������� ��� �������� ������ ������� � Visual Studio � ������� ����������� ��� stdafx.h(VS 2019) 
		// � �������� ����� ����� �������������������� ���������. ��� ����� ����� ����� ���� ��������, �� � ����� ��������� �� ����� ������ �� �����.
		//���� ��������� ��������� ����� :
		//1) ������� ���� stdafx.h � ��������� � ���� ��������� ������������ ������, ������� ����� ������������ � ������
		//2) ������� ���� ���������� stdafx.cpp  � � ���� ��������� ������������ ������   #include "stdafx.h" 
		//3) � ���������� ����� � �������� ����� ���������� ������������ ���� stdafx.h
		//4) ������ ����� ��� ������ ���������� :
		//		��� stdafx.cpp - / Yc
		//		��� lab3.cpp - / Yu
		// 
		// �������������� ����� � Visual Studio:
		//#include "stdafx.h"
		///stdafx.cpp: /Ycstdafx.h
		///lab3.cpp: /Yulab3.h

	}
	// ********************************************************
		//������� 2.������������ �����. ��������� #include
		//�������� � ���������� � ������� ��� ������������ ����� 1.h � 2.h
		//� ������ ������������ ����� �������� ������������ � ����������� �������
		//��������, �� ����������� ����������� ���������� ������ ��������, ��������:
		//1.h - enum MyEnum{My1, My2, My3};  . 2.h - enum MyEnum{My1=5, My2, My3};
		//� ������� �������� �������� ���������� � DEBUG-������ ����������� ����������
		//�������� �� 1.h, � � RELEASE-������ ���������� �������� �� 2.h

		/*
		#include "1.h"

		#ifdef _DEBUG
		#include "1.h"
		#else
		#include "2.h"
		#endif
		*/


		// ********************************************************
		/*
			//������� 3. ���������
			//��������  ��������� �������� ������ ����� � ������������������ ��.
			//�������� ��������� ��������������� ����� � ������������������ ��

			int integerValue = 42;
			double doubleValue = 3.14;
			char charValue = 'A';

			//�������� �������� ��������.
			//�������� �������, � ������� ��������� ����������, ����� ��������
			//����� ��������� ����������-���������� � �� ��� ��� ���������
			//"���������"

			int* pInt = &integerValue;
			double* pDouble = &doubleValue;
			char* pChar = &charValue;



		*/
		// *******************************************************

			//������� 4. ���������� ����������. �������� ������������� ���������.
			//�������� �������, ������� �� ���������� ��������
			//���������� � �������� ��������, �� ������� ��� ���������.
			//�������������� ����������� ����������
	{
		int nAr[3] = { 1,3 };
		int* pn = &nAr[0];
		(*pn)++;
		pn++;

		char cAr[] = { 'A','B','C','D' };
		char* pc = &cAr[0];
		(*pc) = (*pc) + 5;
		pc = pc + 3;

		double dAr[3] = { 1.0,2.0 };
		double* pd1 = &dAr[0];
		double* pd2 = pd1;
		(*pd2) += 2;
		pd2 += 2;

		// ���������� ����������� ���������� �������� ��������� ���� ����������
		pd1 = &dAr[0];         // = ����� ������� ��������
		pd2 = &dAr[1];         // = ����� ������� ��������
		int nNumber = pd2 - pd1;  // = 1, �.�. pd2 ��������� �� ���� ������� ������� pd1

		// ��������� ���������� pd2 � pd1 � ����� ����������� ��������� � ������� cout
		std::cout << "Comparison of pd2 and pd1: " << (pd2 > pd1) << std::endl;  // 1, �.�. pd2 ��������� ������� pd1


	}


	// *******************************************************

		//������� 5. Void-���������. 
		//5.1. �������� �������, ���������� - ����� �������� �������������
		//void-���������. �������� ��������: ���������� ��������� ��
		//�� ������ ���������� ��������, �� ������� "���������"
	{
		void* pVoid;  // ���������� void-���������
		int nObject3 = 5;
		char cObject3 = 'A';
		int* pInt = &nObject3;
		pVoid = &nObject3;
		pVoid = &cObject3;
		pVoid = pInt;

		//������, ��� ����������������� ��������� �������, ���������:
		//��� ����� �������, ����� ��������� ����� ���������� 	
		pInt = static_cast<int*>(pVoid);
	}

	// *******************************************************

		//5.2. ��� ���������� ���������� ��������� ����������, ����� ������������
		//����� ��� ������� ��� ����� ���������� ���� void-���������,
		//������� � ������ ������� (1) ��������� �� double, � ���� 
		//��������� �� int (2) 
{

	void* pVoid;
	double dObject3 = 33.33;
	pVoid = &dObject3;  // (1)


	// ��� ���������� ���������� ��������� ����������, ����� ������������
	// ����� ��� ������� ��� ����� ���������� ���� void-���������,
	// ������� � ������ ������� (1) ��������� �� double, � ����
	// ��������� �� int (2)
	int nTmp = *(static_cast<int*>(pVoid));  // (2)

	std::cout << "nTmp: " << nTmp << std::endl;

	//��� ���������� ������� ��������� ���������� ������������ ���������� ���� ���������. 
	// ��� ��� pVoid ��������� �� ������ ���� double, � �� int, ���������� ���� ����� ���������, � ��������� (nTmp) ����� ��������������.

	//���������� ���� static_cast<int*>(pVoid) ����� �������� � ��������������� ����������� � ������������� �������� ��������, 
	// ������� � �������� ��������� ��������� ������������. �������� � ����������� ������ ��������� ��������� ������, ������� ��� ���������.
}
	stop

// *******************************************************


	//������� 6.��� ���������� ������� �������� �������� �� ��,
	//��� �������� �������� "����������" ����������� ����
	//"��������� �� ���������" � �� ������� ��������� ���������
	//������� �� ����� "�������������" ����������
	int n1 = 1;

    //�������� ��������� pn � ������������������ ��� ���, ����� ��
	//"��������" �� n1
	int* pn = &n1;

    //�������� ��������� ppn � ������������������ ��� ���, ����� ��
	//"��������" �� pn
	int** ppn = &pn;

    //�������� ��������� pppn � ������������������ ��� ���, ����� ��
	//"��������" �� ppn
	int*** pppn = &ppn;
  
	//� ������� ���������� pn, ppn � ppn �������� �������� ������� n1
	//� ��������� ��� n2
	int n2 = ***pppn;
	//int n2=...
	std::cout << "n2: " << n2 << std::endl;
	//C�������� ��������� pn, ppn � pppn, � ����� � �� ������� ���������� �������� ������� n1, ������� ������������� ���������� n2.

	stop
//*********************   �������������� �������   ****************************************************
//������� 7 (*)  
// ��������� ������� 2 �� �������� ������ 
// �������� ������� ��������� � ����� "������� (���� ������)_2 (������ �� ������)_3.docx"
// ������ ������� ����������� � ��������� �������
// ������������:
// ��� ������� (project), ��������� � �������� ������� ����� ����� �������� � ���� ������� (solution)
//*****************************************************************************************************


	return 0;
}//end main
