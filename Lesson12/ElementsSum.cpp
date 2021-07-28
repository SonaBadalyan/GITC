#include <iostream>

int array_sum(int arr[], int size, bool)
{
    if (size <= 0)
    {
        return 0;
    }

    return (array_sum(arr, size - 1, true) + arr[size - 1]);
}

int array_sum(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr[] = {2, 4, 6, 7, 8, 90};
    int size = sizeof(arr)/sizeof(arr[0]);

    std::cout << array_sum(arr, size) << std::endl;

    return 0;
}