#include <iostream>
#include <array>
#include <random>

int main()
{
    std::array<std::array<int, 5>,  3> arr;

    for(auto& row : arr)
    {
        for(auto& element : row)
        {
            element = random() % 90 + 10;
        }
    }

    std::cout << "_______STL STYLE array___________" <<std::endl;


    for(auto& row : arr)
    {
        for(auto& element : row)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    int CStyleArray[15], i = 0;

    for(auto& row : arr)
    {
        for(auto& element : row)
        {
            CStyleArray[i++] = element;
        }  
    }
    
    std::cout << "________C-STILE array_________" << std::endl;
    for (int i = 0; i < 15; ++i)
    {
        std::cout << CStyleArray[i] << " ";
    }
    std::cout << std::endl;

}