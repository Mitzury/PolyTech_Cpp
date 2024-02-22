//------------------------------------------------------------------------------
// Тестируем класс MyString
//------------------------------------------------------------------------------
#include "myString.h"
#include <iostream>
#define	  stop __asm nop

int main()
{
	setlocale(LC_ALL, "Russian");
	MyString test("test");
	std::cout << test << std::endl;
	// С помощью профилировщика проверяем всю ли динамическую память освободили
	{
	//
	// 1. Создаем строки
	//
		
			std::cout << "Chapter 1 \n";
			MyString str("bbb");
			MyString str2("bbb");
			MyString str3("CCC");
			MyString* str4 = new MyString("ddd");
			MyString* str5 = new MyString("CCC");

	//MyString::print();   // при печати выводим количество пользователей строки
	//
	// 2. Конструктор копирования
	//
			std::cout << "\n Chapter 2 \n";
			MyString s;
			MyString s2 = str2;
			MyString s3 = s2;
			MyString::print();

			MyString s4 = std::move(*str4);
			delete str4;
			MyString::print();
		
	//
	// 3. Оператор присваивания
	//
		std::cout << "\n Chapter 3 \n";
		s3 = s4;
		MyString::print();
		*str5 = std::move(s3);
		MyString::print();
		s4 = "bbb";
		MyString::print();
		delete str5;
		MyString::print();
		s4 = "FFF";
		MyString::print();

	//
	// 4. Изменили регистр у всех строк на противоположный
	//
		std::cout << "\n Chapter 4 \n";
		MyString s5("FFF");
		MyString::print();

		MyString::changeCase();
		MyString::print();

	//
	// 5. Распечатали строки в алфавитном порядке
	//
		std::cout << "\n Chapter 5 \n";
		MyString::printAlph();
	
	//
	// 6. Дополнительные тесты
	//
	// ...
	}
	return 0;
}