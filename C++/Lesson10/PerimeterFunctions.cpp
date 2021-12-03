#include <iostream>
#include <cmath>

double rectangle_perimeter(double length, double width)
{
    return 2 * ( length + width );
}

double square_perimeter(double side)
{
    return 4 * side;
}

double circle_perimeter(double radius)
{
    return 2 * 3.14 * radius;
}

double right_triangle_perimeter(double side1, double side2)
{
    return side1 + side2  + sqrt( pow( side1, 2 ) + pow( side2, 2 ) );
}

double triangle_perimeter(double side1, double side2, double base)
{
    return side1 + base + side2;
}

int main()
{
    std::cout << "The rectangle perimeter is equla to " << rectangle_perimeter(4.6, 5.0) << std::endl;
    std::cout << "The square perimeter is equla to " << square_perimeter(7.9) << std::endl;
    std::cout << "The circle perimeter is equla to " << circle_perimeter(5.6) << std::endl;
    std::cout << "The right triangle perimeter is equla to " << right_triangle_perimeter(3.0, 6.9) << std::endl;
    std::cout << "The triangle perimeter is equla to " << triangle_perimeter(1.3, 4.5, 3.5) << std::endl;

    return 0;
}