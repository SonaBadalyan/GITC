#include <iostream>

double rectangle_area(double length, double width)
{
    return length * width;
}

double square_area(double side)
{
    return side * side;
}

double circle_area(double radius)
{
    return 3.14 * radius * radius;
}

double right_triangle_area(double side1, double side2)
{
    return (side1 * side2) / 2;
}

double triangle_area(double height, double base)
{
    return (height * base) / 2;
}

int main()
{
    std::cout << "The rectangle area is equla to " << rectangle_area(4.6, 5.0) << std::endl;
    std::cout << "The square area is equla to " << square_area(7.9) << std::endl;
    std::cout << "The circle area is equla to " << circle_area(5.6) << std::endl;
    std::cout << "The right triangle area is equla to " << right_triangle_area(3.0, 6.9) << std::endl;
    std::cout << "The triangle area is equla to " << triangle_area(1.3, 4.5) << std::endl;

    return 0;
}