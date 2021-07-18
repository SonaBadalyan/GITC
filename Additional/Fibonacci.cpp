#include <iostream>

int fibonacci(int n)
{
    if ( n == 0 || n == 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    std::cout << "Please enter number for calculating fibonacci." << std::endl;
    int n;
    std::cin >> n;
    std::cout << fibonacci(n) << std::endl;

    return 0;
}