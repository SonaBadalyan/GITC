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

    std::cout << "The matrix main dioganal elements : ";

    for (int i = 0; i < 4; ++i)
    {
        std::cout << a[i][i] << " ";
    }

    std::cout << std::endl;

    return 0;
}