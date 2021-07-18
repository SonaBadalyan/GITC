#include <iostream>
#include <vector>

// There is a large pile of socks that must be paired by color.
// Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.

int sockMerchant(int n, std::vector<int> ar) 
{
    int count = 0;
    
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
        {
            if (ar[i] == ar[j] && ar[j] != 0)
            {
                ++count;
                
                ar[i] = ar[j] = 0;
                break;
            }
        }
    }
    
    return count;
}

int main()
{
    std::vector<int> sockArray{10, 20, 20, 10, 10, 30, 50, 10, 20};

    std::cout << "The number of pairs of socks with matching colors is : " << sockMerchant(sockArray.size(), sockArray) << std::endl;

    return 0;
}