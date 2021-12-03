#include <iostream>

double pow(double base, double exponent)
{
	double result = 1;

	while(exponent--)
	{
		result *= base;
	}

	return result;
}

int converter(char* c, int size)
{
    int result = 0;

    for (int i = size - 1; i != -1; --i)
    {
        result += (c[i] - 48) * pow(10, size - 1 - i);
    }

    return result;
}

int main()
{
    char c[] = {'4', '3', '9', '8'};

    int x = converter(c, sizeof(c)/sizeof(c[0]));

    std::cout << x << std::endl;

    return 0;
}