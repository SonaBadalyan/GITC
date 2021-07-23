#include <iostream>
#include <cmath>

double perimeter(double length, double width)
{
    return 2 * ( length + width );
}

double perimeter(double side)
{
    return 4 * side;
}

double perimeter(double radius, bool)
{
    return 2 * 3.14 * radius;
}

double perimeter(double side1, double side2, bool)
{
    return side1 + side2  + sqrt( pow( side1, 2 ) + pow( side2, 2 ) );
}

double perimeter(double side1, double base, double side2)
{
    return side1 + base + side2;
}

int main()
{
    std::cout << "The rectangle perimeter is equla to " << perimeter(4.6, 5.0) << std::endl;
    std::cout << "The square perimeter is equla to " << perimeter(7.9) << std::endl;
    std::cout << "The circle perimeter is equla to " << perimeter(5.6, true) << std::endl;
    std::cout << "The right triangle perimeter is equla to " << perimeter(3.0, 6.9, true) << std::endl;
    std::cout << "The triangle perimeter is equla to " << perimeter(1.3, 4.5, 3.5) << std::endl;

    return 0;
}