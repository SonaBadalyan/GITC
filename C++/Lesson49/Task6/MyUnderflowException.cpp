#include "MyUnderflowException.hpp"
#include <iostream>
#include <string>

MyUnderflowException::MyUnderflowException(std::string message)
{
    this->message = message;
}

void MyUnderflowException::print() const
{
    std::cout << this->message <<std::endl;
}