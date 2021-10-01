#include <iostream>
#include <stdio.h>


int main()
{
    FILE* fp = fopen("source.txt", "r");
    fseek(fp, 0, SEEK_END);

    long int SIZE = ftell(fp);
    //std::cout << SIZE << std::endl;

    fseek(fp, 0, SEEK_SET);

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