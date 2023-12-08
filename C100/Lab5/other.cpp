//#include "other.h"
#include <iostream>
void IncByValue(int value) {
	value++;
}

void IncByPointer(int* pValue) {
	(*pValue)++;
}

void IncByReference(int& refValue) {
	refValue++;
}


void Swap_p(int* pX, int* pY) {
	int temp = *pX;
	*pX = *pY;
	*pY = temp;
}

void Swap_r(int& refX, int& refY) {
	int temp = refX;
	refX = refY;
	refY = temp;
}


void PrintArray(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int Min(int arr[], int size) {
	int min = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int MyStrCmp(const char* str1, const char* str2) {
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 > *str2) {
			return 1;
		}
		else if (*str1 < *str2) {
			return -1;
		}
		++str1;
		++str2;
	}

	if (*str1 == '\0' && *str2 != '\0') {
		return -1;
	}
	else if (*str1 != '\0' && *str2 == '\0') {
		return 1;
	}

	return 0;
}

const char* NameOfMonth(int month) {
	const char* months[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	if (month >= 1 && month <= 12) {
		return months[month - 1];
	}
	else {
		return "Invalid month";
	}
}

int* MyMin(int* array, int size) {
	if (size <= 0 || array == nullptr) {
		return nullptr;
	}

	int* minElement = array;
	for (int i = 1; i < size; ++i) {
		if (array[i] < *minElement) {
			minElement = &array[i];
		}
	}

	return minElement;
}

///////////////////////////////////////////////////







