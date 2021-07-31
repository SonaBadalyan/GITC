#include <iostream>

int main()
{   
    int array[] = {10, 20, 30, 10, 20, 10, 20, 30, 40, 50, 10, 20, 30, 40, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 20};

    int count =  1;
    int max = 1;
    
    int* index = nullptr;

    for (int* i = array; i < array + sizeof(array)/sizeof(int) - 1; ++i)
    {
        if (*(i + 1) < *i)
        {
            if ( count > max)
            {
                max = count;
                index = i;
            }

           count = 1;
        }
        else 
        {
             ++count;
        }
    }

    if ( count > max)
    {
        index = array + sizeof(array)/sizeof(int) - 1;
        max = count;
    }

    for (int* i = index - max + 1; i <= index; ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
