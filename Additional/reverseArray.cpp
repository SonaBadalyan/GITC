#include <iostream>
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};

    int mid = (sizeof(a)/sizeof(a[0])) / 2;

    for ( size_t i = 0; i < mid; ++i)
    {
        swap(a[i], a[sizeof(a)/sizeof(a[0]) - i -1]);
    }

    for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
    {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}