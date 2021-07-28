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

    std::cout << "Boundary elements of matrix." << std::endl;
    for (int j = 0; j < 4; ++j)
    {
        std::cout << a[0][j] << " ";
    }
    std::cout << std::endl;

    for (int j = 1; j < 3; ++j)
    {
        std::cout << a[j][0] << "       " << a[j][4 - 1] << std::endl;
    }

    for (int j = 0; j < 4; ++j)
    {
        std::cout << a[4 - 1][j] << " ";
    }
    std::cout << std::endl;

    return 0;
}