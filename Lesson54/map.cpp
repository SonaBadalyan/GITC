#include <iostream>
#include <map>

int main()
{
    std::map<int, int> m;
    m.emplace(222, 400);
    m.emplace(5, 200);
    m.emplace(10, 1000);
    m.emplace(10, 10900);
    m.insert({90, 200});
    m.insert(std::pair<int, int>(100, 400));
    m[100] = 789;

    for(auto it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first << "  " << (*it).second << std::endl;
    }

    auto elem = m[90];
    std::cout << elem << std::endl;

    auto elem1 = m[10000];
    std::cout << elem1 << std::endl;

    auto elem3 = m.find(90);
    if(elem3 != m.end())
    {
        std::cout << "Element is found. " << elem3->second << std::endl;
    }
    else
    {
        std::cout << "Element is not found. " << std::endl;
    }

    std::cout << "_____ Start of multimap _____" <<std::endl;

    std::multimap<int, int> mm;
    mm.emplace(222, 400);
    mm.emplace(5, 200);
    mm.emplace(10, 1000);
    mm.emplace(10, 10900);
    mm.insert({90, 200});
    mm.insert(std::pair<int, int>(100, 400));

    for(auto it = mm.begin(); it != mm.end(); ++it)
    {
        std::cout << it->first << "  " << (*it).second << std::endl;
    }
    
    return 0;
}