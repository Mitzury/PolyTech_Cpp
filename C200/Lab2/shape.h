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
    ~Shape();

    Color getColor() const;
    virtual void printInfo() const;
    virtual void Inflate(int factor);
  //  virtual void drawShape() const = 0;
    virtual void WhereAmI() const;
    virtual void WhereAmIVirtual() const;
};

class Rect : public Shape {
private:
    int width;
    int height;
    int x;
    int y;

public:
    Rect(Color c = RED, int width = 0, int height = 0, int x = 0, int y = 0);
    ~Rect();
    int getWidth() const;
    int getHeight() const;
    int getX() const;
    int getY() const;

    void printInfo() const override;
    void Inflate(int factor) override;
  //  void drawShape() const override;
    void WhereAmI() const override;
    void WhereAmIVirtual() const override;
};

class Circle : public Shape {
private:
    int centerX;
    int centerY;
    int radius;

public:
    Circle(Color c = RED, int centerX = 0, int centerY = 0, int radius = 0);
    ~Circle();
    void printInfo() const override;
    void Inflate(int factor) override;
   // void drawShape() const override;
    void WhereAmI() const override;
    void WhereAmIVirtual() const override;
};

#endif