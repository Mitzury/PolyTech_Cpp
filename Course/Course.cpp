#include <iostream>
#include <string>
#include "../C100/Lab5/other.h"

using namespace std;

int main () {

	const int N = 5;
	int ar1[] = { 1, 2, 3, 4, 5 };
	int ar2[] = { 10, 5, 8, 2, 7 };

	PrintArray(ar1, N);
	PrintArray(ar2, N);
	int min1 = Min(ar1, N);
	int min2 = Min(ar2, N);

	std::cout << "Min in ar1: " << min1 << std::endl;
	std::cout << "Min in ar2: " << min2 << std::endl;

	const char* str1 = "Hello";
	const char* str2 = "World";
	int cmpResult = MyStrCmp(str1, str2);
	std::cout << "Comparison result: " << cmpResult << std::endl;

return 0;
}