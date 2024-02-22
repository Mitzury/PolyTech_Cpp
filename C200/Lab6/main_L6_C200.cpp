//------------------------------------------------------------------------------
// Тестируем класс MyString
//------------------------------------------------------------------------------
#include "myString.h"
#include <iostream>
#define	  stop __asm nop

int main()
{
	MyString test("test");
	std::cout << test << std::endl;

	// С помощью профилировщика проверяем всю ли динамическую память освободили

	{
		//
		// 1. Создаем строки
		//
		MyString str("bbb");
		MyString str2("bbb");
		MyString str3("CCC");
		MyString* str4 = new MyString("ddd");
		MyString* str5 = new MyString("CCC");

		//MyString::print();   // при печати выводим количество пользователей строки
		//
		// 2. Конструктор копирования
		//
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
		MyString s5("FFF");
		MyString::print();

		MyString::changeCase();
		MyString::print();
		//
		// 5. Распечатали строки в алфавитном порядке
		//
		MyString::printAlph();
		//
		// 6. Дополнительные тесты
		//
		// ...
	}



	return 0;
}