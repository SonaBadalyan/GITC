#include "MyNullPointerException.hpp"
#include <string>
#include <iostream>

MyNullPointerException::MyNullPointerException(std::string message)
{
    this->message = message;
}

void MyNullPointerException::print() const
{
    std::cout << message << std::endl;
}