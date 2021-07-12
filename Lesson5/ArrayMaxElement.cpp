#include <iostream>

int main()
{
    const int SIZE = 4;
    
    int array[SIZE] = {10, 20, 100, 0};
    
    int max = array[0];
    
    int i = 0;

    while (i < SIZE)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        ++i;
    }
    
    std::cout << "The maximum element in the array is equal " << max << ":" << std::endl;
    
    return 0;
}
