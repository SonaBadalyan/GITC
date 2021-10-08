#include <iostream>
#include <string>
#include <regex>
#include <vector>

int main()
{
    std::regex reg("(\\+374|\\(\\+374\\))(\\-?|\\s?)(94|93|44|95|55|45|99)(((\\-?|\\s?)(\\(?)[0-9]{2}(\\)?)){3}|((\\-?|\\s?)(\\(?)[0-9]{3}(\\)?)){2})"); 
    
    std::string text = ("(+374)-95456789 this isn`t phone number +374 44 89 90 90 +374-44-89-90-90 +37444-89-90-90 +(374) -44-(89)-(90)-(90) +374 -44-(89)-(90) +37444-(899)-(900)");
    std::smatch match;

    std::vector<std::string> matches;

    while(std::regex_search(text, match, reg))
    {
        matches.push_back(match[0]);
        text = match.suffix();
    }

    for(auto& m : matches)
    {
        std::cout << m << std::endl;
    }

    return 0;
}