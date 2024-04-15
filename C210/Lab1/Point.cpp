#include "Point.h"

Point::Point(int xCoord = 0, int yCoord = 0)
    {
        X = xCoord;
        Y = yCoord;
    }
int Point::getX() const {
    return X;
}
int Point::getY() const {
    return Y;
}
// перегрузка оператора вывода объекта в консоль
std::ostream& operator << (std::ostream& os, const Point& p);
// переопределение оператора ==, сравнивает точки по координатам
bool operator==(const Point& p1, const Point& p2);