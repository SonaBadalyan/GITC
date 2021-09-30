#include <stdio.h>

int main()
{
    const int SIZE = 43;

    FILE* fp = fopen("source.txt", "r");

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