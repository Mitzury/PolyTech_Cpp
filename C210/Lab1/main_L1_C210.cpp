//------------------------------------------------------------------------------
// ��������� ������������� ������
//------------------------------------------------------------------------------
#include "Rect.h"
#include "Circle.h"
#include "List.h"

#include <tchar.h>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <typeinfo>

const char* sep = "------------------------------------\n";

int main(int argc, _TCHAR* argv[])
{
	//
	// 1. ������� ������
	//
	List ls1;

	ls1.AddToTail(Circle(1, 1, 1, Shape::WHITE));	//��������� �������� � ������
	ls1.AddToTail(Circle(5, 50, 5, Shape::RED));
	ls1.AddToTail(Circle(5, 5, 5, Shape::WHITE));
	ls1.AddToTail(Circle(5, 5, 5, Shape::RED));
	ls1.AddToTail(Circle(5, 5, 5, Shape::WHITE));
	ls1.AddToTail(Rect(2, 3, 4, 5, Shape::GREEN));
	ls1.AddToTail(Rect(2, 4, 8, 10, Shape::RED));
	ls1.AddToTail(Rect(4, 6, 8, 10, Shape::RED));
	ls1.AddToTail(Circle(2, 21, 2, Shape::WHITE));
	ls1.AddToTail(Rect(3, 5, 6, 7, Shape::GREEN));

	// ������� ������
	std::cout << "Chapter 1" << std::endl;
	std::cout << "Out List 1 after init" << std::endl << ls1 << sep;


	ls1.Remove(Circle(5, 5, 5, Shape::RED));
	std::cout << "After remove Circle 5 RED\n";		// ������� ������ �������, ������ ���������
	std::cout << ls1 << sep;
	ls1.Remove(Rect(4, 6, 8, 10, Shape::RED));
	std::cout << "After remove Rect 4-10 RED\n";
	std::cout << ls1 << sep;

	//
	// 2. ����������� ���� ��� ������ ����������� ���������	
	//
	List ls2 = ls1;
	List ls3 = ls2;
	std::cout << "Copy of ls1\n";
	std::cout << ls2 << sep;

	ls2.AddToHead(Circle(5, 5, 5, Shape::RED));
	ls2.AddToHead(Rect(5, 7, 9, 11, Shape::WHITE));

	std::cout << "After add to head Circle 5 R and Rect 5-11 W\n";
	std::cout << ls2 << sep;
	ls1 = ls2;			// �� "��������" ������ � "���������"
	std::cout << "ls1 copied from ls2\n";
	std::cout << ls1 << sep;

	ls1 = ls3;			// �� "����������" ������ � "�������"
	std::cout << "ls1 copied from ls3, small list\n";
	std::cout << ls1 << sep;
	//
	// 3. ���������� ��� ��������� �����������	
	//
	List ls4 = std::move(ls2);

	std::cout << "ls4 moved from ls2\n";
	std::cout << ls4 << sep;
	std::cout << "ls2 after move to ls4\n";
	std::cout << ls2 << sep;

	ls3 = std::move(ls4);
	std::cout << "ls3 moved from ls4\n";
	std::cout << ls3 << sep;
	std::cout << "ls4 after move to ls3\n";
	std::cout << ls4 << sep;
	//
	//4.  ���������� �� ����������� ������� ������
	//
	std::cout << "ls3 before sorting\n";
	std::cout << ls3 << sep;
	ls3.SortList(AREA);
	std::cout << "ls3 after sorting by area\n";
	std::cout << ls3 << sep;

	ls3.SortList(COLOR);
	std::cout << "ls3 after sorting by color\n";
	std::cout << ls3 << sep;

	//
	// 5. �������� ����/�����
	//
	std::ofstream fout("list.txt");
	fout << ls3;	// ������� ������ � ����
	fout.close();

	std::ifstream fin("list.txt");
	List ls5;		// ������ ������ �� �����
	fin >> ls5;
	fin.close();

	std::cout << "ls5 after reading from file\n";
	std::cout << ls5 << sep;
	// 
	// 6. �������������� ��������
	//
	// ...

	ls5.AddToTail(Circle(1, 1, 1, Shape::WHITE));

	ls5.AddToTail(Circle(1, 1, 1, Shape::RED));

	std::cout << "Add two items:\n";
	std::cout << ls5 << sep;

	ls5.RemoveAll(Circle(1, 1, 1, Shape::WHITE));

	std::cout << "Remove all Circle 1 W:\n";
	std::cout << ls5 << sep;


	return 0;
}
