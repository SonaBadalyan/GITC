#include <iostream>

int fibonacci(int n, bool)
{
    if ( n <= 1)
        return n;

    return fibonacci(n - 1, true) + fibonacci(n - 2, true);
}

int fibonacci(int n)
{
    int previousprevious;
    int previous = 0;
    int current = 1;

    for (int i = 1; i < n; ++i)
    {
        previousprevious = previous;

        previous = current;

        current = previousprevious + previous;
    }

    return current;
}

int main()
{
    int num = 10;
    std::cout << "The fibonacci of " << num << " is equal to " << fibonacci(num, true) << std::endl;

    return 0;
}