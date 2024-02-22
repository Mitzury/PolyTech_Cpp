//------------------------------------------------------------------------------
// Тестируем двухсвязный список
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "List.h"

const char* sep = "------------------------------------\n";

int main()
{
	//
	// 1. Создаем список и выводим его содержимое
	//
	std::cout << "Chapter 1 \n";
	List ls1;
	// Добавляем элементы в список
	ls1.addToTail(Circle(1, 1, 1));	
	ls1.addToTail(Circle(5, 5, 5));
	ls1.addToTail(Circle(2, 2, 2));
	ls1.addToTail(Circle(4, 4, 4));
	ls1.addToTail(Circle(2, 2, 2));
	ls1.addToTail(Circle(3, 3, 3));
	// Выводим список	
	std::cout << "List all circles: \n";
	std::cout << ls1;					
	// удаляем первый элемент, равный заданному
	ls1.remove(Circle(5, 5, 5));			
	std::cout << "List all circles after delete \n";
	std::cout << ls1;

	std::cout << "List all circles after delete \n";
	// удаляем все элементы, равные заданному
	ls1.removeAll(Circle(2, 2, 2));
	std::cout << ls1 << sep;

	//
	// 2. Приведенный ниже код должен выполняться корректно	
	// Удаляем элементы из списка. 
	// Из списка удаляется первый элемент, который равен заданному (круг с центром в точке (5,5) и радиусом 5).
	// Из списка удаляются все элементы, равные заданному(круги с центром в точке(2, 2) и радиусом 2).

	std::cout << "\n Chapter 2 \n";
	List ls2 = ls1;
	std::cout << ls2;
	List ls3 = ls2;
	std::cout << ls3;

	ls2.addToHead(Circle(5, 5, 5));
	ls2.addToHead(Circle(2, 2, 2));

	std::cout << ls2;
	ls1 = ls2;			// из "большого" списка в "маленький"
	std::cout << ls1;

	ls1 = ls3;			// из "маленького" списка в "большой"
	std::cout << ls1 << sep;


	//
	// 3. Вспоминаем про семантику перемещения	
	// 
	// Создается новый список ls4, который копируется из ls2.
	// Создается еще один список ls3, который копируется из ls4.

	std::cout << "\n Chapter 3 \n";
	List ls4 = std::move(ls2);
	std::cout << ls4;
	std::cout << ls2;

	ls3 = std::move(ls4);
	std::cout << ls3;
	std::cout << ls4 << sep;

	//
	//4.  Сортировка по возрастанию площади кружка
	//
	std::cout << "\n Chapter 4 \n";
	std::cout << "Sort by square \n";
	std::cout << ls3;
	// Список ls3 сортируется по возрастанию площади круга
	ls3.sortList();
	std::cout << ls3 << sep;

	//
	// 5. Файловый ввод/вывод
	//
	std::cout << "\n Chapter 5 \n";

	std::ofstream fout("list.txt");
	fout << ls3;	// выводим список в файл
	fout.close();

	std::ifstream fin("list.txt");
	List ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();

	std::cout << ls5;
	return 0;

}