//������������ ������ �2
//initializer_list, move, default, delete, move ���������
#include <iostream>
//#include "UniqueVector.cpp"
#include "UniqueVector2.cpp"

using namespace std;
int main()
{
// ������� 1. �������� �����, ������� ������ ������������� ���������������� ������� � ����������� ���������� ������ ���� � �������� ���������.
	/*
	��������:
	� ����� ��������� �������� ����� � ����������� ���������� � ������ ����� ��������[1, 10].������������ ����� �������� � ��� ������{ 2,-1,3,33, 5,2 }. � ���������� � ����� ������� ������ ��������� ��������{ 2,3,5 }
	��������: ��� ������������� ��� ������������ �� ����� ������ ������� ��������, �������� �������������! ��� ������� ������������� �������� ����� �������� ������!
		�	��� �������� ��������� ����������� std::vector.
		o	������� 1 : ������������ std::vector � �������� ����������� �������
		o	������� 2 : ����������� ���� ����� �� std::vector � ��� ���� ����� ����� ������ ���� ������������ ������������
		����������� ��� ��������!
		�	���������� �����������, ������� ����� ��������� ����� ���������� ��������(�������� ����� �����������)
		�	���������� ����� ���������� ������ ���������� ��������(�������� ����� �����������)
		�	���������� ����� �������� ������ ���������� ��������(�������� ����� �����������)
		�	������������� ����������� ��������� ��������� �������� ��������
		�	���������� ����� ����������, ������� ����� ��������� � �������� ��������� ������� ����������(�� ����������� / �� �������� / �� �������)
		�	� ������(�������� �� ��� ������) ������
		�	���� ���������� � ����� ������ �� ����������� ������������� ����������� �������������
		�	���������� ����������� ����������� �� ����� ��������� ������ �������� � ������ ���������, ��������:
	vector<int> v;
	std::copy(my.begin(), my.end(), �);
	*/
	{
		std::cout << "#Chapter: Construct" << std::endl;
		int init_values[] = { 2, -1, 3, 33, 5, 2 };
		UniqueVector<int> unique_vector(1, 10, init_values, 6);

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " " ;
		}

		std::cout << "\n#Chapter: Additional values (1,4,7)" << std::endl;
		// ���������� ����� ���������� ������ ���������� ��������(�������� ����� �����������)
		int additional_values[] = { 1, 4, 7 };
		unique_vector.add(additional_values, 3);

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " ";
		}

		std::cout << "\n#Chapter: Remove values (2,5)" << std::endl;
		// ���������� ����� �������� ������ ���������� ��������(�������� ����� �����������)
		int to_remove[] = { 2, 5 };
		unique_vector.remove(to_remove, 2);

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " ";
		}

		std::cout << "\n#Chapter: Sort values" << std::endl;
		// ���������� ����� ����������, ������� ����� ��������� � �������� ��������� ������� ����������(�� ����������� / �� �������� / �� �������)
		unique_vector.sort(std::greater<int>());

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " ";
		}

		std::cout << "\n#Chapter: Copy values" << std::endl;
		// ���������� ����������� ����������� �� ����� ��������� ������ �������� � ������ ���������, ��������:
		std::vector<int> copy_vector(unique_vector.begin(), unique_vector.end());

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " ";
		}
	}
//������� 2. ���������� ������ ������ MyUniquePTR, ������� �������� �������� ��� ��������� �� ������ ������ ����.
	//������ � ����� ������ ������������ ����������� �������� ����������� ����������� ��������.��������� ���������������� ������� �� ������� MyString :
	{
		/*
		MyUniquePTR<MyString> p1(new MyString(�abc�));
		std::cout << p1->GetString();
		p1->SetNewString(�qwerty�);
		MyString  s2 = *p1;
		//MyUniquePTR< MyString > p2=p1; //����� ���������� ������ �������� ������ => 
		���������!
			If(p1) { std::cout << �No object!� } //� ��� ������ ��������
		MyUniquePTR< MyString > p3(new MyString(�vvv�));
		//p3 = p2; //� ����� ���������� ������ �������� ������
		vector< MyUniquePTR< MyString >> v; //��� �������������������???
		list< MyUniquePTR< MyString >> l;
		//��� ����������� �� v � l ???
		*/
	}
	return 0;
}