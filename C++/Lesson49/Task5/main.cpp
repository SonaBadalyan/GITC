#include "MyOverflowException.hpp"
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
            throw MyOverflowException("Trying to assign a bigger value than can hold signed char.");
        }

        c = number;
    }
    catch(const MyOverflowException& e)
    {
        e.print();
    }
    
    return 0;
}
