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
		std::cout << "\nChapter 2: " << std::endl;
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
		std::cout << "\nChapter 3a: ";
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
		std::cout << "\nChapter 4: " << endl;
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
		std::cout << "\nChapter 5: " << std::endl;
		std::vector<double> vd{ 1.1,2.2,3.3 };
		NegateAll(vd);
		PrintAnyCont(vd);
		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		NegateAll(ls);
		PrintAnyCont(ls);
		int ar[]{ 1, -2, 3, 10,-3 };
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
		std::cout << "\nChapter 6: " << std::endl;
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		std::cout << " Original vector" << std::endl; 
		PrintAnyCont(vd);
		absSort(vd);
		std::cout << " Sorted vector" << std::endl;
		PrintAnyCont(vd);
		std::cout << " Original Arr" << std::endl;
		int ar[] = { -3, 2, -1 };
		PrintAnyCont(ar);
		absSort(ar);
		std::cout << " Sorted Arr" << std::endl;
		PrintAnyCont(ar);
	}
#endif
#if 1
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
		std::cout << "\nChapter 7: " << std::endl;
		std::vector<int> v{ 1,2,3,4 };
		std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };

		auto summed1 = sumContainers(v, l);
		PrintAnyCont(summed1);
		
		std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
		double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		auto summed2 = sumContainers(ll, ar); 
		PrintAnyCont(summed2);

		std::set<std::string> s{ "abc", "qwerty", "my" };
		std::deque<const char*> d{ "111", "22" };
		auto summed3 = sumContainers(s, d);
		PrintAnyCont(summed3);

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
		std::cout << "\nChapter 8.1: " << std::endl;
		std::vector<int> values{ 1,2,3,4,5 };
		std::cout << " Original vector: " << std::endl;
		PrintAnyCont(values);
		std::list<int> evens; //���� ������
		std::deque<int> odds; //� ���� ��������

		// ���������� �������� �� ������ � �������� � �������������� ������-�������
		Separate(values, evens, odds, [](int x) { return x % 2 == 0; });
		std::cout << "׸����: ";
		for (int val : evens) {
			std::cout << val << " ";
		}
		std::cout << "\n��������: ";
		for (int val : odds) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\nChapter 8.2: " << std::endl;
		//2. ��������� �������� �������: �� ��������, ������� �������� � �������� ��������, 
		// � ���� ���������, ��������� - � ������
		double values[] = { 0.8, 1.1, 33.3, -4.1, 5.5 };
		std::set<double> s; //���� ��, ������� �������� � [0,6]
		std::vector<double> v; //���� ���������
		int start = 0, end = 6;
		std::cout << " Original: " << std::endl;
		PrintAnyCont(values);

		Separate(values, s, v, [start, end](const auto a) {return a >= start && a <= end; });
		std::cout << " in diap " << std::endl;
		PrintAnyCont(s);
		std::cout << " out diap " << std::endl;
		PrintAnyCont(v);

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
		std::cout << "\nChapter 10: " << std::endl;
		Color color = Color::Green;
		std::string colorStr = enumToString(color);
		std::cout << "Enum � ������: " << colorStr << std::endl;
		std::string str = "�����";
		try {
			Color newColor = stringToEnum<Color>(str);
			std::cout << "������ � enum: " << enumToString(newColor) << std::endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}

		// ������ ������������� ��� ���� ������
		day dayValue = day::friday;
		std::string dayStr = enumToString(dayValue);
		std::cout << "Enum � ������ (���� ������): " << dayStr << std::endl;

		str = "�����";
		try {
			day newDay = stringToEnum<day>(str);
			std::cout << "������ � Enum (���� ������): " << enumToString(newDay) << std::endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
	}
#endif
	return 0;
}
