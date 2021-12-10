#include "Convertor.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
    try
    {
        if(argc != 2)
        {
            throw std::invalid_argument("Program must have 4 argumnet. First argument is program name, seconde is file path. \n Please rerun programm and give path to the file.");
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
    }
    
    Convertor convertor(argv[1]);


    return 0;
}