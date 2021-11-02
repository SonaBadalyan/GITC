#include "OverflowException.hpp"
#include <iostream>
#include <string>

int main()
{
    char c;

    std::cout << "Please enter number and program will assign it to the char." << std::endl;
    int number = 0;
    std::cin >> number;

    try
    {
        if (number > 127)
        {
            throw OverflowException("Can`t assign a bigger value than can hold signed char.");
        }

        c = number;
    }
    catch(const OverflowException& e)
    {
        std::cout << e.what() <<std::endl;
    }
    
    return 0;
}
