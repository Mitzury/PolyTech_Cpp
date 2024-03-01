//------------------------------------------------------------------------------
// Тестируем двухсвязный список
//------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

const char* sep = "------------------------------------\n";



int main() {
	// 1. Создаем список

	List ls1;

	// Добавляем элементы в список

	ls1.AddToTail(Circle(1, 1, 1));
	ls1.AddToTail(Circle(5, 5, 5));
	ls1.AddToTail(Circle(2, 2, 2));
	ls1.AddToTail(Circle(4, 4, 4));
	ls1.AddToTail(Circle(2, 2, 2));
	ls1.AddToTail(Circle(3, 3, 3));

	// Выводим список

	std::cout << ls1 << std::endl;
	std::cout << sep << std::endl;

	// удаляем первый элемент, равный заданному

	ls1.remove(Circle(5, 5, 5));

	// Выводим список после удаления

	std::cout << "Remove 5.5.5" << std::endl;
	std::cout << ls1;
	std::cout << sep << std::endl;

	// Удаляем все элементы, равные заданному

	ls1.removeAll(Circle(2, 2, 2));

	// Выводим список после удаления

	std::cout << "Remove all 2.2.2" << std::endl;
	std::cout << ls1 << std::endl;
	std::cout << sep;

	// 2. Приведенный ниже код должен выполняться корректно	

	std::cout << "Chapter 2" << std::endl;
	List ls2 = ls1;
	std::cout << "Ls2 = ls1" << std::endl;
	std::cout << ls2;
	std::cout << "Ls3 = ls2" << std::endl;
	List ls3 = ls2;
	std::cout << ls3;

	ls2.AddToHead(Circle(2, 2, 2));
	ls2.AddToHead(Circle(5, 5, 5));

	std::cout << "Ls2 add ho Head 2.2.2 and 5.5.5" << std::endl;

	std::cout << ls2;
	// из "большого" списка в "маленький"
	ls1 = ls2;
	std::cout << "ls1 from ls2" << std::endl;
	std::cout << ls1;
	// из "маленького" списка в "большой"
	ls1 = ls3;
	std::cout << "ls1 from ls3" << std::endl;
	std::cout << ls1 << sep;

	// 3. Вспоминаем про семантику перемещения	

	std::cout << "Chapter 3" << std::endl;
	List ls4 = std::move(ls2);
	std::cout << "ls4" << std::endl;
	std::cout << ls4;
	std::cout << "ls2" << std::endl;
	std::cout << ls2;

	ls3 = std::move(ls4);
	std::cout << "ls3" << std::endl;
	std::cout << ls3;
	std::cout << "ls4" << std::endl;
	std::cout << ls4 << sep;

	// 4.  Сортировка по возрастанию площади кружка

	std::cout << "Chapter 4" << std::endl;
	std::cout << "ls3" << std::endl;
	std::cout << ls3;
	ls3.SortList();
	std::cout << "ls3 after sort" << std::endl;
	std::cout << ls3 << sep;


	// 5. Файловый ввод/вывод

	ofstream fout("list.txt");
	fout << ls3;	// выводим список в файл
	fout.close();

	ifstream fin("list.txt");
	List ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();

	return 0;

}