#include <queue>
#include <iostream>
#include <cstdlib>
#include <list>
#include <deque>
#include <vector>

int main()
{
    const int ELEM_COUNT = 10;

    std::priority_queue<int, std::deque<int>> pqd;

    int pqdInsertionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        pqd.push(rand() % 10 + 10);
    }
    int pqdInsertionEnd = clock();
    int pqdInsertionDiff = pqdInsertionEnd - pqdInsertionStart;

    int pqdDeletionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        pqd.pop();
    }
    int pqdDeletionEnd = clock();
    int pqdDeletionDiff = pqdDeletionEnd - pqdDeletionStart;


    std::priority_queue<int, std::vector<int>> pqv;

    int pqvInsertionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        pqv.push(rand() % 10 + 10);
    }
    int pqvInsertionEnd = clock();
    int pqvInsertionDiff = pqdInsertionEnd - pqdInsertionStart;

    int pqvDeletionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        pqv.pop();
    }
    int pqvDeletionEnd = clock();
    int pqvDeletionDiff = pqvDeletionEnd - pqvDeletionStart;


    std::cout << "_______INSERTION_______ " << std::endl;
    std::cout << "deque : " << pqdInsertionDiff << std::endl;
    std::cout << "vector : " << pqvInsertionDiff << std::endl;

    std::cout << "_______DELETION_______ " << std::endl;
    std::cout << "deque : " << pqdDeletionDiff << std::endl;
    std::cout << "vector : " << pqvDeletionDiff << std::endl;

    return 0;
}