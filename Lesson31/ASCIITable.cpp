#include<iostream>

int main()
{
    for (int i = 0; i < 256; ++i)
    {
        std::cout << i << " : " << char(i) << std::endl;
    }

    return 0;
}
