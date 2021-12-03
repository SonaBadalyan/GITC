#include <iostream>

int array_max(int *array, int SIZE)
{
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

    return max;
}

int array_min(int *array, int SIZE)
{
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
    
    return min;
}

int main()
{
    const int SIZE = 4;
    
    int array[SIZE] = {10, 20, 100, 0};
    
    std::cout << "The maximum element in the array is equal " << array_max(array, SIZE) << std::endl;
    std::cout << "The minimum element in the array is equal " << array_min(array, SIZE) << std::endl;

    return 0;
}
