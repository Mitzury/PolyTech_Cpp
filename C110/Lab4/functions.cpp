// File: functions.cpp

#include "functions.h"
#include <iostream>

// 1.1
int sumOfFirstN(int N) {
    if (N == 0) {
        return 0;
    } else {
        return N + sumOfFirstN(N - 1);
    }
}

// 1.2
int countDigits(int number) {
    if (number == 0) {
        return 0;
    } else {
        return 1 + countDigits(number / 10);
    }
}

// 1.3 const char*
void reversePrint(const std::string &str) {
    if (str.empty()) {
        return;
    } else {
        reversePrint(str.substr(1));
        std::cout << str[0];
    }
}

// 1.4
void forwardPrint(const std::string &str) {
    if (str.empty()) {
        return;
    } else {
        std::cout << str[0];
        forwardPrint(str.substr(1));
    }
}
