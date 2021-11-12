#include <iostream>
#include <set>
#include <vector>

int main()
{
    std::vector<int> source{1, 2, 3, 5, 1, 3, 4, 78, 3, 4, 4, 5, 5};

    auto iter_begin = source.begin();
    auto iter_end = source.end();

    std::set<int> destination;

    while(iter_begin != iter_end)
    {
        destination.insert(*iter_begin);
        ++iter_begin;
    }

    return 0;
}