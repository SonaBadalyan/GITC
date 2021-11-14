#include <iostream>
#include <vector>
#include <string>

void checkoutPath
                (
                    int citiesCount,
                    std::string cities[],
                    std::vector<std::string>& shortestPath,
                    int adjacencyMatrix[][9], 
                    int citiesWeight[],                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                    bool chaked[], 
                    int curr,
                    std::string to
                )
{
    if (to == cities[curr])
        return;

    int min = -1;
    int index = 0;

    for (int k = 0; k < citiesCount; ++k)
    {
        if(adjacencyMatrix[k][curr] && citiesWeight[curr] + adjacencyMatrix[k][curr] < citiesWeight[k])
        {
            citiesWeight[k] = citiesWeight[curr] + adjacencyMatrix[k][curr];

            if (-1 == min || min > citiesWeight[k])
            {
                min = citiesWeight[k];
                index = k;
            }
        }
    }

    shortestPath.push_back(cities[index]);

    chaked[curr] = true;
    
    checkoutPath 
                (                        
                    citiesCount,
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
                int citiesCount,
                std::string cities[],
                std::vector<std::string>& shortestPath,
                int adjacencyMatrix[][9], 
                std::string from,
                std::string to
            )
{
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

    bool fromFound = false;
    bool toFound = false;

    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; i < citiesCount; ++i)
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
                        citiesCount,
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
        if (!fromFound)
            std::cout << "You have entered an unknown city name: " << from << std::endl;
        
        if (!toFound)
            std::cout << "You have entered an unknown city name: " << to << std::endl;
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

    std::cout << "Please enter a cities names and the program will print the shortest path between them." << std::endl;
    
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
        citiesCount, 
        cities, 
        shortestPath,
        adjacencyMatrix, 
        from,
        to
    );

    for (auto const& it : shortestPath)
    {
        std::cout << it << " -> ";
    }

    std::cout << std::endl;

    return 0;
}