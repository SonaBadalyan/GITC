#include <iostream>

void print_array(int a[], int SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    print_array(a, sizeof(a)/sizeof(a[0]));
    
    return 0;
}