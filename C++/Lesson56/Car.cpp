#include <iostream>
#include <set>

class Car
{
    protected:

        double price = 0.0;

    public:

        Car(double price)
        {
            this->price = price;
        }

        void print() const 
        {
            std::cout << "Price : " << price << std::endl;
        }

        friend bool operator<(const Car& a, const Car& b);
};

bool operator<(const Car& a, const Car& b)
{
    if(a.price < b.price)
    {
        return true;
    }
    return false;
}

int main()
{
    std::multiset<Car> m;
    
    m.emplace(Car(1800.80));
    m.emplace(Car(1900.80));
    m.emplace(Car(2000.80));
    m.emplace(Car(500));

    for(auto& elem : m)
    {
        elem.print();
    }

    return 0;
}