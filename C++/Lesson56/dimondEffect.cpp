#include <iostream>

class Car
{
    public:
        virtual void speed() = 0;
        virtual void power() = 0;
};

class Jeep: virtual public Car
{
    public:
        void speed() override
        {
            std::cout << "250 km/h" << std::endl;
        }

        void power() override
        {
            std::cout << "400 house power" << std::endl;
        }

};

class Luxury : virtual  public Car
{
    public:
        void speed() override
        {
            std::cout << "222 km/h" << std::endl;
        }

        void power() override
        {
            std::cout << "333 house power" << std::endl;
        }
};

class Cayenne : public Jeep, public Luxury
{
    public:
        void speed() override
        {
           Jeep::speed();
        }

        void power() override
        {
           Luxury::power();
        }

};

int main()
{
    Cayenne c;
    c.power();
    c.speed();

    return 0;
}