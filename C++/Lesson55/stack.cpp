#include <stack>
#include <iostream>
#include <cstdlib>
#include <list>
#include <deque>
#include <vector>

int main()
{
    const int ELEM_COUNT = 1000000;

    std::stack<int, std::deque<int>> sd;

    int sdInsertionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        sd.push(rand() % 10 + 10);
    }
    int sdInsertionEnd = clock();
    int sdInsertionDiff = sdInsertionEnd - sdInsertionStart;

    int sdDeletionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        sd.pop();
    }
    int sdDeletionEnd = clock();
    int sdDeletionDiff = sdDeletionEnd - sdDeletionStart;


    std::stack<int, std::vector<int>> sv;

    int svInsertionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        sv.push(rand() % 10 + 10);
    }
    int svInsertionEnd = clock();
    int svInsertionDiff = sdInsertionEnd - sdInsertionStart;

    int svDeletionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        sv.pop();
    }
    int svDeletionEnd = clock();
    int svDeletionDiff = svDeletionEnd - svDeletionStart;

    std::stack<int, std::list<int>> sl;

    int slInsertionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        sl.push(rand() % 10 + 10);
    }
    int slInsertionEnd = clock();
    int slInsertionDiff = sdInsertionEnd - sdInsertionStart;

    int slDeletionStart = clock();
    for (int i = 0; i < ELEM_COUNT; ++i)
    {
        sl.pop();
    }
    int slDeletionEnd = clock();
    int slDeletionDiff = slDeletionEnd - slDeletionStart;

    std::cout << "_______INSERTION_______ " << std::endl;
    std::cout << "deque : " << sdInsertionDiff << std::endl;
    std::cout << "vector : " << svInsertionDiff << std::endl;
    std::cout << "list : " << slInsertionDiff << std::endl;

    std::cout << "_______DELETION_______ " << std::endl;
    std::cout << "deque : " << sdDeletionDiff << std::endl;
    std::cout << "vector : " << svDeletionDiff << std::endl;
    std::cout << "list : " << slDeletionDiff << std::endl;

    return 0;
}