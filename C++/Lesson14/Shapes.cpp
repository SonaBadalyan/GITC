#include<iostream>
#include<string>

class Square
{
    public:
    double side;
    
    double get_area()
    {
        return side * side;
    }
    
    double get_perimeter()
    {
       return 4 * side;
    }
};

class Rectangle
{
    public:
    double length;
    double width;
    
    double get_area()
    {
        return length * width;
    }
    
    double get_perimeter()
    {
        return 2 * ( length + width );
    }
};

class Circle
{
    public:
    double radius;
    
    double get_area()
    {
        return  3.14 * radius * radius;
    }
    
    double get_diameter()
    {
        return 2 * radius;
    }
};


int main()
{
    Square square;
    square.side = 3.6;
    
    std::cout << "The square area is equal to " << square.get_area() <<std::endl;
    std::cout << "The square perimeter is equal to " << square.get_perimeter() <<std::endl;
    
    Rectangle rectangle;
    rectangle.length = 2.5;
    rectangle.width = 4.8;
    
    std::cout << "The rectangle area is equal to " << rectangle.get_area() <<std::endl;
    std::cout << "The rectangle perimeter is equal to " << rectangle.get_perimeter() <<std::endl;
    
    Circle circle;
    circle.radius = 5.6;
    
    std::cout << "The circle area is equal to " << circle.get_area() <<std::endl;
    std::cout << "The circle diameter is equal to " << circle.get_diameter() <<std::endl;
    
    return 0;
}