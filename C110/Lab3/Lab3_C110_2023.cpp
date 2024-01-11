/*************************************************************
Практическое занятие №3-курс-С110. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/

#include "book.h"
#include "card_index.h"
#include <iostream>

void main()
{

#if 0;
	//Тема. Структуры С.	
//Задание 1.1 Объявите структуру BOOK, описывающую книгу
//(автор, заглавие, год издания, цена, категория…).
//Подумайте: какого типа могут быть поля структуры.
//Подсказка: объявление структуры рекомендуется выносить
//в заголовочный файл.

	//Задание 1.2. Создайте разными способами экземпляры (объекты) типа BOOK 

	//a) глобальный объект типа BOOK создайте без инициализации

	BOOK globalBook;

	//б) динамический объект типа BOOK создайте также без инициализации

	BOOK* dynamicBook = new BOOK;

	//в) локальный объект типа BOOK создайте без инициализации, но позднее заполните вручную поля структуры некоторыми значениями

	BOOK localBook;

	//г) статический объект типа BOOK создайте  и проинициализируйте при определении с помощью списка инициализации.

	BOOK staticBook = { "John Doe", "The Book", 2020, 25.99, "Fiction" };

	//Используйте структуру BOOK, созданную в предыдущем задании.
	//Для этого достаточно переписать и подключить к проекту файлы book.h и book.cpp

	//Определите - сколько памяти отводит компилятор под каждый такой объект. 
	//Подумайте: от чего зависит объем выделяемой памяти?


	//Задание 1.3.1 Напишите функцию, выводящую на экран реквизиты книги. 
	//Прототип функции поместите в файл "book.h", а реализацию - в "book.cpp"
	//Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
	//Для вывода на консоль используйте функцию стандартной библиотеки printf

	printBookInfo(staticBook);

	//Задание 1.3.2
	//С помощью разработанной функции выведите на консоль информацию о книгах, созданных в п.1.2 (кроме динамической)

	printBookInfo(globalBook);
	printBookInfo(localBook);

	//Задание 1.4.1 Напишите функцию для формирования полей структуры.
	//Прототип функции поместите в файл "book.h", а реализацию - в "book.cpp"
	//Для ввода используйте функцию стандартной библиотеки scanf

	fillBookFields(*dynamicBook);

	//Замечание: неплохо заложить в такую функцию возможность проверки
	//корректности введенного значения, например, год издания не может быть
	//меньше, чем... (год появления письменности), категорию пользователь
	//должен выбирать из существующих, цена не может быть отрицательной...

	//Задание 1.4.2
	//Используйте разработанную функцию для заполнения полей динамически созданного экземпляра книги 
	//распечатайте содержимое этой книги с помощью функции, соданной в п.1.3.1 
	//
	printBookInfo(*dynamicBook);



	delete dynamicBook;

#endif;
#if 0;
	//----------------------------------------------------------------------------------------------------------------
		//Задание 2.1 Создаем "картотеку".

		//Пользователь должен иметь возможность по своему желанию выполнять
		//разные действия с картотекой => нужно такую возможность ему
		//предоставить: это может выглядеть как вывод "меню" (перечень
		//возможных действий и соответствующих реакций пользователя), например:
		//Распечатать содержимое картотеки (1)
		//Ввести новую книгу (2)
		//Удалить существующую(ие) (3)
		//...
		//Выход из программы (...)

		//"Картотека" - это массив структур => нужно такой массив создать.
		//Замечание: размер массива придется увеличиватьпо мере добавления книг => Каким должен быть такой массив???	

		//Помимо самого массива потребуется хранить дополнительно текущие значения количества книг и емкости этого массива,
		//так как эти значения могут изменяться в процессе работы
		//Поскольку эти параметры логически связаны, имеет смысл объединить их в структуру, например, CARD_INDEX
		// ПОДРОБНЫЕ ПОДСКАЗКИ к работе над картотекой описаны в файле  "Картотека_2021.pdf"

		//Реализуйте посредством функций разные возможности работы с картотекой

		// Упрощения:
		//1. пусть автор и заглавие книги состоят из одного слова
		//2. все строки можно задавать латинскими буквами. 
		//   для вывода русских символов требуется установить кодировку  -	setlocale(LC_CTYPE, ".1251");
		//   (заголовочный файл <clocale>)
		//   Если хочется не только выводить, но и вводить русские символы, следует
		//   а) пользоваться расширенными функциями ввода/вывода - wprintf(), wscanf()
		//   б) хранить строки как расширенные - wchar_t
		//   в) установить кодировку для ввода русских символов - setlocale(LC_CTYPE, ".866");

	setlocale(LC_CTYPE, ".1251"); // Установка кодировки для вывода русских символов

	CARD_INDEX cardIndex;
	initializeCardIndex(cardIndex, 4); // Начальная емкость массива - 5

	int choice;
	do {
		printMenu_1();
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			printCardIndex(cardIndex);
			break;
		case 2:
			addBook(cardIndex);
			break;
		case 3:
			removeBook(cardIndex);
			break;
		case 4:
			std::cout << "Exiting program.\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);

	cleanUp(cardIndex); // Освобождение выделенной памяти

#endif;
#if 0;
	//----------------------------------------------------------------------------------------------------------------
		//Задание 2.2 (*) Дорабатываем "картотеку".	

		//Записать текущее содержимое картотеки в файл (4)
		//Считать из файла содержимое в картотеку (5)

		//Подсказка1:	для файлового ввода/вывода используйте функции fprintf и fscanf
		//				(заголовочный файл <cstdio>


		// Подсказка2: удобно в качестве первого данного в файле хранить количество
		//			   книг в картотеке

		// Подсказка3:  для чтения из файла можно использовать следующий алгоритм:
		//				Если файл существует и его удалось открыть:
		//if()
		//{
		//Чтение данных из файла
		//а) считали количество элементов
		//б) создали массив требуемой размерности
		//в) считали данные из файла в массив
		//}

	setlocale(LC_CTYPE, ".1251"); // Установка кодировки для вывода русских символов

	CARD_INDEX cardIndex_1;
	initializeCardIndex(cardIndex_1, 5); // Начальная емкость массива - 5

	int choice_1;
	do {
		printMenu();
		std::cout << "Enter your choice: ";
		std::cin >> choice_1;

		switch (choice_1) {
		case 1:
			printCardIndex(cardIndex_1);
			break;
		case 2:
			addBook(cardIndex_1);
			break;
		case 3:
			removeBook(cardIndex_1);
			break;
		case 4:
			saveToFile(cardIndex_1, "card_index.txt");
			break;
		case 5:
			loadFromFile(cardIndex_1, "card_index.txt");
			break;
		case 6:
			std::cout << "Exiting program.\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	} while (choice_1 != 6);

	cleanUp(cardIndex_1); // Освобождение выделенной памяти

#endif;
#if 1;
	//----------------------------------------------------------------------------------------------------------------
	//Задание 3 (*). Предоставьте пользователю возможность выводить перечень книг
	//в определенном порядке => напишите функцию (функции) сортировки массива
	//по любому из полей структуры.
	// НЕ (!!!) используйте функцию sort  из 2-ой лабораторной работы, а напишите 
	//функцию  сортировки сами  (либо  selection, либо пузырьковую)

	//Замечание: признак - "по какому полю сортируем" можно ввести с помощью
	//перечисления.

	//При завершении программы пребуется очистить динамическую память. Не забудьте это сделать

	setlocale(LC_CTYPE, ".1251"); // Установка кодировки для вывода русских символов

	CARD_INDEX cardIndex_2 = { 0 };
	//initializeCardIndex(cardIndex_2, 1); // Начальная емкость массива - 5

	int choice_2;
	do {
		printMenu();
		std::cout << "Enter your choice: ";
		std::cin >> choice_2;

		switch (choice_2) {
		case 1:
			printCardIndex(cardIndex_2);
			break;
		case 2:
			addBook(cardIndex_2);
			break;
		case 3:
			removeBook(cardIndex_2);
			break;
		case 4:
			saveToFile(cardIndex_2, "card_index.txt");
			break;
		case 5:
			loadFromFile(cardIndex_2, "card_index.txt");
			break;
		case 6: {
			int sortField;
			std::cout << "Sort by:\n";
			std::cout << "1. Author\n";
			std::cout << "2. Title\n";
			std::cout << "3. Year\n";
			std::cout << "4. Price\n";
			std::cout << "5. Category\n";
			std::cout << "Enter your choice: ";
			std::cin >> sortField;

			if (sortField >= 1 && sortField <= 5) {
				sortBooks(cardIndex_2, static_cast<SortField>(sortField - 1));
			}
			else {
				std::cout << "Invalid choice. Sorting aborted.\n";
			}
			break;
		}
		case 7:
			std::cout << "Exiting program.\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	} while (choice_2 != 7);

	cleanUp(cardIndex_2); // Освобождение выделенной памяти
#endif;

}