#include "T.h"


template<typename T>
void printStack(stack<T> s) {
	while (!s.empty()) {
		cout << s.top() << " "; // ���������� top ��� ��������� �������� ��������
		s.pop(); // ������� ������� ������� ����� ��� ������
	}
	cout << "\n";
}
