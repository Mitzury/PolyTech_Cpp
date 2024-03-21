//------------------------------------------------------------------------------
// Тестируем двухсвязный список
//------------------------------------------------------------------------------

#include <fstream>
#include "list.h"
using namespace std;

const char* sep = "------------------------------------\n";


int main()
{
    //
    // 1. Создаем список
    //
    List ls1; 

    // Добавляем элементы в список
    ls1.AddToTail(Circle(1, 1, 1));
    ls1.AddToTail(Circle(5, 5, 5));
    ls1.AddToTail(Circle(2, 2, 2));
    ls1.AddToTail(Circle(4, 4, 4));
    ls1.AddToTail(Circle(2, 2, 2));
    ls1.AddToTail(Circle(3, 3, 3));
    // Выводим список
    std::cout << "Chapter 1" << std::endl;
    std::cout << "Out List 1 after init" << endl << ls1 << sep;

    // Удаляем первый элемент, равный заданному
    ls1.Remove(Circle(5, 5, 5));
    std::cout << "Out List 1 after delete 5 circle" << endl << ls1 << sep;
    // Удаляем все элементы, равные заданному
    ls1.RemoveAll(Circle(2, 2, 2));
    std::cout << "Out List 1 after delete all 2 circles" << endl << ls1 << sep;
    //
    // 2. Приведенный ниже код должен выполняться корректно	
    //
    std::cout << "Chapter 2" << std::endl;
    List ls2 = ls1;
    std::cout << "Out List 2 - copy List 1" << endl << ls2 << sep;
    List ls3 = ls2;
    std::cout << "Out List 3 - copy List 2" << endl << ls3 << sep;

    ls2.AddToHead(Circle(2, 2, 2));
    ls2.AddToHead(Circle(5, 5, 5));

    std::cout << "Out List 2 after add to head 2 and 5 circles" << endl << ls2 << sep;
    ls1 = ls2;			// из "большого" списка в "маленький"
    std::cout << "Out List 1 after copy from List 2" << endl << ls1 << sep;

    ls1 = ls3;			// из "маленького" списка в "большой"
    std::cout << "Out List 1 after copy from List 3" << endl << ls1 << sep;
    //
    // 3. Вспоминаем про семантику перемещения	
    // 
    {
        std::cout << "Chapter 3" << std::endl;
        List ls4 = std::move(ls2);
        std::cout << "Out List 4 after move from List 2" << endl << ls4 << sep;
        std::cout << "Out List 2 after move List 4 from List 2" << endl << ls2 << sep;

        List ls3 = std::move(ls4);
        std::cout << "Out List 3 after move from List 4" << endl << ls3 << sep;
        std::cout << "Out List 4 after move List 3 from List 4" << endl << ls4 << sep;
    }
    //
    //4.  Сортировка по возрастанию площади кружка
    //
    std::cout << "Chapter 4" << std::endl;
    std::cout << "Out List 3 before sorting" << endl << ls3 << sep;
    ls3.SortList();
    std::cout << "Out List 3 after sorting" << endl << ls3 << sep;
    //
    // 5. Файловый ввод/вывод
    //
    std::cout << "Chapter 5" << std::endl;
    ofstream fout("list.txt");
    fout << ls3;	// выводим список в файл
    fout.close();

    ifstream fin("list.txt");
    List ls5;		// читаем список из файла
    fin >> ls5;
    fin.close();

    std::cout << "Out List 5 after read from file, which contains List 3" << endl << ls5 << sep;
    // 6. Дополнительные проверки
    //
    // ...

    std::cout << "Chapter 6" << std::endl;
    // Стартовый список
    std::cout << "Out List 1" << endl << ls1 << sep;
    // Добавляем ноду в конец списка
    ls1.AddToTail(Circle(1, 1, 1));
    std::cout << "Out List 1 Insert to tail 1,1,1" << endl << ls1 << sep;
    // Делаем вставку новой ноды после указанной
    ls1.InsertAfter(Circle(2, 2, 2), Circle(1, 1, 1));
    std::cout << "Out List 1 Insert 2,2,2 After 1,1,1" << endl << ls1 << sep;
    // Делаем вставку новой ноды перед указанной
    ls1.InsertBefore(Circle(9, 9, 9), Circle(1, 1, 1));
    std::cout << "Out List 1 Insert 9,9,9 before 1,1,1" << endl << ls1 << sep;
    std::cout << "Out List 1 before Reverse" << endl << ls1 << sep;
    // Реверсиурем список
    ls1.Reverse();
    std::cout << "Out List 1 after Reverse" << endl << ls1 << sep;

    return 0;
}