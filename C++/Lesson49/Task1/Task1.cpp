#include <iostream>

class MyException
{
    public:

        MyException(std::string reason, std::string solution, int number ) : m_reason(reason), m_solution(solution), m_number(number) {}

        void print() const
        {
            std::cout << "Exception " << m_number << " arise because of \"" << m_reason << "\" reason." << std::endl;
            std::cout << "You can solve it by applying of \"" << m_solution << "\" solution." << std::endl;
        }

    private:

        std::string m_reason;
        std::string m_solution;
        int m_number;
};

int divade(int dividend, int divisor)
{
    if (0 == divisor)
    {
        std::string reason = "Try to divade " + std::to_string(dividend) + " by zero.";

        std::string solution = "You must enter number different from zero.";
        int number = 0;

        throw MyException(reason, solution, number);
    }

    return dividend / divisor;
}

int main()
{
    std::cout << "Please enter a number and the program will divide 24 to the entered number." << std::endl;
     
    int divisor = 0;
    std::cin >> divisor;

    try
    {
        int quotient = divade(24, divisor);
        std::cout << "Quotient: " << quotient << std::endl;
    }
    catch(const MyException& exception)
    {
        exception.print();
    }

    return 0;
}