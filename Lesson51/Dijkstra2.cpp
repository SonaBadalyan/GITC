#include <iostream>

int main()
{
    const int citiesCount = 9;

    std::string cities[citiesCount] = 
    { 
        "Gyumri", 
        "Vanadzor", 
        "Maralik", 
        "Abovyan",
        "Artik", 
        "Ashtarak", 
        "Ijevan",
        "Dilijan",
        "Yerevan"
    };

    int adjacencyMatrix[citiesCount][citiesCount] = 
    {
        { 0,  40, 20,  0,  0,  0,  0,  0,  0  },
        { 40, 0,  0,   60, 0,  0,  25, 0,  0  },
        { 20, 0,  0,   10, 10, 0,  0,  0,  0  },
        { 0,  60, 120, 0,  0,  30, 0,  45, 0  },
        { 0,  0,  10,  0,  0,  80, 0,  0,  0  },
        { 0,  0,  0,   30, 80, 0,  0,  0,  10 },
        { 0,  25, 0,   0,  0,  0,  0,  5,  0  },
        { 0,  0,  0,   45, 0,  0,  5,  0,  55 },
        { 0,  0,  0,   0,  0,  10, 0,  55, 0  }
    };

    int citiesWeight[citiesCount] = {INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX};

    std::cout << "Please enter a city name and the program will calculate all cities weights." << std::endl;

    std::string city;
    std::cin >> city;

    bool ifFound = false;

    int i = 0;

    for (; i < citiesCount; ++i)
    {
        if (city == cities[i])
        {
            ifFound = true;
            citiesWeight[i] = 0;
            break;
        }
    }

    if (ifFound)
    {
        for (int n = i; n < citiesCount; ++n)
        {
            for (int k = 0; k < citiesCount; ++k)
            {
                if(adjacencyMatrix[n][k] && citiesWeight[n] + adjacencyMatrix[n][k] < citiesWeight[k])
                {
                    citiesWeight[k] = citiesWeight[n] + adjacencyMatrix[n][k];
                }
            }
        }

        if (0 != i)
        {
            for (int n = i; n != 0; --n)
            {
                for (int k = 0; k < citiesCount; ++k)
                {
                    if(adjacencyMatrix[n][k] && citiesWeight[n] + adjacencyMatrix[n][k] < citiesWeight[k])
                    {
                        citiesWeight[k] = citiesWeight[n] + adjacencyMatrix[n][k];
                    }
                }
             }
        }
    }
    else
    {
        std::cout << "You have entered an unknown city name." << std::endl;
    }

    for (i = 0; i < citiesCount; ++i)
    {
        std::cout << "City : " << cities[i] << ", weight : " << citiesWeight[i] << std::endl;
    }

    return 0;
}