// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.
#include <tchar.h>
#include "MyString.h"
#include "shape.h"
#include <iostream>
#include <cstring>
#include "bytes.h"
#define	  stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	//Задание 1.Массив объектов класса.
	{
		std::cout << "Chapter 1 \n";
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
		MyString str2[M] = { MyString("String1"), MyString("String2"), MyString("String3") };
		//for (int i = 0; i < N; ++i) {
		//	str2[i] = str1[i];
		//}
		//for (int i = N; i < M; ++i) {
		//	str2[i] = MyString(("String" + std::to_string(i + 1)).c_str());
		//}// нет оператора присваивания

		// Печать строк-членов обновленного массива
		for (int i = 0; i < M; ++i) {
			std::cout << "str2[" << i << "]: " << str2[i].GetString() << std::endl;
		}
	}
#endif;
#if 0	
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
			std::cout << "arPtr[" << i << "]: " << (*arPtr[i]).GetString() << std::endl;
		}
	   	//Замените размер const int N=5; , не изменяя список инициализаторов.
		const int M = 5;
		MyString* arPtrNew[M] = { new MyString("String1"), new MyString("String2"), new MyString("String3") };
		// Создание нового массива указателей с новым размером

		// Печать строк-членов нового массива указателей
		for (int i = 0; i < M; ++i) {
			if (arPtrNew[i] != 0) {
				std::cout << "arPtrNew[" << i << "]: " << arPtrNew[i]->GetString() << std::endl;
			}
		}
		// Освобождение памяти для каждого созданного объекта старого массива
		for (int i = 0; i < N; ++i) {
			delete arPtr[i];
		}
		// Освобождение памяти для каждого созданного объекта нового массива 
		for (int i = 0; i < M; ++i) {
			delete arPtrNew[i];
		}
	}
#endif;
#if 1
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
	//В конструкторах производных классов предусмотрите передачу
	//параметра-цвета конструктору базового класса.
	//При создании и уничтожении объекта производного типа определите
	//последовательность вызовов конструкторов и деструкторов базового
	//и производного классов
	std::cout << "\nChapter 3:\n";
	// Создание объектов иерархии
	Rect rect(Color::RED, 10, 20, 5, 5); // Создаем прямоугольник с заданными параметрами
	Circle circle(rect); // Создаем круг, используя прямоугольник

	// Вывод информации о фигурах
	rect.printInfo();
	std::cout << std::endl;
	circle.printInfo();
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

		//Shape s(RED);
		Rect r(Color::GREEN, 0, 10, 0, 10);
		Circle c(Color::BLUE, 5);

		//s.WhereAmI();  // Now I am in class Shape
		r.WhereAmI();  // Now I am in class Rect
		c.WhereAmI();  // Now I am in class Circle

		//Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
		//pShape->WhereAmI();  // Now I am in class Shape
		pRect->WhereAmI();   // Now I am in class Shape
		pCircle->WhereAmI(); // Now I am in class Shape

		//Shape& rShape = s;
		Shape& rRect = r;
		Shape& rCircle = c;
		//rShape.WhereAmI();  // Now I am in class Shape
		rRect.WhereAmI();   // Now I am in class Shape
		rCircle.WhereAmI(); // Now I am in class Shape


		//4б) Добавьте в базовый и производные классы виртуальный
		// метод WhereAmIVirtual(). По аналогии с 4а вызовите
		// виртуальный метод посредством объектов, указателей и
		// ссылок, определенных в предыдущем фрагменте.
		//Выполните новый фрагмент, объясните разницу.
		// Вызов виртуального метода

		std::cout << "\nChapter 4b:\n";
		//s.WhereAmIVirtual();   // Now I am in class Shape (virtual)
		r.WhereAmIVirtual();   // Now I am in class Rect (virtual)
		c.WhereAmIVirtual();   // Now I am in class Circle (virtual)

		//pShape->WhereAmIVirtual();  // Now I am in class Shape (virtual)
		pRect->WhereAmIVirtual();   // Now I am in class Rect (virtual)
		pCircle->WhereAmIVirtual(); // Now I am in class Circle (virtual)

		//rShape.WhereAmIVirtual();  // Now I am in class Shape (virtual)
		rRect.WhereAmIVirtual();   // Now I am in class Rect (virtual)
		rCircle.WhereAmIVirtual(); // Now I am in class Circle (virtual)
	}
