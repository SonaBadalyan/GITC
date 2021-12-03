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

        switch (currency)
        {
        case 1:
        {
            std::cout << AMD_amount << " AMD = " << AMD_amount / 492 << " US Dollar." << std::endl;
            break;
        }
        case 2:
        {
            std::cout << AMD_amount << " AMD = " << AMD_amount / 581  << " Euro." << std::endl;
            break;
        }
        case 3:
        {
            std::cout << AMD_amount << " AMD = " << AMD_amount / 6.60 << " Russian ruble." << std::endl;
            break;
        }
        default: 
        {
            std::cout << "Wrong input!" << std::endl;
            break;
        }
        }
         
        std::cout << "Do you want to continue? \n Type 1 to continue or anything to terminate the program." << std::endl;  

        int answer;
        std::cin >> answer;

        switch (answer)
        {
        case 1:
        {
            break;
        }
        default:
        {
            flag = false;
            break;
        }
            
        }
                    
    }
    return 0;
}
