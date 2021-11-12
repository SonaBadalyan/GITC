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

    std::vector<int> count;
    for (auto dit = destination.begin(); dit != destination.end(); ++dit)
    {
        int elem_count = 0;

        for(auto sit = source.begin(); sit != source.end(); ++sit)
        {
            if (*dit == *sit)
            {
                ++elem_count;
            }
        }
        count.push_back(elem_count);
    }

    for (std::set<int>::iterator it = destination.begin(); it != destination.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    for (std::vector<int>::iterator it = count.begin(); it != count.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    return 0;
}