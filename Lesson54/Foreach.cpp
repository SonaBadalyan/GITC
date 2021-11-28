#include <iostream>
#include <array>

// void print (int arr[])
// {
//     for(int elem : arr) // Iterator error because C-style array doesn't know its own size.
//     {
//         std::cout << elem << std::endl;
//     }
// }


void print (std::array<int, 4> arr)
{
    for(auto elem : arr) 
    {
        std::cout << elem << std::endl;
    }
}

int main()
{
    //int arr[] = {10, 20, 30, 40};

    // for(int elem : arr)
    // {
    //     std::cout << elem << std::endl;
    // }

    //print(arr);

    std::array<int, 4> arr {10, 20, 30, 40};
    //print(arr);

    std::cout << "Array size is " << arr.size() << std::endl;

    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it <<std::endl;
    }

    std::cout << "_______________" << std::endl;

    for (auto rit = arr.rbegin(); rit != arr.rend(); ++rit)
    {
        std::cout << *rit << std::endl;
    }

    return 0;
}