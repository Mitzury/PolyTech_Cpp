// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.


#include <tchar.h>
#include "MyString.h"
#include "shape.h"
#include <iostream>
#include <string>
#define	  stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
#if 1
	//Задание 1.Массив объектов класса.
	{
		std::cout << "Chapter 1 \n" ;
		//Объявите и проинициализируйте массив ar из объектов
	    // Исходный размер массива
		const int N = 3;
		// Инициализация статического массива объектов MyString
		MyString str1[N] = { MyString("String1"), MyString("String2"), MyString("String3") };
		// Печать строк-членов класса
		for (int i = 0; i < N; ++i) {
			std::cout << "str1[" << i << "]: " << str1[i].GetString() << std::endl;
		}
		// Новый размер массива 
		const int M = 5;
		// Изменение размера массива без явного создания нового
		MyString str2[M];
		for (int i = 0; i < N; ++i) {
			str2[i] = str1[i];
		}
		for (int i = N; i < M; ++i) {
			str2[i] = MyString(("String" + std::to_string(i + 1)).c_str());
		}

		// Печать строк-членов обновленного массива
		for (int i = 0; i < M; ++i) {
			std::cout << "str2[" << i << "]: " << str2[i].GetString() << std::endl;
		}

	}
#endif;
#if 0;	
	//Задание 2.Массив указателей на объекты класса.
	{
		//Объявите и проинициализируйте массив arPtr из N
		//указателей 

		std::cout << "\nChapter 2:\n";
		const int N=3;

		// Инициализация массива указателей на объекты MyString (создание объектов динамически)
		MyString* arPtr[N] = { new MyString("String1"), new MyString("String2"), new MyString("String3") };

		//Печать строк-членов класса
		for (int i = 0; i < N; ++i) {
			std::cout << "arPtr[" << i << "]: " << arPtr[i]->m_str1 << std::endl;
		}

	   	//Замените размер const int N=5; , не изменяя список инициализаторов.
		const int M = 5;

		MyString* arPtr2[M] = { new MyString("String1"), new MyString("String2"), new MyString("String3") };
		//Печать строк-членов класса
		for (int i = 0; i < M; ++i) {
			std::cout << "arPtr[" << i << "]: " << arPtr2[i]->m_str1 << std::endl;
		}

	}
#endif;
#if 0
	//Задание 3.Простое наследование.Аргументы конструктора, передаваемые в базовый класс.
	{
		//Создайте иерархию классов:
		//базовый класс Shape (который описывает любую фигуру)
		//и два производных класса Rect и Circle.
		//Подумайте: какие данные и методы нужно ввести в базовый
		//и производные классы (например, любую фигуру можно сделать
		//цветной => в базовом классе можно ввести переменную, которая
		//будет определять цвет фигуры.
		//Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);

		// Создание объектов иерархии
		std::cout << "\nChapter 3:\n";
		//Rect rect(RED);
		//Circle circle(GREEN);
		Shape x(RED);
		// Вывод информации о фигурах
		//rect.printInfo();
		std::cout << x.getColor() << std::endl;
		//circle.printInfo();

		//В конструкторах производных классов предусмотрите передачу
		//параметра-цвета конструктору базового класса.
		//При создании и уничтожении объекта производного типа определите
		//последовательность вызовов конструкторов и деструкторов базового
		//и производного классов
	}
#endif;
#if 0
	//Задание 4.Виртуальные функции.
	{
		//4а) Модифицируйте классы Shape,Rect и Circle:
		//добавьте в каждый класс public метод void WhereAmI().
		//Реализация каждой функции должна выводить сообщение
		//следующего вида "Now I am in class Shape(Rect или Circle)".
		//Выполните приведенный фрагмент, объясните результат.
		std::cout << "\nChapter 4a:\n";
		
		Shape s(RED);
		Rect r(GREEN);
		Circle c(BLUE);

		//Метод какого класса вызывается в следующих строчках???
		s.WhereAmI();  // Now I am in class Shape
		r.WhereAmI();  // Now I am in class Rect
		c.WhereAmI();  // Now I am in class Circle
		
		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
		pShape->WhereAmI();  // Now I am in class Shape
		pRect->WhereAmI();   // Now I am in class Shape
		pCircle->WhereAmI(); // Now I am in class Shape
			
		//Заполните ... согласно комментариям
		Shape& rShape = s;
		Shape& rRect = r;
		Shape& rCircle = c;
		rShape.WhereAmI();  // Now I am in class Shape
		rRect.WhereAmI();   // Now I am in class Shape
		rCircle.WhereAmI(); // Now I am in class Shape
	

		//4б) Добавьте в базовый и производные классы виртуальный
		// метод WhereAmIVirtual(). По аналогии с 4а вызовите
		// виртуальный метод посредством объектов, указателей и
		// ссылок, определенных в предыдущем фрагменте.
		//Выполните новый фрагмент, объясните разницу.
		// Вызов виртуального метода
		s.WhereAmIVirtual();   // Now I am in class Shape (virtual) 
		r.WhereAmIVirtual();   // Now I am in class Rect (virtual) 
		c.WhereAmIVirtual();   // Now I am in class Circle (virtual) 

		pShape->WhereAmIVirtual();  // Now I am in class Shape (virtual) 
		pRect->WhereAmIVirtual();   // Now I am in class Rect (virtual) 
		pCircle->WhereAmIVirtual(); // Now I am in class Circle (virtual) 

		rShape.WhereAmIVirtual();  // Now I am in class Shape (virtual) 
		rRect.WhereAmIVirtual();   // Now I am in class Rect (virtual) 
		rCircle.WhereAmIVirtual(); // Now I am in class Circle (virtual) 
	}
