#include <iostream>
#include <stdexcept>

unsigned int toLargerBaytes(unsigned int simbol, unsigned short bayteCount)
{
    if (bayteCount > 4)
    {
        throw std::invalid_argument("Invalid argument: passed byte count is greater than it possible.");
    }

    unsigned int simbolCopy = simbol;
    int bitsCount = 0;

    while (0 != simbolCopy)
    {
        simbolCopy >> 1;
        ++bitsCount;
    }

    unsigned int resultedSimbol = 0;
    unsigned int temp = 0;

    if (1 == bayteCount)
    {
        if (bitsCount > 7)
        {
            throw std::invalid_argument("Invalid argument, 1 byte.");
        }

        resultedSimbol = simbol;

    }
    else if (2 == bayteCount)
    {
        if (bitsCount > 11)
        {
            throw std::invalid_argument("Invalid argument, 2 byte.");
        }

        resultedSimbol |= 0b1100000010000000;

        temp = 0b0000000000111111;

        resultedSimbol |= (temp & simbol);

        temp = 0b0000011111000000;
        temp &= simbol;
        temp << 2;

        resultedSimbol |= temp;
    }
    else if (3 == bayteCount)
    {
        if (bitsCount > 16)
        {
            throw std::invalid_argument("Invalid argument, 3 byte.");
        }
        
        resultedSimbol |= 0b111000001000000010000000;

        temp = 0b000000000000000000111111;

        resultedSimbol |= (temp & simbol);

        temp = 0b000000000000111111000000;
        temp &= simbol;
        temp << 2;

        resultedSimbol |= temp;

        temp = 0b000000001111000000000000;
        temp &= simbol;
        temp << 2;

        resultedSimbol |= temp;
    }
    else if (4 == bayteCount)
    {
        if (bitsCount > 21)
        {
            throw std::invalid_argument("Invalid argument, 4 byte.");
        }

        resultedSimbol |= 0b11110000100000001000000010000000;

        temp = 0b00000000000000000000000000111111;

        resultedSimbol |= (temp & simbol);

        temp = 0b00000000000000000000111111000000;
        temp &= simbol;
        temp << 2;

        resultedSimbol |= temp;

        temp = 0b00000000000000111111000000000000;
        temp &= simbol;
        temp << 2;

        resultedSimbol |= temp;

        temp = 0b00000000000111000000000000000000;
        temp &= simbol;
        temp << 2;

        resultedSimbol |= temp;
    }
    
    return resultedSimbol;
}

int main()
{
    try
    {
        std::cout << toLargerBaytes(120, 3) << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}