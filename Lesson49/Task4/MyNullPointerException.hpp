#pragma once
#include <string>

class MyNullPointerException
{
    public:
        MyNullPointerException(std::string message);
        void print() const;

    private:

        std::string message;

};