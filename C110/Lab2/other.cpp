#include <iostream>
#include "other.h"
#include <cstdarg> 
#include <cstdio>
#include <cmath>



void printBuiltInArray(int ar[][M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << ar[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printDynamicArray(int** ar, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << ar[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


bool isLeapYear(size_t year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

size_t DayOfYear(size_t day, size_t month, size_t year, const int(&nDayTab)[2][13]) {
    size_t dayOfYear = day;
    for (size_t i = 1; i < month; ++i) {
        dayOfYear += nDayTab[isLeapYear(year)][i];
    }
    return dayOfYear;
}

void DayOfMonth(size_t numDay, size_t year, size_t& day, size_t& month, const int(&nDayTab)[2][13]) {
    size_t i;
    for (i = 1; i <= 12; ++i) {
        if (numDay <= nDayTab[isLeapYear(year)][i]) {
            break;
        }
        numDay -= nDayTab[isLeapYear(year)][i];
    }
    day = numDay;
    month = i;
}


void VarArgs(int arg1, ...) {
    va_list args;
    va_start(args, arg1);
    std::cout << "Macro_ Number of arguments: ";
    int count = 0;
    int value = arg1;
    while (value != 0) {
        ++count;
        value = va_arg(args, int);
    }
    std::cout << count << std::endl;
    va_end(args);
}

void VarArgs_1(int arg1, ...)
{
    int number = 0;	//счетчик элементов
    //Объявите указатель на int и инициализируйте его адресом
    //первого аргумента

    //Пока не достигнут конец списка:
    // а) печать значения очередного аргумента
    // б) модификация указателя (он должен указывать на
    //следующий аргумент списка)
    // в) увеличить счетчик элементов
    int* p = &arg1;
    for (int* p = &arg1; *p; p++, number++) {
       // std::cout << *p << ' ';
    }
    std::cout << "NoMacro_ Number of arguments: " << number << '\n';
    //Печать числа элементов

}


void inputCoefficients(double& A, double& B, double& C) {
    printf("Enter coefficients A, B, and C: ");
    scanf("%lf %lf %lf", &A, &B, &C);
}

void printTable(double A, double B, double C) {
    printf("\nTable of values for y = A*x*x + B*x + C\n");
    printf(" x    |    y\n");
    printf("--------------\n");

    for (double x = -2.0; x <= 2.0; x += 0.5) {
        double y = A * x * x + B * x + C;
        printf("%.2lf  |  %.2lf\n", x, y);
    }
}

double Sum(double a, double b) {
    return a + b;
}

double Sub(double a, double b) {
    return a - b;
}

double Mul(double a, double b) {
    return a * b;
}

double Div(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    else {
        return 0.0;
    }
}

double Power(double base, double exponent) {
    return std::pow(base, exponent);
}

void Sort(void* arr, size_t count, size_t size, void (*swapFn)(void*, void*), int (*cmpFn)(const void*, const void*)) {
    for (size_t i = 0; i < count - 1; ++i) {
        for (size_t j = 0; j < count - i - 1; ++j) {
            void* elem1 = static_cast<char*>(arr) + j * size;
            void* elem2 = static_cast<char*>(arr) + (j + 1) * size;

            if (cmpFn(elem1, elem2) > 0) {
                swapFn(elem1, elem2);
            }
        }
    }
}

void SwapInt(void* a, void* b) {
    int temp = *static_cast<int*>(a);
    *static_cast<int*>(a) = *static_cast<int*>(b);
    *static_cast<int*>(b) = temp;
}

int CmpInt(const void* a, const void* b) {
    return *static_cast<const int*>(a) - *static_cast<const int*>(b);
}

void SwapDouble(void* a, void* b) {
    double temp = *static_cast<double*>(a);
    *static_cast<double*>(a) = *static_cast<double*>(b);
    *static_cast<double*>(b) = temp;
}

int CmpDouble(const void* a, const void* b) {
    if (*static_cast<const double*>(a) < *static_cast<const double*>(b)) return -1;
    if (*static_cast<const double*>(a) > *static_cast<const double*>(b)) return 1;
    return 0;
}

void SwapStr(void* a, void* b) {
    char* temp = *static_cast<char**>(a);
    *static_cast<char**>(a) = *static_cast<char**>(b);
    *static_cast<char**>(b) = temp;
}

int CmpStr(const void* a, const void* b) {
    return std::strcmp(*static_cast<const char* const*>(a), *static_cast<const char* const*>(b));
}

const char* GetString1()
{
    return "Hello";
}

const char* GetString2()
{
    const char* str = "Book";
    return str;
}

const char* GetString3()
{
    char str[] = "Little";
    return str;
}

const char* GetString4()
{
    static char str[] = "world";
    return str;
}

const char* GetString5()
{
    char* str = new char[strlen("time") + 1];
    return str;
}