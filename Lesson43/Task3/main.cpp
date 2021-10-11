#include <fstream>
#include <string>
#include <regex>

int main()
{      
    std::fstream destination_ipv4;
    std::fstream destination_ipv6;

    destination_ipv4.open("Ipv4.txt", std::ios::out);
    destination_ipv6.open("Ipv6.txt", std::ios::out);

    std::regex reg_ipv4("((\\b((2[0-5]{2})|(1[0-9]{2})|([1-9][\\d])|([\\d]))\\.){3})\\b((2[0-5]{2})|(1[\\d]{2})|([1-9][\\d])|([\\d]))");
    std::regex reg_ipv6("(\\b[\\da-fA-F]{1,4}:){7}\\b[\\da-fA-F]{1,4}"); 
     
    std::smatch match_ipv4;
    std::smatch match_ipv6;

    std::string line;

    std::fstream source;
    source.open("source.txt", std::ios::in);

    while(getline(source, line))
    {
        while(std::regex_search(line, match_ipv4, reg_ipv4))
        {
            destination_ipv4 << match_ipv4[0];
            destination_ipv4 << "\n";
            line = match_ipv4.suffix();
        }

        while(std::regex_search(line, match_ipv6, reg_ipv6))
        {
            destination_ipv6 << match_ipv6[0];
            destination_ipv6 << "\n";
            line = match_ipv6.suffix();
        }
    }

    destination_ipv4.close();
    destination_ipv6.close();

    source.close();

    return 0;
}