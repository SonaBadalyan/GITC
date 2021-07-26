#include <iostream>

bool binary_search(int arr[], int key, int start, int end, bool)
{
    int mid = 0;

    if (end >= start)
    {
         mid = start + (end - start) / 2;
    }
    else 
    {
        return false;
    }

    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] > key)
    {
        return binary_search(arr, key, start, mid - 1, true);
    }
    else
    {
        return binary_search(arr, key, mid + 1, end, true);
    }

    return false;
}

bool binary_search(int arr[], int key, int start, int end)
{
    int mid = start + (end - start) / 2;

    while (end >= start)
    {
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

        mid = start + (end - start) / 2;
    }

    return false;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 600;

    if (binary_search(arr, key, 0, size))
    {
        std::cout << "We have " << key << " in our array." << std::endl;
    } 
    else 
    {
        std::cout << "We have not " << key << " in our array." << std::endl;
    }

    return 0;
}