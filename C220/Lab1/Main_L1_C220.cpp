//�������� 1:
// enum class
// initializer_list � ������������� ������ �������������
// auto
// decltype
// lambda 
// template variable

#include <iostream>
#include <vector>
#include <list>
#include <string>
int main()
{
	//������� 1. 
	{
		enum months { January, February, March/*...*/ };
		enum weekDays { Monday, Tuesday /*...*/ };

		months m = January;
		//�) ������� �������� (��� ������, ��� ���������� ��
		//������ ��������� ������������ ������������ �������
		//���������!)

		if (m == Monday) { /*...*/ }

		//�) ������������� ������������� ������
		months year[] = { January, February, March };
		size_t n = sizeof(year); //???

		__asm nop
	}


	/**********************************************************/
		//������� 2. �������� � � ������� ������ �������������
		//��������� ���������� ������ � ���������� - string
		//� ������� range-based for ������������ ��� ����� � 	
		//������� ������� � ��������� ������� ������ ��������
		//�����������
	{



		__asm nop
	}


	/**********************************************************/
		///������� 3. �������� � ��������� ����������
		//map ����� ��������� (3� � 3�) ����� �������, ����� �� �������� 
		//� �������� ����� �����, � � �������� �������� 
		//��������������� �� �������� ������������ ���� (string), 
		//������������ � ���� �����

		//3�. ������������������ map "�������" ����������� ������ �������������
		//� ������� range-based for � structured binding
		//������������ ����������, ��������: A: any, apple, away
	{



		__asm nop
	}

	//3�. �������� ������ map � ����������� �������� ������
	//��� ���������� �������.
	//� ������� range-based for � structured binding
	//������������ ����������, ��������: A: any, apple, away
	{
		//���� (��������):
		const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };



		__asm nop
	}


	/*********************************************************/
		//������� 4. ������� ������� ��� ������ �� ������
		//��������� �������������������, �������� ����:
	{
		std::vector<double> vd = { 1.1,2.2,3.3 };
		//PrintAnyCont(vd);

		std::string s("abc");
		//PrintAnyCont(s);

		int ar[] = { 1, 2, 3 };
		//PrintAnyCont(ar);

		std::initializer_list<int> il{ 3,4,5 };
		//PrintAnyCont(il);		

		__asm nop
	}


	/********************************************************/
		///������� 5. 	
		//C������ ������� ��� "���������" ��������, ��������:
		//����: {1, -2, 5}, �����: {-1, 2, -5})
		//��������� �������� ���� std::string ����� ��������� "aBc1" -> "AbC1"
		//��������� �������������������, �������� ����:
	{
		std::vector<double> vd{ 1.1,2.2,3.3 };
		//NegateAll(vd);

		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		//NegateAll(ls);

		int ar[]{ 1, 2, 3 };
		//NegateAll(ar);

		__asm nop

	}


	/********************************************************/
		//������� 6. ����������� ������� ���������� �� ������
		//��������� �������������������, �������� ����
		//���������� ��� ���������� ����� ������������ ����������
		//�������� sort(), � ��� ������� ������� - ������-�������
	{
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		//absSort(vd);


		int ar[] = { -3, 2, -1 };
		//absSort(ar);

		__asm nop
	}


	/********************************************************/
		//������� 7.
		//�������� �������, ������� ����� ����������� �
		//���������� ������, ������ ������� 
		//�������� �������� ������ ��������� ���� 
		//������������������� ������ �����
		//� � ���������� ������� ����.

		//��������� 1: ��� ��� ������������������ ����� ����
		//������ �����, ������� ������� ������ ���������������
		//������� ������������ �� ����

		//��������� 2: ��������� � ����������� �������������
		//���������� copy() � transform(), � ������� 
		//���������������� �������� ������ � ���� �������
		//�������� ������-��������

		//��������:
	{
		std::vector<int> v{ 1,2,3,4 };
		std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };

		//??? = SumCont(v, l);


		std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
		double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		//??? = SumCont(ar, ll);


		std::set<std::string> s{ "abc", "qwerty", "my" };
		std::deque<const char*> d{ "111", "22" };
		//??? = SumCont(s, d);

		__asm nop
	}


	/********************************************************/
		//������� 8. ���������� �������, ������� ��������� ��������� ���������:	
		//�������������� ������������������ ������ ���� � ���������� ������ ����, 
		//��� (������) ���������� ������ ���� �� vector, list, deque, set 
		//� ���������� ���� �� ����, ��� � � �������������� ������������������ 

		//������� ������ "���������" �������� �������� ������������������ � ��� ������ ���������� 
		//�������� ��������� �������. ������� ������ ������-��������
		//�������� ������������������ ��� ���� �� ��������
	{
		//�������� 1:
		std::vector<int> v{ 1,2,3,4,5 };
		std::list<int> l; //���� ������
		std::deque<int> d; //� ���� ��������
		//Separate(v, l, d, <�������>);

		__asm nop
	}
	{
		//2.
		//��������� �������� �������: �� ��������, ������� �������� � �������� ��������, � ���� //���������, ��������� - � ������
		double ar[] = { 0.8, 1.1, 33.3, -4.1, 5.5 };
		std::set<double> s; //���� ��, ������� �������� � [0,6]
		std::vector<double> v; //���� ���������
	}


	/********************************************************/
		//������� 9. C ������� ��������� for_each()!!! 
		//(� �� count_if()) ��������� ������� ���� � �������
		//��������.
		//  ������������ ������ �������
	{
		char s[] = "Hello World!";
		//for_each


		__asm nop
	}


	/********************************************************/
		//������� 10. ����������� ����������� enum � ��������� �������������  - enumToString
		// � �������� - stringToEnum

		//���������: 
		//***********
		//1. ��������������� ����������� ���������� ������ ��� ����� ����� ���-�� ������� =>
		//1.1 ����������� ��������� � ������������ ������ ���� ����������� => ��������������� ������
		//���� ������ ���� �����������, => ���������� ������ ����� ���� ������������ � ��������
		//����� � std::map

		//1.2 � ��� �������� (��������������� ���������� ����������)
		//����� ���� ������ � ���� ����� ����������� (�������� ������, ������, ��� �������� �� �����������) 
		//=> �������� ��������� std::map<string,<��������> >

		//1.3 �������� ��������� �++11 ���������� ������������� ���� ����� ���� ������� ������� � ����,
		//� �������� �� ���������� ������������� ����������� 

		//***********
		//2.1 ��� ��� ���� ������������ ������, �� enumToString � stringToEnum ������ ���� ����������
		//2.2 ������������ ����� ��������� ��� ������������ �������� � ������� ��������, �������
		//   ������ �� ������������� => ������!


		//***********
		//3. ����� �������� � map<string, <��������> > �� �������� �� ���� ������������, ��������� ��� ��������������
		//��������� ���������� (� ��������� ��������� � ����������� ������������� ��������� ����������)


		//***********

	{
		//��������:
	/*
			COLORS c1;
			try {
				c1 = stringToEnum<COLORS>("blue");
			}
			catch (...)
			{
			//...
			}


			auto Str = enumToString(c1);
	*/

		__asm nop
	}

	return 0;
}
