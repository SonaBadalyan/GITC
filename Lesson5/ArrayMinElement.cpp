#include <iostream>

int main()
{
    const int SIZE = 4;
    
    int array[SIZE] = {10, 20, 100, 0};
    
    int min = array[0];
    
    int i = 0;

    while (i < SIZE)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        ++i;
    }
    
    std::cout << "The minimum element in the array is equal " << min << ":" << std::endl;
    
    return 0;
}
