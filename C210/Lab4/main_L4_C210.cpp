﻿// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"

#include "T.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений

	std::cout << "Chapter 1:" << std::endl;
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout << "Stack: " << std::endl; 
	Show(stk);

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << "Queue: " << std::endl;
	Show(q);

	priority_queue<int> pq;
	pq.push(3);
	pq.push(1);
	pq.push(2);
	cout << "Priority Queue: " << std::endl;
	Show(pq);

	////////////////////////////////////////////////////////////////////////////////////
	//stack
	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 

	std::cout << "Chapter 2 stack:" << std::endl;
	vector<int> vec = { 1, 2, 3, 4, 5 }; // Исходный вектор
	stack<int> stkСopied;

	// Копирование элементов вектора в стек в обратном порядке
	for (int i = vec.size() - 1; i >= 0; --i) {
		stkСopied.push(vec[i]);
	}

	// Выводим исходный вектор
	cout << "Исходный вектор: ";
	for (int num : vec) {
		cout << num << ' ';
	}
	cout << "\n";

	cout << "Созданный стек: ";
	// Выводим элементы стека (должны совпадать с порядком в векторе)
	printStack(stkСopied);


	////////////////////////////////////////////////////////////////////////////////////
	//queue
	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	std::cout << "Chapter 3 queue:" << std::endl;
	// Создаём очередь, явно указывая list как базовый контейнер
	queue<Point*, list<Point*>> pointQueue;

	// Добавляем новые объекты Point
	pointQueue.push(new Point(1, 2));
	pointQueue.push(new Point(3, 4));
	pointQueue.push(new Point(5, 6));

	cout << "Оригинальная очередь: ";
	printPointQueue(pointQueue);

	// Изменяем значения через front() и back()
	pointQueue.front()->x = 10; // Изменение первого элемента
	pointQueue.back()->y = 20;  // Изменение последнего элемента

	cout << "Очередь с изменёнными первым и последним элементами: ";
	printPointQueue(pointQueue);

	// При уничтожении очереди необходимо освободить выделенную память для каждого объекта Point
	while (!pointQueue.empty()) {
		delete pointQueue.front(); // Освобождение памяти
		pointQueue.pop();          // Удаление указателя из очереди
	}

	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//Ответ на вопрос: что сравнивается при вставке?
	// При вставке в priority_queue сравниваются значения элементов с использованием оператора сравнения,
	// в данном случае, адреса строковых литералов. Так как строки сортируются по их адресам в памяти, 
	// а не лексикографически, упорядоченность может быть не такой, как ожидалось.

	std::cout << "Chapter 4 priority_queue:" << std::endl;
	// а) Создаем priority_queue для хранения адресов строковых литералов
	priority_queue<const char*> pq_two;

	// б) Инициализируем очередь с приоритетами при создании
	const char* arr[] = { "Apple", "Banana", "Cherry", "Date" };
	for (auto& s : arr) {
		pq_two.push(s);
	}

	// в) Проверяем упорядоченность значений
	cout << "Очередь с приоритетами: ";
	while (!pq_two.empty()) {
		cout << pq_two.top() << " "; // Выводим элемент с наивысшим приоритетом
		pq_two.pop(); // Удаляем элемент с наивысшим приоритетом после его вывода
	}
	cout << "\n";

	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)jgz
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	
	// е) Ответ на вопрос: что происходит, если в массиве имеются дубли?
	// Множества автоматически удаляют дубликаты при вставке, поэтому дублирующиеся значения в массиве будут игнорироваться.
	std::cout << "Chapter 4 set:" << std::endl;
