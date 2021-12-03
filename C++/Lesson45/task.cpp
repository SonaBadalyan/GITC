#include <iostream>
#include <stdio.h>


int main()
{
    FILE* fp = fopen("source.txt", "r");
    fseek(fp, 0, SEEK_END);

    long int SIZE = ftell(fp);

    fseek(fp, 0, SEEK_SET);

    char buff[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        buff[i] = 0;
    } 

    fread(buff, 1, SIZE, fp);

    FILE* wpf = fopen("destination.txt", "w");
    unsigned short simbol = 0;

    for (int i = 0; i < SIZE; )
    {
        if (buff[i] & 0b10000000) // First bit is not 0, it means that it is a 2, 3, or 4 byte version of utf8
        {     
            simbol = buff[i + 1] & 0b00111111;

            unsigned char firstByte = buff[i] & 0b00011111;
            
            unsigned char lastTwo = firstByte & 0b00000011;
            lastTwo << 6;
            simbol |= lastTwo;

            unsigned short lastThree = firstByte >> 2;
            lastThree << 8;
            simbol |= lastThree;

            i += 2;
        }
        else // First bit is 0, it means that it is a 1 byte version of utf8
        {
            simbol = buff[i];
            ++i;
        }

        fwrite(&simbol, 1, sizeof(unsigned short), wpf);
    }

    fclose(fp);
    fclose(wpf);
    
    return 0;
}