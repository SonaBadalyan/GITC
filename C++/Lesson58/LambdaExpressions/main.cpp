#include "BMW.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    // BMW b;
    // std::cin >> b;
    // std::cout << b << std::endl;

    std::vector<BMW> vec;
    vec.push_back(BMW(220, 120, 9, 1000, 10000, 160));
    vec.push_back(BMW(320, 230, 6, 1200, 40000, 300));
    vec.push_back(BMW(300, 500, 5, 2000, 24000, 500));
    vec.push_back(BMW(120, 100, 2, 1400, 5000, 290));
    vec.push_back(BMW(100, 200, 10, 1500, 2500, 340));
    // vec.push_back(b);

    std::cout << "__________Befor sorting._______" << std::endl;

    for (auto const& car: vec)
    {
        std::cout << car <<std::endl;
    }

    std::sort(vec.begin(), vec.end(), [](const BMW& a, const BMW& b){return a.speed < b.speed;});

    std::cout << "__________After sorting by speed._______" << std::endl;

    for (auto const& car: vec)
    {
        std::cout << car <<std::endl;
    }

    std::sort(vec.begin(), vec.end(), [](const BMW& a, const BMW& b){return a.power < b.power;});

    std::cout << "__________After sorting by power._______" << std::endl;

    for (auto const& car: vec)
    {
        std::cout << car <<std::endl;
    }

    std::sort(vec.begin(), vec.end(), [](const BMW& a, const BMW& b){return a.years < b.years;});

    std::cout << "__________After sorting by years._______" << std::endl;

    for (auto const& car: vec)
    {
        std::cout << car <<std::endl;
    }

    std::sort(vec.begin(), vec.end(), [](const BMW& a, const BMW& b){return a.volume < b.volume;});

    std::cout << "__________After sorting by volume._______" << std::endl;

    for (auto const& car: vec)
    {
        std::cout << car <<std::endl;
    }

    std::sort(vec.begin(), vec.end(), [](const BMW& a, const BMW& b){return a.price < b.price;});

    std::cout << "__________After sorting by price._______" << std::endl;

    for (auto const& car: vec)
    {
        std::cout << car <<std::endl;
    }
    
    std::sort(vec.begin(), vec.end(), [](const BMW& a, const BMW& b){return a.weight < b.weight;});

    std::cout << "__________After sorting by weight._______" << std::endl;

    for (auto const& car: vec)
    {
        std::cout << car <<std::endl;
    }

    return 0;
}