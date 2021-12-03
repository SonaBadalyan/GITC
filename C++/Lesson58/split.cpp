#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    std::string s = "one two three four five six";
    std::stringstream ss(s);
    std::vector<std::string> vs;
    std::string temp;

    while(std::getline(ss, temp, ' '))
    {
        vs.push_back(temp);
    }

    for(auto const& i: vs)
    {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;

    return 0;
}