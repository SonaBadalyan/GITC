#include <iostream>
#include <cstdlib>
 
int main()
{
    for (int i = 0; i < 20; ++i)
    {
        std::cout << "Random number is equal to " << rand() % 31 + 15 << std::endl;
    }

    return 0;
}