#include <string>
#include <iostream>

class Mlass
{
    private:
        std::string name;
    
    public:
        void foo(){}

        std::string getName() const 
        {
            // foo(); error: passing ‘const Mlass’ as ‘this’ argument discards qualifiers 
            
            return name;
        }
};

int main()
{
    const Mlass m;
    std::cout << m.getName() << std::endl; // if getName is nonconst, error: passing ‘const Mlass’ as ‘this’ argument discards qualifiers 

    return 0;
}