// a) Создание множества с элементами типа Point
	set<Point> pointSet;
	pointSet.insert(Point(1, 2));
	pointSet.insert(Point(3, 4));
	pointSet.insert(Point(5, 6));

	// b) Вывод значений элементов с помощью шаблона
	cout << "Значения Points: ";
	printContainer(pointSet);

	// в) Попытка изменить любое значение...
	// Множества (set) в C++ хранят только константные значения, чтобы поддерживать упорядоченность.
	// Изменение значений непосредственно в множестве невозможно без удаления и вставки.

	// г) Создание двух множеств с одинаковыми значениями в разном порядке
	set<int> set1 = { 1, 2, 3, 4, 5 };
	set<int> set2 = { 5, 4, 3, 2, 1 };
	// Порядок элементов в set определяется автоматически, независимо от порядка вставки,
	// так что оба множества будут содержать элементы в одном и том же порядке.

	// д) Вставка диапазона элементов из массива
	int Myarr[] = { 6, 7, 8, 9, 10 };
	set1.insert(begin(Myarr), end(Myarr)); // Вставляем элементы из массива в set1
	cout << "Множество set1 после вставки элементов из массива: ";
	printContainer(set1);


	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	// Создаем map, используя строковые литералы в качестве ключей
	std::cout << "Chapter 4 map, multiset:" << std::endl;
	map<const char*, int> salary_map;

	// Заполняем map с помощью operator[]
	salary_map["Иванов"] = 50000;
	salary_map["Петров"] = 60000;

	// Заполняем map с помощью метода insert
	salary_map.insert(make_pair("Сидоров", 70000));

	// в) Выводим содержимое map
	cout << "Зарплаты сотрудников:" << endl;
	for (const auto& pair : salary_map) {
		cout << pair.first << " имеет зарплату:" << pair.second << endl;
	}

	// Замена ключа "Иванова" на "Петрова"
	// Сначала проверяем наличие "Иванова" в map
	auto it = salary_map.find("Иванова");
	if (it != salary_map.end()) {
		// Сохраняем зарплату Ивановой
		int salary = it->second;
		// Удаляем Иванову
		salary_map.erase(it);
		// Добавляем Петрову с сохраненной зарплатой
		salary_map["Петрова"] = salary;
	}
	else {
		cout << "Запись для Ивановой не найдена." << endl;
	}


	// Выводим обновленное содержимое
	cout << "\nОбновленные зарплаты после изменения фамилии:" << endl;
	for (const auto& pair : salary_map) {
		cout << pair.first << " имеет зарплату:" << pair.second << endl;
	}


		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе

	vector<string> names = { "Иванов", "Петров", "Иванов", "Сидоров", "Петров" };

	// Создаем map для подсчета количества повторений
	map<string, int> counts;
	for (const auto& name : names) {
		counts[name]++;
	}

	// Выводим количество повторений
	cout << "\nКоличество повторений имен:" << endl;
	for (const auto& pair : counts) {
		cout << pair.first << " повторяется " << pair.second << " раз(а)." << endl;
	}


	//е) 
	//задан массив:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//создайте map, в котором каждой букве будет соответствовать совокупность 
	//лексиграфически упорядоченных слов, начинающихся с этой буквы.
	//Подсказка: не стоит хранить дубли одной и той же строки
	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"

	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty", "Alpha" };
	map<char, set<string>> sorted_words;

	for (const char* word : words) {
		sorted_words[toupper(word[0])].insert(word);
	}

	// Выводим слова, упорядоченные по первой букве
	cout << "\nСлова, упорядоченные по первой букве:" << endl;
	for (const auto& pair : sorted_words) {
		cout << pair.first << ": ";
		for (const auto& word : pair.second) {
			cout << word << " ";
		}
		cout << endl;
	}


		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 

	map<int, multiset<string>> student_groups;

	// Добавление студентов в группы
	student_groups[201].insert("Иванов");
	student_groups[201].insert("Петров");
	student_groups[202].insert("Сидоров");
	student_groups[201].insert("Кузнецов");
	student_groups[202].insert("Петров");

	// Выводим студентов по группам
	cout << "\nСтуденты по группам:" << endl;
	for (const auto& group : student_groups) {
		cout << "Группа " << group.first << ": ";
		for (const auto& name : group.second) {
			cout << name << " ";
		}
		cout << endl;
	}




	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

	std::cout << "Chapter 4 multimap:" << std::endl;
	// а) Создание англо-русского словаря с использованием multimap
	multimap<string, string> dict;

	// б) Заполнение словаря парами
	dict.insert(make_pair("strange", "чужой"));
	dict.insert(make_pair("strange", "странный"));
	dict.insert(make_pair("bright", "яркий"));
	dict.insert(make_pair("bright", "светлый"));
	dict.insert(make_pair("light", "свет"));
	dict.insert(make_pair("light", "лёгкий"));

	// в) Вывод всех содержаний словаря на экран
	cout << "Весь словарь:" << endl;
	for (const auto& pair : dict) {
		cout << pair.first << ": " << pair.second << endl;
	}

	// г) Вывод переводов для заданного ключа
	string search_key = "bright";
	cout << "\nПереводы для слова '" << search_key << "':" << endl;

	auto range = dict.equal_range(search_key); // Получаем диапазон итераторов для ключа "bright"
	for (auto it = range.first; it != range.second; ++it) {
		cout << it->second << endl;
	}

		return 0;
}

