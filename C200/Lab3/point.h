#include <iostream>

class Point {
private:
    int x, y;

public:
    Point();
    Point(int x, int y);

    Point& operator+=(const Point& other);
    Point& operator+=(int value);

    Point operator+(const Point& other) const;
    Point operator+(int scalar) const;
    Point operator-(int scalar) const;

    Point operator+() const;
    Point operator-() const;

    friend Point operator-=(Point& pt1, const Point& pt2);
    friend Point operator-=(Point& pt, int value);
    friend Point operator-(const Point& left, const Point& right);
    friend Point operator-(int scalar, const Point& point);

    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    void printCoordinates() const;

};