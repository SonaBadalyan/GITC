#include <iostream>
#include <array>
#include <map>
#include <random>

int main()
{
    const int SIZE = 4;
    std::array<std::array<int, SIZE>, SIZE> array;

    for (int i = 0; i < array.size(); ++i)
    {
        for (int j = 0; j < array[0].size(); ++j)
        {
            array[i][j] = random() % 90 + 10;
        }
    }

    std::array<int, (SIZE * SIZE - SIZE) / 2> keys;
    int k = 0;

    std::array<int, (SIZE * SIZE - SIZE) / 2> values;
    int v = 0;

    for (int i = 0; i < array.size(); ++i)
    {
        for (int j = 0; j < array[0].size(); ++j)
        {
            std::cout << array[i][j] << " ";
            if ( i < j )
            {
                keys[k++] = array[i][j];
            }
            if ( j < i)
            {
                values[v++] = array[i][j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::map<int, int> m;

    for(int i = 0; i < k; ++i)
    {
        m.emplace(keys[i], values[i]);
    }

    std::cout << "______________" <<std::endl;

    for(auto& elem : m)
    {
        std::cout << elem.first << " " << elem.second << std::endl;
    }

    std::cout << std::endl;

    return 0;
}