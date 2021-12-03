#include <iostream>
#include <iomanip>

int main()
{
    int n = 8;
    int m = 9;

    int a[n][m];

    int row_start = 0;
    int column_start = 0;
    int row_end = m - 1;
    int column_end = n - 1;

    int x = n * m;

    while (x != 0)
    {
        for (int i = column_start; i <= column_end && x != 0; ++i)
        {
            a[i][row_start] = x--;
        }

        for (int i = row_start + 1; i <= row_end && x != 0; ++i)
        {
            a[column_end][i] = x--;
        }

        for (int i = column_end - 1 ; i >= column_start && x != 0; --i)
        {
            a[i][row_end] = x--;
        }

        for (int i = row_end - 1; i > row_start && x != 0; --i)
        {
            a[row_start][i] = x--;
        }

        ++row_start;
        ++column_start;
        --row_end;
        --column_end;
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