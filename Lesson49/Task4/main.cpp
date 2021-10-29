#include "MyNullPointerException.hpp"
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
            throw MyNullPointerException("mlass object`s pointer is null pointer!");
        }
    }
    catch(const MyNullPointerException& e)
    {
        e.print();
    }
    
    return 0;
}