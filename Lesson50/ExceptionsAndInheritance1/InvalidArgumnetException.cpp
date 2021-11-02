#include <iostream>
#include <stdexcept>
#include <cstring>
#include "InvalidArgumnetException.hpp"

template<typename T>
InvalidArgumnetException<T>::InvalidArgumnetException(std::string message, T argument) : std::invalid_argument(message)
{
    this->message = message;
    this->argument = argument;
}

template<typename T>
const char* InvalidArgumnetException<T>::what() const noexcept
{
    std::string result =  this->message + "Argument: " + std::to_string(argument) + "\n";
    return result.c_str();
}

template class InvalidArgumnetException<double>; // Explicit template instantiation