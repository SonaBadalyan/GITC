#include<iostream>

int main()
{
    char carr[] = {'7', '3', '2'};

    for (int i = 0; i < sizeof(carr)/ sizeof(carr[0]); ++i)
    {
        std::cout << carr[i] - '0' << " : " << carr[i] << std::endl;
    }

    return 0;
}