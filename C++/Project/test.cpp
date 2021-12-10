#include <iostream>

class Base
{
    public:
        Base()
        {
            foo();
        }

        virtual void foo()
        {
            std::cout << "Base foo" << std::endl;
        }

    private:
};

class Dir : public Base
{
    public:
    virtual void foo()
    {
        std::cout << "Dir foo" << std::endl;
    }
};

int main()
{
    Dir b;

    return 0;
}
