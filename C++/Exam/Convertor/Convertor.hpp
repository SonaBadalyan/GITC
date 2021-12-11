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
        std::string rawFileName;

    public:

        Convertor(std::string path);
        void convert();
        long int getSize() const;
        std::string getFileName() const;
};

#endif // CONVERTOR_HPP