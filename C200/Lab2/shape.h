#ifndef COLOR_H
#define COLOR_H

#include <iostream>

// Перечисление, представляющее различные цвета
    enum Color { RED, GREEN, BLUE };
// Функция для преобразования перечисления Color в строку
    const char* colorToString(Color c);
// Базовый класс для фигур
    class Shape {
        protected:
            Color color;
        public:
            // Конструктор, устанавливающий цвет фигуры
            Shape(Color c);
            // Геттер для цвета фигуры
            Color getColor() const;
            // Невиртуальная функция
            void WhereAmI() const;
            // Виртуальная функция, указывающая местоположение фигуры (может быть переопределена в производных классах)
            virtual void WhereAmIVirtual() const;
            // Чисто виртуальная функция, требующая от производных классов реализации метода Inflate
            //virtual void Inflate(int factor) = 0;
            // Виртуальный деструктор для обеспечения правильного освобождения ресурсов при удалении объектов производных классов
            virtual ~Shape();
            // Виртуальная функция для вывода информации о фигуре (может быть переопределена в производных классах)
            virtual void printInfo() const;
    };
// Класс прямоугольника, наследующий от базового класса Shape
    class Rect : public Shape {
        private:
            int width;
            int height;
            int x;
            int y;
        public:
            // Конструктор прямоугольника с установкой цвета по умолчанию RED
            Rect(Color c = RED);

            void WhereAmI() const;
            void WhereAmIVirtual() const override;

            void printInfo() const override;
            // Реализация чисто виртуальной функции Inflate для прямоугольника
            //void Inflate(int factor) override;

            int getWidth() const;
            int getHeight() const;
            int getX() const;
            int getY() const;

            // Деструктор прямоугольника
            ~Rect();
    };
// Класс круга, наследующий от базового класса Shape
    class Circle : public Shape {
        private:
            int m_centerX;
            int m_centerY;
            int m_radius;

        public: 
            // Конструктор круга с установкой цвета
          //  Circle(Color c);
            // Конструктор круга по умолчанию
          //  Circle();
            // Конструктор круга
            Circle(Color = RED, int centerX = 0, int centerY = 0, int radius = 0);

            // Конструктор круга, принимающий прямоугольник и устанавливающий цвет
            Circle(const Rect& rect);

            void WhereAmI() const;

            void WhereAmIVirtual() const override;

            //void Inflate(int factor) override;

            void printInfo() const override;
            // Деструктор круга
            ~Circle();
    };

#endif