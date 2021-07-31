#include <iostream>

int main()
{
    int arr[] = {10, 20, 30, 40};
    int *parr = &arr[0]; // parr = arr;

    std::cout << "arr = " << arr << std::endl;
    std::cout << "parr = " << parr << std::endl;

    std::cout << *parr << std::endl;
    ++parr;
    std::cout << *parr <<std::endl;
    
    std::cout << "--------------------------" <<std::endl;

    parr = arr; 

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
    {
        std::cout << *parr++ << " ";
    }
    std::cout << std::endl;

    return 0;
}