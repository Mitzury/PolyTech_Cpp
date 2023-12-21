#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cstddef> 
#include <cstdarg>

const int N = 3;
const int M = 4;

void printBuiltInArray(int ar[N][M]);
void printDynamicArray(int** ar, int rows, int cols);


const int nDayTab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool isLeapYear(size_t year);
size_t DayOfYear(size_t day, size_t month, size_t year, const int(&nDayTab)[2][13]);
void DayOfMonth(size_t numDay, size_t year, size_t& day, size_t& month, const int(&nDayTab)[2][13]);


void VarArgs(int arg1, ...);

template<typename T>
void PrintArgs(T value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Args>
void PrintArgs(T value, Args... args) {
    std::cout << value << " ";
    PrintArgs(args...);
}

template<typename... Args>
void VarArgs_1(Args... args) {
    std::cout << "Number of arguments: ";
    PrintArgs(args...);
}

void inputCoefficients(double& A, double& B, double& C);

void printTable(double A, double B, double C);


double Sum(double a, double b);
double Sub(double a, double b);
double Mul(double a, double b);
double Div(double a, double b);
double Power(double base, double exponent);


void Sort(void* arr, size_t count, size_t size, void (*swapFn)(void*, void*), int (*cmpFn)(const void*, const void*));
void SwapInt(void* a, void* b);
int CmpInt(const void* a, const void* b);
void SwapDouble(void* a, void* b);
int CmpDouble(const void* a, const void* b);
void SwapStr(void* a, void* b);
int CmpStr(const void* a, const void* b);

const char* GetString1();
const char* GetString2();
const char* GetString3();
const char* GetString4();
const char* GetString5();

#endif




