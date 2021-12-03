#include <iostream>
#include <set>

int main()
{
    std::cout << "____ Start of set ______" << std::endl;

    std::set<int> s;
    s.emplace(10);
    s.insert(34);
    s.insert(10);
    s.emplace(20);
    s.emplace(20);

    for(auto& elem : s)
    {
        std::cout << elem <<std::endl;
    }

    std::cout << "____ Start of multiset ______" << std::endl;
    
    std::multiset<int> ms;
    ms.emplace(10);
    ms.insert(34);
    ms.insert(10);
    ms.emplace(20);
    ms.emplace(20);

    for(auto& elem : ms)
    {
        std::cout << elem <<std::endl;
    }


    return 0;
}