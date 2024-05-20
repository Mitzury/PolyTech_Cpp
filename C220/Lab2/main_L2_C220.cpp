//Лабораторная работа №2
//initializer_list, move, default, delete, move итераторы


//#include "UniqueVector.h"
#include "UniqueVector2.h"

#include "MyString.h"
#include "MyUniquePTR.h"
#include <list>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Ru");
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
		std::cout << "Chapter: 1" << std::endl;
		std::cout << "#Chapter: Construct" << std::endl;
		UniqueVector<int> unique_vector(1, 10, { 2, -1, 3, 33, 5, 2 });
		std::cout << unique_vector << std::endl;

		std::cout << "\n#Chapter: Additional values (1,4,7)" << std::endl;
		// Реализуйте метод добавления любого количества значений(значения могут повторяться)
		unique_vector.add({ 1, 4, 7 });
		std::cout << unique_vector << std::endl;

		std::cout << "\n#Chapter: Remove values (2,5)" << std::endl;
		// Реализуйте метод удаления любого количества значений(значения могут повторяться)
		int to_remove[] = { 2, 5 };
		unique_vector.remove(to_remove, 2);
		std::cout << unique_vector << std::endl;

		std::cout << "\n#Chapter: Sort values" << std::endl;
		// Реализуйте метод сортировки, который будет принимать в качестве параметра условие сортировки
		// (по возрастанию / по убыванию / по модулю…)
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
		// Реализуйте возможность копирования из нашей структуры данных значения в другое хранилище, например:
		std::vector<int> copy_vector(unique_vector.begin(), unique_vector.end());
		std::cout << unique_vector << std::endl;

	}
	//Задание 2. Реализуйте шаблон класса MyUniquePTR, который является оберткой для указателя на объект любого типа.
		//Задача – класс должен обеспечивать единоличное владение динамически создаваемым объектом.
		// Проверить функционирование шаблона на примере MyString :
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

		//MyUniquePTR<MyString> p2=p1; //здесь компилятор должен выдавать ошибку 
		// предпринята попытка ссылки на удаленную функцию
		// Ошибка	C2280	"MyUniquePTR<MyString>::MyUniquePTR(const MyUniquePTR<MyString> &)": предпринята попытка ссылки на удаленную функцию
		// Исправьте!

		MyUniquePTR<MyString> p2 = std::move(p1);

		// Проверка оператора проверки наличия
		if (!p1) {
			std::cout << "\np1 не содержит объект!" << std::endl;
		}

		MyUniquePTR<MyString> p3(new MyString("vvv"));
		//p3 = p2; //и здесь компилятор должен выдавать ошибку

		// Создаем пустой вектор v
		vector<MyUniquePTR<MyString>> v; //как проинициализировать???
		// Используем оператор emplace_back(), чтобы добавить элементы в вектор v
		v.emplace_back(MyUniquePTR<MyString>(new MyString("abc")));
		v.emplace_back(MyUniquePTR<MyString>(new MyString("cde")));
		v.emplace_back(MyUniquePTR<MyString>(new MyString("efg")));

		// В результате данных действий, в векторе v будут храниться указатели на объекты типа mystring, 
		// обернутые в класс myuniqueptr<mystring>.
		// Каждый объект mystring будет содержать соответствующую строку

		std::cout << "\nVector V:" << std::endl;
		// напечатать содержимое вектора v
		for (const auto& element : v) {
			std::cout << element->GetString() << std::endl;
		}

		//list<MyUniquePTR<MyString>> l;
		//как скопировать из v в l ???
		list<MyUniquePTR<MyString>> l(make_move_iterator(v.begin()), make_move_iterator(v.end()));

		std::cout << "\nList l:" << std::endl;
		// напечатать содержимое лист l
		for (const auto& element : l) {
			std::cout << element->GetString() << std::endl;
		}

		std::cout << "\nVector V:" << std::endl;
		// напечатать содержимое вектора v
		for (const auto& element : v) {
			std::cout << element->GetString() << std::endl;
		}

		for (auto& n : v)cout << n->GetString() << "\n";


		return 0;
	}
}