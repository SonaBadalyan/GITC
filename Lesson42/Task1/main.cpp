#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "LinkedList.hpp"


int main()
{
    std::regex reg("(\\+374|\\(\\+374\\))(\\-?|\\s?)(94|93|44|95|55|45|99)(((\\-?|\\s?)(\\(?)[0-9]{2}(\\)?)){3}|((\\-?|\\s?)(\\(?)[0-9]{3}(\\)?)){2})"); 
    
    std::string text = ("(+374)-95456789 this isn`t phone number +374 44 89 90 90 +374-44-89-90-90 +37444-89-90-90 +(374) -44-(89)-(90)-(90) +374 -44-(89)-(90) +37444-(899)-(900)");
    std::smatch match;

    LinkedList<std::string> matches;

    while(std::regex_search(text, match, reg))
    {
        std::string m = match[0];
        matches.add(m);
        text = match.suffix();
    }

    for (int i = 0; i < matches.length(); ++i)
    {
        std::cout << matches[i] << std::endl;
    }

    return 0;
}