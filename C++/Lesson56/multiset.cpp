#include <iostream>
#include <set>
#include <string>

class Person
{
    public:

        std::string name;
        std::string surname;
        int age;

    public:

        Person(std::string name, std::string surname, int age)
        {
            this->name = name;
            this->surname = surname;
            this->age = age;
        }

        friend bool operator<(const Person& a, const Person& b)
        {
            if (a.age < b.age)
            {
                return true;
            }
            return false;
        }

};

int main()
{
    Person p("Armine", "Gevorkian", 23);

    std::multiset<Person> m;
    m.emplace(p);
    m.emplace(p);
    m.emplace(p);
    m.emplace(p);
    m.emplace(p);
    m.emplace(p);

    for(auto it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->name << "  " << it->surname << it->age << std::endl;
    }

    return 0;
}