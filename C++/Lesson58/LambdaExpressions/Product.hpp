#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product
{
    public:

        double volume;
        double price;
        double weight;

    public:
        Product()
        {
            volume = 0.0;
            price = 0.0;
            weight = 0.0;
        }

        Product(double volume, double price, double weight)
        {
            this->volume = volume;
            this->price = price;
            this->weight = weight;
        }

        friend bool operator<(const Product& a, const Product& b)
        {
            return a.volume < b.volume;
        }

        friend bool byPrice(const Product& a, const Product& b)
        {
            return a.price < b.price;
        }

        friend bool byWeight(const Product& a, const Product& b)
        {
            return a.weight < b.weight;
        }

        friend std::istream& operator>>(std::istream& input, Product& p)
        {
            std::cout << "Please enter product paramenetrs." << std::endl;
            
            std::cout << "Volume : ";
            input >> p.volume;

            std::cout << "Price : ";
            input >> p.price;

            std::cout << "Weight : ";
            input >> p.weight;

            return input;
        }

        friend std::ostream& operator<<(std::ostream& output, const Product& p)
        {
            output << "Product parameters are. " << std::endl;
            output << "Volume : " << p.volume << std::endl;
            output << "Price : " << p.price << std::endl;
            output << "Weight : " << p.weight << std::endl;

            return output;
        }
};

#endif // PRODUCT_H