#endif;
#if 0
		//////////////////////////////////////////////////////////////////////
		/*
			//Задание 5.Виртуальные деструкторы.
			//Модифицируйте классы:
			//a) введите соответствующие
			// деструкторы (без ключевого слова virtual).
			//Реализация каждого деструктора
			//должна выводить сообщение следующего вида
			// "Now I am in Shape's destructor!" или
			// "Now I am in Rect's destructor!"
			//Выполните фрагмент. Объясните результат.
		*/
	{
		Rect r(GREEN);
		Shape* ar[] = { new Shape(r), new Rect(r), new Circle(r), new Circle() };

		for (int i = 0; i < 4; ++i) {
			ar[i]->WhereAmIVirtual();
		}

		for (int i = 0; i < 4; ++i) {
			delete ar[i];
		}
	}

			// b) Добавьте в объявление деструкторов ключевое слово virtual
			//Выполните фрагмент.Объясните разницу.


			//Подумайте: какие конструкторы вызываются в следующей строке?
				//Если в разработанных классов каких-то конструкторов
				//не хватает - реализуйте
				//Если Вы считаете, что в приведенном фрагменте чего-то
				//не хватает - добавьте

				//Rect r(<>);
				//Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
				//Вызовите для каждого элемента массива метод WhereAmIVirtual()


#endif;
#if 0
		/*
			//Задание 6*. В чем заключается отличие 1) и 2)
			{
				Shape* pShapes = new Rect[10];//1)
				Rect* pRects = new Rect[10];//2)

				//Попробуйте вызвать метод WhereAmIVirtual() для каждого элемента обоих массивов -
				//в чем заключается проблема???


				//Освободите динамически захваченную память

			}

		*/

		//////////////////////////////////////////////////////////////////////
		//Задание 7.Виртуальные функции и оператор разрешения области видимости.

		{
			Rect r(GREEN);
			Shape* p = &r;
			p->WhereAmIVirtual();   // Now I am in class Shape (virtual)
		// Оператор разрешения области видимости для вызова WhereAmIVirtual() из класса Shape
			r.Shape::WhereAmIVirtual();       // Now I am in class Shape (virtual)


				//4a Оператор разрешения области видимости.
				//Посредством объекта r и указателя p вызовите виртуальную функцию
				//WhereAmIVirtual()класса Shape


		}

		//////////////////////////////////////////////////////////////////////
		//Задание 8.Чисто виртуальные функции.
		//Введите в базовый класс метод void Inflate(int); Подумайте:
		//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
		//Реализуйте этот метод для производных классов.
		{
		Rect r;
		Shape* p = &r;
		p->Inflate(5);

		Circle c;
		p = &c;
		p->Inflate(5);
		}
#endif;
#if 0
		//////////////////////////////////////////////////////////////////////
			//Задание 9*. Создайте глобальную функцию, которая будет принимать любое
			//количество указателей на строки, а возвращать объект MyString,
			//в котором строка будет конкатенацией параметров
		////////////////////////////////////////////////////////////////////////
#endif;
#if 0
			//Задание 10.Объединения (union) C++. Битовые поля.
			//1.
			//Создайте следующие классы для различных представлений значений байта:
			//Bin - для двоичного представления
			//Hex - для шестнадцатерчного представления
			//Oct - для восьмеричного представления.
			//Подсказка 1: - для удобства используйте битовые поля.
			//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
			//так как все они будут членами объединения (union).
			//2.
			//В каждом классе введите метод Show, который должен выводить значение в
			//соответствующем виде
			//3.
			//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
			//одним и тем же значением по-разному:
			//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта
			//          а также символ, соответствующий хранимому значению (если есть соответствие);
			//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
			//			восьмеричные, двоичные цифры;
			//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;

			MyByte byte(0x1f);
			byte.ShowHex();
			byte.ShowBin();
			//...


#endif;
		return 0;
}
//endmain