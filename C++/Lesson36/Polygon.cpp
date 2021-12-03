#include<iostream>
#include <cmath>

class Polygon
{
    public:

        virtual double area() = 0;
        virtual double perimeter() = 0;

    private:

        int vertexCount;

};

class Square : public Polygon
{
    public:

        Square(double side)
        {
            this->side = side;
        }
    
        virtual double area()
        {
            return side * side;
        }

        virtual double perimeter()
        {
            return 4 * side;
        }

    private:
        double side;
        int vertexCount = 4;
};

class Rectangle : public Polygon
{
    public:
        Rectangle(double length, double width)
        {
            this->length = length;
            this->width = width;
        }
    
        virtual double area()
        {
            return length * width;
        }

        virtual double perimeter()
        {
            return 2* (length + width);
        }

    private:
        double length;
        double width;
        int vertexCount = 4;

};

class RightTriangle : public Polygon
{
    public:

        RightTriangle(double leg1, double leg2)
        {
            this->leg1 = leg1;
            this->leg2 = leg2;
        }
    
        virtual double area()
        {
            return (leg1 * leg2) / 2;
        }

        virtual double perimeter()
        {
            return leg1 + leg2 + sqrt( pow( leg1, 2 ) + pow( leg2, 2 ) );
        }

    private:
        double leg1;
        double leg2;
        int vertexCount = 3;
};

int main()
{
    Polygon* p;

    Square s(5.6);
    p = &s;
    std::cout << "Square area " << p->area() << std::endl;
    std::cout << "Square peremeter " << p->perimeter() << std::endl;

    Rectangle r(1.3, 4.5);
    p = &r;
    std::cout << "Rectangle area " << p->area() << std::endl;
    std::cout << "Rectangle peremeter " << p->perimeter() << std::endl;

    RightTriangle rt(2.5, 6.8);
    p = &rt;
    std::cout << "RightTriangle area " << p->area() << std::endl;
    std::cout << "RightTriangle peremeter " << p->perimeter() << std::endl;

    return 0;
}