#include <iostream>

int main()
{
    bool flag = true;

    while (flag)
    {
        std::cout << "Please enter the AMD amount and it will be converted to your chosen currency." << std::endl;

        double AMD_amount = 0.0;
        std::cin >> AMD_amount;

        std::cout << "Please choose currency." << std::endl;
        std::cout << "1. US Dollar." << std::endl;
        std::cout << "2. Euro." << std::endl;
        std::cout << "3. Russian ruble." << std::endl;

        int currency = 0;
        std::cin >> currency;

        std::cout << "Please enter today's currency exchange rate." << std::endl;

        double rate = 0.0;
        std::cin >> rate;

        std::cout << AMD_amount << " AMD = " << AMD_amount / rate;

        if (1 == currency) 
            std::cout << " US Dollar." << std::endl;
        else if (2 == currency)
            std::cout << " Euro." << std::endl;
        else if (3 == currency)
            std::cout << " Russian ruble." << std::endl;
        else
            std::cout << "Wrong input!" << std::endl;
         
        std::cout << "Do you want to continue? \n Type \"yes\" to continue or anything to terminate the program." << std::endl;  

        std::string answer;
        std::cin >> answer;

        if ("yes" != answer)
            flag = false;
                    
    }

    return 0;
}