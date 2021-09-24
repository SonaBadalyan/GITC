#include <iostream>
#include <string>

template <typename T>
class Person
{
    public:
        Person(std::string name, std::string surname, T age) : name(name), surname(surname), age(age)
        {
            ++count;
        }

        ~Person()
        {
            --count;
        }

        static int getCount()
        {
            return count;
        }

    private:
        std::string name;
        std::string surname;
        T age;
        static int count;
};

template<>
int Person<int>::count = 0;

int main()
{
    Person<int> p1("Armen", "Abrahamyan", 23);
    Person<int> p2("Vardges", "Kirakosyan", 34);
    Person<int> p3("Ashot", "Adibekyan", 56);
   
    std::cout << p1.getCount() << std::endl;
    
    return 0;
}