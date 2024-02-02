#ifndef COLOR_H
#define COLOR_H

#include <iostream>

enum Color { RED, GREEN, BLUE };

const char* colorToString(Color c);

class Shape {
protected:
    Color color;

public:
    Shape(Color c);

    Color getColor() const;

    void WhereAmI() const;

    virtual void WhereAmIVirtual() const;

    virtual void Inflate(int factor) = 0;

    virtual ~Shape();

    virtual void printInfo() const;
};

class Rect : public Shape {
public:
    Rect(Color c = RED);

    void WhereAmI() const;

    void WhereAmIVirtual() const override;

    void printInfo() const override;

    void Inflate(int factor) override;

    ~Rect();
};

class Circle : public Shape {
public:
    Circle(Color c);

    Circle();

    Circle(const Rect& rect);

    void WhereAmI() const;

    void WhereAmIVirtual() const override;

    void Inflate(int factor) override;

    void printInfo() const override;

    ~Circle();
};

#endif