#include<iostream>

int main()
{
    int a = 0b1011001;
    int b = 0b1001010;

    int c = a & b;
    std::cout << c << std::endl;

    int d = a | b;
    std::cout << d << std::endl;

    int e = a ^ b;
    std::cout << e << std::endl;

    std::cout << ~e << std::endl;

    int f = e >> 5;
    std::cout << f << std::endl;

    int g = (-1) << 1;
    std::cout << g << std::endl;

    return 0;
}