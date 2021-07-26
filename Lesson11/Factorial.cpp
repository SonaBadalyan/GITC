#include <iostream>

int factorial(int n, bool)
{
    if (1 == n)
    {
        return 1;
    }

    return n * factorial(n - 1, true);
}

int factorial(int n)
{
    int fact = 1;

    for (int i = n; i != 1; --i)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int num = 5;
    std::cout << "The factorial of " << num << " is equal to " << factorial(num, true) << std::endl;

    return 0;
}