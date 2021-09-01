#include <iostream>

class Complex
{
    public:

        Complex() = default;

        Complex(double real, double img) : real{real}, img{img} {}

        Complex& operator=(const Complex& rhs)
        {
            if(this == &rhs)
            {
                return *this;
            }

            real = rhs.real;
            img = rhs.img;

            return *this;
        }

        bool operator==(const Complex& rhs)
        {
            if(this == &rhs)
            {
                return true;
            }

            if (real == rhs.real && img == rhs.img)
            {
                return true;
            }

            return false;
        }

        bool operator!=(const Complex& rhs)
        {
            if (*this == rhs)
            {
                return false;
            }

            return true;
        }

        Complex operator+(const Complex& rhs)
        {
            Complex temp;

            temp.real = real + rhs.real;
            temp.img = img + rhs.img;

            return temp;
        }

        Complex operator-(const Complex& rhs)
        {
            Complex temp;

            temp.real = real - rhs.real;
            temp.img = img - rhs.img;

            return temp;
        }

        Complex operator/(const Complex& rhs)
        {
            Complex temp;

            temp.real = real / rhs.real;
            temp.img = img / rhs.img;

            return temp;
        }

        Complex operator*(const Complex& rhs)
        {
            Complex temp;

            temp.real = real * rhs.real;
            temp.img = img * rhs.img;

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
    Complex c1(12.3, 3.4);
    Complex c2(12.5, 3.4);

    if (c1 != c2)
    {
        std::cout << "Complex numbers are not equal." << std::endl;
    }
    else
    {
        std::cout <<  "Complex numbers are equal." << std::endl;
    }

    Complex c;

    c = c1 + c2;
    c.print();

    c = c1 - c2;
    c.print();

    c = c1 * c2;
    c.print();

    c = c1 / c2;
    c.print();

    c = c2;
    c.print();

    return 0;
}