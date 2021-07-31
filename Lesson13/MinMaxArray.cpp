#include <iostream>

int main()
{
    int arr[] = {0, 20, 13, 45, 23};

    int min = arr[0];
    int max = arr[0];

    int* parr = arr;

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
    {
        if(*parr > max)
        {
            max = *parr;
        }
        
        if(*parr < min)
        {
            min = *parr;
        }

        ++parr;
    }

    std::cout << "Maximum = " << max << std::endl;
    std::cout << "Minimum = " << min << std::endl;

    return 0;
}