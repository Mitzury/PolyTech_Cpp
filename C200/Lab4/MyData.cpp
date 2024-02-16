#include "MyData.h"

// ќпределение конструктора класса MyData
MyData::MyData(Sex s, size_t a, const char* j, float sal) : sex(s), age(a), job(j), salary(sal) {}
// ¬ конструкторе инициализируютс€ члены данных класса MyData значени€ми аргументов конструктора

// ќпределение перегруженного оператора вывода
std::ostream& operator<<(std::ostream& os, const MyData& data) {
    // ќператор вывода выводит информацию о сотруднике в поток вывода
    os << "Sex: " << data.sex << ", Age: " << data.age << ", Job: " << data.job << ", Salary: " << data.salary;
    return os; // ¬озвращаем ссылку на поток вывода
}