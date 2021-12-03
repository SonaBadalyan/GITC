#include <iostream>

int main()
{
    int a[5][5] = 
    {
        {12, 34, 56, 78, 90},
        {12, 34, 56, 78, 90},
        {12, 34, 56, 78, 90},
        {12, 34, 56, 78, 90},
        {12, 34, 56, 78, 90}
    };

    int sum = 0;

    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
    {
        sum += a[i][i];
    }

    std::cout << "The matrix main dioganal elements average equal to: " << sum / (sizeof(a)/sizeof(a[0])) << std::endl;
    
    return 0;
}