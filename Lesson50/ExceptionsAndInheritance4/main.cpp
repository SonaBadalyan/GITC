#include "NullPointerException.hpp"
#include <iostream>
#include <string>

class Mlass
{
    void foo()
    {
        std::cout << "Mlass::foo" << std::endl;
    }
};

int main()
{
    Mlass* mlass = nullptr;

    try
    {
        if(!mlass)
        {
            throw NullPointerException("mlass object`s pointer is null pointer!");
        }
    }
    catch(const NullPointerException& e)
    {
        std::cout << e.what() <<std::endl;
    }
    
    return 0;
}