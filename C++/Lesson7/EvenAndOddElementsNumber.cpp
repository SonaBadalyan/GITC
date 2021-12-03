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

    std::cout <<"Even numbers count " << even_count << std::endl;
    std::cout <<"Odd numbers count " << sizeof(array)/sizeof(int) - even_count << std::endl;
    
    return 0;
}
