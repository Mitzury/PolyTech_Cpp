#include <iostream>
#include <string>

class MyString {
public:
    std::string str;
    MyString() : str("") {}
    // ����������� ������ MyString ������� ��������� std::string � �������� ��������� 
    // � �������������� ���������� - ���� str ���������� �������. ���� ����������� ����������, 
    // ����� ������ ���� MyString ��������� � ���������� ������.
    MyString(const std::string& s) : str(s) {}
};

//������� 3
// ������������ ��� ������
enum Color {
    RED,
    GREEN,
    BLUE
};

// ������� ����� Shape
class Shape {
protected:
    Color color;

public:
    // ����������� �������� ������ � ����������-������
    Shape(Color c) : color(c) {
        std::cout << "Shape constructor" << std::endl;
    }

    // ����������� ���������� ��� ����������� �������� �������� ����� ��������� �� ������� �����
    virtual ~Shape() {
        std::cout << "Shape destructor" << std::endl;
    }

    // ����������� ������� ��� ������ ���������� � ������
    virtual void printInfo() const {
        std::cout << "Shape color: ";
        switch (color) {
        case RED:
            std::cout << "RED";
            break;
        case GREEN:
            std::cout << "GREEN";
            break;
        case BLUE:
            std::cout << "BLUE";
            break;
        }
        std::cout << std::endl;
    }
    void WhereAmI() {
        std::cout << "Now I am in class Shape" << std::endl;
    }

    virtual void WhereAmIVirtual() {
        std::cout << "Now I am in class Shape (virtual)" << std::endl;
    }
};

// ����������� ����� Rect
class Rect : public Shape {
protected:
    // �������������� ������ ��� ��������������

public:
    // ����������� ������������ ������ Rect
    Rect(Color c) : Shape(c) {
        std::cout << "Rect constructor" << std::endl;
    }
    void WhereAmI() {
        std::cout << "Now I am in class Rect" << std::endl;
    }

    // ���������� ������������ ������ Rect
    ~Rect() override {
        std::cout << "Rect destructor" << std::endl;
    }

    // ��������������� ����������� ������� ��� ������ ���������� � ��������������
    void printInfo() const override {
        Shape::printInfo();  // ����� ������� �������� ������
        std::cout << "Type: Rectangle" << std::endl;
    }
    void WhereAmIVirtual() override {
        std::cout << "Now I am in class Circle (virtual)" << std::endl;
    }
};

// ����������� ����� Circle
class Circle : public Shape {
protected:
    // �������������� ������ ��� �����

public:
    // ����������� ������������ ������ Circle
    Circle(Color c) : Shape(c) {
        std::cout << "Circle constructor" << std::endl;
    }
    void WhereAmI() {
        std::cout << "Now I am in class Circle" << std::endl;
    }

    // ���������� ������������ ������ Circle
    ~Circle() override {
        std::cout << "Circle destructor" << std::endl;
    }

    // ��������������� ����������� ������� ��� ������ ���������� � �����
    void printInfo() const override {
        Shape::printInfo();  // ����� ������� �������� ������
        std::cout << "Type: Circle" << std::endl;
    }
    void WhereAmIVirtual() override {
        std::cout << "Now I am in class Circle (virtual)" << std::endl;
    }
};

