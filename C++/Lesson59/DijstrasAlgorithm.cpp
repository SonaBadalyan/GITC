#include <iostream>
#include <vector>
#include <string>

void checkoutPath
                (
                    const int CITIES_COUTNT,
                    const std::string cities[],
                    std::vector<std::string>& shortestPath,
                    const int adjacencyMatrix[][9], 
                    int citiesWeight[],                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                    bool chaked[], 
                    const int curr,
                    const std::string to
                )
{
    if (to == cities[curr] || chaked[curr])
        return;

    int min = -1;
    int index = 0;
    int weight = 0;

    for (int k = 0; k < CITIES_COUTNT; ++k)
    {
        if(adjacencyMatrix[k][curr] && citiesWeight[curr] + adjacencyMatrix[k][curr] < citiesWeight[k])
        {
            weight = citiesWeight[curr] + adjacencyMatrix[k][curr];

            if (-1 == min || min > weight)
            {
                min = weight;
                index = k;
            }
        }
    }

    citiesWeight[index] = weight;
    chaked[curr] = true;
    shortestPath.push_back(cities[index]);

    checkoutPath 
                (                        
                    CITIES_COUTNT,
                    cities,
                    shortestPath,
                    adjacencyMatrix, 
                    citiesWeight,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                    chaked, 
                    index,
                    to
                );

}

void Dijkstra
            ( 
                const int CITIES_COUTNT,
                const std::string cities[],
                std::vector<std::string>& shortestPath,
                const int adjacencyMatrix[][9], 
                const std::string from,
                const std::string to
            )
{
    int citiesWeight[CITIES_COUTNT] = 
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

    bool chaked[CITIES_COUTNT] =  { 0,  0,  0,  0,  0,  0,  0,  0,  0 };

    bool fromFound = false;
    bool toFound = false;

    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; i < CITIES_COUTNT; ++i)
    {
        if (from == cities[i])
        {
            fromFound = true;
            citiesWeight[i] = 0;
            startIndex = i;
        }

        if (to == cities[i])
        {
            toFound = true;
            endIndex = i;
        }

        if (fromFound && toFound)
        {
            break;
        }
    }

    if (fromFound && toFound)
    {
        checkoutPath 
                    (                        
                        CITIES_COUTNT,
                        cities,
                        shortestPath,
                        adjacencyMatrix, 
                        citiesWeight,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                        chaked, 
                        startIndex,
                        to
                    );
    }
    else
    {
        std::cout << "You have entered an unknown city name: ";

        if (!fromFound)
            std::cout << from << std::endl;
        
        if (!toFound)
            std::cout << to << std::endl;
    }
}

int main()
{
    const int CITIES_COUNT = 9;

    const std::string cities[CITIES_COUNT] = 
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

    const int adjacencyMatrix[CITIES_COUNT][CITIES_COUNT] = 
    {
        { 0,  40, 20,  0,   0,  0,  0,  0,  0  },
        { 40, 0,  0,   60,  0,  0,  25, 0,  0  },
        { 20, 0,  0,   120, 10, 0,  0,  0,  0  },
        { 0,  60, 120, 0,   0,  30, 0,  45, 0  },
        { 0,  0,  10,  0,   0,  80, 0,  0,  0  },
        { 0,  0,  0,   30,  80, 0,  0,  0,  10 },
        { 0,  25, 0,   0,   0,  0,  0,  5,  0  },
        { 0,  0,  0,   45,  0,  0,  5,  0,  55 },
        { 0,  0,  0,   0,   0,  10, 0,  55, 0  }
    };

    std::cout << "Please enter source and destination cities names and the program will print the shortest path between them." << std::endl;
    
    std::cout << " From : ";
    std::string from;
    std::cin >> from;

    std::cout << " To : ";
    std::string to;
    std::cin >> to;

    std::vector<std::string> shortestPath;
    shortestPath.push_back(from);

    Dijkstra
    (  
        CITIES_COUNT, 
        cities, 
        shortestPath,
        adjacencyMatrix, 
        from,
        to
    );

    for (int i = 0; i < shortestPath.size(); ++i)
    {
        std::cout << shortestPath[i];

        if ( i == shortestPath.size() - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " -> ";
        }
        
    }

    return 0;
}