#include <iostream>

bool binary_search(int arr[], int key, int start, int end, bool)
{
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] > key)
    {
        binary_search(arr, key, start, mid - 1, true);
    }
    else
    {
        binary_search(arr, key, mid + 1, end, true);
    }
}

bool binary_search(int arr[], int key, int start, int end)
{
    int mid = 0;

    while (end >= start)
    {
        mid = start + (end - start) / 2;

        if (key == arr[mid])
        {
            return true;
        }

        if (key < arr[mid])
        {
            end = mid - 1;   
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
    }

    return false;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 100;

    if (binary_search(arr, key, 0, size, true))
    {
        std::cout << "We have " << key << " in our array." << std::endl;
    } 
    else 
    {
        std::cout << "We have not " << key << " in our array." << std::endl;
    }

    return 0;
}