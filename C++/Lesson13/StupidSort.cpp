#include <iostream>

// Output
// Array before sorting: 10 20 100 0 6 0 12 1000 1 23 
// Array after sorting: 0 0 1 6 10 12 20 23 100 1000 
// Number of swaps: 20
// Number of comparisions: 99

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

    int* parray_next = array;
    int* parray_current = array + 1;

    int count_swaps = 0;
    int count_comp = 0;
    
    int i = 0;

    while (i < SIZE - 1)
    {
        if (*parray_current < *parray_next)
        {
                *parray_current  = *parray_current  ^ *parray_next;
                *parray_next = *parray_current  ^ *parray_next;
                *parray_current  = *parray_current  ^ *parray_next;

                i = -1;

                parray_current = array;
                ++count_swaps;      
        }
        parray_next = parray_current;
        ++parray_current;
        ++i;
        ++count_comp;
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
