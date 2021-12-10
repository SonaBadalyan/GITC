#include "Calculator.hpp"
#include <stdexcept>

double Calculator::add()
{
    return m_firstOperand + m_secondOperand;
}

double Calculator::subtract()
{
    return m_firstOperand - m_secondOperand;
}

double Calculator::multiply()
{
    return m_firstOperand * m_secondOperand;
}

double Calculator::divide()
{
    if (0 == m_secondOperand)
    {

        throw std::logic_error("Division by zero!");
    }

    return m_firstOperand / m_secondOperand;
}