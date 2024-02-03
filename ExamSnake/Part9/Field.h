#pragma once


struct Field {
	int* X;
	int* Y;
	int* arr;
	void CreateField(int X, int Y, Field& Field);
	void PrintField(const Field& Field, int X, int Y);
};