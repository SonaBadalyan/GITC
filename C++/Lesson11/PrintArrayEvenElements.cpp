#include <iostream>

void print_array(int arr[], int n, bool)
{
    if (n > 0)
    {
        if (0 == arr[n - 1] % 2)
        {
            std::cout << arr[n - 1] << " ";
        }

        print_array(arr, n - 1, true);
    }

    return;
}

void print_array(int a[], int n)
{
    for (int i = n - 1; i >= 0; --i)
    {
        if (0 == a[i] % 2)
        {
            std::cout << a[i] << " ";
        }
    }

    std::cout << std::endl;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    
    print_array(arr, 6, true);

    return 0;
}