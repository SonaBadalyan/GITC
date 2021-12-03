#include <iostream>

void swap(int &x, int &y)
{
    int c = x;
    x = y;
    y = c;
}

int main()
{
    int a = 5;
    int b = 10;
    
    std::cout << a << " " << b << std::endl;
    swap(a, b);
    std::cout << a << " " << b << std::endl;

    return 0;
}