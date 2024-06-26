//������������ ������ �3
//initializer_list, move, default, delete, move ���������
/*�������. ������������ �����, ������� ��������� ���������������� ������� � ���������� ������ ����.
������ ��������� ������� � ������������ �������, ��� ���� ������������ ������ ��� ����������� �����.
���������: ��� ��� ������� � ��� ������������� ��������� ������, ��� ������� ����� ������ ���������� � �����, 
�  ������� ������ ��������� �� ������ ������� = > ���� ��������� ������� ������� ������������, 
�� ������ ������ ����� ��� ������������ = > ��������������� �����, ��������� ��������� � �������� ��������.
�������� �� ��������� ������������� ����� ��������� ������, ����� ��������� ��������, ����� ������������ ������ push(),
� ��������� ��������� � ������� �� �������� = > ��� ������������� ������ ������� �����������.
��� ���������� ����� ���������� ����������� ������ � ������������ ������� = >
�	������������� ������� ��������� ���������
�	������ ��� ��������� ������������� �� ����������������
��������!
1.	������� ��������� ��� ������������� ������ ������! � ������������� ��������� �� ���� ������������� move - ���������
2.	������� ������� �� ������ � ������� range - base - for
��������� ������������� ����� �� ����������� ���� ���������.
���������: ���� �� �� ������� �� ���������� ������ � �� ������������� ������������ � ������� ����� MyString, ������ �������� ��� �� std::string
��������� �������� ������ �������� �� ������ ���������, �� � ����������:

MyQueue<MyString>  q1{ MyString(�AAA�), MyString(�qwerty�),<������_��������������> };

//������������� MyQueue � ����������� for:
for (const auto& el : q1) { std::cout << el << ' '; }

MyString s(�abc�);
q1.push(s);
q1.push(MyString(�123�));
MyString s1 = q1.pop();
q1.push(�qqq�);
MyQueue < MyString >  q2 = q1;
MyQueue < MyString >  q22 = std::move(q1);

MyQueue < MyString >  q3{ 10, MyString(�!�) }; //������� ������ ��������� 10 ��������� �� ������� �!� 
q1 = q3;
q2 = MyQueue < MyString >(5, MyString(� ? �));
q1 = { MyString(�bbb�), MyString(�ssss�) };
*/

#include <iostream>
#include "MyString.h"
#include "MyQueue.h"

int main() {
	setlocale(LC_ALL, "Ru");
	using namespace std;
	MyQueue<MyString>  q1{ MyString("AAA"), MyString("qwerty") };

	// ������������� MyQueue � ����������� for:
	cout << "������� ������������� �����" << endl;
	q1.print();


	cout << endl << "��������� �������� ������� push()" << endl;
	MyString s("abc");
	q1.push(s);
	q1.push(MyString("123"));
	q1.print(); 


	cout << endl << "����������� q2 = q1" << endl;
	MyQueue <MyString> q2 = q1; 
	q2.print();
	q1.print();

	cout << endl << "���������� move q21 = q1" << endl;
	MyQueue <MyString> q21 = std::move(q1); 
	q1.print();
	q21.print();


	MyQueue <MyString> q3{ 10, MyString("!") }; //������� ������ ��������� 10 ��������� �� ������� �!� 
	cout << endl << "������� ������ ��������� 10 ��������� �� ������� �!� " << endl;
	q3.print();
	cout << endl << "����������� q1 = q3" << endl;
	q1 = q3;
	q3.push("k");
	q1.print();
	q3.print();

	q2 = MyQueue < MyString >(5, MyString(" ? "));
	cout << endl << "������� ������ ��������� 5 ��������� �� ������� �?� " << endl;
	q2.print();

	cout << endl << "�������� ������������ �� ������ ������������� " << endl;
	q1 = { MyString("bbb"), MyString("ssss")};
	q1.print();
	MyString k("abc");
	MyString c("cde");
	MyString v("efg");
	q1.push(k);
	q1.push(c);
	q1.push(v);
	q1.print();
	q1.pop();
	q1.print();
	q1.pop();
	q1.print();
	q1.pop();
	q1.print();
	q1.pop();
	q1.print();
	q1.pop();
	q1.print();

	return 0;
};