#endif;
#if 0
//Задание 5.Виртуальные деструкторы.
	//Модифицируйте классы:
	//a) введите соответствующие
	// деструкторы (без ключевого слова virtual).
	//Реализация каждого деструктора
	//должна выводить сообщение следующего вида
	// "Now I am in Shape's destructor!" или
	// "Now I am in Rect's destructor!"
	//Выполните фрагмент. Объясните результат.
	{
		{
			std::cout << "\nChapter 5a:\n";
			Rect r(Color::GREEN, 10, 20, 5, 5); // Создаем прямоугольник с зеленым цветом и заданными параметрами
			
			Shape* ar[] = { &r, new Rect(r), new Circle(r), new Circle(r) }; // Создаем массив указателей на Shape

			// Выводим информацию о том, где находятся объекты до преобразования
			for (int i = 0; i < 4; ++i) {
				ar[i]->WhereAmIVirtual();
			}


			// Преобразуем каждый объект круга и выводим информацию о новом местоположении
			for (int i = 1; i < 4; ++i) {
				Circle* circlePtr = dynamic_cast<Circle*>(ar[i]); // Приводим указатель к типу Circle
				if (circlePtr) { // Проверяем, удалось ли преобразование
					*circlePtr = Circle(*dynamic_cast<Rect*>(ar[0])); // Конструируем круг из прямоугольника
					ar[i]->WhereAmIVirtual(); // Выводим информацию о новом местоположении
				}
			}

			// Удаляем динамически созданные объекты, чтобы избежать утечек памяти
			for (int i = 1; i < 4; ++i) {
				delete ar[i];
			}


			std::cout << "\nChapter 5b:\n";
		// b) Добавьте в объявление деструкторов ключевое слово virtual
		//Выполните фрагмент. Объясните разницу.
			//Shape s(RED);


			/*При выполнении кода будет вызван деструктор для каждого объекта, когда он выходит из области видимости. 
			Однако, поскольку деструкторы не виртуальные, при удалении объектов через указатель на базовый класс 
			(который может указывать на объект производного класса), вызывается только деструктор базового класса. 
			В данном случае, деструкторы производных классов (Rect и Circle) не будут вызваны.
			Теперь, если мы добавим ключевое слово virtual к деструкторам базового класса и запустим фрагмент, 
			то деструкторы производных классов будут вызваны правильно при удалении объектов через указатель на базовый класс.*/


			//Подумайте: какие конструкторы вызываются в следующей строке?
			//Если в разработанных классов каких-то конструкторов
			//не хватает - реализуйте
			//Если Вы считаете, что в приведенном фрагменте чего-то
			//не хватает - добавьте
			
			//Вызовите для каждого элемента массива метод WhereAmIVirtual()
			//Shape* ar[] = { new Rect(r), new Circle(r), new Circle() };
			//Вызовите для каждого элемента массива метод WhereAmIVirtual()
			for (int i = 0; i < 4; ++i) {
				ar[i]->WhereAmIVirtual();
			}

			/*Вызывается конструктор Rect с параметрами <параметры>.
			Вызываются конструкторы для каждого элемента массива ar:
			new Shape(r) вызывает конструктор Shape с параметром r.
			new Rect(r) вызывает конструктор Rect с параметром r.
			new Circle(r) вызывает конструктор Circle с параметром r.
			new Circle() вызывает конструктор Circle без параметров.*/
		}
}
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
#endif;
#if 1
//Задание 7.Виртуальные функции и оператор разрешения области видимости.

		{
		std::cout << "\nChapter 7:\n";
		Rect r(GREEN);
		Shape* p = &r;
		p->WhereAmIVirtual(); // Now I am in class Shape (virtual)


		//7a Оператор разрешения области видимости.
		//Посредством объекта r и указателя p вызовите виртуальную функцию
		//WhereAmIVirtual()класса Shape
		// Оператор разрешения области видимости для вызова WhereAmIVirtual() из класса Shape
		std::cout << "\nChapter 7a:\n";
		r.Shape::WhereAmIVirtual(); // Now I am in class Shape (virtual)

		//4a Оператор разрешения области видимости.
		//Посредством объекта r и указателя p вызовите виртуальную функцию
		//WhereAmIVirtual()класса Shape


		}
#endif;
#if 1
		//////////////////////////////////////////////////////////////////////
		//Задание 8.Чисто виртуальные функции.
		//Введите в базовый класс метод void Inflate(int); Подумайте:
		//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
		//Реализуйте этот метод для производных классов.
		{
			std::cout << "\nChapter 8:\n";
			Rect r(GREEN);
			Shape* p = &r;
			p->Inflate(5);

			Circle c(BLUE, 10);
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
		{
			std::cout << "\nChapter 9:\n";
			const char* str1 = "Hello, ";
			const char* str2 = "world!";
			const char* str3 = " How are you?";

			MyString result = MyString(str1) + MyString(str2) + MyString(str3);

			std::cout << result << std::endl;
		}
#endif;
#if 1
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



		//создается объект класса Bytes с начальным значением 0x1F.
		std::cout << "\nChapter 10:\n";
		Bytes byte(0x48);
		std::cout << "Show Hex:" << std::endl;
		byte.ShowHex();
		std::cout << std::endl;
		std::cout << "Show Bin:" << std::endl;
		byte.ShowBin();
		std::cout << std::endl;
		std::cout << "Show Dec:" << std::endl;
		byte.ShowDec();
		std::cout << std::endl;
		std::cout << "Show Char:" << std::endl;
		byte.ShowChar();
		std::cout << std::endl;

		std::cout << "Show Hex Pos:" << std::endl;
		byte.ShowHexPos(0);
		std::cout << std::endl;
		std::cout << "Show Bin Pos:" << std::endl;
		byte.ShowBinPos(2);
		std::cout << std::endl;

		std::cout << "Edit Hex:" << std::endl;
		byte.EditHex(1, 8);
		byte.ShowHex();
		std::cout << std::endl;


#endif;
		return 0;
}