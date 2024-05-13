//Лабораторная работа №2
//initializer_list, move, default, delete, move итераторы
#include <iostream>
//#include "UniqueVector.cpp"
#include "UniqueVector2.cpp"

using namespace std;
int main()
{
// Задание 1. Создайте класс, который должен предоставлять функциональность вектора с УНИКАЛЬНЫМИ значениями любого типа в заданном диапазоне.
	/*
	Например:
	В нашей структуре хранятся целые с уникальными значениями и данных задан диапазон[1, 10].Пользователь хочет добавить в наш вектор{ 2,-1,3,33, 5,2 }. В результате в нашем векторе должны храниться значения{ 2,3,5 }
	Внимание: при инициализации или присваивании НЕ нужно менять порядок значений, заданный пользователем! При наличии повторяющихся значений нужно оставить первое!
		•	Для хранения элементов используйте std::vector.
		o	Вариант 1 : использовать std::vector в качестве внедренного объекта
		o	Вариант 2 : наследовать свой класс от std::vector – при этом важно каким должен быть спецификатор наследования
		Реализовать оба варианта!
		•	Реализуйте конструктор, который может принимать любое количество значений(значения могут повторяться)
		•	Реализуйте метод добавления любого количества значений(значения могут повторяться)
		•	Реализуйте метод удаления любого количества значений(значения могут повторяться)
		•	Предусмотрите возможность изменения диапазона хранимых значений
		•	Реализуйте метод сортировки, который будет принимать в качестве параметра условие сортировки(по возрастанию / по убыванию / по модулю…)
		•	и другие(полезные на Ваш взгляд) методы
		•	явно обозначьте – какие методы вы делегируете сгенерировать компилятору автоматически
		•	реализуйте возможность копирования из нашей структуры данных значения в другое хранилище, например:
	vector<int> v;
	std::copy(my.begin(), my.end(), …);
	*/
	{
		std::cout << "#Chapter: Construct" << std::endl;
		int init_values[] = { 2, -1, 3, 33, 5, 2 };
		UniqueVector<int> unique_vector(1, 10, init_values, 6);

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " " ;
		}

		std::cout << "\n#Chapter: Additional values (1,4,7)" << std::endl;
		// Реализуйте метод добавления любого количества значений(значения могут повторяться)
		int additional_values[] = { 1, 4, 7 };
		unique_vector.add(additional_values, 3);

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " ";
		}

		std::cout << "\n#Chapter: Remove values (2,5)" << std::endl;
		// Реализуйте метод удаления любого количества значений(значения могут повторяться)
		int to_remove[] = { 2, 5 };
		unique_vector.remove(to_remove, 2);

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " ";
		}

		std::cout << "\n#Chapter: Sort values" << std::endl;
		// Реализуйте метод сортировки, который будет принимать в качестве параметра условие сортировки(по возрастанию / по убыванию / по модулю…)
		unique_vector.sort(std::greater<int>());

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " ";
		}

		std::cout << "\n#Chapter: Copy values" << std::endl;
		// Реализуйте возможность копирования из нашей структуры данных значения в другое хранилище, например:
		std::vector<int> copy_vector(unique_vector.begin(), unique_vector.end());

		for (typename std::vector<int>::const_iterator it = unique_vector.begin(); it != unique_vector.end(); ++it) {
			std::cout << *it << " ";
		}
	}
//Задание 2. Реализуйте шаблон класса MyUniquePTR, который является оберткой для указателя на объект любого типа.
	//Задача – класс должен обеспечивать единоличное владение динамически создаваемым объектом.Проверить функционирование шаблона на примере MyString :
	{
		/*
		MyUniquePTR<MyString> p1(new MyString(“abc”));
		std::cout << p1->GetString();
		p1->SetNewString(“qwerty”);
		MyString  s2 = *p1;
		//MyUniquePTR< MyString > p2=p1; //здесь компилятор должен выдавать ошибку => 
		Исправьте!
			If(p1) { std::cout << ”No object!” } //а это должно работать
		MyUniquePTR< MyString > p3(new MyString(“vvv”));
		//p3 = p2; //и здесь компилятор должен выдавать ошибку
		vector< MyUniquePTR< MyString >> v; //как проинициализировать???
		list< MyUniquePTR< MyString >> l;
		//как скопировать из v в l ???
		*/
	}
	return 0;
}