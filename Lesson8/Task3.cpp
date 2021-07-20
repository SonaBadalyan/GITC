#include <iostream>

int main()
{
    int a[4][4];

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            a[i][j] = (i + 1) + (j + 1) * 10;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
           std::cout << a[i][j] << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "The top half`s elements : ";
    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            std::cout << a[i][j] << " ";
        }
    }
    std::cout << std::endl; 

    std::cout << "The bottom half`s elements : ";
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << a[i][j] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}