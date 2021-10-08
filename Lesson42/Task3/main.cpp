#include <fstream>
#include <string>
#include <regex>

int main()
{      
    std::fstream destination_ucom;
    std::fstream destination_beeline;
    std::fstream destination_viva;

    destination_ucom.open("Ucom.txt", std::ios::out);
    destination_beeline.open("Beeline.txt", std::ios::out);
    destination_viva.open("Viva.txt", std::ios::out);

    std::regex reg_ucom("(\\+374|\\(\\+374\\))(\\-?|\\s?)(55|95|41|44)(((\\-?|\\s?)(\\(?)[0-9]{2}(\\)?)){3}|((\\-?|\\s?)(\\(?)[0-9]{3}(\\)?)){2})");
    std::regex reg_beeline("(\\+374|\\(\\+374\\))(\\-?|\\s?)(99|91)(((\\-?|\\s?)(\\(?)[0-9]{2}(\\)?)){3}|((\\-?|\\s?)(\\(?)[0-9]{3}(\\)?)){2})");
    std::regex reg_viva("(\\+374|\\(\\+374\\))(\\-?|\\s?)(94|93)(((\\-?|\\s?)(\\(?)[0-9]{2}(\\)?)){3}|((\\-?|\\s?)(\\(?)[0-9]{3}(\\)?)){2})");
    
    std::smatch match_ucom;
    std::smatch match_beeline;
    std::smatch match_viva;

    std::fstream source;
    source.open("source.txt", std::ios::in);

    std::string line_ucom;

    while(getline(source, line_ucom))
    {
        while(std::regex_search(line_ucom, match_ucom, reg_ucom))
        {
            destination_ucom << match_ucom[0];
            destination_ucom << "\n";
            line_ucom = match_ucom.suffix();
        }
    }

    destination_ucom.close();
    source.close();
    
    source.open("source.txt", std::ios::in);
    std::string line_beeline;

    while(getline(source, line_beeline))
    {
        while(std::regex_search(line_beeline, match_beeline, reg_beeline))
        {
            destination_beeline << match_beeline[0];
            destination_beeline << "\n";
            line_beeline = match_beeline.suffix();
        }
    }

    destination_beeline.close();
    source.close();

    source.open("source.txt", std::ios::in);
    std::string line_viva;

    while(getline(source, line_viva))
    {
        while(std::regex_search(line_viva, match_viva, reg_viva))
        {
            destination_viva << match_viva[0];
            destination_viva << "\n";
            line_viva = match_viva.suffix();
        }
    }

    destination_viva.close();
    source.close();

    return 0;
}