#include "T.h"


template<typename T>
void printStack(stack<T> s) {
	while (!s.empty()) {
		cout << s.top() << " "; // Используем top для получения верхнего элемента
		s.pop(); // Удаляем верхний элемент после его вывода
	}
	cout << "\n";
}
