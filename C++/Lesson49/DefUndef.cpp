#include <iostream>

#define PI 3.14

int main()
{
    std::cout << PI << std::endl;
    #undef PI
    // std::cout << PI << std::endl; error: ‘PI’ was not declared in this scope
    
    return 0;
}