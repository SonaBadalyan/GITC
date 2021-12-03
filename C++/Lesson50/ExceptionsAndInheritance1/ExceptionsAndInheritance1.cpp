#include <iostream>
#include <stdexcept>

class DividebyZeroException : public std::runtime_error
{
    public:

        DividebyZeroException(const char* reason) : std::runtime_error(reason)
        {
            this->m_reason = reason;
        }

        const char* what() const noexcept
        {
            return m_reason;
        }

    private:

        const char* m_reason;
};

int divade(int dividend, int divisor) 
{
    if (0 == divisor)
    {
        throw DividebyZeroException( "Can't divide by zero!");
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
    catch(DividebyZeroException exception)
    {
        std::cout << exception.what() << std::endl;
    }
    catch(std::runtime_error er)
    {
        std::cout << er.what() << std::endl;
    }

    return 0;
}