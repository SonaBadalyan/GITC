#include<iostream>

int main()
{
    // char k[] = "test"; // We can assign string literal to the char array. 
    // std::cout << k << std::endl;

    std::string name1 = "Abgar";
    std::string name2 = "Armen";

    if (name1 > name2)
    {
        std::cout << name1 << " is bigger than " << name2 << " in alphabetical order." << std::endl;
    }
    else
    {
        std::cout << name2 << " is bigger than " << name1 << " in alphabetical order." << std::endl;
    }

    std::cout << "b`s ASCII code is " << (int) 'b' << std::endl;
    std::cout << "r`s ASCII code is " << (int) 'r' << std::endl;
    
    // b - 98, r - 114
    // Thats why Abgar bigger than Armen in alphabetical order.
 
    return 0;
}