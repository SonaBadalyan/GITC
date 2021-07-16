#include<iostream>

int main()
{
    int a_b_size = 9;
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int b[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
    
    int c_size;

    bool flag = true;

    while (flag)
    {
        std::cout << "Please enter new array size. It must be less than or equal to " << a_b_size << ". " << std::endl;
        std::cin >> c_size;

        if (c_size <= a_b_size)
            flag = false;
    }

    int c[c_size];

    for (int i = sizeof(a)/sizeof(a[0]) - c_size , j = 0; i < sizeof(a)/sizeof(a[0]), j < c_size; ++i, ++j)
    {
        c[j] = a[i] + b[i];
    }

    for (int j = 0; j < c_size; ++j)
    {
        std::cout << c[j] << " ";
    }

    std::cout << std::endl;
    return 0;
}