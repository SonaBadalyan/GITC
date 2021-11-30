#include <iostream>

inline int f1(int a, int b)
{
    return a + b;
}

int f2(int a, int b)
{
    return a + b;
}

int main()
{
    int start = clock();
    int  a = 10, b = 10;
    for(int i = 0; i < 10000000; ++i)
    {
        f1(a, b);
    }
    int end = clock();
    int diff = end - start;

    std::cout << "Time passed for 10000000 iterations f1 inline call : " << diff << std::endl;
    
    start = clock();
    int  c = 10, d = 10;
    for(int i = 0; i < 10000000; i++)
    {
        f2(c, d);
    }
    end = clock();
    diff = end - start;

    std::cout << "Time passed for 10000000 iterations f2 call: " << diff << std::endl;

    return 0;
}