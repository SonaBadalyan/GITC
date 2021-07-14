#include <iostream>

int main()
{
    int array[] = {10, 20, 30, 10, 20, 30, 40, 50, 60, 70, 10, 20, 30, 40, 50, 10, 20, 30, 40, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int new_array[sizeof(array)/sizeof(int)];

    int min = array[0];
    int max = array[0];

    for (size_t i = 1; i < sizeof(array)/sizeof(int); ++i)
    {
        if (array[i]  < min)
            min = array[i];

        if (array[i]  > max)
            max = array[i];
    }

    std::cout << "Minimum equal to " << min <<std::endl;
    std::cout << "Maximum equal to " << max <<std::endl;

    return 0;
}
