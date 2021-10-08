#include <fstream>
#include <string>
#include <regex>

int main()
{
    std::fstream source;
    source.open("source.txt", std::ios::in);
    
    std::fstream destination;
    destination.open("destination.txt", std::ios::out);
    
    std::regex reg("((((2[0-5]{2})|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3})((2[0-5]{2})|(1[0-9]{2})|([1-9][0-9])|([0-9]))");
    std::smatch match;
    std::string line;

    while(getline(source, line))
    {
        while(std::regex_search(line, match, reg))
        {
            destination << match[0];
            destination << "\n";
            line = match.suffix();
        }
    }

    source.close();
    destination.close();

    return 0;
}