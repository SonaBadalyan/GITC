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

    std::regex reg_ucom("((\\+374|\\(\\+374\\))(\\-?|\\s?)|0)(55|95|44)(((\\-?|\\s?)([0-9]{2}|(\\()[0-9]{2}(\\)))){3}|((\\-?|\\s?)([0-9]{3}|(\\()[0-9]{3}(\\)))){2})");
    std::regex reg_beeline("((\\+374|\\(\\+374\\))(\\-?|\\s?)|0)(99|91)(((\\-?|\\s?)([0-9]{2}|(\\()[0-9]{2}(\\)))){3}|((\\-?|\\s?)([0-9]{3}|(\\()[0-9]{3}(\\)))){2})"); 
    std::regex reg_viva("((\\+374|\\(\\+374\\))(\\-?|\\s?)|0)(94|93)(((\\-?|\\s?)([0-9]{2}|(\\()[0-9]{2}(\\)))){3}|((\\-?|\\s?)([0-9]{3}|(\\()[0-9]{3}(\\)))){2})"); 
    
    std::smatch match_ucom;
    std::smatch match_beeline;
    std::smatch match_viva;

    std::string line;

    std::fstream source;
    source.open("source.txt", std::ios::in);

    while(getline(source, line))
    {
        while(std::regex_search(line, match_ucom, reg_ucom))
        {
            destination_ucom << match_ucom[0];
            destination_ucom << "\n";
            line = match_ucom.suffix();
        }

        while(std::regex_search(line, match_beeline, reg_beeline))
        {
            destination_beeline << match_beeline[0];
            destination_beeline << "\n";
            line = match_beeline.suffix();
        }

        while(std::regex_search(line, match_viva, reg_viva))
        {
            destination_viva << match_viva[0];
            destination_viva << "\n";
            line = match_viva.suffix();
        }
    }

    destination_ucom.close();
    destination_beeline.close();
    destination_viva.close();

    source.close();

    return 0;
}