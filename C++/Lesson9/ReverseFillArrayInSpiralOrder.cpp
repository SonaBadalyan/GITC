#include <iostream>
#include <iomanip>

int main()
{
    int n = 8;
    int m = 9;

    int a[n][m];

    int row_start = 0;
    int colums_start = 0;
    int row_end = m - 1;
    int colums_end = n - 1;

    int x = n * m;

    while (x != 0)
    {
        for (int i = row_start; i <= row_end && x != 0; ++i)
        {
            a[colums_start][i] = x--;
        }

        for (int i = colums_start + 1; i <= colums_end && x != 0; ++i)
        {
            a[i][row_end] = x--;
        }

        for (int i = row_end - 1; i >= row_start && x != 0; --i)
        {
            a[colums_end][i] = x--;
        }

        for (int i = colums_end - 1 ; i > colums_start && x != 0; --i)
        {
            a[i][row_start] = x--;
        }

        ++row_start;
        ++colums_start;
        --row_end;
        --colums_end;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] < 10)
            {
                std::cout << "    " << a[i][j] << "  ";
            }
            else
            {
                std::cout << "   " << a[i][j] << "  ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    return 0;
}