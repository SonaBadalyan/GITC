#pragma once
#include <string>

class MyUnderflowException
{
    public:
        MyUnderflowException(std::string message);
        void print() const;

    private:
        std::string message;
};