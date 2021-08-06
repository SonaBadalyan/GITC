#include<iostream>
#include<string>
#include<cmath>

class Square
{
    private:
        double m_side;
    
    public:
        
        Square()
        {
            std::cout<<"Default constructor for Square."<< std::endl;
        }

        Square(double side)
        {
            std::cout << "Square(side)" << std::endl;

            m_side = side;
        }

        void set_side(double side)
        {
            m_side = side;
        }

        double get_side()
        {
            return m_side;
        }

        double get_area()
        {
            return m_side * m_side;
        }
        
        double get_perimeter()
        {
            return 4 * m_side;
        }

        void print()
        {
            std::cout << "________________Print square______________________" << std::endl;
            std::cout << "Side = " << m_side << std::endl;
            std::cout << "__________________________________________________" << std::endl;
            std::cout << std::endl;
        }
};

class Rectangle
{
    private:

        double m_length;
        double m_width;
    
    public:

        Rectangle ()
        {
            std::cout << "Default constructor for Rectangle." << std::endl;
        }

        Rectangle (double length)
        {
            std::cout << "Rectagle(length)" <<std::endl;
            m_length = length;
        }

        Rectangle (double width, bool)
        {
            std::cout << "Rectagle(width, bool)" <<std::endl;
            m_width = width;
        }

        Rectangle (double length, double width)
        {
            std::cout << "Rectagle(length, width)" <<std::endl;
            m_length = length;
            m_width = width;
        }

        void set_length(double length)
        {
            m_length = length;
        }

        void set_width(double width)
        {
            m_width = width;
        }

        double get_length()
        {
            return m_length;
        }

        double get_width()
        {
            return m_width;
        }

        double get_area()
        {
            return m_length * m_width;
        }
        
        double get_perimeter()
        {
            return 2 * ( m_length + m_width );
        }

        void print()
        {
            std::cout << "________________Print rectangle___________________" << std::endl;
            std::cout << "Length = " << m_length << std::endl;
            std::cout << "Width = " << m_width << std::endl;
            std::cout << "__________________________________________________" << std::endl;
            std::cout << std::endl;
        }
};

class Circle
{
    private:

        double m_radius;
    
    public: 

        Circle()
        {
            std::cout << "Default constructor for Circle." << std::endl;
        }

        Circle(double radius)
        {
            std::cout << "Circle(radius)" << std::endl;
            m_radius = radius;
        }

        void set_radius(double radius)
        {
            m_radius = radius;
        }

        double get_radius()
        {
            return m_radius;
        }

        double get_area()
        {
            return  3.14 * m_radius * m_radius;
        }
        
        double get_diameter()
        {
            return 2 * m_radius;
        }

        void print()
        {
            std::cout << "________________Print circle______________________" << std::endl;
            std::cout << "Radius = " << m_radius << std::endl;
            std::cout << "__________________________________________________" << std::endl;
            std::cout << std::endl;
        }
};

class Triangle
{
    private:
        double m_base;
        double m_height;
        double m_side1;
        double m_side2;

    public:
    
        Triangle()
        {
            std::cout << "Default constructor for Triangle." << std::endl;
        }

        Triangle(double base)
        {
            std::cout << "Triangle(base)" << std::endl;
            m_base = base;
        }

        Triangle(double height, bool)
        {
            std::cout << "Triangle(height, bool)" << std::endl;
            m_height = height;
        }

        Triangle(double side1, bool, bool)
        {
            std::cout << "Triangle(side1, bool, bool)" << std::endl;
            m_side1 = side1;
        }

        Triangle(double side2, bool, bool, bool)
        {
            std::cout << "Triangle(side2, bool, bool, bool)" << std::endl;
            m_side2 = side2;
        }

        Triangle(double base, double height)
        {
            std::cout << "Triangle(base, height)" << std::endl;
            m_base = base;
            m_height = height;
        }

        Triangle(double base, double side1, bool)
        {
            std::cout << "Triangle(base, side1, bool)" << std::endl;
            m_base = base;
            m_side1 = side1;
        }

        Triangle(double base, double side2, bool, bool)
        {
            std::cout << "Triangle(base, side2, bool, bool)" << std::endl;
            m_base = base;
            m_side2 = side2;
        }

        Triangle(double height, double side1, bool, bool, bool)
        {
            std::cout << "Triangle(height, side1, bool, bool, bool)" << std::endl;
            m_height = height;
            m_side1 = side1;
        }

