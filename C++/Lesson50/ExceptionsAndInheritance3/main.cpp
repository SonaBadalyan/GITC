#include <iostream>
#include "InvalidArgumnetException.hpp"

double rectangleArea(double length, double width)
{
    if (length < 0)
    {
        throw InvalidArgumnetException<double>("Invalid argument, length: ", length);
    }

    if (width < 0)
    {
        throw std::invalid_argument("Invalid argument, width: ");
    }

    return length * width;
}

int main()
{
    try
    {
        std::cout << rectangleArea(2, -45);
    }
    catch(const InvalidArgumnetException<double>& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(const std::invalid_argument& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}