#include <iostream>

template<class X>
X array_max(X array[], int SIZE)
{
    if (1 == SIZE)
    {
        return array[0];
    }

    return std::max(array[SIZE - 1], array_max(array, SIZE - 1));
}

template <typename X>
X array_min(X array[], int SIZE)
{
    if (1 == SIZE)
    {
        return array[0];
    }

    return std::min(array[SIZE - 1], array_min(array, SIZE - 1));
}

int main()
{
    const int SIZE = 4;
    
    int array[SIZE] = {10, 20, 100, 0};
    
    std::cout << "The maximum element in the array is equal " << array_max(array, SIZE) << std::endl;
    std::cout << "The minimum element in the array is equal " << array_min(array, SIZE) << std::endl;

    return 0;
}
