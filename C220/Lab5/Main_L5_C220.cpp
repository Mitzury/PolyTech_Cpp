#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>
#include <list>

#include "T.h"
#include "human.h"

int main() {
	setlocale(LC_ALL, "Ru");
	using namespace std;
	//Задание 1. unique_ptr
	{
		//1.а - обеспечьте корректное выполнение фрагмента
		{
			cout << "\t Chapter 1a: " << endl;
			std::vector<std::string*> v = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			//Распечатайте все строки
			for (std::string* str : v) {
				// Распечатываем строку, на которую указывает указатель
				std::cout << *str << std::endl;
			}
			// Освобождаем память, выделенную для строк
			for (std::string* str : v) {
				delete str;
			}
		}
	//1.b - модифицируйте задание 1.а:
		 //обеспечьте посредством std::unique_ptr: 
		 //эффективное заполнение (вспомните про разные способы формирования std::unique_ptr), 
		 //безопасное хранение указателей на динамически создаваемые объекты std::string, 
		 //манипулирование,
		 //и освобождение ресурсов
		{
			cout << "\t ************** " << endl;
			std::cout << "\t chapter 1b: " << std::endl;
			// Создаем вектор умных указателей на строки std::unique_ptr<std::string>
			std::vector<std::unique_ptr<std::string>> v;
			// Вспомним про разные способы формирования std::unique_ptr и добавим строки в вектор
			v.push_back(std::make_unique<std::string>("aa")); 
			v.push_back(std::make_unique<std::string>("bb"));
			v.push_back(std::make_unique<std::string>("cc")); 

			// Распечатаем все строки
			for (const auto& str : v) {
				// распечатываем строку, на которую указывает умный указатель
				std::cout << *str << std::endl;
			}
			//??? Уничтожение динамически созданных объектов?
			// У памяти, выделенной для строк, будет освобождена автоматически благодаря умным указателям
		}

		{//1.c - дополните задание 1.b добавьте возможность изменять хранящиеся строки
		 //следующим образом (например, добавить указанный суффикс: "AAA" -> "AAA_1")  
			cout << "\t ************** " << endl;
			std::cout << "\t chapter 1с: " << std::endl;
			// Создаем вектор умных указателей на строки std::unique_ptr<std::string>
			std::vector<std::unique_ptr<std::string>> v;
			// Вспомним про разные способы формирования std::unique_ptr и добавим строки в вектор
			v.push_back(std::make_unique<std::string>("aa"));
			v.push_back(std::make_unique<std::string>("bb"));
			v.push_back(std::make_unique<std::string>("cc"));

			std::cout << "before modify: " << std::endl;
			// Распечатаем все строки
			for (const auto& str : v) {
				// распечатываем строку, на которую указывает умный указатель
				std::cout << *str << std::endl;
			}
			// изменяем хранящиеся строки
			for (auto& str : v) {
				*str += "_1"; // добавляем суффикс "_1" к каждой строке
			}
			std::cout << "after modify: " << std::endl;
			// Распечатаем все строки
			for (const auto& str : v) {
				// распечатываем строку, на которую указывает умный указатель
				std::cout << *str << std::endl;
			}
		}
		//1.d - динамический массив объектов	
		//Создайте unique_ptr, который является оберткой для динамического массива
		//с элементами std::string
		//С помощью unique_ptr::operator[] заполните обернутый массив значениями
		//Когда происходит освобождения памяти?
		{
			cout << "\t ************** " << endl;
			cout << "\t Chapter 1d: " << endl;

			// Создаем умный указатель на массив из трех элементов типа std::string
			std::unique_ptr<std::string[]> arr(new std::string[3]);
			// Заполняем массив значениями с помощью operator[]
			arr[0] = "Hello";
			arr[1] = "World";
			arr[2] = "!";
			// Выводим элементы массива
			for (int i = 0; i < 3; ++i) {
				std::cout << arr[i] << std::endl;
			}
			// Умный указатель автоматически освобождает память при выходе из области видимости

		}
		//1.e - массивы динамических объектов и пользовательская delete-функция (функтор)
		//Задан стековый массив указателей на динамически созданные объекты
		//Создайте unique_ptr для такого массива
		//Реализуйте пользовательскую delete-функцию (функтор) для корректного 
		//освобождения памяти
		{
			cout << "\t ************** " << endl;
			cout << "\t Chapter 1e: " << endl;
			string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			// Вычисление количества элементов в массиве
			size_t n = sizeof(arStrPtr) / sizeof(arStrPtr[0]);
	
		}
		//1.f Создайте и заполните вектор, содержащий unique_ptr для указателей на std::string
		//Посредством алгоритма copy() скопируйте элементы вектора в пустой список с элементами 
		//того же типа
		//Подсказка: перемещающие итераторы и шаблон std::make_move_iterator
		{
			cout << "\t ************** " << endl;
			cout << "\t Chapter 1f: " << endl;
			// Создаем вектор unique_ptr<string>
			vector<unique_ptr<string>> vector;

			// Добавляем элементы в вектор
			vector.push_back(std::unique_ptr<std::string>(new std::string("aa")));
			vector.push_back(std::unique_ptr<std::string>(new std::string("bb")));
			vector.push_back(std::unique_ptr<std::string>(new std::string("сс")));
			vector.push_back(std::unique_ptr<std::string>(new std::string("dd")));

			printContainer(vector);
			// Создаем список unique_ptr<string> размером, равным размеру вектора
			list<unique_ptr<string>> list(vector.size()); 

			// Копируем элементы из вектора в список с помощью move_iterator
			copy(std::make_move_iterator(vector.begin()), std::make_move_iterator(vector.end()), list.begin());

			printContainer(list);

		}
	}
	////////////////////////////////////////////////////////////////////////////////
	//Задание 2.shared_ptr + пользовательская delete-функция 

	//Реализовать возможность записи в файл данных (строчек) из разных источников 
	//Так как все "писатели" будут по очереди записывать свои данные в один и тот же файл,
	//логично предоставить им возможность пользоваться одним и тем же объектом потока вывода =>
	//безопасной оберткой для такого указателя является shared_ptr
	//а. Первый владелец должен открыть/создать файл для записи
	//б. Все остальные писатели должны присоединиться к использованию
	//в. Последний владелец указателя должен закрыть файл

	//Подсказка: имитировать порядок записи можно с помощью функции rand()
	//"писатели":
	//Создать writer1, writer2
	{
	cout << "\t ************** " << endl;
	cout << "\t Chapter 2: " << endl;
	std::shared_ptr<std::ofstream> logFile(new ofstream("log.txt"));
	// Проверяем, удалось ли открыть файл
	if (!logFile || !logFile->is_open()) {
		std::cerr << "Error: Unable to open file for writing!" << std::endl;
		return 1;
	}
	// Создаем "писателей"
	std::string writer1 = "Writer 1";
	std::string writer2 = "Writer 2";
	// Задаем количество итераций
	int iterations = 10;
	// Имитируем случайный порядок записи
	for (int i = 0; i < iterations; ++i) {
		// Случайным образом выбираем, какой писатель будет писать
		int randomWriter = rand() % 2;

		// Пишем в файл в зависимости от результата выбора
		if (randomWriter == 0) {
			writeToLogFile(logFile, writer1);
		}
		else {
			writeToLogFile(logFile, writer2);
		}
	}
	// Последний владелец закрывает файл
	logFile->close();

	std::cout << "Writing to file completed successfully!" << std::endl;
	//заданное число итераций случайным образом позволяем одному из "писателей" записать в файл
	//свою строчку


	}//закрытие файла???
	/***************************************************************/
	//Задание 3.
	{
		//Дан массив элементов типа string
		std::string strings[] = { "abc", "123", "qwerty", "#$%" };
		//До завершения фрагмента строки должны существовать в единственном экземпляре.
		//Требуется обеспечить манипулирование строками а) без копирования и б) без изменения порядка
		//элементов в массиве!
		//В std::set "складываем" по алфавиту обертки для строк, которые содержат только буквы 
		/******************************************************************************************/
		//В std::vector "складываем" обертки для строк, которые содержат только цифры 
		//Выводим на экран
		//Находим сумму
		//std::vector<std::shared_ptr < std::string>>
		/******************************************************************************************/
		//сюда "складываем" обертки для строк, которые не содержат ни символов букв, ни символов цифр
		//и просто выводим
		cout << "\t ************** " << endl;
		cout << "\t Chapter 3: " << endl;
		std::set<AlphabeticalString> alphabeticalSet;
		std::vector<std::shared_ptr<NumericString>> numericVector;
		std::vector<std::string> otherStrings;

		for (const auto& str : strings) {
			bool isAlphabetical = true;
			bool isNumeric = true;
			for (char ch : str) {
				if (!std::isalpha(ch)) {
					isAlphabetical = false;
				}
				if (!std::isdigit(ch)) {
					isNumeric = false;
				}
			}
			if (isAlphabetical) {
				alphabeticalSet.insert(AlphabeticalString(str));
			}
			else if (isNumeric) {
				numericVector.push_back(std::make_shared<NumericString>(str));
			}
			else {
				otherStrings.push_back(str);
			}
		}
		// Вывод отсортированных по алфавиту строк, содержащих только буквы
		std::cout << "Вывод отсортированных по алфавиту строк, содержащих только буквы:" << std::endl;
		for (const auto& str : alphabeticalSet) {
			std::cout << str.value << std::endl;
		}
		std::cout << std::endl;
		// Вывод строк, содержащих только цифры, и их суммы
		std::cout << "Вывод строк, содержащих только цифры, и их суммы:" << std::endl;
		int sum = 0;

		for (const auto& ptr : numericVector) {
			std::cout << ptr->value << "Вывод строк, содержащих только цифры, и их суммы: " << ptr->sumDigits() << std::endl;
			sum += ptr->sumDigits();
		}
		std::cout << "Total sum of digits: " << sum << std::endl;
		// Вывод остальных строк
		std::cout << "Other Strings:" << std::endl;
		for (const auto& str : otherStrings) {
			std::cout << str << std::endl;
		}
	}
	/******************************************************************************************/
	//Задание 4. 
	{
	//Дано:
		cout << "\t ************** " << endl;
		cout << "\t Chapter 4: " << endl;
		std::string ar[] = { "my","Hello", "World" };
		std::vector < std::shared_ptr<std::string>> v = { std::make_shared<std::string>("good"), std::make_shared<std::string>("bye") };

	//а) Требуется добавить в вектор обертки для элементов массива, НЕ копируя элементы массива! 
		// Добавляем в вектор обертки для элементов массива, не копируя элементы массива
		for (const auto& str : ar) {
			v.push_back(std::make_shared<std::string>(str));
		}
	//б) Отсортировать вектор по алфавиту и вывести на экран
		// Сортируем вектор по алфавиту
		std::sort(v.begin(), v.end(), [](const std::shared_ptr<std::string>& a, const std::shared_ptr<std::string>& b) {
			return *a < *b;
			}); 
		//в) Обеспечить корректное освобождение памяти
		// Выводим отсортированный вектор на экран
		std::cout << "Sorted Vector:" << std::endl;
		for (const auto& ptr : v) {
			std::cout << *ptr << std::endl;
		}
		v.clear();
	}
	/***************************************************************/
		//Задание 5. shared_ptr и weak_ptr
		//Создаем генеалогическое дерево посредством класса human. В классе хранятся:
		//имя - string
		//возможно признак: жив или уже нет...
		//родители - shared_ptr (родители не всегда известны...)
		//дети - контейнер из weak_ptr (чтобы избежать циклических зависимостей)
		//Методы класса human:
		//конструктор - для инициализации имени и признака
		//конструктор копирования, оператор присваивания, move ???
		//статический метод child() - 
		//				должен создать создать и вернуть обертку для родившегося человека
		//				+ сформировать все связи ребенка с родителями и наоборот
		//Ввести возможность распечатать генеалогическое дерево для указанного индивидума

	{
		//История должна с кого-то начинаться => "Жили-были дед да баба, например, Адам и Ева"
		//(то есть на самом деле два деда и две бабы):
		//std::shared_ptr<human> grandM1(new human("Eva"));
		//...
		//у них появились дети - child():
		//а у детей в свою очередь свои дети:
		//...

		// Создаем "деда" и "бабу" - начало истории
		cout << "\t ************** " << endl;
		cout << "\t Chapter 5: " << endl;
		shared_ptr<human> Adam(new human("Адам", false));
		shared_ptr<human> Eva(new human("Ева"));

		// Создаем их ребенка
		shared_ptr<human> child1 = human::child("Авель", Adam, Eva);
		shared_ptr<human> child2 = human::child("Каин", Adam, Eva);
		shared_ptr<human> child3 = human::child("Сиф", Adam, Eva);

		shared_ptr<human> Enoh = human::child("Енох", child3, nullptr);
		shared_ptr<human> Noeh = human::child("Ной", Enoh, nullptr);
		shared_ptr<human> Sim = human::child("Сим", Noeh, nullptr);
		shared_ptr<human> Avraam = human::child("Авраам", Sim, nullptr);

		shared_ptr<human> Sara(new human("Сара"));
		shared_ptr<human> Iisaak = human::child("Исаак", Avraam, Sara);

		// Печатаем генеалогическое дерево для ребенка
		cout << "Адам познал Еву, жену свою; и она зачала,\n"
			"и родила Каина, и сказала: приобрела я человека от Господа.\n"
			"И еще родила брата его, Авеля. И был Авель пастырь овец, \n"
			"а Каин был земледелец» (Быт.4: 1-2)." << endl;

		Adam->printFamilyTree();
		//Noeh->printReverseFamilyTree();
	}

	return 0;
};
