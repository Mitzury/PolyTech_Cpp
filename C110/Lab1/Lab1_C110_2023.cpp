/*************************************************************
	Практическое занятие 1. Встроенные многомерные массивы.
							Динамическое выделение памяти.
							Простейшие алгоритмы сортировки и поиска.
							Сложные указатели.
							Ссылки.
*************************************************************/
#define _CRT_SECURE_NO_WARNINGS // Разрешение использовать небезопасные функции
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <clocale>

#define N 4
#define M 4
#define K 3

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");

#if 0
	///////////////////////////////////////////////////////////////
	//			Встроенные  многомерные массивы                  //
	///////////////////////////////////////////////////////////////
	
	//Задание 1.
	//а)Объявите трехмерный N*M*K массив и сформируйте указанные
	//значения элементов следующим образом:
	//(проинициализируйте массив при определении)
	//						  |------------|
	//  					/ |	5  5  5  5 |
	//					   |------------|5 |
	//  				 / | 4  4  4  4 |5 |
	//				    |------------|4 |__|
	//			      / | 3  3  3  3 |4 |/
	//    			 |------------|3 |__|
	//			   / | 2  2  2  2 |3 | /
	//			  |------------|2 |__|
	//			  | 1  1  1  1 |2 | /
	//			  | 1  1  1  1 |__|
	//			  | 1  1  1  1 | /
	//			  |____________|
	
	const int X = 4;
	const int Y = 3;
	const int Z = 5;
	int arrayA[Z][Y][X] = {
		{ {5, 5, 5, 5}, {5, 5, 5, 5}, {5, 5, 5, 5}},
		{ {4, 4, 4, 4}, {4, 4, 4, 4}, {4, 4, 4, 4}},
		{ {3, 3, 3, 3}, {3, 3, 3, 3}, {3, 3, 3, 3}},
		{ {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}},
		{ {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}
	};

	for (int i = 0; i < Z; ++i) {
		for (int j = 0; j < Y; ++j) {
			for (int k = 0; k < X; ++k) {
				cout << arrayA[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
#endif
	
#if 0	
	//б) объявите трехмерный N*M*K неинициализированный массив, 
	// присвойте значения элементам с помощью кода
	//						  |------------|
	//  					/ |	5  5  5  5 |
	//					   |------------|5 |
	//  				 / | 4  4  4  4 |5 |
	//				    |------------|4 |__|
	//			      / | 3  3  3  3 |4 |/
	//    			 |------------|3 |__|
	//			   / | 2  2  2  2 |3 | /
	//			  |------------|2 |__|
	//			  | 1  1  1  1 |2 | /
	//			  | 1  1  1  1 |__|
	//			  | 1  1  1  1 | /
	//			  |____________|
	

	//Рекомендация: В качестве размерностей массива лучше указать N, M, K,
	//а не задавать их жестко.

	//Средствами отладчика проверьте правильность Вашего решения.

	//Или выведите содержимое массива на печать.
	// Удобно выводить построчно каждый слой  массива и
	//после каждого слоя пропускать строку для того, чтобы отделить один слой от другого
	{
		const int X = 4;
		const int Y = 3;
		const int Z = 5;
		int arrayB[Z][Y][X];
		for (int i = 0; i < Z; ++i) {
			for (int j = 0; j < Y; ++j) {
				for (int k = 0; k < X; ++k) {
					arrayB[i][j][k] = i + 1;
				}
			}
		}

		for (int i = 0; i < Z; ++i) {
			for (int j = 0; j < Y; ++j) {
				for (int k = 0; k < X; ++k) {
					cout << arrayB[i][j][k] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';
		}


		//в) найдите сумму элементов массива, объявленного в пункте 
		//б) Подумайте, как это сделать эффективно.

		int sum = 0;
		int* p = &arrayB[0][0][0];
		for (size_t i = 0; i < (X*Y*Z); i++)
		{
			sum += p[i];

		}

		
		for (int i = 0; i < Z; ++i) {
			for (int j = 0; j < Y; ++j) {
				for (int k = 0; k < X; ++k) {
					sum += arrayB[i][j][k];
				}
			}
		}

		cout << "Sum of elements: " << sum << '\n';

	}
#endif
#if 0
	//г) объявите трехмерный N*M*K  массив и проинициализируйте его при определении:
	//				     |--------|
	//			       / |3  0  0 |
	//      		 |---------|0 |
	//    		   / | 2  0  0 |0 |
	//			  |---------|0 |__|
	//			  | 1  0  0 |0 | /
	//			  | 0  0  0 |__|
	//			  | 0  0  0 | /
	//			  |_________|
	
	{
		const int X = 3;
		const int Y = 3;
		const int Z = 3;
		int arrayC[Z][Y][X] = {
			{{3}},
			{{2}},
			{{1}}
		};

		for (int i = 0; i < Z; ++i) {
			for (int j = 0; j < Y; ++j) {
				for (int k = 0; k < X; ++k) {
					cout << arrayC[i][j][k] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';
		}
	}
	//д) Инициализация массивов строковыми литералами:
	//Объявите и проинициализируйте строковыми литералами два массива:
	//двумерный массив символов и одномерный массив указателей на char. 
	//Поясните разницу в использовании элементов таких массивов.
	// Двумерный массив символов
	char charArray[][6] = { "Hello", "World" };
	
	// Одномерный массив указателей на char
	const char* charPointerArray[] = { "Hello", "World" };
	
	// Печать двумерного массива символов
	for (int i = 0; i < 2; ++i) {
		cout << charArray[i] << '\n';
	}
	
	// Печать одномерного массива указателей
	for (int i = 0; i < 2; ++i) {
		cout << charPointerArray[i] << '\n';
	}
#endif
#if 0
	/////////////////////////////////////////////////////////////////////
	//Задание 2.
	//С помощью данной заготовки напишите программу,которая:
	//вводит строки с клавиатуры с помощью cin>>...
	//в объявленный Вами двухмерный ВСТРОЕННЫЙ массив 10*80 элементов типа char;
	//признаком конца ввода является символ * (то есть строка - "*") или
	//заполнение всего массива (больше свободных строк нет);

	//То есть:
		//a) можно заполнять весь массив полностью (не забудьте подсказать, сколько элементов в массиве)
		//б) можно заполнять массив частично, до тех пор, пока пользователь не ввел строку "*".
		//Например:вводим строки (строки с пробелами не задаются, т.к. пробелы являются разделителями):
		//"Hello"
		//"Ok"
		//"*"
	//Выполните сортировку строк в алфавитном порядке. 
	// 
	//Пояснение: крайне не рекомендуется для сортировки сложных объектов физически
	//перемещать их в памяти ( в нашем случае перемещать (копировать) строки)
	//Намного эффективнее завести массив указателей на соответствующие строки 
	//и перемещать только указатели на начало строк (массивов символов).
	//Вопрос: При таком способе что будет  отсортировано?

	//Подсказка: для лексикографического сравнения строк пользуйтесь
	//функцией стандартной библиотеки strcmp(...), заголовочный файл <string.h>.
	
	//int strcmp(char const* _Str1, char const* _Str2);

	// далее Вам предлагается алгоритм, следуя которому, Вы сможете решить задачу.
	{

		//Определите необходимые значения как константы
		//STOP_STRING  -  "*"	//признак "прекратить ввод"
		//M  -  80	//максимальный размер одной строки
		//N  -  10	//максимальное количество строк в массиве

		const char STOP_STRING[] = "*";
		const int M_1 = 80;
		const int N_1 = 10;

		//Объявите двухмерный массив с именем cBuffer типа char и
		// размерностью N*M

		char cBuffer[N_1][M_1];

		//Объявите массив (с именем cPointers) указателей на строки
		//размерностью N

		char* cPointers[N_1];

		//Цикл ввода строк:
		//а) выведите приглашение для ввода

		cout << "Введите строки (для завершения введите '*'):\n";

		//б) пока не введена строка STOP_STRING или не заполнен весь массив

		int nIndex = 0;
		while (nIndex < N_1) {
			cout << "Строка " << nIndex + 1 << ": ";
			//ввод строки в массив cBuffer:
			cin.getline(cBuffer[nIndex], M_1);
			//если введена строка - признак окончания, то выйти из цикла
			if (strcmp(cBuffer[nIndex], STOP_STRING) == 0) {
				//Выдать диагностику о том, что прием строк завершен.
				cout << "Ввод строк завершен.\n";
				break;
			}
			//Присвойте элементу массива cPointers с индексом nIndex
            //указатель на строку с номером nIndex в массиве cBuffer
			cPointers[nIndex] = cBuffer[nIndex];
			++nIndex;
		}

		//Распечатайте содержимое массива
		cout << "\nИсходный массив:\n";
		for (int i = 0; i < nIndex; ++i) {
			cout << cPointers[i] << '\n';
		}
		
		//Теперь сортируем строки:
		//Цикл сортировки строк по методу "всплывающего пузырька" в
		//порядке возрастания кода первого символа
		for (int i = 0; i < nIndex - 1; ++i) {
			for (int j = 0; j < nIndex - i - 1; ++j) {
				//if (strcmp(cPointers[j], cPointers[j + 1]) > 0) { // (лексико графическая сортировка по алфавиту) 
				if (cPointers[j][0] > cPointers[j + 1][0]) { // по коду символа
					char* temp = cPointers[j];
					cPointers[j] = cPointers[j + 1];
					cPointers[j + 1] = temp;
				}
			}
		}
		//Распечатайте содержимое массива после сортировки
		cout << "\nОтсортированный массив:\n";
		for (int i = 0; i < nIndex; ++i) {
			cout << cPointers[i] << '\n';
		}


	}
#endif
#if 0
	//////////////////////////////////////////////////////////////////////////////

	//Задание 3*. Объявление и использование указателей на многомерные
	// массивы. Проинициализируйте трехмерный массив

	const size_t N_2 = 4, M_2 = 3, K_2 = 4;
	double dArray[N_2][M_2][K_2]; 
	
	//так, как показано на рисунке и напишите фрагмент
	//кода, который меняет местами значения элементов четных
	//и нечетных слоев:
	//	было:
	//					    |-----------|
	//  				  / |4  4  4  4 |
	//				     |-----------|4 |
	//			       / |3  3  3  3 |4 |
	//    			 |------------|3 |__|
	//			   / | 2  2  2  2 |3 | /
	//			  |------------|2 |__|
	//			  | 1  1  1  1 |2 | /
	//			  | 1  1  1  1 |__|
	//			  | 1  1  1  1 | /
	//			  |____________|

	//	стало:	

	//					   |------------|
	//  				  /| 3  3  3  3 |
	//				     |-----------|3 |
	//			       / |4  4  4  4 |3 |
	//    			 |------------|4 |__|
	//			   / | 1  1  1  1 |4 | /
	//			  |------------|1 |__|
	//			  | 2  2  2  2 |1 | /
	//			  | 2  2  2  2 |__|
	//			  | 2  2  2  2 | /
	//			  |____________|

	/*
	for(int i=0; i<...; ...)
	{
	//Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА РАВЕНСТВА!!!
	... =  dArray[i];
	... =  dArray[i+1];
	//Подсказки:
	//1) Слева от знака равенства надо определить два  сложных указателя.
	//Так как справа находятся "имена" слоев, т.е. двумерных массивов, то
	// остается вспомнить какой указатель является эквивалентным для имени двумерного массива.

	//2)дальше, воспользовавшись этими указателями, переставляем местами элементы i-того и i+1-ого слоев


	}
	*/

	double value = 1.0;
	for (size_t i = 0; i < N_2; ++i) {
		for (size_t j = 0; j < M_2; ++j) {
			for (size_t k = 0; k < K_2; ++k) {
				dArray[i][j][k] = value++;
			}
		}
	}


	cout << "Исходный массив:\n";
	for (size_t i = 0; i < N_2; ++i) {
		for (size_t j = 0; j < M_2; ++j) {
			for (size_t k = 0; k < K_2; ++k) {
				cout << dArray[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}


	for (size_t i = 0; i < N_2 - 1; i += 2) {
		for (size_t j = 0; j < M_2; ++j) {
			for (size_t k = 0; k < K_2; ++k) {
				double temp = dArray[i][j][k];
				dArray[i][j][k] = dArray[i + 1][j][k];
				dArray[i + 1][j][k] = temp;
			}
		}
	}

	cout << "\nМассив после обмена:\n";
	for (size_t i = 0; i < N_2; ++i) {
		for (size_t j = 0; j < M_2; ++j) {
			for (size_t k = 0; k < K_2; ++k) {
				cout << dArray[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

#endif

#if 0
	///////////////////////////////////////////////////////////////////////////
	/*
	//Задание 4
	//а) Объявите двухмерный ВСТРОЕННЫЙ массив элементов типа char.
	//Сформируйте значения элементов массива с помощью генератора случайных
	//чисел таким образом, чтобы в массиве были только символы '_' и '*'

		//Подсказка 1: для генерации случайных чисел используйте функцию
		//стандартной библиотеки - rand() (<cstdlib>)
		//Можно с помощью генератора случайных чисел  и оператора % получать значения 0 и 1,
		// а в массив помещать соответственно '_' и '*'.


		//Подсказка 2: На самом деле те значения, которые создаются генератором случайных
		//чисел являются "псевдослучайными", то есть при двух последовательных запусках
		//приложения Вы получаете две одинаковые последовательности значений.
		//Для того чтобы генерируемые "случайные" значения были разными при каждом
		//запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
		//и time() (<ctime>).
		//Функция srand() осуществляет "привязку" начала генерации к указанному в качестве параметра значению.
		//Функция time() задает эту точку отсчета, считывая текущее время
		//srand( time( 0 ) );

		//Замечание: в программе запускать функцию srand()  достаточно один раз


	//В каждой строке "сдвиньте звездочки" в начало строки, например:
	//было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
	//стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
	//и распечатайте массив по строкам - "постройте распределение"

	*/
	const int rows = 5;
	const int cols = 10;

	srand((time(0)));
	char charArray_2[rows][cols];

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			charArray_2[i][j] = (rand() % 2 == 0) ? '*' : '_';
		}
	}

	for (int i = 0; i < rows; ++i) {
		int starsCount = 0;
		for (int j = 0; j < cols; ++j) {
			if (charArray_2[i][j] == '*') {
				char temp = charArray_2[i][j];
				charArray_2[i][j] = charArray_2[i][starsCount];
				charArray_2[i][starsCount] = temp;
				++starsCount;
			}
		}
	}

	cout << "Left Aray:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << charArray_2[i][j] << " ";
		}
		cout << endl;
	}
	
	// б) Модифицируйте предыдущее задание следующим способом:
	//После заполнения массива с помощью генератора случайных чисел
	//"сдвиньте" звездочки по столбцам вниз и распечатайте полученное
	//"распределение"
	char charArray_3[rows][cols];
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			charArray_3[i][j] = (rand() % 2 == 0) ? '*' : '_';
		}
	}

	cout << "\nMain Array:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << charArray_3[i][j] << " ";
		}
		cout << endl;
	}

	for (int j = 0; j < cols; ++j) {
		int emptyCount = 0;
		for (int i = rows - 1; i >= 0; --i) {
			if (charArray_3[i][j] == '_') {
				++emptyCount;
			}
			else if (emptyCount > 0) {
				charArray_3[i + emptyCount][j] = charArray_3[i][j];
				charArray_3[i][j] = '_';
			}
		}
	}

	cout << "\nDown Array:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << charArray_3[i][j] << " ";
		}
		cout << endl;
	}


#endif
#if 1
	///////////////////////////////////////////////////////////////
	//			Динамическое выделение памяти                    //
	///////////////////////////////////////////////////////////////
	//Задание 5.
		////Задание 5а.Создайте ДИНАМИЧЕСКИЙ двухмерный массив с размерностями,
		//вычисляемыми в процессе выполнения программы - N*M.
		//Задайте значения элементов помощью генератора случайных чисел.


		//Задание 5б. В сформированном массиве отсортируйте каждую строку по
		//убыванию значений. Используйте сортировку "выбором"


		//Задание 5в. Объявите одномерный массив размерностью N.
		//Сформируйте значение i-ого элемента одномерного массива  
		//равным среднему значению элементов i-ой строки
		//двухмерного массива


		//Подсказка - не забудьте освободить память!
		
	// Задание 5а: Создание динамического двухмерного массива
	{
		int N_4, M_4;
		cout << "Введите размерности массива (N M): ";
		cin >> N_4 >> M_4;

		int** dynamicArray = new int* [N_4];
		for (int i = 0; i < N_4; ++i) {
			dynamicArray[i] = new int[M_4];
		}

		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i < N_4; ++i) {
			for (int j = 0; j < M_4; ++j) {
				dynamicArray[i][j] = rand() % 10;
			}
		}

		cout << "Original Array:\n";
		for (int i = 0; i < N_4; ++i) {
			for (int j = 0; j < M_4; ++j) {
				cout << dynamicArray[i][j] << " ";
			}
			cout << "\n";
		}
		// Сортировка выбором
		for (int i = 0; i < N_4; ++i) {
			for (int j = 0; j < M_4 - 1; ++j) {
				int maxIndex = j;
				for (int k = j + 1; k < M_4; ++k) {
					if (dynamicArray[i][k] > dynamicArray[i][maxIndex]) {
						maxIndex = k;
					}
				}

				if (maxIndex != j) {
					int temp = dynamicArray[i][j];
					dynamicArray[i][j] = dynamicArray[i][maxIndex];
					dynamicArray[i][maxIndex] = temp;
				}
			}
		}

		cout << "Sort string:\n";
		for (int i = 0; i < N_4; ++i) {
			for (int j = 0; j < M_4; ++j) {
				cout << dynamicArray[i][j] << " ";
			}
			cout << "\n";
		}


		int* averageArray = new int[N_4];
		for (int i = 0; i < N_4; ++i) {
			int sum = 0;
			for (int j = 0; j < M_4; ++j) {
				sum += dynamicArray[i][j];
			}
			averageArray[i] = sum / M_4;
		}

		cout << "Avg:\n";
		for (int i = 0; i < N_4; ++i) {
			cout << averageArray[i] << " ";
		}

		for (int i = 0; i < N_4; ++i) {
			delete[] dynamicArray[i];
		}
		delete[] dynamicArray;
		delete[] averageArray;
	}
#endif
#if 0
	
	/////////////////////////////////////////////////////////////////////////////
	//Задание 6. 
		//Реализуйте задание 2, используя не встроенные, а ДИНАМИЧЕСКИЕ массивы (массив?).
		// Важно! 
		//Так как строки могут быть разной длины, /эффективным решением было бы 
		//отводить под каждую строку ровно столько байтов, сколько требуется для ее хранения.
		//
		//Для того, чтобы определить длину введенной строки можно воспользоваться 
		//функцией strlen 
		//size_t strlen(char const* _Str);

	//При этом значение количества строк сформируйте с помощью потока ввода
	//Цикл ввода строк:

	// Для ввода строки нужно использовать буфер "достаточного" размера. 
	// В качестве такого буфера обычно используется встроенный массив.
	// Для того, чтобы введенную строку  скопировать из буфера в массив  строк,
	// можно воспользоваться функцией strcpy
	//char* strcpy(	char* _Dest,  char const* _Source);
	//  или
	// 
	//errno_t strcpy_s(char* _Dest, size_t  _SizeInBytes, char const* _Source); 
	//где _SizeInBytes - размер "приемного" буфера _Dest
	
	//Замечание: 
	//скорее всего,если Вы используете strcpy, то при компиляции Вы получите следующую ошибку:
	//Severity	Code	Description	Project	File	Line	Suppression State
	//	Error	C4996	'strcpy': This function or variable may be unsafe.
	//Consider using strcpy_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.

	//Это происходит потому, что функция strcpy считается небезопасной.

	//Для того, чтобы пользоваться функцией strcpy, а не strcpy_s, можно
	//  - либо объявить макрос #define _CRT_SECURE_NO_WARNINGS   (обязательно ДО всех #include !!!!!)
	//- либо установить режим без доп. проверки на безопасность Properties->C/C++ ->General->SDL checs -> No


	//Цикл сортировки строк по методу "всплывающего пузырька" в
	//порядке возрастания кода первого символа int nStringNumber;
	int nStringNumber;
	int nIndex;
	char buff[256];
	int Size = 0;

	const char stop_str[] = { "*" };

	std::cout << "Enter a number of string:";
	std::cin >> nStringNumber;
	char** cPointers = new char* [nStringNumber];

	std::cout << "For EOL'*'\n";
	for (int i = 0; i < nStringNumber; i++)
	{
		std::cout << "String " << i + 1 << ": ";
		std::cin >> buff;
		Size = 0;
		Size = strlen(buff);
		cPointers[i] = new char[Size +1];
		strcpy(cPointers[i], buff);
		if (strcmp(cPointers[i], stop_str) == 0)
		{
			std::cout << "\nYou Have entered stop word\n";
			break;

		}
		nIndex = i + 1;
	}
	for (int i = 0; i < nIndex; i++)
	{
		std::cout << cPointers[i];
		std::cout << '\n';
	}
	for (int i = 0; i < nIndex; i++)
	{
		for (int j = 0; j < nIndex - 1; j++)
		{
			if ((strcmp(cPointers[j], cPointers[j + 1])) > 0)
			{
				char* temp = cPointers[j];
				cPointers[j] = cPointers[j + 1];
				cPointers[j + 1] = temp;
			}
		}
	}
	std::cout << '\n';
	for (int i = 0; i < nIndex; i++)
	{
		std::cout << cPointers[i] << " Size: " << strlen(cPointers[i]);
		std::cout << '\n';
	}

	for (int i = 0; i < nIndex; i++) {
		delete[] cPointers[i];
	}

	delete[] cPointers;

#endif
	return 0;
}
