// Темы:
// Перегрузка операторов.

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
#include <tchar.h>
#include "point.h"
#include "myString.h"
using namespace std;

enum WEEKDAY {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY,
};

// Операторы + и +=
WEEKDAY operator+(const WEEKDAY& day, int daysToAdd) {
	// Результат делится на 7 и берется остаток от деления с помощью оператора %, чтобы получить номер дня недели от 0 до 6.
	int result = (static_cast<int>(day) + daysToAdd) % 7;
	// Если результат отрицательный, то к нему добавляется 7, чтобы получить корректный номер дня недели.
	return static_cast<WEEKDAY>(result < 0 ? result + 7 : result);
}

WEEKDAY& operator+=(WEEKDAY& day, int daysToAdd) {
	day = day + daysToAdd;
	return day;
}

// Функция для преобразования перечисления в строку
const char* weekdayToString(WEEKDAY day) {
	switch (day) {
	case MONDAY: return "Monday";
	case TUESDAY: return "Tuesday";
	case WEDNESDAY: return "Wednesday";
	case THURSDAY: return "Thursday";
	case FRIDAY: return "Friday";
	case SATURDAY: return "Saturday";
	case SUNDAY: return "Sunday";
	default: return "Invalid day";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
#if 0;	
//////////////////////////////////////////////////////////////////////
//Задание 1
//Создайте класс Point, который будет содержать координаты "точки". 
// Объявите конструктор (конструкторы) класса
	//1a. "Перегрузите" оператор += так, чтобы при выполнении операции типа pt2+=pt1; складывались
    //одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	// (!) Перегрузку выполните с помощью метода класса (оператор +=)
	//Проверьте корректность работы перегруженного оператора

	{
		std::cout << "Chapter 1a \n";
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2 += pt1;
		pt2.printCoordinates();
		pt2 += 1;
		pt2.printCoordinates();

		Point pt3(3, 3);
		pt2 += pt1 += pt3;
		pt2.printCoordinates();
	}

		//1b. "Перегрузите" оператор -= так, чтобы при выполнении
		//операции типа pt2-=pt1; вычитались
		//одноименные переменные объектов pt1 и pt2, а разность
		//присваивалась соответствующим переменным объекта pt2 или
		// в случае  pt2-=1; обе переменные объекта pt2 уменьшались на
		// указанное значение
		//(!) Перегрузку выполнитес помощью глобальной функции (оператор -=)
		//Проверьте корректность работы перегруженного оператора

	{
		std::cout << "\nChapter 1b \n";
		Point pt1(1, 1);
		Point pt2(6, 4);
		pt2 -= pt1;
		pt2.printCoordinates();

		pt2 -= 1;
		pt2.printCoordinates();

		Point pt3(3, 3);
		pt2 -= pt1 -= pt3;
		pt2.printCoordinates();
	}

#endif;
#if 0;	
		//Задание 2
		//2a. Перегрузите оператор +
		//с помощью методов класса, где это возможно
		//так, чтобы любая из закомментированных строк
		//кода выполнялась корректно
		{
		std::cout << "\n Chapter 2a \n";
			Point pt1(1, 1);
			Point pt2(2, 2);
			Point pt3;

			pt3 = pt1 + 5;
			std::cout << pt3 << std::endl;

			pt3 = pt1 + pt2;
			std::cout << pt3 << std::endl;
		}
		//2b. Перегрузите оператор -
		// с помощью  глобальных функций (оператор -)
		//так, чтобы любая из закомментированных строк
		//кода выполнялась корректно
		{
			std::cout << "\n Chapter 2b \n";
			Point pt1(1,1);
			Point pt2(2,2);
			Point pt3;

			pt3 = pt1 - 5;
			pt3 = 2 - pt1;
			std::cout << pt3 << std::endl;
			pt3 = pt1 - pt2;
			std::cout << pt3 << std::endl;
			
		}
#endif;
#if 0;	
//Задание 3
		// Перегрузите унарный оператор +/-
		{
			std::cout << "\n Chapter 3 \n";
			Point pt1(1,1);
			Point pt3;
			// Перегрузка унарного оператора - с помощью глобальной функции
			pt3 = -pt1;
			std::cout << pt3 << std::endl;

			// Перегрузка унарного оператора + с помощью метода класса
			pt3 = +pt1;
			std::cout << pt3 << std::endl;
		}
#endif;
#if 0;	
		//Задание 4. Перегрузите оператор << (вывода в поток) для
		// класса Point  таким образом, чтобы при выводе отображались координаты точки
		{
			std::cout << "\n Chapter 4 \n";
			Point pt(10,20);
			std::cout << pt << std::endl;//например, так:x=10, y=20
			
		}

#endif;
#if 0;	
//Задание 5.Перегрузка оператора  =.
//Подключите к проекту файлы MyString.cpp и MyString.h
//класса MyString, разработанного Вами на предыдущем занятии
// Перегрузите оператор присваивания для класса MyString
//Проверьте корректность работы перегруженного оператора

		{
			std::cout << "\n Chapter 5 \n";
			MyString s1("AAA"), s2;
			s2=s1;
			std::cout << "s2 after assignment: " << s2.GetString() << std::endl;
			s1="CCC";
			std::cout << "s1 after assignment: " << s1.GetString() << std::endl;
			s2 = MyString("tmp");
			std::cout << "s2 after assignment with temporary: " << s2.GetString() << std::endl;
			s1=s1;
		}
	

#endif;
#if 0;	
//Задание 6. Перегрузите оператор << (вывода в поток) для
//класса MyString таким образом, чтобы при выполнении приведенной строки
//на экран было выведено:
//contents:  "QWERTY"
	{
			std::cout << "\n Chapter 6 \n";
			MyString s("QWERTY");
			cout << s << endl;
	}
	{
	//Задание 7. Перегрузите операторы + и += для класса MyString таким образом,
	//чтобы происходила конкатенация строк
		std::cout << "\n Chapter 7 \n";
		MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
		s3 = s1 + s2;
		s4 += s1;
		std::cout << s3.GetString() << std::endl;
		std::cout << s4.GetString() << std::endl;
	}
#endif;
#if 0;
		//Задание 8. Перегрузите операторы  постфиксный декремент -- и префиксный инкремент
		//для класса MyString таким образом, при применении декремента производился перевод в нижний регистр всех символов,
		// являющихся буквами латинского алфавита, а при применении инкремента производился перевод в верхний регистр.
		// при работе можно воспользоваться следующими функциями <ctype.h>:
		//int  isupper( int C);
		//int  islower( int C);
		//int  toupper( int C);
		//int  tolower( int C);
		{
		    std::cout << "\n Chapter 8 \n";
			MyString str1("Hello World!!!");
			MyString str1_2 = str1--;

			MyString str2("Hello World!");
			MyString str2_2 = ++str2;

			std::cout << str1_2.GetString() << std::endl;
			std::cout << str2_2.GetString() << std::endl;
		}
#endif;
#if 0;
//Задание 9. Перегрузите операторы + и +=   для enum WEEKDAY
			{
			std::cout << "\n Chapter 9 \n";
			    enum WEEKDAY wd1 = SATURDAY;
				wd1 = wd1 + 2;
				enum WEEKDAY wd2 = wd1 + 1;
				wd2 += 2;
				std::cout << "wd1: " << wd1 << std::endl;
				std::cout << "wd2: " << wd2 << std::endl;
			}

			//Задание 10. Перегрузите оператор << (вывода в поток) для
			//перечисления WD таким образом, чтобы при выводе отображалась строка,
			// соответствующая именованной константе:
			{
			std::cout << "\n Chapter 10 \n";
				enum WEEKDAY wd1 = SATURDAY;
				enum WEEKDAY wd2 = MONDAY;
				std::cout << "wd1: " << weekdayToString(wd1) << std::endl;
				std::cout << "wd2: " << weekdayToString(wd2) << std::endl;


			}
#endif;
#if 1;
			{
				std::cout << "\n Chapter 11 \n";
				enum WEEKDAY wd1 = SATURDAY; // 5
				wd1 = wd1 + 2; // 5 + 2 = 7
				std::cout << "wd1 = wd1 + 2: " << weekdayToString(wd1) << std::endl;
				WEEKDAY wd2 = wd1 + 1; // 2
				wd2 += 2; // 4
				std::cout << "wd1: " << weekdayToString(wd1) << std::endl;
			}

#endif;
	return 0;
}

