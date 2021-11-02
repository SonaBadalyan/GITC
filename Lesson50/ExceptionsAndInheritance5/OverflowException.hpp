#pragma once
#include <string>
#include <stdexcept>

class OverflowException : public std::overflow_error
{
    public:
        OverflowException(std::string message);
        const char* what() const noexcept;

    private:
        std::string message;
};