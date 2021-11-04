#include <iostream>

int main()
{
    const int vertexCount = 9;

    std::string cities[vertexCount] = {"Gyumri", "Vanadzor", "Maralik", "Abovyan", "Artik", "Ashtarak", "Ijevan", "Dilijan", "Yerevan"};

    int adjacencyMatrix[vertexCount][vertexCount] = 
    {
        { 0,  40, 20,  0,  0,  0,  0,  0,  0 },
        { 40, 0,  0,   60, 0,  0,  25, 0,  0 },
        { 20, 0,  0,   10, 10, 0,  0,  0,  0 },
        { 0,  60, 120, 0,  0,  30, 0,  45, 0 },
        { 0,  0,  10,  0,  0,  80, 0,  0,  0 },
        { 0,  0,  0,   30, 80, 0,  0,  0,  10 },
        { 0,  25, 0,   0,  0,  0,  0,  5,  0 },
        { 0,  0,  0,   45, 0,  0,  5,  0,  55 },
        { 0,  0,  0,   0,  0,  10, 0,  55, 0 }
    };

    std::cout << "Please enter a city name and the program will output all adjacent cities distance." << std::endl;

    std::string city;

    std::cin >> city;

    bool ifFound = false;
    bool adjCity = false;

    for (int i = 0; i < vertexCount; ++i)
    {
        if (city == cities[i])
        {
            ifFound = true;

            for(int j = 0; j < vertexCount; ++j)
            {
                if (adjacencyMatrix[i][j])
                {
                    adjCity = true;

                    std::cout << "Distance from the " << cities[i] << " to " << cities[j] << " is "  << adjacencyMatrix[i][j] << "km." << std::endl;
                }
            }
        }
    }

    if (!adjCity)
    {
        std::cout << "Your entered city doesn't have any adjacency city." << std::endl;
    }

    if (!ifFound)
    {
        std::cout << "You have entered an unknown city name." << std::endl;
    }

    return 0;
}