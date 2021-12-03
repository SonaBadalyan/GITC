#ifndef MY_INVALID_ARGUMENT_EXCEPTION_HPP
#define MY_INVALID_ARGUMENT_EXCEPTION_HPP

#include <string>
#include <stdexcept>

template<typename T>
class InvalidArgumnetException : public std::invalid_argument
{
    public:

        InvalidArgumnetException(std::string message, T argument);
        const char* what() const noexcept;

    private:

        T argument;
        std::string message;
};

#endif // MY_INVALID_ARGUMENT_EXCEPTION_HPP