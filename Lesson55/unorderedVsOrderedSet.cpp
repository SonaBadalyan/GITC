#include <set>
#include <unordered_set>
#include <iostream>
#include <cstdlib>

int main()
{
    const int ELEMENT_COUNT = 1000;

    std::set<int> s;

    int SetInsertionStart = clock();
    for(int i = 0; i < ELEMENT_COUNT; ++i)
    {
        s.emplace(rand() % 10 + 10);
    }
    int SetInsertionEnd = clock();
    int SetInsertionDiff = SetInsertionEnd - SetInsertionStart;

    int SetFindStart = clock();
    for(int i = 0; i < ELEMENT_COUNT; ++i)
    {
        s.find(rand() % 10 + 10);
    }
    int SetFindEnd = clock();
    int setFindDiff = SetFindEnd - SetFindStart;

    std::unordered_set<int> us;

    int USetInsertionStart = clock();
    for(int i = 0; i < ELEMENT_COUNT; ++i)
    {
        us.emplace(rand() % 10 + 10);
    }
    int USetInsertionEnd = clock();
    int USetInsertionDiff = USetInsertionEnd - USetInsertionStart;

    int USetFindStart = clock();
    for(int i = 0; i < ELEMENT_COUNT; ++i)
    {
        us.find(rand() % 10 + 10);
    }
    int USetFindEnd = clock();
    int USetFindDiff = USetFindEnd - USetFindStart;

    if (USetInsertionDiff < SetInsertionDiff)
    {
        std::cout << "Insertion time for unordered set is less." << std::endl;
    }
    else
    {
        std::cout << "Insertion time for set is less." << std::endl;
    }

    std::cout << "Unordered set : " << USetInsertionDiff << std::endl;
    std::cout << "set : " << SetInsertionDiff <<std::endl;

       if (USetFindDiff < USetFindDiff)
    {
        std::cout << "Find time for unordered set is less." << std::endl;
    }
    else
    {
        std::cout << "Find time for set is less." << std::endl;
    }

    std::cout << "Unordered set : " << USetFindDiff << std::endl;
    std::cout << "Set : " << setFindDiff <<std::endl;

    std::cout << "_______Print set _________" << std::endl;
    for( auto const& elem : s)
    {
        std::cout << elem << std::endl;
    }

    std::cout << "_______Print unordered set _________" << std::endl;
    for( auto const& elem : us)
    {
        std::cout << elem << std::endl;
    }
    return 0; 
}