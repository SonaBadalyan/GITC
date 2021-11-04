#include <iostream>

int main()
{
    const int vertexCount = 9;

    std::string cities[vertexCount] = {"Gyumri", "Vanadzor", "Maralik", "Abovyan", "Artik", "Ashtarak", "Ijevan", "Dilijan", "Yerevan"};

    bool adjacencyMatrix[vertexCount][vertexCount] = 
    {
        { 0, 1, 1, 0, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 1, 1, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0, 0, 0, 1 },
        { 0, 1, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 1, 0, 1, 0 }
    };

    std::cout << "Please enter a city name and the program will output all adjacent cities names." << std::endl;

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

                    std::cout << cities[j] << std::endl;
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