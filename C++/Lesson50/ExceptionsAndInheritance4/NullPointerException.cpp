#include "NullPointerException.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>

NullPointerException::NullPointerException(std::string message) : std::invalid_argument(message)
{
    this->message = message;
}

const char* NullPointerException::what() const noexcept
{
    return message.c_str();
}