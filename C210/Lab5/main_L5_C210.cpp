// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <tchar.h>
#include "Rect.h"
#include "T.h"

using namespace std;
#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[]) {
setlocale(LC_ALL, "Ru");
///////////////////////////////////////////////////////////////////
cout << "Задание 1. Итераторы\n" << endl;
//Задание 1. Итераторы
//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
//являются копиями элементов set, но упорядочены по убыванию

// Создаем set из точек
	set<Point> pointsSet;
	pointsSet.insert(Point(1, 2));
	pointsSet.insert(Point(3, 4));
	pointsSet.insert(Point(5, 6));

// Создаем вектор, который будет хранить элементы set в обратном порядке
	vector<Point> pointsVector(pointsSet.rbegin(), pointsSet.rend());

//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
//vector и set из предыдущего задания на экран.
// Выводим содержимое set с помощью ostream_iterator
	cout << "Содержимое set: ";
	copy(pointsSet.begin(), pointsSet.end(), ostream_iterator<Point>(cout, " "));
	cout << endl;

// Выводим содержимое vector
	cout << "Содержимое вектора (в обратном порядке): ";
	copy(pointsVector.begin(), pointsVector.end(), ostream_iterator<Point>(cout, " "));
	cout << endl;

//Итераторы вставки. С помощью возвращаемых функциями:
//back_inserter()
//front_inserter()
//inserter()
//итераторов вставки добавьте элементы в любой из созданных контейнеров. 

// Демонстрируем использование различных итераторов вставки
// Используем back_inserter для добавления в vector
	vector<Point> additionalPoints;
	additionalPoints.push_back(Point(7, 8));
	copy(additionalPoints.begin(), additionalPoints.end(), back_inserter(pointsVector));


// Показываем обновленное содержимое vector
	cout << "Обновлённый vector: ";
	copy(pointsVector.begin(), pointsVector.end(), ostream_iterator<Point>(cout, " "));
	cout << endl;

//Подумайте:
//какие из итераторов вставки можно использовать с каждым контейнером.
// Объяснение использования итераторов вставки:
	// back_inserter работает с контейнерами, поддерживающими операцию push_back (например, vector, deque).
	// front_inserter подходит для контейнеров с push_front (например, deque, list).
	// inserter используется для ассоциативных контейнеров, таких как set, map.


///////////////////////////////////////////////////////////////////
//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	cout << "\n\nЗадание 2. Обобщенные алгоритмы\n" << endl;

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон;


	// Создаем вектор целых чисел
	vector<int> numbers = { 1, 2, 3, 4, 5 };
	cout << "Исходный вектор целых чисел: ";
	for_each(numbers.begin(), numbers.end(), printElement<int>);
	cout << endl;


	// Создаем вектор точек
	vector<Point> points = { Point(1, 2), Point(3, 4), Point(5, 6) };
	cout << "Исходный вектор точек: ";
	for_each(points.begin(), points.end(), printElement<Point>);
	cout << endl;

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката

	// Изменяем координаты всех точек в векторе
	for_each(points.begin(), points.end(), [&](Point& p) { changePoint(p, 10, 20); });
	cout << "Измененный вектор точек: ";
	for_each(points.begin(), points.end(), printElement<Point>);
	cout << endl;

	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
	// Поиск конкретной точки в векторе
	Point searchPoint(10, 20); // точка, которую ищем
	vector<Point>::iterator it = find(points.begin(), points.end(), searchPoint);
	if (it != points.end()) {
		cout << "Точка найдена: " << *it << endl;
	}
	else {
		cout << "Точка не найдена" << endl;
	}

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!

	// Создание и сортировка вектора точек
	vector<Point> pointss = { Point(1, 2), Point(-1, -2), Point(5, 6) };
	sort(pointss.begin(), pointss.end()); // Сортировка точек по умолчанию
	cout << "Отсортированные точки: ";
	for (const Point& p : pointss) {
		cout << p << " ";
	}
	cout << endl;

	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].
	// Поиск точки с координатами в заданном диапазоне
	int n = -10, m = 10; // Задаем диапазон координат
	vector<Point>::iterator foundPoint = find_if(pointss.begin(), pointss.end(), [n, m](const Point& p) {
		return p.x >= n && p.x <= m && p.y >= n && p.y <= m;
		});
	if (foundPoint != pointss.end()) {
		cout << "Найдена точка в заданном диапазоне: " << *foundPoint << endl;
	}
	else {
		cout << "Точка в заданном диапазоне не найдена." << endl;
	}

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.

	// Создание вектора прямоугольников
	vector<Rect> rects = {
		Rect(Point(0, 0), 2, 4),
		Rect(Point(3, 3), 5, 5),
		Rect(Point(1, 1), 2, 2)
	};


	// Сортировка прямоугольников по удаленности от начала координат
	sort(rects.begin(), rects.end(), compareRects);
	cout << "Отсортированные прямоугольники по удаленности от начала координат: ";
	for (const Rect& r : rects) {
		cout << r << "; ";
	}
	cout << endl;
	cout << "\n\ntransform\n" << endl;
	//transform
