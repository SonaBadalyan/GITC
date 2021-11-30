#include <iostream>

int main()
{
    int start = clock();
    for(register int i = 0; i < 10000000; ++i)
    {

    }
    int end = clock();
    int diff = end - start;

    std::cout << "Time passed for 10000000 iterations with register keyword : " << diff << std::endl;
    
    start = clock();
    for(int i = 0; i < 10000000; ++i)
    {

    }
    end = clock();
    diff = end - start;

    std::cout << "Time passed for 10000000 iterations without keyword : " << diff << std::endl;

    return 0;
}