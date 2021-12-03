#include <iostream>

int main()
{   
    int array[] = {12, 34, 7, 5, 21, 18, 24};

    int even_count = 0;

    for (int i = 0; i < sizeof(array)/sizeof(int); ++i)
    {
        if (0 == array[i] % 2)
        {
            ++even_count;
        }
    }

    int new_array[even_count];

    for (int i = 0, j = 0; i < sizeof(array)/sizeof(int) && j < even_count; ++i)
    {
        if (0 == array[i] % 2)
        {
            new_array[j] = array[i];
            ++j;
        }
    }

    for (int j = 0; j < even_count; ++j)
    {
        std::cout << new_array[j] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}
