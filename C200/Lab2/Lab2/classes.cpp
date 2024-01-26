#include <iostream>
#include <string>

class MyString {
public:
    std::string str;
    MyString() : str("") {}
    // Конструктор класса MyString который принимает std::string в качестве параметра 
    // и инициализирует переменную - член str переданной строкой. Этот конструктор вызывается, 
    // когда объект типа MyString создается с параметром строки.
    MyString(const std::string& s) : str(s) {}
};

//Задание 3
// Перечисление для цветов
enum Color {
    RED,
    GREEN,
    BLUE
};

// Базовый класс Shape
class Shape {
protected:
    Color color;

public:
    // Конструктор базового класса с параметром-цветом
    Shape(Color c) : color(c) {
        std::cout << "Shape constructor" << std::endl;
    }

    // Виртуальный деструктор для правильного удаления объектов через указатель на базовый класс
    virtual ~Shape() {
        std::cout << "Shape destructor" << std::endl;
    }

    // Виртуальная функция для вывода информации о фигуре
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

// Производный класс Rect
class Rect : public Shape {
protected:
    // Дополнительные данные для прямоугольника

public:
    // Конструктор производного класса Rect
    Rect(Color c) : Shape(c) {
        std::cout << "Rect constructor" << std::endl;
    }
    void WhereAmI() {
        std::cout << "Now I am in class Rect" << std::endl;
    }

    // Деструктор производного класса Rect
    ~Rect() override {
        std::cout << "Rect destructor" << std::endl;
    }

    // Переопределение виртуальной функции для вывода информации о прямоугольнике
    void printInfo() const override {
        Shape::printInfo();  // Вызов функции базового класса
        std::cout << "Type: Rectangle" << std::endl;
    }
    void WhereAmIVirtual() override {
        std::cout << "Now I am in class Circle (virtual)" << std::endl;
    }
};

// Производный класс Circle
class Circle : public Shape {
protected:
    // Дополнительные данные для круга

public:
    // Конструктор производного класса Circle
    Circle(Color c) : Shape(c) {
        std::cout << "Circle constructor" << std::endl;
    }
    void WhereAmI() {
        std::cout << "Now I am in class Circle" << std::endl;
    }

    // Деструктор производного класса Circle
    ~Circle() override {
        std::cout << "Circle destructor" << std::endl;
    }

    // Переопределение виртуальной функции для вывода информации о круге
    void printInfo() const override {
        Shape::printInfo();  // Вызов функции базового класса
        std::cout << "Type: Circle" << std::endl;
    }
    void WhereAmIVirtual() override {
        std::cout << "Now I am in class Circle (virtual)" << std::endl;
    }
};

