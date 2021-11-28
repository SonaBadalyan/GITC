#include <vector>
#include <set>
#include <cstdlib>
#include <iostream>

int main()
{
    const int ELEMENT_CONT = 10;

    std::vector<int> randomVector;

    int vectorStart = clock();

    for(int i = 0; i < ELEMENT_CONT; ++i)
    {
        randomVector.push_back(rand() % 10 + 10);
    }

    int vectorEnd = clock();
    int vectorDiff = vectorEnd - vectorStart;


    std::multiset<int> randomSet;

    int setStart = clock();

    for(int i = 0; i < ELEMENT_CONT; ++i)
    {
        randomSet.emplace(rand() % 10 + 10);
    }

    int setEnd = clock();
    int setDiff = setEnd - setStart;

    if (setDiff > vectorDiff)
    {
        std::cout << "Insertion time for vector is less." << std::endl;
    }
    else
    {
        std::cout << "Insertion time for set is less." << std::endl;
    }

    std::cout <<"Vector : " << vectorDiff << std::endl;
    std::cout <<"Set : " << setDiff << std::endl;

    return 0;
}