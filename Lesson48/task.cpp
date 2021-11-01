#include <stdio.h>
#include <stdexcept>

unsigned short UTF8ToUTF16BE(unsigned char byte1, unsigned char byte2)
{
    unsigned short resultedSimbol = 0;
    resultedSimbol = byte2 & 0b00111111;

    unsigned char firstByte = byte1 & 0b00011111;
    
    unsigned char lastTwo = firstByte & 0b00000011;
    lastTwo = (lastTwo << 6);
    resultedSimbol |= lastTwo;

    unsigned short lastThree = firstByte >> 2;
    lastThree = (lastThree << 8);
    resultedSimbol |= lastThree;

    return resultedSimbol;
}

unsigned short UTF8ToUTF16LE(unsigned char byte1, unsigned char byte2)
{
    unsigned short k = ( byte1 & 0b00011100 );
    unsigned short resultedSimbol = 0b1111111100000000 & (( k >> 2) << 8);

    byte2 &= 0b00111111;
    byte2 |= ( byte1 << 6 );

    resultedSimbol |= byte2;

    return resultedSimbol;
}

unsigned short UTF16ToUTF8(unsigned char byte1, unsigned char byte2)
{
    unsigned char bytecopy = byte1;
    int bitsCount = 0;

    while (0 != bytecopy)
    {
        bytecopy = (bytecopy >> 1);
        ++bitsCount;
    }

    bytecopy = byte2;

    while (0 != bytecopy)
    {
        bytecopy = (bytecopy >> 1);
        ++bitsCount;
    }

    if (bitsCount > 11)
    {
        throw std::invalid_argument("Invalid argument, 2 byte.");
    }

    unsigned short resultedSimbol =0;
    resultedSimbol |= 0b1100000010000000;
    resultedSimbol |= (byte1 & 0b00111111);
    unsigned short temp = (((byte1 >> 6) | (byte2 << 2)) << 8);
    resultedSimbol |= temp;

    return resultedSimbol;
}

int main()
{  
    FILE* fp = fopen("UTF8Source.txt", "r");
    fseek(fp, 0, SEEK_END);

    long int SIZE = ftell(fp);

    fseek(fp, 0, SEEK_SET);

    unsigned char buff[SIZE];
    fread(buff, 1, SIZE, fp);
    fclose(fp);
    FILE* wpf = fopen("UTF16Converted.txt", "w");

    unsigned short resultedSimbol;

    for (int i = 0; i < SIZE; i += 2)
    {
        resultedSimbol = UTF8ToUTF16BE(buff[i], buff[i + 1]);
        fwrite(&resultedSimbol, 1, sizeof(resultedSimbol), wpf);
    } 
    fclose(wpf);

    fp = fopen("UTF16Converted.txt", "r");
    fseek(fp, 0, SEEK_END);

    SIZE = ftell(fp);

    fseek(fp, 0, SEEK_SET);
    fread(buff, 1, SIZE, fp);
    fclose(fp);

    wpf = fopen("UTF8Destination.txt", "w");
    for (int i = 0; i < SIZE; i += 2)
    {
        resultedSimbol = UTF16ToUTF8(buff[i], buff[i + 1]); // in case BE we can just swap  i and i + 1 elements
        fwrite(&resultedSimbol, 2, 1, wpf);
    }
    fclose(wpf);

    return 0;
}