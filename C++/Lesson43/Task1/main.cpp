#include <iostream>
#include <string>
#include <regex>

#include "Queue.hpp"

int main()
{
    std::regex reg("((\\+374|\\(\\+374\\))(\\-?|\\s?)|0)(94|93|44|95|55|45|99)(((\\-?|\\s?)([0-9]{2}|(\\()[0-9]{2}(\\)))){3}|((\\-?|\\s?)([0-9]{3}|(\\()[0-9]{3}(\\)))){2})"); 
    
    std::string text = ("(095456789 this isn`t phone number +374 44 89 90 90 +374-44-89-90-90 +37444-89-90-90 +(374) -44-(89)-(90)-(90) +374 -44-(89)-(90) +37444-(899)-(900");
    std::smatch match;

    Queue<std::string> matches;

    while(std::regex_search(text, match, reg))
    {
        matches.push(match[0]);
        text = match.suffix();
    }

    while(!matches.isEmpty()) 
    {
        std::cout << matches.pop() << std::endl;
    }   
    
    return 0;
}