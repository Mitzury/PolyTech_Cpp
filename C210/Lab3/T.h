#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void printVectorOfPointersStats(const std::vector<T*>& v);

template <typename T>
void printVectorInfo(const std::vector<T>& vec);

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& vv);

template <typename T>
void printVector(const std::vector<T>& vec);

template <typename T>
void insertBeforeEveryElement(std::vector<T>& vec, const T& value);

template <typename T>
void removeConsecutiveDuplicates(std::vector<T>& vec);

template <typename T>
void removeAllDuplicates(std::vector<T>& vec);

template <typename container>
void printContainer(const container& c);

template<typename T>
void insertIfNotExists(std::vector<T>& vec, const T& value);

bool isNegative(int x);
