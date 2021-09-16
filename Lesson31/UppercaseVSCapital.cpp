#include<iostream>

int main()
{
    std::cout << "Please enter letter." << std::endl;

    char c; 
    std::cin >> c;

    if (int(c) >= 65 && int(c) <= 90)
    {
        std::cout << "Entered leter is capital." << std::endl;
        return 0 ;
    }

    if (int (c) >= 97 && int (c) <= 121)
    {
        std::cout << "Entered leter is uppercase." << std::endl;
        return 0;
    }

    std::cout << "You are not enter a letter! " << c << " is not a letter!" << std::endl;


    return 0;
}