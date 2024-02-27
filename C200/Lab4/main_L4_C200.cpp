﻿// Темы:
// Перегрузка операторов.
// Встроенные объекты 

#include <iostream>
#include "CppDb.h"
using namespace std;

int main()
{
    {
        setlocale(LC_ALL, "Russian");
        //////////////////////////////////////////////////////////////////////
        //Задание 1. Разработать "базу данных" о сотрудниках посредством ассоциативного
        //массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
        //в базе быть не может), а данными: пол, возраст, должность, зарплата...
        //Реализуйте:
        //добавление сотрудников в базу
        //исключение сотрудника из базы
        //вывод информации о конкретном сотруднике
        //вывод всей (или интересующей) информации о всех сотрудниках
        //(подсказки по реализации базы в файле "База_данных-ооп.pdf")
        std::cout << "Chapter 1 \n";
        // Создаем пустую базу данных
        CppDb bd1;

        // Добавляем сотрудников в базу
        // bd["Ivanov"] создает новую пару с ключом "Ivanov" в базе данных bd. 
        // Этот оператор [] возвращает ссылку на данные, связанные с этим ключом.
        bd1["Ivanov"] = MyData(MyData::MALE, 30, "Engineer Java", 40000);
        bd1["Petrova"] = MyData(MyData::FEMALE, 35, "Designer", 25000);
        bd1["Sidorov"] = MyData(MyData::MALE, 50, "Programmer С++", 50000);


        // Выводим информацию обо всех сотрудниках
        std::cout << "Информация обо всех сотрудниках:" << std::endl;
        std::cout << bd1 << std::endl;
        // Выводим информацию о конкретном сотруднике
        std::cout << "Информация о сотруднике Ivanov:" << std::endl;
        std::cout << bd1["Ivanov"] << std::endl;
        // Исключаем сотрудника
        bd1.deletePair("Petrova");
        std::cout << "После удаления Petrova:" << std::endl;
        std::cout << bd1 << std::endl;


        //Задание 2. Разработайте необходимые методы для того, чтобы код,
        // приведенный ниже выполнялся корректно
        //Задание 2.1. создайте 2 копии  базы  bd1
        std::cout << "\n Chapter 2.1 \n";
        CppDb bd2 = bd1;
        std::cout << "BD2:" << std::endl;
        std::cout << bd2; //выводим информацию обо всех сотрудниках  из базы bd2
        CppDb bd3 = bd1;
        std::cout << "BD3:" << std::endl;
        std::cout << bd3; //выводим информацию обо всех сотрудниках  из базы bd3

        // Задание 2.2: Добавляем сотрудников в базу bd2
        std::cout << "\n Chapter 2.2 \n";
        bd2["Sidorov"] = MyData(MyData::MALE, 40, "Manager", 60000);
        bd2["Petrov"] = MyData(MyData::MALE, 45, "Accountant", 55000);
        // Выводим информацию о сотрудниках в базе bd2 после добавления новых записей
        std::cout << "Информация о сотрудниках в базе bd2 после добавления новых записей:" << std::endl;
        std::cout << bd2 << std::endl;
        // Задание 2.3: Присваиваем содержимое базы bd3 базе bd1
        std::cout << "\n Chapter 2.3 \n";
        bd1 = bd3;
        // Выводим информацию о сотрудниках в базе bd1 после присваивания
        std::cout << "Информация о сотрудниках в базе bd1 после присваивания:" << std::endl;
        std::cout << bd1 << std::endl;
        //Задание 3. вспоминаем про семантику перемещения
        //Задание 3.1.создайте копию  базы  bd1
        std::cout << "\n Chapter 3.1 \n";
        CppDb bd4 = move(bd2); // «Перемещение» ресурсов из одного объекта в другой вместо копирования
        std::cout << bd4; //выводим информацию обо всех сотрудниках  из базы bd4
        std::cout << bd2; //выводим информацию обо всех сотрудниках  из базы bd2
        //Задание 3.2.
        std::cout << "\n Chapter 3.2 \n";
        bd3 = move(bd4);
        std::cout << bd3; //выводим информацию обо всех сотрудниках  из базы bd3
        std::cout << bd4; //выводим информацию обо всех сотрудниках  из базы bd4

        //Задание 4.  Сортировка
        //Задание 4.1. Разработайте сортировку базы данных  по возрастанию ключа
        //подумайте, что надо перегрузить в классе MyString
        // Нужно было перегрузить оператор << вывода, для правильного вывода базы данных на экран


        //Задание 4.2.Отсортируйте любую базу данных и выведите результат
        // Создаем базу данных
        CppDb bd;
        std::cout << "\n Chapter 4.1 \n";
        // Добавляем некоторые данные
        bd["Zadov"] = MyData(MyData::MALE, 20, "Programmer C++", 500000);
        bd["Ivanov"] = MyData(MyData::MALE, 30, "Engineer Java", 40000);
        bd["Petrova"] = MyData(MyData::FEMALE, 35, "Designer UI\\UX", 25000);
        bd["Sidorov"] = MyData(MyData::MALE, 50, "Programmer C#", 50000);
        bd["Abvgdeykin"] = MyData(MyData::UNDEF, 71, "Tester", 123500);


        // Выводим информацию о сотрудниках до сортировки
        std::cout << "Информация о сотрудниках до сортировки:" << std::endl;
        std::cout << bd << std::endl;
        // Сортируем базу данных по возрастанию ключа
        bd.sort();
        // Выводим отсортированную информацию о сотрудниках
        std::cout << "\n Chapter 4.2 \n";
        std::cout << "Информация о сотрудниках после сортировки:" << std::endl;
        std::cout << bd << std::endl;

        //bd1.clear();
        //bd2.clear();
        //bd3.clear();
        //bd4.clear();
    
    }
    return 0;
};