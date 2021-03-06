#include <iostream>
#include <fstream>
#include <stdio.h>


int main()
{
    FILE* fp = fopen("source.txt", "r");
    fseek(fp, 0, SEEK_END);

    long int SIZE = ftell(fp);

    fseek(fp, 0, SEEK_SET);

    unsigned char buff[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        buff[i] = 0;
    } 

    fread(buff, 1, SIZE, fp);

    FILE* wpf = fopen("destination.txt", "w");
    unsigned int simbol = 0;

    std::fstream numDestination;

    numDestination.open("output.txt", std::ios::out);

    for (int i = 0; i < SIZE; )
    {
        if ((buff[i] & 0b11110000) == 0b11110000) // 4 byte version
        { 
            simbol = buff[i + 3] & 0b00111111;

            unsigned int byte = buff[i + 2] & 0b00111111;
            
            unsigned int lastTwo = byte & 0b00000011;
            lastTwo = (lastTwo << 6);
            simbol |= lastTwo;

            byte = (byte >> 2);
            byte = (byte << 8);

            simbol |= byte;

            byte = buff[i + 1] & 0b00111111;
            
            lastTwo = byte & 0b00000011;
            lastTwo = (lastTwo << 12);
            simbol |= lastTwo;

            byte = (byte >> 2);
            byte = (byte << 14);

            simbol |= byte;

            unsigned int lastFive = buff[i] & 0b00000111;
            lastFive = (lastFive << 18);
            simbol |= lastFive;

            i += 4;
        }
        else if ((buff[i] & 0b11100000) == 0b11100000) // 3 byte version
        {    
            simbol = buff[i + 2] & 0b00111111;

            unsigned int midByte = buff[i + 1] & 0b00111111;
            
            unsigned int lastTwo = midByte & 0b00000011;
            lastTwo = (lastTwo << 6);
            simbol |= lastTwo;

            midByte = (midByte >> 2);
            midByte = (midByte << 8);

            simbol |= midByte;

            unsigned int lastFour = buff[i] & 0b00001111;
            lastFour = (lastFour << 12);
            simbol |= lastFour;

            i += 3;
        }
        else if ((buff[i] & 0b11000000) == 0b11000000) // 2 byte version
        {  
            simbol = buff[i + 1] & 0b00111111;

            unsigned char firstByte = buff[i] & 0b00011111;
            
            unsigned char lastTwo = firstByte & 0b00000011;
            lastTwo = (lastTwo << 6);
            simbol |= lastTwo;

            unsigned short lastThree = firstByte >> 2;
            lastThree = (lastThree << 8);
            simbol |= lastThree;

            i += 2;
        }
        else if((buff[i] & 0b10000000) == 0b00000000) // First bit is 0, it means that it is a 1 byte version of utf8
        {
            simbol = buff[i];
            ++i;
        }

        fwrite(&simbol, 1, sizeof(unsigned int), wpf);
        numDestination << simbol << std::endl;
    }

    numDestination.close();

    fclose(fp);
    fclose(wpf);
    
    return 0;
}