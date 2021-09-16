#include<iostream>

double pow(double base, double exponent)
{
	double result = 1;

	while(exponent--)
	{
		result *= base;
	}

	return result;

}

int main()
{
	std::cout << pow(2, 0) << std::endl;

	return 0;
}
