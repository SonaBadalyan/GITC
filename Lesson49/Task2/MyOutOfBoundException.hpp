#pragma once
#include <string>

class MyOutOfBoundException
{
    public:

        MyOutOfBoundException(std::string message, int index, int start, int end);
        void print() const;

    private:

        std::string message;
        int index;
        int start;
        int end;
};