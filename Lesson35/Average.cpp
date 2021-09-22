#include <iostream>

template <class X>
X array_average(X arr[], int i, int size, bool)
{
    if ( i == size - 1)
    {
        return arr[i];
    }

    if ( i == 0)
    {
        return (arr[i] + array_average(arr, i + 1, size, true)) / size;
    }

    return arr[i] + array_average(arr, i + 1, size, true);
}

template <class X>
X array_average(X arr[], int size)
{
    X sum = 0;

    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum/size;
}

int main()
{
    int arr[] = {12, 4, 5, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    std::cout << array_average(arr, 0, size, true) << std::endl;

    return 0;
}