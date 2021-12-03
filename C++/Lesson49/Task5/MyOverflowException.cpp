#include "MyOverflowException.hpp"
#include <iostream>
#include <string>

MyOverflowException::MyOverflowException(std::string message)
{
    this->message = message;
}

void MyOverflowException::print() const
{
    std::cout << this->message <<std::endl;
}