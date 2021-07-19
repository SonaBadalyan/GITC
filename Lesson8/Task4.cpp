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

    std::cout << "Boundary elements of matrix  " << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (0 == i || 3 == i || 0 == j || 3 == j)
            {
                std::cout << a[i][j] << " ";
            }
            else
            {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}