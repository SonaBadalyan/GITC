#include <iostream>

int main()
{
    bool general_flag = true;

    while (general_flag)
    {
        double AMD_amount = 0.0;
        bool AMD_amount_flag = true;
        
        while (AMD_amount_flag)
        {
            std::cout << "Please enter the AMD amount and it will be converted to your chosen currency." << std::endl;

            std::cin >> AMD_amount;
            
            if (AMD_amount >= 0.0)
            {
                AMD_amount_flag = false;
            }
            else
            {
                std::cout << "AMD amount must be positive number. Please enter positive number." << std::endl;
            }
        }

        bool currency_flag = true;
        
        while (currency_flag)
        {
            std::cout << "Please choose currency." << std::endl;
            std::cout << "1. US Dollar." << std::endl;
            std::cout << "2. Euro." << std::endl;
            std::cout << "3. Russian ruble." << std::endl;
    
            int currency = 0;
            std::cin >> currency;
    
            if (1 == currency) 
            {
                std::cout << AMD_amount << " AMD = " << AMD_amount / 492 << " US Dollar." << std::endl;
                currency_flag = false;
            }
            else if (2 == currency)
            {
                std::cout << AMD_amount << " AMD = " << AMD_amount / 581 << " Euro." << std::endl;
                currency_flag = false;
            }
            else if (3 == currency)
            {
                std::cout << AMD_amount << " AMD = " << AMD_amount / 6.60 << " Russian ruble." << std::endl;
                currency_flag = false;
            }
            else
            {
                std::cout << "Wrong input! Please choose from suggested options." << std::endl;
            }
        }
         
         
        bool answer_flag = true;
        
        while (answer_flag)
        {
            std::cout << "Do you want to continue? \n Type 1 to continue or 2 to terminate the program." << std::endl;  
    
            int answer;
            std::cin >> answer;
    
            if (2 == answer)
            {
                answer_flag = false;
                general_flag = false;
            }
            else if (1 == answer)
            {
                answer_flag = false;
            }
            else
            {
                std::cout << "Please press 1 or 2." << std::endl;
            }
        }
                    
    }

    return 0;
}