//Напишите функцию, которая с помощью алгоритма transform переводит 
//содержимое объекта string в нижний регистр.
//Подсказка: класс string - это "почти" контейнер, поэтому для него
// определены методы begin() и end()
// Преобразование строки в нижний регистр

	string exampleStr = "Hello, World!";
	string lowerStr = toLowerCase(exampleStr);
	cout << "Преобразованная строка в нижний регистр: " << lowerStr << endl;

//Заполните list объектами string. С помощью алгоритма transform сформируте
//значения "пустого" set, конвертируя строки в нижний регистр
// Заполнение list строками

	list<string> stringList = { "One", "Two", "Three" };
	set<string> stringSet;

// Конвертация строк list в нижний регистр и заполнение set
	transform(stringList.begin(), stringList.end(), inserter(stringSet, stringSet.end()), toLowerCase);
	cout << "Содержимое set после преобразования: ";
	for (const auto& str : stringSet) {
		cout << str << " ";
	}
	cout << endl;

	cout << "\n\ncopy_if\n" << endl;
	{
	//copy_if
	//Дан вектор с элементами типа string. С помощью copy_if() требуется
	//вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
	//При этом порядок строк в исходном векторе менять не нужно!


	// Вектор строк для демонстрации работы copy_if

		vector<string> words = { "Apple", "авокадо", "Апельсин", "банан", "Барбарис" };

	// Вывод строк, начинающихся с определенной буквы
		for (char letter = 'А'; letter <= 'Б'; ++letter) {
			cout << "Строки, начинающиеся с буквы " << letter << ": ";
			copy_if(words.begin(), words.end(), ostream_iterator<string>(cout, " "), [letter](const string& str) {
				return str.size() > 0 && (str[0] == letter || str[0] == tolower(letter));
				});
			cout << endl;
		}


	//Дан multimap, содержаций пары: "месяц - количество денй в месяце"
	//pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
	//с парами, содержащими четное количество дней, 2-ой - нечетное.
	// Multimap с количеством дней в месяце

		multimap<string, int> month{
			{"Январь", 31}, {"Февраль", 28}, {"Февраль", 29}, { "Март", 31},
			{"Апрель", 30}, {"Май",31}, {"Июнь", 30}, {"Июль", 31}, {"Август",31},
			{"Сентябрь",30}, {"Октябрь", 31}, {"Ноябрь",30}, {"Декабрь",31}
		};

	// Создание двух map из multimap: для четного и нечетного количества дней

		map<string, int> evenDays, oddDays;
		for (const auto& m : month) {
			if (m.second % 2 == 0) {
				evenDays.insert(m);
			}
			else {
				oddDays.insert(m);
			}
		}


	// Вывод содержимого map с четным количеством дней
		cout << "Месяцы с четным количеством дней: ";
		for (const auto& pair : evenDays) {
			cout << pair.first << " ";
		}
		cout << endl;

	// Вывод содержимого map с нечетным количеством дней
		cout << "Месяцы с нечетным количеством дней: ";
		for (const auto& pair : oddDays) {
			cout << pair.first << " ";
		}
		cout << endl;

	//Распечатайте multimap и map-ы, используя написанный вами ранее шаблон
	//функции, выводящей элементы ЛЮБОГО контейнера на печать.
	//Что нужно сделать дополнительно для вывода пары?

		cout << "\n\nВывод мультимап\n" << endl;

	// Вывод multimap и map

		cout << "Multimap (month):" << endl;
		printContainer(month);
		cout << "\nMap (even days):" << endl;
		printContainer(evenDays);
		cout << "\nMap (odd days):" << endl;
		printContainer(oddDays);
	}
	return 0;
};
