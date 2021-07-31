#include <iostream>

int main()
{
    int arr[] = {10, 20, 30, 40};
    int* parr = arr; 
    int sum = 0;

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
    {
        sum += *parr++;
    }

    std::cout << sum << std::endl;

    return 0;
}