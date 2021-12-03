#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car
{
    protected:

        double speed;
        double power;
        int years;

    public:

        Car()
        {
            speed = 0.0;
            power = 0.0;
            years = 0;
        }

        Car(double speed, double power, int years)
        {
            this->speed = speed;
            this->power = power;
            this->years = years;
        }

        friend bool operator<(const Car& a, const Car& b)
        {
            return a.speed < b.speed;
        }

        friend bool byPower(const Car& a, const Car& b)
        {
            return a.power < b.power;
        }

        friend bool byYears(const Car& a, const Car& b)
        {
            return a.years < b.years;
        }

        friend std::istream& operator>>(std::istream& input, Car& c)
        {
            std::cout << "Please enter car paramenetrs." << std::endl;
            
            std::cout << "Speed : ";
            input >> c.speed;

            std::cout << "Power : ";
            input >> c.power;

            std::cout << "Years : ";
            input >> c.years;

            return input;
        }

        friend std::ostream& operator<<(std::ostream& output, const Car& c)
        {
            output << "Car parameters are. " << std::endl;
            output << "Speed : " << c.speed << std::endl;
            output << "Power : " << c.power << std::endl;
            output << "Years : " << c.years << std::endl;

            return output;
        }
};

#endif // CAR_H