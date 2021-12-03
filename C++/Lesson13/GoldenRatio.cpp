#include <iostream>

int fibonacci(int n)
{
    if ( n == 0 || n == 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
   for( int i = 2; i < 30; ++i) 
   {
       std::cout << fibonacci(i) / (double) fibonacci(i - 1) << std::endl;
   }
    return 0;
}