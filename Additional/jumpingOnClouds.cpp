
// There is a new mobile game that starts with consecutively numbered clouds. 
// Some of the clouds are thunderheads and others are cumulus. 
// The player can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus  1 or 2. 
// The player must avoid the thunderheads. Determine the minimum number of jumps it will take to jump from the starting postion to the last cloud.
// It is always possible to win the game.

// For each game, you will get an array of clouds numbered 0 if they are safe or 1 if they must be avoided.

#include <iostream>
#include <vector>

int jumpingOnClouds(std::vector<int> c) 
{
    int count = 0;

    for (int i = 0; i < c.size() - 1;)
    {
        if ((i + 2) < c.size() && 0 == c[i + 2])
        {
            ++count;
            i = i + 2;
            continue;
        }
        
        if ((i + 1) < c.size() && 0 == c[i + 1])
        {
            ++count;
            i = i + 1;
            continue;
        }
    }
    return count;
}

int main()
{
    std::vector<int> clouds {0, 0, 0, 1, 0, 0};

    std::cout << jumpingOnClouds(clouds) << std::endl;

    return 0;
}