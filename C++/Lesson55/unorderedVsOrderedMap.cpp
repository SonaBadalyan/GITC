#include <map>
#include <unordered_map>
#include <iostream>
#include <cstdlib>

int main()
{
    const int ELEMENT_COUNT = 10;

    std::map<int, int> m;

    int MapInsertionStart = clock();
    for(int i = 0; i < ELEMENT_COUNT; ++i)
    {
        m.emplace(rand() % 10 + 10, rand() % 10 + 10);
    }
    int MapInsertionEnd = clock();
    int MapInsertionDiff = MapInsertionEnd - MapInsertionStart;

    int MapFindStart = clock();
    for(int i = 0; i < ELEMENT_COUNT; ++i)
    {
        m.find(rand() % 10 + 10);
    }
    int MapFindEnd = clock();
    int MapFindDiff = MapFindEnd - MapFindStart;

    std::unordered_map<int, int> um;

    int UMapInsertionStart = clock();
    for(int i = 0; i < ELEMENT_COUNT; ++i)
    {
        um.emplace(rand() % 10 + 10, rand() % 10 + 10);
    }
    int UMapInsertionEnd = clock();
    int UMapInsertionDiff = UMapInsertionEnd - UMapInsertionStart;

    int UMapFindStart = clock();
    for(int i = 0; i < ELEMENT_COUNT; ++i)
    {
        um.find(rand() % 10 + 10);
    }
    int UMapFindEnd = clock();
    int UMapFindDiff = UMapFindEnd - UMapFindStart;

    if (UMapInsertionDiff < MapInsertionDiff)
    {
        std::cout << "Insertion time for unordered map is less." << std::endl;
    }
    else
    {
        std::cout << "Insertion time for map is less." << std::endl;
    }

    std::cout << "Unordered map : " << UMapInsertionDiff << std::endl;
    std::cout << "Map : " << MapInsertionDiff <<std::endl;

       if (UMapFindDiff < MapFindDiff)
    {
        std::cout << "Find time for unordered map is less." << std::endl;
    }
    else
    {
        std::cout << "Find time for map is less." << std::endl;
    }

    std::cout << "Unordered map : " << UMapFindDiff << std::endl;
    std::cout << "Map : " << MapFindDiff <<std::endl;

    std::cout << "_______Print map _________" << std::endl;
    for( auto const& elem : m)
    {
        std::cout << elem.first << " : " << elem.second << std::endl;
    }

    std::cout << "_______Print unordered map _________" << std::endl;
    for( auto const& elem : um)
    {
        std::cout << elem.first << " : " << elem.second << std::endl;
    }
    return 0; 
}