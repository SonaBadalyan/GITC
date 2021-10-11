#include <fstream>
#include <string>
#include <regex>

int main()
{      
    std::fstream destination;

    destination.open("NameSurnamePassportSerialNumber.txt", std::ios::out);
    std::regex reg("\\b[A-Z][a-z]{2,20}\\b\\s+\\b[A-Z][a-z]{2,30}\\b\\s+\\b[A-Z]{2}[\\d]{7}\\b");
    std::smatch match;
    std::string line;

    std::fstream source;
    source.open("source.txt", std::ios::in);

    while(getline(source, line))
    {
        while(std::regex_search(line, match, reg))
        {
            destination << match[0];
            destination << "\n";
            line = match.suffix();
        }
    }

    destination.close();
    source.close();

    return 0;
}