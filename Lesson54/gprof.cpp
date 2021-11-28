#include <iostream>

void f1()
{
    for (int i = 0; i < 256; ++i)
    {
        char c = (char)i;
        std::cout << i << " : " << c << std::endl;
    }
}

void f2()
{
    for (int i = 0; i < 100000; ++i)
    {
        int x = 10000;
    }
}

void f3()
{
    for (int i = 0; i < 256; ++i)
    {
        int k = k * k;
    }
}

int main()
{
    f1();
    f1();
    f1();
    f2();
    f2();
    f3();

    // we may use -pf option for compiling with gprof. ( g++ -pg gprof.cpp)
    // it will be generat gmon.out file.
    // that file we can use as source file for gprof tool. Redirecting output to the text file we may see profileing information. (.gprof ./a.out gmon.out > output.txt)
    
    return 0;
}