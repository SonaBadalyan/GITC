#include <iostream>

// Output
// Array before sorting: 10 20 100 0 6 0 12 1000 1 23 
// Array after sorting: 0 0 1 6 10 12 20 23 100 1000 
// Number of swaps: 20
// Number of comparisions: 42

void swap(int* value1, int* value2)
{
    *value1 = *value1 ^ *value2;
    *value2 = *value1 ^ *value2;
    *value1 = *value1 ^ *value2;  
}

int main()
{
    const int SIZE = 10;
    
    int array[SIZE] = {10, 20, 100, 0, 6, 0, 12, 1000, 1, 23};

    std::cout << "Array before sorting: ";

    int* parray = array;
    
    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << *parray++ << " ";
    }

    std::cout << std::endl;

    int count_swaps = 0;
    int count_comp = 0;
    
    bool b = true;

    int size = SIZE;

    while (b)
    {
        b = false;
        int i = 0;
        int* next = array;
        int* current = array + 1;

        while ( i < size - 1 )
        {
            if (*current < *next)
            {
                swap(current, next);
                ++count_swaps;
                b = true; 
            }
            next = current;
            ++current;
            ++i;
            ++count_comp;
        }
        --size;
    }
    
    std::cout << "Array after sorting: ";
    parray = array;
    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << *parray++ << " ";
    }
    
    std::cout << std::endl;

    std::cout << "Number of swaps: " << count_swaps << std::endl;
    std::cout << "Number of comparisions: " << count_comp << std::endl;

    return 0;
}
