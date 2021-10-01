#include <stdio.h>
#include <iostream>

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

    char numbers_buff[1];
    FILE* wpf = fopen("destination.txt", "w");

    for (int i = 0; i < SIZE; ++i)
    {
        if (int (buff[i]) >= 48 && int (buff[i]) <= 57)
        {
            numbers_buff[0] = buff[i];
            fwrite(numbers_buff, 1, 1, wpf);
        }
    }

    fclose(wpf);
    fclose(fp);
    
    return 0;
}