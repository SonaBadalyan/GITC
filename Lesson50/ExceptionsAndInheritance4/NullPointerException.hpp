#pragma once
#include <string>
#include <stdexcept>

class NullPointerException : public std::invalid_argument
{
    public:
        NullPointerException(std::string message);
        const char* what() const noexcept;

    private:
        std::string message;
};