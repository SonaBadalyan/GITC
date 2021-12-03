#include <iostream>

double area(double length, double width)
{
    return length * width;
}

double area(double side)
{
    return side * side;
}

double area(double radius, bool)
{
    return 3.14 * radius * radius;
}

double area(bool, double side1, double side2)
{
    return (side1 * side2) / 2;
}

double area(double height, bool, double base)
{
    return (height * base) / 2;
}

int main()
{
    std::cout << "The rectangle area is equla to " << area(4.6, 5.0) << std::endl;
    std::cout << "The square area is equla to " << area(7.9) << std::endl;
    std::cout << "The circle area is equla to " << area(5.6, true) << std::endl;
    std::cout << "The right triangle area is equla to " << area(true, 3.0, 6.9) << std::endl;
    std::cout << "The triangle area is equla to " << area(1.3, true, 4.5) << std::endl;

    return 0;
}