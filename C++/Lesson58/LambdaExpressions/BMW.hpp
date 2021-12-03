#ifndef BMW_H
#define BMW_H
#include <iostream>
#include "Car.hpp"
#include "Product.hpp"

class BMW : public Car, public Product
{
    public:
        BMW() : Car(), Product() {}

        BMW(double speed, double power, int years, double volume, double price, double weight) : 
            Car(speed, power, years), 
            Product(volume, price, weight)
        {}

        friend std::ostream& operator<<(std::ostream& output, const BMW& bmw)
        {
            output << "BMW parameters are." << std::endl;
            output << "Speed : " << bmw.speed << std::endl;
            output << "Power : " << bmw.power << std::endl;
            output << "Years : " << bmw.years << std::endl;
            output << "Volume : " << bmw.volume << std::endl;
            output << "Price : " << bmw.price << std::endl;
            output << "Weight : " << bmw.weight << std::endl;

            return output;
        }

        friend std::istream& operator>>(std::istream& input, BMW& bmw)
        {
            std::cout << "Please enter BMW parameters." << std::endl;

            std::cout << "Speed : ";
            input >> bmw.speed;

            std::cout << "Power : " ;
            input >> bmw.power;

            std::cout << "Years : ";
            input >> bmw.years;

            std::cout << "Volume : ";
            input >> bmw.volume;

            std::cout << "Price : ";
            input >> bmw.price;

            std::cout << "Weight : ";
            input >> bmw.weight;

            return input;
        }

        friend bool operator<(const BMW& a, const BMW& b);
        friend bool byPower(const BMW& a, const BMW& b);
        friend bool byYears(const BMW& a, const BMW& b);
        friend bool byVolume(const BMW& a, const BMW& b);
        friend bool byPrice(const BMW& a, const BMW& b);
        friend bool byWeight(const BMW& a, const BMW& b);
};

bool operator<(const BMW& a, const BMW& b)
{
    return a.speed < b.speed;
}

bool byPower(const BMW& a, const BMW& b)
{
    return a.power < b.power;
}

bool byYears(const BMW& a, const BMW& b)
{
    return a.years < b.years;
}

bool byVolume(const BMW& a, const BMW& b)
        {
    return a.volume < b.volume;
}

bool byPrice(const BMW& a, const BMW& b)
{
    return a.price < b.price;
}

bool byWeight(const BMW& a, const BMW& b)
{
    return a.weight < b.weight;
}

#endif // BMW_H