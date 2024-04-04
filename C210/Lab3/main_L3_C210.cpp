//����������� ���������� �������� - STL 
//���������� ����������� ���������� - vector
//���������

#include <iostream>
#include <vector>
#include "MyString.h"

#pragma warning(disable: 4786)


#define	  stop __asm nop

template <typename T>
void printVectorInfo(const std::vector<T>& vec) {
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	std::cout << "Max Size: " << vec.max_size() << std::endl;
	std::cout << "Elements: ";
	for (const auto& elem : vec) {
		std::cout << elem << " ";
	}
	std::cout << std::endl << std::endl;
}

using namespace std;
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




	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 




	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).



	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{

		//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
			//�) ������������� ����� ��������� �������
			//�) ��� ���������� operator<< ��� Point*

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

		/*
		{
		int n=...
		size_t m=...
		vector<int> v(n);
		v.reserve(m);
		if(v.capacity() == m) //true?
		}
		*/

		/*
		{
		vector<int> v(3,5);
		v.resize(4,10); //��������?
		v.resize(5); //��������?

		}
		*/

		//�������� ��� "������" ������� � ����������
		//������ (�� ������ � ���� �� ����) ����. 
		//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
		//��� ���������� � ������� push_back.
		//������ ������ ������ ��������� ���������� ����������� push_back.
		//
		//�������� ������, ������� �������� � �������� ���������







		//!!! shrink_to_fit - ���������� ������� �������.
		//��� ������ ������� �� ����������� ������� ��������� ��������� �������
		//�� size.




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



		///////////////////////////////////////////////////////////////////
			//�������� �������, ������� ������ ������� ������ ������������� ������������������.
			//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"




		stop

		///////////////////////////////////////////////////////////////////

			//�������� �������� ������������������ erase()
			//�������� ������� �������� �� ������ ������� ���� ������ 
				 //��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"





		///////////////////////////////////////////////////////////////////
			//�������� ����� ������ ����� �������, ����� ��� �������� �����
			//������� ��������� ������ �� ��������� ����� ��������, �� �����������
			//���� �� � �������� �������






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