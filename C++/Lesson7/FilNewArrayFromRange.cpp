#include<iostream>

int main()
{
    int a [] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int a_size = sizeof(a)/sizeof(a[0]);

    std::cout << "Please enter start and end positions." << std::endl;

    int start, end;
    std::cin >> start >> end;

    while (start < 0 || end <= 0 || start >= end || end > a_size -1)
    {
        std::cout << "Invalid range!!! Please enter again." << std::endl;
        std::cin >> start >> end;
    }

    int b_size = end - start + 1;
    int b[b_size];

    for (int i = start, j = 0; i < end + 1 && j < b_size; ++i, ++j)
    {
        b[j] = a[i];
    }

    for (int j = 0; j < b_size; ++j)
    {
        std::cout << b[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}