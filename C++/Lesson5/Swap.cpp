#include<iostream>

int main()
{
    int a = 100;
    int b = 200;

    //////////////////////////////////////////////////////////////////
    std::cout << "Swap numbers using additional variable." << std::endl;
    std::cout << "Numbers before swap: a = " << a << ", b = " << b << std::endl;

    int c = a + b;
    b = c - b;
    a = c - a;

    std::cout << "Numbers after swap: a = " << a << ", b = " << b << std::endl;

    //////////////////////////////////////////////////////////////////
    std::cout << "Swap numbers without using additional variable with XOR operation." << std::endl;
    a = 100;
    b = 200;
    std::cout << "Numbers before swap: a = " << a << ", b = " << b << std::endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    std::cout << "Numbers after swap: a = " << a << ", b = " << b << std::endl;

    //////////////////////////////////////////////////////////////////
    std::cout << "Swap numbers without using additional variable and XOR operation." << std::endl;
    a = 100;
    b = 200;
    std::cout << "Numbers before swap: a = " << a << ", b = " << b << std::endl;

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "Numbers after swap: a = " << a << ", b = " << b << std::endl;  

    return 0;
}