#include <iostream>

class Math
{
    public:

        constexpr static double PI = 3.14;
        constexpr static double E = 2.7;

        static double pow(double base, double exponent)
        {
            double result = 1;

            while(exponent--)
            {
                result *= base;
            }

            return result;

        }

        static double abs(double number)
        {
            if (number < 0)
                return number * -1;

            return number;
        }

        static double max(double a, double b)
        {
            return a > b ? a : b;
        }

        static double min(double a, double b)
        {
            return a < b ? a : b;
        }

        static int factorial(int n)
        {
            if (1 == n)
            {
                return 1;
            }

            return n * factorial(n - 1);
        }
        
        static int fibonacci(int n)
        {
            if ( n == 0 || n == 1)
                return n;

            return fibonacci(n - 1) + fibonacci(n - 2);
        }

        static void swap(int &value1, int &value2)
        {
            value1 = value1 ^ value2;
            value2 = value1 ^ value2;
            value1 = value1 ^ value2; 
        }

        static void bubble_sort(int *array, int SIZE)
        {
            bool b = true;

            while (b)
            {
                b = false;
                int i = 0;

                while ( i < SIZE - 1 )
                {
                    if (array[i + 1] < array[i])
                    {
                        swap(array[i + 1], array[i]);
                        b = true; 
                    }
                    ++i;
                }
            }
        }

        static void shaker_sort(int *array, int SIZE)
        {
            bool b = true;

            int size = SIZE;

            while (b)
            {
                b = false;
                int i = 0;

                while ( i < size - 1 )
                {
                    if (array[i + 1] < array[i])
                    {
                        swap(array[i + 1], array[i]);
                        b = true; 
                    }
                    ++i;
                }
                --size;
            }
        }

        static void stupid_sort(int *array, int SIZE)
        {
            int i = 0;

            while (i < SIZE - 1)
            {
                if (array[i + 1] < array[i])
                {
                    swap(array[i + 1], array[i]);
                    i = -1;     
                }
                ++i;
            }
        }

};

int main()
{
    std::cout << Math::factorial(3) << std::endl;
    std::cout << Math::fibonacci(15) << std::endl;
    std::cout << Math::abs(-1) << std::endl;
    std::cout << Math::min(2, 4) << std::endl;
    std::cout << Math::max(2, 4) << std::endl;

    return 0;
}