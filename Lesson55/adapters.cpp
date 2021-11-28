#include <iostream>
#include <stack>
#include<vector>
#include <list>

// The same in queue, priority_queue

int main()
{
    std::stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    std::cout << "______________" << std::endl;

    std::stack<int, std::list<int>> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    while (!s1.empty())
    {
        std::cout << s1.top() << std::endl;
        s1.pop();
    }

    //auto x = s1._Get_container(); //return underlying container, but it is a non-standart function, it is added in windows environment

    return 0;
}