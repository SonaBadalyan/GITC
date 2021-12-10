#include "Calculator.hpp"
#include <iostream>
#include <string>

enum operation { add = 1, subtract = 2, multiply = 3, divide = 4 };

double getOperand()
{
    std::cout << "Please enter operand value: ";

    double operand = 0.0;
    std::cin >> operand;

    return operand;
}

bool mustContinue()
{
    std::cout << "Are you want to continue? Type 1 for continue or anything for exit." << std::endl;

    int input;
    std::cin >> input;
    
    if (1 != input)
    {
        return false;
    }
    else
    {
        return true;
    }

}

int main()
{
    std::cout << " _________________Calculator!____________________" << std::endl;
    
    bool continueCalculate = true;

    do
    {
        Calculator calculator(getOperand(), getOperand());

        std::cout << "Please enter operation number ( 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division or anything else for exit): ";
        
        int operation;
        std::cin >> operation;

        switch (operation)
        {
            case add:
            {
                std::cout << "Addition result is equal to " << calculator.add() << std::endl;
                
                continueCalculate = mustContinue();

                break;
            }
            case subtract:
            {
                std::cout << "Subtraction result is equal to " << calculator.subtract() << std::endl;
                
                continueCalculate = mustContinue();

                break;
            }
            case multiply:
            {
                std::cout << "Multiplication result is equal to " << calculator.multiply() << std::endl;
                
                continueCalculate = mustContinue();
                
                break;
            }
            case divide:
            {
                try
                {
                    std::cout << "Division result is equal to " << calculator.divide() << std::endl;
                    
                    continueCalculate = mustContinue();
                
                    break;
                }
                catch(const std::logic_error& e)
                {
                    std::cout << e.what() << '\n';

                    continueCalculate = mustContinue();
                }
            }
            default:
            {
                std::cout << "Bye!" << std::endl;

                continueCalculate = false;

                break;
            }    
        }
    }
    while (continueCalculate);

    return 0;
}