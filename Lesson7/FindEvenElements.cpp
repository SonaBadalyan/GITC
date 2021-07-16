#include <iostream>

int main()
{   
    int array[] = {12, 34, 7, 5, 21, 18};

    for (int i = 0; i < sizeof(array)/sizeof(int); ++i)
    {
        if (0 == array[i] % 2)
        {
            std::cout << array[i] << " ";
        }
    }

    std::cout << std::endl;
    
    return 0;
}
