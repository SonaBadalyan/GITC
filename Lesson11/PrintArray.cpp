#include <iostream>

void print_array(int arr[], int i, int n, bool)
{
    if( i >= n)
    {
        return;
    }
        
    std::cout << arr[i] << " ";

    print_array(arr, i + 1, n, true);
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    
    print_array(arr, 0, 6, true);

    return 0;
}