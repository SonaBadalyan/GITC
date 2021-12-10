#include <iostream>
#include <string>
#include <stack>

bool isBalanced(const std::string& source)
{
    std::stack<char> s;

    for(int i = 0; i < source.length(); ++i)
    {
        if (source[i] == '{')
        {
            s.push(source[i]);
        }
        else
        {
            char c = s.top();
            s.pop();

            if (c != '}')
            {
                return false;
                break;
            }
        }
    }

    return s.empty();
};

int main()
{
    std::string s = "{{}}{}";

    std::cout << isBalanced(s) << std::endl;
    
    return 0;
}