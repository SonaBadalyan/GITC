#include <unordered_map>
#include <iostream>

int main()
{
    std::unordered_map<int, int> um;
    um.emplace(0,  45);
    um.emplace(10, 34);
    um.emplace(34, 45);
    um.emplace(20, 34);
    um.emplace(4,  45);
    um.emplace(10, 34);

    if (um.empty())
    {
        std::cout << "Unordered map is empty. " << std::endl;
    }
    else
    {
        std::cout << "Unordered map is not empty. " << std::endl;
    }

    std::cout << um.size() <<std::endl;

    for (auto const& elem: um)
    {
        std::cout << elem.first << " " << elem.second << std::endl;
    }

    std::cout << "____________________________" << std::endl;
    auto x = um.find(10);
    if (x != um.end())
    {
        std::cout << x->first << " " << x->second <<std::endl;
    }
    else
    {
        std::cout << "Element is not exist!" << std::endl;
    }

    // bool ifExist = um.contains(10);
    // if (ifExist)
    // {
    //     std::cout << x->first << " " << x->second <<std::endl;
    // }
    // else
    // {
    //     std::cout << "Element is not exist!" << std::endl;s
    // }

    return 0;
}