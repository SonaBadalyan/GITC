#include <iostream>
#include <array>

int main()
{   
    std::array<int, 25> array = {10, 20, 30, 10, 20, 10, 20, 30, 40, 50, 10, 20, 30, 40, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 20};

    int count =  1;
    int max = 1;

    for (int i = 0; i < array.size() - 1; ++i)
    {
        if (array[i + 1] < array[i])
        {
            if ( count > max)
            {
                max = count;
            }

           count = 1;
        }
        else 
        {
             ++count;
        }
    }

    if ( count > max)
    {
        max = count;
    }

    std::cout  << "Longest increasing subsequence elements number equal to " <<  max << "." << std::endl;

    return 0;
}
