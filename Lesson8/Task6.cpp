#include <iostream>
#include <cassert>

int main()
{
    int a[5][5] = 
    {
        { 0,  6,  7,  0,  5},
        { 3,  9,  7,  1,  2},
        {-2,  5,  0,  4,  3},
        {-4,  7, -9,  1,  0},
        { 6,  9,  3,  1,  4}
    };

    int sum = 0;
    int count = 0;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = i + 1; j < 5; ++j)
        {
            if (0 != a[i][j] % 2)
            {
                sum += a[i][j];
                ++count;
            }
        }
    }

    assert(sum != 0 && count != 0);

    std::cout << "The top half`s odd elements average equal to : " << sum / count << std::endl; 

    sum = 0;
    count = 0;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (0 == a[i][j] % 2 && a[i][j] < 0)
            {
                sum += a[i][j];
                ++count;
            }
        }
    }
    assert(sum != 0 && count != 0);

    std::cout << "The bottom half`s even and negative elements average equal to : " << sum / count << std::endl; 

    return 0;
}