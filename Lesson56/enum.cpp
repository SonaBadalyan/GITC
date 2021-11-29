#include <iostream>

int main()
{
    enum colors {red = 0, blue = 1, green = 2, yellow = 3};
    colors color = green;

    switch (color)
    {
    case red:
        std::cout << "red" << std::endl;
        break;
    case blue:
        std::cout << "blue" << std::endl;
        break;
    case green:
        std::cout << "green" << std::endl;
        break;
    case yellow:
        std::cout << "yellow" << std::endl;
        break;
    }
    
    return 0;
}