#include <array>
#include <iostream>
#include <set>
#include <random>

int main()
{
    std::array<std::array<int, 5>, 5> arr;

    for(auto& row : arr)
    {
        for(auto& element : row)
        {
            element = random() % 90 + 10;
        }
    }

    for(auto& row : arr)
    {
        for(auto& element : row)
        {
            std::cout << element << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;


    std::set<int> uniqueOdd;

    for(auto& row : arr)
    {
        for(auto& element : row)
        {
            if (element % 2 )
            {
                uniqueOdd.emplace(element);
            }
        }
    }

    std::cout << "___________" <<std::endl;

    for(auto& elem : uniqueOdd)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}