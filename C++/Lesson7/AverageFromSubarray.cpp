#include<iostream>

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    std::cout << "Please enter minimum and maximum values." << std::endl;
    int min, max;
    std::cin >> min >> max;

    int b_size = 0;

    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
    {
        if (a[i] > min && a[i] < max)
        {
            ++b_size;
        }
    }

    int b[b_size];
    int sum = 0;

    for (int i = 0, j = 0; i < sizeof(a)/sizeof(a[0]), j < b_size; ++i)
    {
        if (a[i] > min && a[i] < max)
        {
            b[j] = a[i];
            sum += b[j];
            ++j;
        }
    }

    for (int j = 0; j < b_size; ++j)
    {
        std::cout << b[j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Average is equal to : " << sum / b_size << std::endl;

    return 0;
}