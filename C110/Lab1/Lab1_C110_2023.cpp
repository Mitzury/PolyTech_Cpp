//Распечатайте содержимое массива после сортировки
	
		// Объявление двухмерного массива
		char cBuffer[N_1][M_1];
		
		// Объявление массива указателей на строки
		char* cPointers[N_1];
		
		// Цикл ввода строк
		cout << "Введите строки (для завершения введите '*'):\n";
		
		int nIndex = 0;
		while (nIndex < N_1) {
			cout << "Строка " << nIndex + 1 << ": ";
			cin.getline(cBuffer[nIndex], M_1);
			
			// Проверка на завершение ввода
			if (strcmp(cBuffer[nIndex], STOP_STRING) == 0) {
				cout << "Ввод строк завершен.\n";
				break;
			}
			
			// Присвоение указателя на строку в массиве указателей
			cPointers[nIndex] = cBuffer[nIndex];
			
			++nIndex;
		}
		
		// Распечатка содержимого массива
		cout << "\nИсходный массив:\n";
		for (int i = 0; i < nIndex; ++i) {
			cout << cPointers[i] << '\n';
		}
		
		// Сортировка строк по методу "всплывающего пузырька"
		for (int i = 0; i < nIndex - 1; ++i) {
			for (int j = 0; j < nIndex - i - 1; ++j) {
				if (strcmp(cPointers[j], cPointers[j + 1]) > 0) {
					// Обмен указателями
					char* temp = cPointers[j];
					cPointers[j] = cPointers[j + 1];
					cPointers[j + 1] = temp;
				}
			}
		}
		
		// Распечатка содержимого массива после сортировки
		cout << "\nОтсортированный массив:\n";
		for (int i = 0; i < nIndex; ++i) {
			cout << cPointers[i] << '\n';
		}

