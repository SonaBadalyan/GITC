// An hourglass in  is a subset of values with indices falling in this pattern in 's graphical representation:

// a b c
//   d
// e f g

// There are 16 hourglasses in 2D array. An hourglass sum is the sum of an hourglass values.
// Calculate the hourglass sum for every hourglass in 2D array, then print the maximum hourglass sum. 
//The array will always be 6X6.

#include<iostream>
#include <bits/stdc++.h>

const int SIZE = 6;

int hourglassSumMax(int arr[][SIZE])
{
    int max = INT_MIN;
    int curr_max = 0;

    for (int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            curr_max = arr[j][i] + arr[j][i + 1] + arr[j][i + 2] + arr[j + 1][i + 1] + arr[j + 2][i] + arr[j + 2][i + 1] + arr[j + 2][i + 2];

            if (max < curr_max)
            {
                max = curr_max; 
            }
        }
    }

    return max;
}

int main()
{
    int array[SIZE][SIZE] = 
    {
        {  0, -4, -6,  0, -7, -6 },
        { -1, -2, -6, -8, -3, -1 },
        { -8, -4, -2, -8, -8, -6 },
        { -3, -1, -2, -5, -7, -4 },
        { -3, -5, -3, -6, -6, -6 },
        { -3, -6,  0, -8, -6, -7 }
    };

    std::cout << "Max : " << hourglassSumMax(array) <<std::endl;

    return 0;
}