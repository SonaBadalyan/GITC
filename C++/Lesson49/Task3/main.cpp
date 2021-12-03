#include <iostream>
#include "MyInvalidArgumnetException.hpp"

double rectangleArea(double length, double width)
{
    if (length < 0)
    {
        throw MyInvalidArgumnetException<double>("Invalid argument, length: ", length);
    }

    if (width < 0)
    {
        throw MyInvalidArgumnetException<double>("Invalid argument, width: ", width);
    }

    return length * width;
}

int main()
{
    try
    {
        std::cout << rectangleArea(-2, -45);
    }
    catch(const MyInvalidArgumnetException<double>& ex)
    {
        ex.print();
    }

    return 0;
}