#ifndef MY_INVALID_ARGUMENT_EXCEPTION_HPP
#define MY_INVALID_ARGUMENT_EXCEPTION_HPP

#include <string>

template<typename T>
class MyInvalidArgumnetException
{
    public:

        MyInvalidArgumnetException(std::string message, T argument);
        void print() const;

    private:

        T argument;
        std::string message;
};

#endif // MY_INVALID_ARGUMENT_EXCEPTION_HPP