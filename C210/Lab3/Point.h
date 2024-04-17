#pragma once
#include <iostream>

class Point {
public:
    double x, y;
    Point();
    Point(double x_val, double y_val);
    Point(int x_val, int y_val);

    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    bool operator<(const Point& other) const;
    bool operator==(const Point& other) const;
};

