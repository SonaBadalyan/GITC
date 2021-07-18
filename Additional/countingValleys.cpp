#include<iostream>
#include<string>

// An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly  steps, for every step it was noted if it was an uphill, , or a downhill,  step. Hikes always start and end at sea level, and each step up or down represents a  unit change in altitude. We define the following terms:

// A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
// A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.
// Given the sequence of up and down steps during a hike, find and print the number of valleys walked through

int countingValleys(int steps, std::string path) 
{
    int count = 0;
    int valley = 0;

    for (int i = 0; i < steps; ++i)
    {
        if ('U' == path[i])
        {
            ++valley;

            if ( 0 == valley)
            {
                ++count;
            }
        }
        else
        {
            --valley;
        }
    }

    return count;
}

int main()
{
    std::string path = "UDDDUDUU";
    std::cout << "Valleys count are equal to " << countingValleys(path.size(), path) << std::endl;

    return 0;
}