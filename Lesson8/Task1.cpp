#include <iostream>

int main()
{
    int a[10] = {12, 34, 56, 7, 8, 12, 7, 4, 12, 78};
    int b[10] = {34, 8, 0, 15, 78, 6, 100, 10, 45, 8};

    int count = 0;

    for ( int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
    {
        for ( int j = 0; j < sizeof(b)/sizeof(b[0]); ++j)
        {
            if (a[i] == b[j])
            {
                ++count;
            }
        }
    }

    std::cout <<"The equal elements number is :" << count << std::endl;
    return 0;
}