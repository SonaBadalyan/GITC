#include "Convertor.hpp"
#include <stdio.h>
#include <stdexcept>
#include <regex>

Convertor::Convertor(std::string path)
{
    std::regex reg("*.txt|*.doc|*.docx"); // or any other text file
    std::smatch match;

    std::string fileName = path.substr(path.find_last_of("/\\") + 1);

    if (std::regex_search(fileName, match, reg))
    {
        m_path = path;
    }
    else
    {
        throw std::invalid_argument(fileName + " Wrong format!");
    }
    
    rfp = fopen(m_path.c_str(), "r");

    if ( NULL == rfp)
    {
        throw std::invalid_argument(m_path + " File not found!");
    }

    fseek(rfp, 0, SEEK_END);

    size = ftell(rfp);

    fseek(rfp, 0, SEEK_SET);
}

void Convertor::convert()
{
    unsigned char buff[size];
    fread(buff, 1, size, rfp);

    const char* path = std::string(m_path + ".pdf").c_str();
    wfp = fopen(path, "w");

    for (int i = 0; i < size; ++i)
    {
        if (int (buff[i]) != 32)
        {
            ++count;
            fwrite(&buff[i], 1, sizeof(buff[i]), wfp);
        }
    }
}

long int Convertor::getSize() const
{
    return count;
}

Convertor::~Convertor()
{
    if (wfp)
    {
        fclose(wfp);
    }

    fclose(rfp);
}