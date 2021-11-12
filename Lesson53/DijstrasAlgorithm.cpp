#include <iostream>

void calculateCitiesWeight
                        (
                            int citiesCount,
                            int adjacencyMatrix[][9], 
                            int citiesWeight[],                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                            bool chaked[], 
                            int n
                        )
{
    if (false == chaked[n])
    {
        for (int k = 0; k < citiesCount; ++k)
        {
            if(adjacencyMatrix[n][k] && citiesWeight[n] + adjacencyMatrix[n][k] < citiesWeight[k])
            {
                citiesWeight[k] = citiesWeight[n] + adjacencyMatrix[n][k];
            }
        }

        chaked[n] = true;

        for (int k = 0; k < citiesCount; ++k)
        {
            if(adjacencyMatrix[n][k])
            {           
                calculateCitiesWeight 
                                    (                        
                                        citiesCount,
                                        adjacencyMatrix, 
                                        citiesWeight,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                                        chaked, 
                                        k
                                    );
            }
        }
    }

    return;
}

void Dijkstra
            ( 
                int citiesCount,
                std::string cities[],
                int adjacencyMatrix[][9], 
                int citiesWeight[],                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                bool chaked[], 
                std::string city
            )
{
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
        calculateCitiesWeight 
                            (                        
                                citiesCount,
                                adjacencyMatrix, 
                                citiesWeight,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                                chaked, 
                                i
                            );
    }
    else
    {
        std::cout << "You have entered an unknown city name." << std::endl;
    }
}

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

    int citiesWeight[citiesCount] = 
    { 
        INT32_MAX,
        INT32_MAX, 
        INT32_MAX, 
        INT32_MAX, 
        INT32_MAX, 
        INT32_MAX, 
        INT32_MAX, 
        INT32_MAX, 
        INT32_MAX
    };

    bool chaked[citiesCount] =  { 0,  0, 0,  0,  0,  0,  0,  0,  0  };

    std::cout << "Please enter a city name and the program will calculate all cities weights." << std::endl;

    std::string city;
    std::cin >> city;

    Dijkstra
            (  
                citiesCount, 
                cities, 
                adjacencyMatrix, 
                citiesWeight, 
                chaked, 
                city
            );

    for (int i = 0; i < citiesCount; ++i)
    {
        std::cout << "City : " << cities[i] << ", weight : " << citiesWeight[i] << std::endl;
    }

    return 0;
    return 0;

}