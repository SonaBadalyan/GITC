#pragma once
#include <string>

class MyOverflowException
{
    public:
        MyOverflowException(std::string message);
        void print() const;

    private:
        std::string message;
};