        Triangle(double height, double side2, bool, bool, bool, bool)
        {
            std::cout << "Triangle(height, side2, bool, bool, bool)" << std::endl;
            m_height = height;
            m_side2 = side2;
        }

        Triangle(double side1, double side2, bool, bool, bool, bool, bool)
        {
            std::cout << "Triangle(side1, side2, bool, bool, bool, bool, bool)" << std::endl;
            m_side1 = side1;
            m_side2 = side2;
        }
        
        Triangle(double base, double height, double side1)
        {
            std::cout << "Triangle(base, height, side1)" << std::endl;
            m_base = base;
            m_height = height;
            m_side1 = side1;
        }

        Triangle(double base, double height, double side2, bool)
        {
            std::cout << "Triangle(base, height, side2, bool)" << std::endl;
            m_base = base;
            m_height = height;
            m_side2 = side2;
        }

        Triangle(double base, double height, double side1, double side2)
        {
            std::cout << "Triangle(base, height, side2, side2)" << std::endl;
            m_base = base;
            m_height = height;
            m_side1 = side1;
            m_side2 = side2;
        }

        void set_base(double base)
        {
            m_base = base;
        }

        void set_height(double height)
        {
            m_height = height;
        }

        void set_side1(double side1)
        {
            m_side1 = side1;
        }

        void set_side2(double side2)
        {
            m_side2 = side2;
        }

        double get_base()
        {
            return m_base;
        }

        double get_height()
        {
            return m_height;
        }

        double get_side1()
        {
            return m_side1;
        }

        double get_side2()
        {
            return m_side2;
        }

        double get_area()
        {
            return (m_height * m_base) / 2;
        }

        double get_perimeter()
        {
            return m_side1 + m_base + m_side2;
        }

        void print()
        {
            std::cout << "________________Print triangle____________________" << std::endl;
            std::cout << "Base = " << m_base << std::endl;
            std::cout << "Height = " << m_height << std::endl;
            std::cout << "Side1 = " << m_side1 << std::endl;
            std::cout << "Side2 = " << m_side2 << std::endl;
            std::cout << "__________________________________________________" << std::endl;
            std::cout << std::endl;
        }
};

class RightTriangle
{
    private:
        double m_side1;
        double m_side2;

    public:

        RightTriangle()
        {
            std::cout << "Default constructor for RightTriangle." << std::endl;
        }

        RightTriangle(double side1)
        {
            std::cout << "RightTriangle(side1)" << std::endl;
            m_side1 = side1;
        }

        RightTriangle(double side2, bool)
        {
            std::cout << "RightTriangle(side2, bool)" << std::endl;
            m_side2 = side2;
        }

        RightTriangle(double side1, double side2)
        {
            std::cout << "RightTriangle(side1, side2)" << std::endl;
            m_side1 = side1;
            m_side2 = side2;
        }

        void set_side1(double side1)
        {
            m_side1 = side1;
        }

        void set_side2(double side2)
        {
            m_side2 = side2;
        }

        double get_side1()
        {
            return m_side1;
        }

        double get_side2()
        {
            return m_side2;
        }

        double get_area()
        {
            return (m_side1 * m_side2) / 2;
        }

        double get_perimeter()
        {
            return m_side1 + m_side2  + sqrt( pow( m_side1, 2 ) + pow( m_side2, 2) );
        }

        void print()
        {
            std::cout << "________________Print right triangle______________" << std::endl;
            std::cout << "Side1 = " << m_side1 << std::endl;
            std::cout << "Side2 = " << m_side2 << std::endl;
            std::cout << "__________________________________________________" << std::endl;
            std::cout << std::endl;
        }
};


int main()
{
    // Square square;
    // square.print();

    // Rectangle rectangle;
    // rectangle.print();

    // Circle circle;
    // circle.print();

    // Triangle triangle;
    // triangle.print();

    // RightTriangle rightTriangle;
    // rightTriangle.print();

    Square square(2.4);
    square.print();

    // Rectangle rectangle(4.6);
    // rectangle.print();

    Rectangle rectangle(4.6, 6.7);
    rectangle.print();

    Circle circle(4.9);
    circle.print();

    Triangle triangle(2.5, 4.6, 6.7, 2.5);
    triangle.print();

    RightTriangle rightTriangle(5.8, 3.4);
    rightTriangle.print();
    
    return 0;
}