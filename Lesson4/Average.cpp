#include <iostream>

int main()
{
    const int SIZE = 4;
    
    int array[SIZE];
    
    int sum = 0;
    
    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << "Please enter " << i + 1 << "-th elemt value : ";
        std::cin >> array[i];
        sum += array[i];
    }
    
    std::cout << "Average is equal to " << sum << " / " << SIZE << " = " << sum / SIZE << std::endl;
    
    return 0;
}
