#include <iostream>
#include <stdio.h>


int main()
{
    const int SIZE = 909;

    FILE* fp = fopen("source.txt", "r");

    char buff[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        buff[i] = 0;
    } 

    fread(buff, 1, SIZE, fp);

    for (int i = 0; i < SIZE; ++i)
    {
        if (int (buff[i]) >= 97 && int (buff[i]) <= 122)
        {
            buff[i] = char(buff[i] - 32);
        }
    }

    FILE* wpf = fopen("destination.txt", "w");
    fwrite(buff, 1, SIZE, wpf);
    fclose(wpf);

    fclose(fp);
    
    return 0;
}