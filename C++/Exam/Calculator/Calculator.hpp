#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

class Calculator
{
    private:
        double m_firstOperand = 0.0;
        double m_secondOperand = 0.0;

    public:
        Calculator(double firstOperand, double secondOperand) : m_firstOperand(firstOperand), m_secondOperand(secondOperand) 
        {}

        double add();
        double subtract();
        double multiply();
        double divide(); 
};

#endif //CALCULATOR_HPP