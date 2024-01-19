#include "myRect.h"
#include "myString.h"
#include <iostream>
#include "Bochka.h"

#define stop __asm nop

int main()
{
using namespace std;

	//������� 1.���������� ������. �������� ���������� ������.
	//����� ������� ������.  
	//�������� �������� Class View - (����� �� ������� ����� ������� �
	//������ - ������� Rect � MyString)
	//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
	//���������� ������������ ������� � ������� ����� ������.

	//����� ����������� ���������� ��� �������� ���������� ������?

{
	Rect rect; //���������� ����������� ��� ����������
	cout << "#### Chapter 1 \n";
	std::cout << "Rect1: " << rect.m_left << ", " << rect.m_right << ", " << rect.m_top << ", " << rect.m_bottom << std::endl;

}

	//1a. �������� � ���������� ����������� � ����������� ���
	//������������� ���������� ������. �������� ��������� ������ Rect
	//� ������� ������������ � �����������. ���� ���������� ������
	//������ � ���������� ���������, ��������� - ���� ��� ��
	//�������? ��������� ���������� ������.
	//�������� ������� � ������ ������ �� �����, ����������:
	//� ����� ������ ���������� ����� ������������(������?)?

{
	cout << "\n#### Chapter 1.1a \n";
	Rect rect2(4, 2, 3, 1);
	std::cout << "Rect2: " << rect2.m_left << ", " << rect2.m_right << ", " << rect2.m_top << ", " << rect2.m_bottom << std::endl;


	//���������*: ������ ���� �� ������ ��� ����, ��� �������������
	//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
	//m_top>m_bottom
	//���������: ������, ��� ������������ ������ ������ ����� ���������
	//� �������� ���������� ����� ��������! ��������:

	// Rect rrr(4,3,2,1);

	//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
	//������������� ������������� ���������� ������, ��������, �����
	cout << "\n#### Chapter 1B \n";
	Rect rect3;
	rect3.PrintRect();
}

	//1�. ��������, ���������� � �������� ����� ������ InflateRect(), 
	//������� ����������� ������� �������������� �� �������� ����������
	//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
	//���������: �������� � ���������� ������ ����� �� ������ "�������",
	//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
	//ClassView ���� �������, �������� �������� ����� Rect � �������
	//������ ������ ���� - � ����������� ����������� ���� ��������
	//Add/Add Member Function... � ������� ����������� ���������� ������
	//"����� ��������" Wizard-� ��� �������� � ���������� �����.
	{
		cout << "\n#### Chapter 1.1B \n";
		Rect rect2;
		rect2.InflateRect(1, 1);
		std::cout << "Rect2 after InflateRect: " << rect2.m_left << ", " << rect2.m_right << ", " << rect2.m_top << ", " << rect2.m_bottom << std::endl;
		
	}


	//������� 2.���������� ������������� � ������� ������.
	//����������� �����������.

	//2�.�������� � ���������� ����������� ����������� � ������ Rect.
	//�������� ������� �� �����, ����������, �����
	//����������� ���������� ��� �������� r1,r2,r3 � r4?
	//���� ����� ���������� ��������� ��������?
	{
		cout << "\n#### Chapter 2.2a \n";
		Rect r1;  // ���������� ����������� ��� ����������
		Rect r2(1, 2, 3, 4);  // ���������� ����������� � �����������
		Rect r3 = r1;  // ���������� ����������� �����������
		Rect r4(r2);  // ���������� ����������� �����������
		r1.PrintRect();
		r2.PrintRect();
		r3.PrintRect();
		r4.PrintRect();
	}


  //2�. �������� � ���������� � ������ Rect ����� InflateRect(),
	//������� ��������� ��� ���������, �� ��������� ������ 1, � 
	//���������� ������� �������������� �� �� �������� ����������.
	//��� ����� �������� ���������� ������� InflateRect()?
	{
		Rect r1;
		Rect r2;
		Rect r3;
		Rect r4;
		Rect r5;
		Rect r6;
		cout << "\n#### Chapter 2.2B \n";
		r1.InflateRect();
		r2.InflateRect(1, 1);
		r3.InflateRect(2, 2);
		r4.InflateRect(2, 2, 2, 2);
		r5.InflateRect(3, 3);
	    r6.InflateRect(5);

		r1.PrintRect();
		r2.PrintRect();
		r3.PrintRect();
		r4.PrintRect();
		r5.PrintRect();
		r6.PrintRect();
	}

	//������� 3.������������� �������. ������������. 
	{
	Rect r;
	//���������������� ��������� ������. ��������� ������ �����������
    //	int tmp = r.m_left;
	/*
		������ ������ int tmp = r.m_left; ������� ������ ����������, ��� ��� m_left �������� ������ ������ Rect, 
		����������� � ������������� private.
		������������ ������� private ��������, ��� ����� ������ (���������� ��� �������) � ���� ������������� ������� 
		����� ���� ������������ ������ ������ ������ ������, �� �� �������. ����� �������, ������� ��������� � m_left ��� ������ �������� 
		� ������ ����������, ��������� ���������� � private �������� ���������� �� ��������� ������, ��� ��� ���������.
	*/
	//������� � ����� Rect ����� void SetAll(...),
	//������� ����������� ���������� ������ ������������ ��������. �������� ��������� �����, ��������� ������������. 
	//������� � ����� Rect ������ ����� GetAll(...),
	//������� "�������" �������� private-���������� ������. �������� ��������� �����, ��������� ������������. 
	cout << "\n#### Chapter 3 \n";
	r.SetAll(1, 2, 3, 4);
	int left, right, top, bottom;
	r.GetAll(left, right, top, bottom);
	r.PrintRect(); 
	}

/*
	//������� 4.�������� ���������� ������ � �������� ��������� �������. 
	//����������� ������� ������ �� ��������. �������� �������� � ������������ ����������� ��� �������� ��������
	//�� �����, ����������: � ����� ������ ���������� ��������� � ������������ �����������. 
	//�������� ���������� ������� 
	// Rect BoundingRect(Rect, Rect); ������� ��������� ��� ������� ������ Rect �� �������� �
	//���������� ������ ������ Rect, ������� �������� ���������������, � ������� ������� �������� ��������������. 
	��� ���������� �������� ���������� � ����������� ������� ������?
*/
	{

	//������� 4�. �������� �������� �� ������.
	//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
	//������, �������� ��������� �� ������
	//���������� �� ������������ ��� �������� ����������?
	Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;
	cout << "\n#### Chapter 4.a \n";
	r3 = BoundingRect(r1, r2);
	r3.PrintRect();

	}
	//������� 4�.���������� �� �� ������ (BoundingRect) ������� ������
	{
		Rect r1;
		Rect r2;
		Rect r3;
		
		cout << "\n#### Chapter 4.b \n";
		r3 = BoundingRect2(r1, r2);
		r3.PrintRect();
	}
/*
	//������� 5. ����� ���������� ������������ � �����������.
	//�������� � ����������
	//����� ���������� ������. ��������� �������� � 
	//������������ (�������������) � �����������. ����������: ����� ���
	//������� �� �������� ���������� �����������, � ����� - ����������?
*/
	{

		Rect r1;
		Rect*	pR = new Rect(1,2,1,2);	
		{
			Rect r2(r1);
			Rect arRect[2];
			for(int i=0; i<3; i++)
			{
				static Rect r3 (i,i,i,i) ;
				Rect r4(*pR);
				Rect r5(i,i,i,i);
			}
		}
		delete pR;	
		stop
	}
/* 
	//������� 6.����������� + ���������� = ��������������
	// ���������. ����� MyString
	// ����������� ������������ (�������������) � ����������� ����������
	//���������� ������������� � ����������� �������
	//C ������� ��������� ���������� ����� ����������
	//������ � ������������ ������ ��� ������-����� ������
*/
	{
		cout << "\n#### Chapter 6 \n";
		MyString	str1("It's my string1!");
		//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
		//� ������� cout � ������ GetString() ������������ ������ ������� str1
		//���������: ���������, ��� ������� ��������� ����������� ����� GetString().

		//��������� 1:
		//����������� ���� ��� ������ ��������:

		// ������� ������ � ������� ������ GetString()
		std::cout << str1.GetString() << std::endl;

		//��������� 2:
	    // ������� ��������� ������ �� ������ ���������������
	    // str1.GetString()[1] = 'W'; // ������, ��� ��� GetString() ���������� const char*


		//��������� 3:
		//����������� ���� ��� ������ ��������:
		// ������� ������ � ������� ������ GetString()
		const MyString	str2("It's my string2!");
		std::cout << str2.GetString() << std::endl;
	}
/*
	//6a. ���������������� ��������� ��������. ��������� - �����
	//������������ ��� �������. ���������� ��������� ��������� (���?)
*/
		{
		    cout << "\n#### Chapter 6a \n";
			MyString str1("The first string!");
			MyString str2 = str1;
		} // ����������� ���������� ��� str1 � str2


	//6�. ���������� ����� SetNewString, ������� ����� �������� ������
	// �� �����

		cout << "\n#### Chapter 6.b \n";
		MyString str3("Original String");
		std::cout << "Original String: " << str3.GetString() << std::endl;

		// �������� ������ � ������� SetNewString
		str3.SetNewString("Updated String");
		std::cout << "Updated String: " << str3.GetString() << std::endl;


	//������� 7.  ������ � ������� ������� ��������� ������:
	//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
	//������� ���������� ����� (96%), � ������ � ����.
	//������� �������� 1� ���������� ���������� ���������� �� ����� �����
	//� ������ ��������� ��������: �� ������ ��������
	//���������� �� ������ ����� -> ������ �� ������
	//���������� �� ������ ����� -> ������ � ������.
	//��������� ���������� ����� ��������, �� ������� ������������ ������ �
	//������ ����� ������ ������ 50%.

	//Bochka spirt(...);
	//Bochka water(...);
	//...
	//	while(������������ ������ � ����� spirt > 50%)
	//	{
	//		spirt.Pereliv(water); //��� spirt.Pereliv(water, �����_������);
	//		water.Pereliv(spirt); // ����������
	//		...

	//	} 159
		cout << "\n#### Chapter 7 \n";
		Bochka spirt(10.0, 96.0);
		Bochka water(10.0, 0.0);

		int iteration = IterativePereliv::FindIterationNumber(spirt, water);

		std::cout << "Number of iterations: " << iteration << std::endl;

return 0;

}

