#include<iostream>

int main()
{
    int a = 16;
    int*  pa = &a;

    std::cout << pa << std::endl;
    std::cout << *pa << std::endl;
    ++pa;
    std::cout << pa << std::endl;

    return 0;
}