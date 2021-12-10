#include "Calculator.hpp"
#include <iostream>
#include <string>

enum operation { add = 1, subtract = 2, multiply = 3, divide = 4 };

double getOperand()
{
    std::cout << "Please enter operand: ";

    double firstOperand = 0.0;
    std::cin >> firstOperand;

    return firstOperand;
}

int main()
{
    std::cout << " _________________Calculator!____________________" << std::endl;
    
    bool continueCalculate = true;

    do
    {
        Calculator calculator(getOperand(), getOperand());

        std::cout << "Please enter operation number ( 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division or any other number for exit): ";
        int operation;
        std::cin >> operation;

        switch (operation)
        {
            case add:
            {
                std::cout << "Addition result is equal to " << calculator.add() << std::endl;
                break;
            }
            case subtract:
            {
                std::cout << "Subtraction result is equal to " << calculator.subtract() << std::endl;
                break;
            }
            case multiply:
            {
                std::cout << "Multiplication result is equal to " << calculator.multiply() << std::endl;
                break;
            }
            case divide:
            {
                try
                {
                    std::cout << "Division result is equal to " << calculator.divide() << std::endl;
                    break;
                }
                catch(const std::logic_error& e)
                {
                    continueCalculate = false;
                    std::cout << e.what() << '\n';
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