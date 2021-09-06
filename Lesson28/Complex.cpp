#include <iostream>

class Complex
{
    public:

        Complex() = default;

        Complex(double real, double img) : real{real}, img{img} {}

        Complex& operator++() // postfix
        {
            ++real;
            ++img;

            return *this;
        }

        Complex operator++(int) // prefix
        {
            Complex temp;

            temp.real = real;
            temp.img = img;

            ++real;
            ++img;

            return temp;
        }

        void print()
        {
            std::cout << "__________" << this << " object _____________" << std::endl;
            std::cout << "Real : " << real << std::endl;
            std::cout << "Imaginary : " << img << std::endl;
            std::cout << std::endl;
        }

    private:

        double real;
        double img;

};

int main()
{
    Complex c(12.8, 3.4);
    c.print();

    c++;
    c.print();

    ++c;
    c.print();

    return 0;
}