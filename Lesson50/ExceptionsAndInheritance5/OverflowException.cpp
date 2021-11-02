#include "OverflowException.hpp"
#include <iostream>
#include <string>
#include <cstring>

OverflowException::OverflowException(std::string message) : std::overflow_error(message)
{
    this->message = message;
}

const char* OverflowException::what() const noexcept
{
    return message.c_str();
}