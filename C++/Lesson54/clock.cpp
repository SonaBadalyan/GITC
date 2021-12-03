#include <iostream>
#include <cstdlib>
 
int main()
{
    int start = clock();

    for(int i = 0; i < 1000000000; ++i)
    {
        int k = k + 200000;
    }

    int end = clock();
    int diff = end - start;

    std::cout << "Time for for() is : " << diff << std::endl;

    return 0;
}