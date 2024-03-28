﻿//------------------------------------------------------------------------------
// Тестируем разработанный список
//------------------------------------------------------------------------------
#include "Rect.h"
#include "Circle.h"
#include "List.h"

const char* sep = "------------------------------------\n";

enum SortType { AREA, COLOR /* .... */ };

int _tmain(int argc, _TCHAR* argv[])
{
	//
	// 1. Создаем список
	//
	List ls1;

	ls1.AddToTail(Circle(1, 1, 1, Shape::WHITE));	//добавляем элементы в список
	ls1.AddToTail(Circle(5, 5, 5, Shape::RED));
	ls1.AddToTail(Rect(2, 3, 4, 5, Shape::RED));
	ls1.AddToTail(Rect(4, 6, 8, 10, Shape::GREEN));
	ls1.AddToTail(Circle(2, 2, 2, Shape::WHITE));
	ls1.AddToTail(Rect(3, 5, 6, 7, Shape::GREEN));
	std::cout << ls1;								//выводим список	

	ls1.Remove(Circle(5, 5, 5, Shape::RED));		// удаляем первый элемент, равный заданному
	std::cout << ls1;
	ls1.Remove(Rect(4, 6, 8, 10, Shape::GREEN));
	std::cout << ls1;

	//
	// 2. Приведенный ниже код должен выполняться корректно	
	//
	List ls2 = ls1;
	List ls3 = ls2;
	std::cout << ls2;

	ls2.AddToHead(Circle(5, 5, 5, Shape::RED));
	ls2.AddToHead(Rect(5, 7, 9, 11, Shape::WHITE));

	std::cout << ls2;
	ls1 = ls2;			// из "большого" списка в "маленький"
	std::cout << ls1;

	ls1 = ls3;			// из "маленького" списка в "большой"
	std::cout << ls1 << sep;
	//
	// 3. Вспоминаем про семантику перемещения	
	//
	List ls4 = std::move(ls2);
	std::cout << ls4;
	std::cout << ls2;

	ls3 = std::move(ls4);
	std::cout << ls3;
	std::cout << ls4 << sep;
	//
	//4.  Сортировка по возрастанию площади кружка
	//
	std::cout << ls3;
	ls3.SortList(AREA);
	std::cout << ls3 << sep;

	ls3.SortList(COLOR);
	std::cout << ls3 << sep;

	//
	// 5. Файловый ввод/вывод
	//
	std::ofstream fout("list.txt");
	fout << ls3;	// выводим список в файл
	fout.close();

	std::ifstream fin("list.txt");
	List ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();

	std::cout << ls5;
	// 
	// 6. Дополнительные проверки
	//
	// ...

	return 0;
}