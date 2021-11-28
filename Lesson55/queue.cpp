#include <queue>
#include <iostream>
#include <cstdlib>
#include <list>
#include <deque>

int main()
{
    const int ELEM_COUNT = 10000;

    std::queue<int, std::deque<int>> qd;

    int qdInsertionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        qd.push(rand() % 10 + 10);
    }
    int qdInsertionEnd = clock();
    int qdInsertionDiff = qdInsertionEnd - qdInsertionStart;

    int qdDeletionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        qd.pop();
    }
    int qdDeletionEnd = clock();
    int qdDeletionDiff = qdDeletionEnd - qdDeletionStart;

    std::queue<int, std::list<int>> ql;

    int qlInsertionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        ql.push(rand() % 10 + 10);
    }
    int qlInsertionEnd = clock();
    int qlInsertionDiff = qdInsertionEnd - qdInsertionStart;

    int qlDeletionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        ql.pop();
    }
    int qlDeletionEnd = clock();
    int qlDeletionDiff = qlDeletionEnd - qlDeletionStart;

    std::cout << "_______INSERTION_______ " << std::endl;
    std::cout << "deque : " << qdInsertionDiff << std::endl;
    std::cout << "list : " << qlInsertionDiff << std::endl;

    std::cout << "_______DELETION_______ " << std::endl;
    std::cout << "deque : " << qdDeletionDiff << std::endl;
    std::cout << "list : " << qlDeletionDiff << std::endl;

    return 0;
}