#include <iostream>

// Перечисление для цветов
enum Color { RED, GREEN, BLUE };

// Базовый класс Shape
class Shape {
    protected:
        Color color;  // Цвет фигуры

    public:
        Shape(Color c) : color(c) {}
        // Конструктор базового класса с параметром-цветом

        Color getColor() const {
            return color;
        }
        //Shape(Color c) : color(c) {
        //    std::cout << "Constructing Shape with color" << std::endl;
        //}
        // Виртуальная функция для вывода информации о фигуре
        virtual void printInfo() const {
            std::cout << "Shape of color: " << color << std::endl;
        }
        void WhereAmI() const {
            std::cout << "Now I am in class Shape" << std::endl;
        }
        virtual void WhereAmIVirtual() const {
            std::cout << "Now I am in class Shape (virtual)" << std::endl;
        }
        // Виртуальный деструктор
        virtual ~Shape() {
            std::cout << "Now I am in Shape's destructor!" << std::endl;
        }
        virtual void Inflate(int factor) = 0;
};

// Производный класс Rect
class Rect : public Shape {
    public:
        Rect(Color c = RED) : Shape(c) {}
        //// Конструктор производного класса с параметром-цветом
        //Rect(Color c) : Shape(c) {
        //    std::cout << "Constructing Rect" << std::endl;
        //}
        // Переопределение виртуальной функции базового класса
        void printInfo() const override {
            std::cout << "Rectangle of color: " << color << std::endl;
        }
        // Деструктор производного класса
        ~Rect() {
            std::cout << "Destructing Rect" << std::endl;
        }
        void WhereAmI() const {
            std::cout << "Now I am in class Rect" << std::endl;
        }
        void WhereAmIVirtual() const override {
            std::cout << "Now I am in class Rect (virtual)" << std::endl;
        }
        void Inflate(int factor) override {
            std::cout << "Rect is inflating by a factor of " << factor << std::endl;
        }
};

// Производный класс Circle
class Circle : public Shape {
    public:
        Circle() : Shape(RED) {}
        Circle(const Rect& rect) : Shape(rect.getColor()) {}

        //// Конструктор производного класса с параметром-цветом
        //Circle(Color c) : Shape(c) {
        //    std::cout << "Constructing Circle" << std::endl;
        //}
        // Переопределение виртуальной функции базового класса
        void printInfo() const override {
            std::cout << "Circle of color: " << color << std::endl;
        }
        // Деструктор производного класса
        ~Circle() {
            std::cout << "Destructing Circle" << std::endl;
        }
        void WhereAmI() const {
            std::cout << "Now I am in class Circle" << std::endl;
        }
        void WhereAmIVirtual() const override {
            std::cout << "Now I am in class Circle (virtual)" << std::endl;
        }
        void Inflate(int factor) override {
            std::cout << "Circle is inflating by a factor of " << factor << std::endl;
        }
};
