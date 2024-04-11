//����������
//�������: 
//	������� �������,
//	������� �������,

#include <tchar.h>
#include "swap.h"
#include "MyString.h"
#include "MyStack.h"
#include "MyStack2.h"

//#include <stdexcept>

#define stop __asm nop
int _tmain(int argc, _TCHAR* argv[])
{
	
////////////////////////////////////////////////////////////////////////////
//����. ������� �������.
//�������� ������ ������� ������������ ������� ����
//�������� - Swap(). ��������� ����������������� ����������
//������� � ������� ������������ ���� ��������� ����.
//��������� 1: ���������� ������� ���������� ��������� � .h-����.

		std::cout << "Chapter: Swap\n";
		int iX = 1, iY = -1;
		std::cout << "Before Swap: iX: " << iX << "; iY: " << iY << std::endl;
		Swap(iX, iY);
		std::cout << "After Swap: iX: " << iX << "; iY: " << iY << std::endl;
		double dX = 0.5, dY = -5.5;
		Swap(dX, dY);


//��������� 2: ���������, ��� ����� �����������, ��� ����,
//			����� ��������� ����� ������� � ��������� MyString
//			�� ������ ���������, �� � ����������

		std::cout << "Chapter: 1.1\n";
		MyString str1("One"), str2("Two");
		std::cout << "Before Swap: str1: " << str1 << "; str2: " << str2 << std::endl;
		Swap(str1, str2);
		std::cout << "After Swap: str1: " << str1 << "; str2: " << str2 << std::endl;


/////////////////////////////////////////////////////////////////////
//����. ������� �������.
//������� 1.
//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
//���������: 1. �������� ����� ���-�� ������� - ������� � ������� ���������
//			 ��� �������� ��������������� ������������� � ������ ���������
//			 �������� ������, 
//			 2. ��� ������� ������������� ������� ����� ����� ���� �����������
//			 ��������-��������� �������
//			 3. ������������� ���������� �� ������ �������� "push" � "pop".
//			 ���������� ��� ��������, ���������� operator<< ("push") � operator>> ("pop")
//           ��� ����, ����� ������������� ���������� ���������� ���� �������� 
//			 ������ ���� �� ������������ ���������� � ��������� ��������
//			 4. ������������� ���������� operator[] ����� �������, ����� ������������
//			 ��� ������/�������� �������� ������ ��� ���������, ������� �� ����������
//           5. ������������ ����������� ������ �������� � ����� ���������
//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
//operator<< � operator>>, operator[]
		std::cout << "==========================================\n";
		std::cout << "Chapter: MyStack\n";
		{
			try {
				MyStack< int, 5 > iStack;
				iStack << 1 << 2 << 3 << 4 << 5;
				//std::cout << "try add 6-th element to 5 size stack:\n";
				//iStack << 6; //exception Stack is Full

				int ar[5];
				iStack >> ar[0] >> ar[1] >> ar[2] >> ar[3] >> ar[4];
				//std::cout << "try pop element from empty stack:\n";
				//iStack >> ar[0];	//exception Stack is Empty

				MyStack< MyString, 10 > strStack;
				strStack << MyString("Aaa") << MyString("Bbb") << MyString("Ccc");
				MyString str("Ddd");
				strStack << str;
				std::cout << strStack;

				str = strStack[1];
				strStack[2] = str;
				//std::cout << "try get element with index 5 from 5 size stack:\n";
				//strStack[5] = str;		//exception  Index out of range
				std::cout << strStack;

				MyString s1, s2;
				strStack >> s1 >> s2;
				std::cout << strStack;
			}
			catch (const std::exception& e ) {
				std::cerr << e.what() << '\n';
			}
		}

//������� 2. 
// ���������� ������ ����� - MyStack2 ����� �������, ����� 
//��� �������� ��������� ������������� ����������� ������.
//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
//������������
//���������: 1. ������������� ���������� �� ������ �������� "push" � "pop". 
//           ���������� ��� �������� � ������� ��������������� �������.	
//			 2. operator[] ��� ������ ����� ������������� �� ����� (������?)
//           3. ���� ����� ����������� ��� ���������������� �������� ������ (����������� �����������, 
//			 �������� ������������, ...)
// ��������� ����������������� �������������� ������� ������
		std::cout << "==========================================\n";
		std::cout << "Chapter: MyStack 2\n";
		try {
			MyStack2< MyString> s1;
			s1.push(MyString("Aaa"));
			s1.push(MyString("Bbb"));
			s1.push(MyString("Ccc"));
			s1.push(MyString("Ddd"));

			MyStack2< MyString> s2(s1);
			MyString str = s1.pop();

			s1.pop();
			std::cout << "s1 after 2 pop, s2 copy s1 before s1 pops:\n";
			std::cout << s1 << s2;
			s1 = s2;
			std::cout << "s1 copy s2\n";
			std::cout << s1;

			s1.pop();
			s2 = s1;
			std::cout << "s2 copy s1 after s1 pop:\n";
			std::cout << s2;


			MyStack2< MyString> s3(std::move(s1));
			std::cout << "s3 moved from s1, s1 after moving to s3:\n";
			std::cout << s3 << s1;

			s2.pop();
			s3 = std::move(s2);
			std::cout << "s3 moves from s2 after s2 pop, s2 after moving to s3:\n";
			std::cout << s3 << s2;
			std::cout << "try pop from s2 after moving:\n";
			s2.pop();

		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}


	return 0;
}

