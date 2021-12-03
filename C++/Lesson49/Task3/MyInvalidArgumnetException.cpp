#include <iostream>
#include "MyInvalidArgumnetException.hpp"

template<typename T>
MyInvalidArgumnetException<T>::MyInvalidArgumnetException(std::string message, T argument)
{
    this->message = message;
    this->argument = argument;
}

template<typename T>
void MyInvalidArgumnetException<T>::print() const
{
    std::cout << this->message << std::endl;
    std::cout << "Argument: " << argument << std::endl;
    std::cout << std::endl;
}

template class MyInvalidArgumnetException<double>; // Explicit template instantiation