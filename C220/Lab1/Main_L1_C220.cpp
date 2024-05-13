//Практика 1:
// enum class
// initializer_list и универсальные списки инициализации
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
	//Задание 1. 
	{
		std::cout << "Chapter 1: " << std::endl;
		enum class months:unsigned char { January, February, March/*...*/ };
		enum class weekDays { Monday, Tuesday /*...*/ };

		//months m = January;
		//а) уберите проблемы (это значит, что КОМПИЛЯТОР не
		//должен позволять программисту осуществлять опасные
		//сравнения!)
		months m = months::January;
		//if (m == Monday) { cout << 1; }
		//б) оптимизируйте использование памяти
		months year[] = { months::January, months::February, months::March };
		size_t n = sizeof(year); // int 12 char (3)
		std::cout << "Size of year array: " << n << " bytes" << std::endl;
		std::cout << "Size of year array: " << sizeof(year) << " bytes" << std::endl; 
	}
#endif
#if 1
	/**********************************************************/
		//Задание 2. Создайте и с помощью списка инициализации
		//заполните значениями вектор с элементами - string
		//С помощью range-based for преобразуйте все буквы в 	
		//верхний регистр а остальные символы должны остаться
		//неизменными
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
		///Задание 3. Создайте и заполните значениями
		//map двумя способами (3а и 3б) таким образом, чтобы он содержал 
		//в качестве ключа букву, а в качестве значения 
		//отсортированную по алфавиту совокупность слов (string), 
		//начинающихся с этой буквы

		//3а. Проинициализируйте map "вручную" посредством списка инициализации
		//С помощью range-based for и structured binding
		//распечатайте содержимое, например: A: any, apple, away
	{
		std::cout << "Chapter 3a: ";
		// Создаем map с ключами типа char, и значениями string
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
	//3б. Создайте пустой map и используйте заданный массив
	//для выполнения задания.
	//С помощью range-based for и structured binding
	//распечатайте содержимое, например: A: any, apple, away
	{
		std::cout << "\nChapter 3b: ";
		std::map<char, set<string>> mapExample;
		//дано (например):
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
	//Задание 4. создать функцию для вывода на печать
	//элементов последовательностей, заданных ниже:
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
	///Задание 5. 	
	//Cоздать функцию для "отрицания" значений, например:
	//было: {1, -2, 5}, стало: {-1, 2, -5})
	//изменение объектов типа std::string может выглядеть "aBc1" -> "AbC1"
	//элементов последовательностей, заданных ниже:
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
		//Задание 6. Реализовать функцию сортировки по модулю
		//элементов последовательностей, заданных ниже
		//Собственно для сортировки можно использовать обобщенный
		//алгоритм sort(), а для задания условия - лямбда-функцию
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
		//Задание 7.
		//Напишите функцию, которая будет формировать и
		//возвращать вектор, каждый элемент 
		//которого является суммой элементов двух 
		//последовательностей РАЗНОЙ длины
		//и с элементами РАЗНОГО типа.

		//Подсказка 1: так как последовательности могут быть
		//разной длины, логично сделать размер результирующего
		//вектора максимальным из двух

		//Подсказка 2: подумайте о возможности использования
		//алгоритмов copy() и transform(), в котором 
		//трансформирующее действие удобно в свою очередь
		//задавать лямбда-функцией

		//например:
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
		//Задание 8. Реализуйте функцию, которая принимает следующие параметры:	
		//сформированную последовательность любого типа с элементами любого типа, 
		//два (пустых) контейнера любого типа из vector, list, deque, set 
		//с элементами того же типа, что и у сформированной последовательности 
		//Функция должна "разложить" значения заданной последовательности в два пустых контейнера 
		//согласно заданному условию. Условие задать лямбда-функцией
		//Исходная последовательность при этом не меняется
	{
		//Например 1:
		std::vector<int> values{ 1,2,3,4,5 };
		std::list<int> evens; //сюда четные
		std::deque<int> odds; //а сюда нечетные

		partitionEvenOdd(values, evens, odds);
		std::cout << "Чётные: ";
		for (int val : evens) {
			std::cout << val << " ";
		}
		std::cout << "\nНечётные: ";
		for (int val : odds) {
			std::cout << val << " ";
		}
		std::cout << std::endl;

		//Separate(v, l, d, <условие>);


	}
	{
		//2.
		//Разложить согласно условию: те значения, которые попадают в заданный диапазон, в один //контейнер, остальные - в другой
		double ar[] = { 0.8, 1.1, 33.3, -4.1, 5.5 };
		std::set<double> s; //сюда те, которые попадают в [0,6]
		std::vector<double> v; //сюда остальные
	}
#endif
#if 1
	/********************************************************/
		//Задание 9. C помощью алгоритма for_each()!!! 
		//(а не count_if()) посчитать сколько букв в верхнем
		//регистре.
		//  Использовать лямбда функцию
	{
		std::cout << "Chapter 9: " << std::endl;
		char s[] = "Hello World!";
		PrintAnyCont(s);
		std::cout << "Count Upper case: " << countUppercase(s) << std::endl;
	}
#endif
#if 1
	/********************************************************/
		//Задание 10. Реализовать конвертацию enum в строковое представление  - enumToString
		// и наоборот - stringToEnum
		//Подсказки: 
		//***********
		//1. Соответствующие именованным константам строки все равно нужно где-то хранить =>
		//1.1 Именованные константы в перечислении должны быть уникальными => соответствующие строки
		//тоже должны быть уникальными, => уникальные строки могут быть использованы в качестве
		//ключа в std::map
		//1.2 а вот значения (соответствующие именованым константам)
		//могут быть любыми и даже могут повторяться (упрощаем задачу, считая, что значения НЕ повторяются) 
		//=> подходит контейнер std::map<string,<значение> >
		//1.3 Согласно стандарту С++11 переменные перечислимого типа могут быть разного размера и типа,
		//а хотелось бы обеспечить универсальную конвертацию 
		//***********
		//2.1 Так как типы перечислений разные, то enumToString и stringToEnum должны быть шаблонными
		//2.2 Пользователь может ошибиться или злонамеренно передать в функции значения, которым
		//   ничего не соответствует => защита!
		//***********
		//3. Чтобы действия с map<string, <значение> > не зависили от типа перечисления, подумайте над использованием
		//шаблонной переменной (в частности вспомните о возможности специялизации шаблонной переменной)
		//***********
	{
		std::cout << "Chapter 10: " << std::endl;
		Color color = Color::Green;
		std::string colorStr = enumToString(color);
		std::cout << "Enum в строку: " << colorStr << std::endl;
		std::string str = "Синий";
		try {
			Color newColor = stringToEnum(str);
			std::cout << "Строка в enum: " << enumToString(newColor) << std::endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
	}
#endif
	return 0;
}
