#ifndef COLOR_H
#define COLOR_H

#include <iostream>

// ������������, �������������� ��������� �����
    enum Color { RED, GREEN, BLUE };
// ������� ��� �������������� ������������ Color � ������
    const char* colorToString(Color c);
// ������� ����� ��� �����
    class Shape {
        protected:
            Color color;
        public:
            // �����������, ��������������� ���� ������
            Shape(Color c);
            // ������ ��� ����� ������
            Color getColor() const;
            // ������������� �������
            void WhereAmI() const;
            // ����������� �������, ����������� �������������� ������ (����� ���� �������������� � ����������� �������)
            virtual void WhereAmIVirtual() const;
            // ����� ����������� �������, ��������� �� ����������� ������� ���������� ������ Inflate
            //virtual void Inflate(int factor) = 0;
            // ����������� ���������� ��� ����������� ����������� ������������ �������� ��� �������� �������� ����������� �������
            virtual ~Shape();
            // ����������� ������� ��� ������ ���������� � ������ (����� ���� �������������� � ����������� �������)
            virtual void printInfo() const;
    };
// ����� ��������������, ����������� �� �������� ������ Shape
    class Rect : public Shape {
        private:
            int width;
            int height;
            int x;
            int y;
        public:
            // ����������� �������������� � ���������� ����� �� ��������� RED
            Rect(Color c = RED);

            void WhereAmI() const;
            void WhereAmIVirtual() const override;

            void printInfo() const override;
            // ���������� ����� ����������� ������� Inflate ��� ��������������
            //void Inflate(int factor) override;

            int getWidth() const;
            int getHeight() const;
            int getX() const;
            int getY() const;

            // ���������� ��������������
            ~Rect();
    };
// ����� �����, ����������� �� �������� ������ Shape
    class Circle : public Shape {
        private:
            int m_centerX;
            int m_centerY;
            int m_radius;

        public: 
            // ����������� ����� � ���������� �����
          //  Circle(Color c);
            // ����������� ����� �� ���������
          //  Circle();
            // ����������� �����
            Circle(Color = RED, int centerX = 0, int centerY = 0, int radius = 0);

            // ����������� �����, ����������� ������������� � ��������������� ����
            Circle(const Rect& rect);

            void WhereAmI() const;

            void WhereAmIVirtual() const override;

            //void Inflate(int factor) override;

            void printInfo() const override;
            // ���������� �����
            ~Circle();
    };

#endif