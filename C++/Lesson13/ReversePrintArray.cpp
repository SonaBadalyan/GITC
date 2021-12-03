#include<iostream>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int* parr = arr + size - 1;

    // for (int i = 0 ; i < size; ++i)
    // {
    //     std::cout << *parr-- << std::endl;
    // }

    for (int* i = arr + size - 1; i >= arr; --i)
    {
        std::cout << *i << std::endl;
    }

    return 0;
}