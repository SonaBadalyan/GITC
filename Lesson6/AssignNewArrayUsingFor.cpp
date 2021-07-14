#include <iostream>

int main()
{
    int array[] = {10, 20, 30, 10, 20, 30, 40, 50, 60, 70, 10, 20, 30, 40, 50, 10, 20, 30, 40, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int new_array[sizeof(array)/sizeof(int)];

    for (size_t i = 0; i < sizeof(array)/sizeof(int); ++i)
    {
        new_array[i] = array[i];
    }

    return 0;
}
