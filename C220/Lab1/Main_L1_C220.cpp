//�������� 1:
// enum class
// initializer_list � ������������� ������ �������������
// auto
// decltype
// lambda 
// template variable


#include "T.h"
#include <deque>

using namespace std;

int main() {
setlocale(LC_ALL, "Russian");
#if 1
	//������� 1. 
	{
		std::cout << "Chapter 1: " << std::endl;
		enum class months:unsigned char { January, February, March/*...*/ };
		enum class weekDays { Monday, Tuesday /*...*/ };

		//months m = January;
		//�) ������� �������� (��� ������, ��� ���������� ��
		//������ ��������� ������������ ������������ �������
		//���������!)
		months m = months::January;
		//if (m == Monday) { cout << 1; }
		//�) ������������� ������������� ������
		months year[] = { months::January, months::February, months::March };
		size_t n = sizeof(year); // int 12 char (3)
		std::cout << "Size of year array: " << n << " bytes" << std::endl;
		std::cout << "Size of year array: " << sizeof(year) << " bytes" << std::endl; 
	}
#endif
#if 1
	/**********************************************************/
		//������� 2. �������� � � ������� ������ �������������
		//��������� ���������� ������ � ���������� - string
		//� ������� range-based for ������������ ��� ����� � 	
		//������� ������� � ��������� ������� ������ ��������
		//�����������
	{
		std::cout << "Chapter 2: " << std::endl;
		std::vector<string> words = { "hello", "world" };
		for (auto& word : words) {
			//std::transform(word.begin(), word.end(), word.begin(), ::toupper);
			for (auto& str : word) {
				str = toupper(str);
			}
		}
		PrintAnyCont(words);
	}
#endif
#if 1
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
		std::cout << "Chapter 3a: ";
		// ������� map � ������� ���� char, � ���������� string
		std::map<char, set<string>> mapExample;

		mapExample['A'] = { "away", "apple", "any" };
		mapExample['B'] = { "ball", "banana", "brown" };
		mapExample['C'] = { "cat", "car", "city" };

		for (const auto& [key, value] : mapExample) {
			std::cout << endl << key << ": ";
			for (const auto& value : value) {
				std::cout << value << " ";
			}
		}
	}
	//3�. �������� ������ map � ����������� �������� ������
	//��� ���������� �������.
	//� ������� range-based for � structured binding
	//������������ ����������, ��������: A: any, apple, away
	{
		std::cout << "\nChapter 3b: ";
		std::map<char, set<string>> mapExample;
		//���� (��������):
		const char* s[] = { "yong", "away", "bar", "any", "son", "Apple", "Boris"};
		for (auto str : s) {
			mapExample[toupper(*str)].insert(str);
		}
		for (const auto& [key, value] : mapExample) {
			std::cout << endl << key << ": ";
			for (const auto& value : value) { 
				std::cout << value << ", ";
			}
		}
	}
#endif
#if 1
	/*********************************************************/
	//������� 4. ������� ������� ��� ������ �� ������
	//��������� �������������������, �������� ����:
	{
		std::cout << "\nChapter 4b: " << endl;
		std::vector<double> vd = { 1.1,2.2,3.3 };
		PrintAnyCont(vd);

		std::string s("abc");
		PrintAnyCont(s);

		int ar[] = { 1, 2, 3 };
		PrintAnyCont(ar);

		std::initializer_list<int> il{ 3,4,5 };
		PrintAnyCont(il);		
	}
#endif
#if 1
	/********************************************************/
	///������� 5. 	
	//C������ ������� ��� "���������" ��������, ��������:
	//����: {1, -2, 5}, �����: {-1, 2, -5})
	//��������� �������� ���� std::string ����� ��������� "aBc1" -> "AbC1"
	//��������� �������������������, �������� ����:
	{
		std::cout << "Chapter 5: " << std::endl;
		std::vector<double> vd{ 1.1,2.2,3.3 };
		NegateAll(vd);
		PrintAnyCont(vd);

		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		NegateAll(ls);
		PrintAnyCont(ls);

		int ar[]{ 1, -2, 3 };
		NegateAll(ar);
		PrintAnyCont(ar);
	}
#endif
#if 1
	/********************************************************/
		//������� 6. ����������� ������� ���������� �� ������
		//��������� �������������������, �������� ����
		//���������� ��� ���������� ����� ������������ ����������
		//�������� sort(), � ��� ������� ������� - ������-�������
	{
		std::cout << "Chapter 6: " << std::endl;
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		std::cout << " Original" << std::endl; 
		PrintAnyCont(vd);
		absSort(vd);
		std::cout << " Sorted" << std::endl;
		PrintAnyCont(vd);

		int ar[] = { -3, 2, -1 };
		//absSort(ar);
	}
#endif
#if 0
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

	}
#endif
#if 1
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
		std::vector<int> values{ 1,2,3,4,5 };
		std::list<int> evens; //���� ������
		std::deque<int> odds; //� ���� ��������

		partitionEvenOdd(values, evens, odds);
		std::cout << "׸����: ";
		for (int val : evens) {
			std::cout << val << " ";
		}
		std::cout << "\n��������: ";
		for (int val : odds) {
			std::cout << val << " ";
		}
		std::cout << std::endl;

		//Separate(v, l, d, <�������>);


	}
	{
		//2.
		//��������� �������� �������: �� ��������, ������� �������� � �������� ��������, � ���� //���������, ��������� - � ������
		double ar[] = { 0.8, 1.1, 33.3, -4.1, 5.5 };
		std::set<double> s; //���� ��, ������� �������� � [0,6]
		std::vector<double> v; //���� ���������
	}
#endif
#if 1
	/********************************************************/
		//������� 9. C ������� ��������� for_each()!!! 
		//(� �� count_if()) ��������� ������� ���� � �������
		//��������.
		//  ������������ ������ �������
	{
		std::cout << "Chapter 9: " << std::endl;
		char s[] = "Hello World!";
		PrintAnyCont(s);
		std::cout << "Count Upper case: " << countUppercase(s) << std::endl;
	}
#endif
#if 1
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
		std::cout << "Chapter 10: " << std::endl;
		Color color = Color::Green;
		std::string colorStr = enumToString(color);
		std::cout << "Enum � ������: " << colorStr << std::endl;
		std::string str = "�����";
		try {
			Color newColor = stringToEnum(str);
			std::cout << "������ � enum: " << enumToString(newColor) << std::endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
	}
#endif
	return 0;
}
