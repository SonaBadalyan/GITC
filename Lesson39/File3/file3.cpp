#include <iostream>
#include <stdio.h>


int main()
{
    FILE* fp = fopen("source.txt", "r+"); // r+ open file with read write permition 

    fseek(fp, -10, SEEK_END); // it is work

    char buff[1];

    while(fread(buff, 1, 1, fp))
    {
        std::cout << buff[0];
    }

    fclose(fp);
    
    return 0;
}