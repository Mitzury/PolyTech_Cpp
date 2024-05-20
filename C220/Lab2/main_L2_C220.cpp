//������������ ������ �2
//initializer_list, move, default, delete, move ���������


//#include "UniqueVector.h"
#include "UniqueVector2.h"

#include "MyString.h"
#include "MyUniquePTR.h"
#include <list>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Ru");
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
		std::cout << "Chapter: 1" << std::endl;
		std::cout << "#Chapter: Construct" << std::endl;
		UniqueVector<int> unique_vector(1, 10, { 2, -1, 3, 33, 5, 2 });
		std::cout << unique_vector << std::endl;

		std::cout << "\n#Chapter: Additional values (1,4,7)" << std::endl;
		// ���������� ����� ���������� ������ ���������� ��������(�������� ����� �����������)
		unique_vector.add({ 1, 4, 7 });
		std::cout << unique_vector << std::endl;

		std::cout << "\n#Chapter: Remove values (2,5)" << std::endl;
		// ���������� ����� �������� ������ ���������� ��������(�������� ����� �����������)
		int to_remove[] = { 2, 5 };
		unique_vector.remove(to_remove, 2);
		std::cout << unique_vector << std::endl;

		std::cout << "\n#Chapter: Sort values" << std::endl;
		// ���������� ����� ����������, ������� ����� ��������� � �������� ��������� ������� ����������
		// (�� ����������� / �� �������� / �� �������)
		//unique_vector.sort(std::greater<int>());
		std::cout << "\n  Greater" << std::endl;
		unique_vector.sort([](const auto a, const auto b) {return a < b; });
		std::cout << unique_vector << std::endl;
		std::cout << "\n  Lower" << std::endl;
		unique_vector.sort([](const auto a, const auto b) {return a > b; });
		std::cout << unique_vector << std::endl;
		std::cout << "\n  ABS" << std::endl;
		unique_vector.sort([](const auto a, const auto b) {return abs(a) < abs(b);});
		std::cout << unique_vector << std::endl;

		std::cout << "\n#Chapter: Copy values" << std::endl;
		// ���������� ����������� ����������� �� ����� ��������� ������ �������� � ������ ���������, ��������:
		std::vector<int> copy_vector(unique_vector.begin(), unique_vector.end());
		std::cout << unique_vector << std::endl;

	}
	//������� 2. ���������� ������ ������ MyUniquePTR, ������� �������� �������� ��� ��������� �� ������ ������ ����.
		//������ � ����� ������ ������������ ����������� �������� ����������� ����������� ��������.
		// ��������� ���������������� ������� �� ������� MyString :
	{
		std::cout << "\nChapter: 2" << std::endl;
		MyUniquePTR<MyString> p1(new MyString("abc"));
		std::cout << "\np1:" << std::endl;
		std::cout << p1->GetString();
		p1->SetNewString("qwerty");
		std::cout << "\np1 after set new string:" << std::endl;
		std::cout << p1->GetString(); 
		MyString  s2 = *p1;
		std::cout << "\ns2:" << std::endl;
		std::cout << s2.GetString();

		//MyUniquePTR<MyString> p2=p1; //����� ���������� ������ �������� ������ 
		// ����������� ������� ������ �� ��������� �������
		// ������	C2280	"MyUniquePTR<MyString>::MyUniquePTR(const MyUniquePTR<MyString> &)": ����������� ������� ������ �� ��������� �������
		// ���������!

		MyUniquePTR<MyString> p2 = std::move(p1);

		// �������� ��������� �������� �������
		if (!p1) {
			std::cout << "\np1 �� �������� ������!" << std::endl;
		}

		MyUniquePTR<MyString> p3(new MyString("vvv"));
		//p3 = p2; //� ����� ���������� ������ �������� ������

		// ������� ������ ������ v
		vector<MyUniquePTR<MyString>> v; //��� �������������������???
		// ���������� �������� emplace_back(), ����� �������� �������� � ������ v
		v.emplace_back(MyUniquePTR<MyString>(new MyString("abc")));
		v.emplace_back(MyUniquePTR<MyString>(new MyString("cde")));
		v.emplace_back(MyUniquePTR<MyString>(new MyString("efg")));

		// � ���������� ������ ��������, � ������� v ����� ��������� ��������� �� ������� ���� mystring, 
		// ��������� � ����� myuniqueptr<mystring>.
		// ������ ������ mystring ����� ��������� ��������������� ������

		std::cout << "\nVector V:" << std::endl;
		// ���������� ���������� ������� v
		for (const auto& element : v) {
			std::cout << element->GetString() << std::endl;
		}

		//list<MyUniquePTR<MyString>> l;
		//��� ����������� �� v � l ???
		list<MyUniquePTR<MyString>> l(make_move_iterator(v.begin()), make_move_iterator(v.end()));

		std::cout << "\nList l:" << std::endl;
		// ���������� ���������� ���� l
		for (const auto& element : l) {
			std::cout << element->GetString() << std::endl;
		}

		std::cout << "\nVector V:" << std::endl;
		// ���������� ���������� ������� v
		for (const auto& element : v) {
			std::cout << element->GetString() << std::endl;
		}

		for (auto& n : v)cout << n->GetString() << "\n";


		return 0;
	}
}