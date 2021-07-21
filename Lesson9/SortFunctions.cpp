#include <iostream>

void swap(int &value1, int &value2)
{
    value1 = value1 ^ value2;
    value2 = value1 ^ value2;
    value1 = value1 ^ value2; 
}

void bubble_sort(int *array, int SIZE)
{
    bool b = true;

    while (b)
    {
        b = false;
        int i = 0;

        while ( i < SIZE - 1 )
        {
            if (array[i + 1] < array[i])
            {
                swap(array[i + 1], array[i]);
                b = true; 
            }
            ++i;
        }
    }
}

void shaker_sort(int *array, int SIZE)
{
    bool b = true;

    int size = SIZE;

    while (b)
    {
        b = false;
        int i = 0;

        while ( i < size - 1 )
        {
            if (array[i + 1] < array[i])
            {
                swap(array[i + 1], array[i]);
                b = true; 
            }
            ++i;
        }
        --size;
    }
}

void stupid_sort(int *array, int SIZE)
{
    int i = 0;

    while (i < SIZE - 1)
    {
        if (array[i + 1] < array[i])
        {
            swap(array[i + 1], array[i]);
            i = -1;     
        }
        ++i;
    }
}

int main()
{
    const int SIZE = 10;
    
    int array[SIZE] = {10, 20, 100, 0, 6, 0, 12, 1000, 1, 23};

    std::cout << "Array before sorting: ";
    
    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    bubble_sort(array, SIZE);
    //shaker_sort(array, SIZE);
    //stupid_sort(array, SIZE);
    
    std::cout << "Array after sorting: ";

    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;


    return 0;
}
