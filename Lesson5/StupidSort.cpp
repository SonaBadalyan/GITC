#include <iostream>

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

    int count_swaps = 0;
    int count_comp = 0;
    
    int i = 0;

    while (i < SIZE - 1)
    {
        if (array[i + 1] < array[i])
        {
                array[i + 1] = array[i + 1] ^ array[i];
                array[i] = array[i + 1] ^ array[i];
                array[i + 1] = array[i + 1] ^ array[i];

                ++count_swaps;
                i = -1;
        }
        ++i;
        ++count_comp;
    }
    
    std::cout << "Array after sorting: ";

    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;

    std::cout << "Number of swaps: " << count_swaps << std::endl;
    std::cout << "Number of comparisions: " << count_comp << std::endl;

    return 0;
}
