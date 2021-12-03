#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {23, 4, 56, 89, 100};

    std::cout << "Before sorting" << std::endl;
    for(auto& elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end());

    std::cout << "After sorting" << std::endl;
    for(auto& elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;


    return 0;
}