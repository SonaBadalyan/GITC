#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

#include <string>
#include <stdio.h>
#include <stdexcept>

class Convertor
{
    private:

        FILE* rfp;
        FILE* wfp;
        int count = 0;
        long int size = 0;
        std::string m_path;

    public:

        Convertor(std::string path);
        void convert();
        long int getSize() const;
        ~Convertor();
};

#endif // CONVERTOR_HPP