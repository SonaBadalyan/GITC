#include <iostream>
#include <string>

class Person
{
    public:
    void set_name(std::string name)
    {
        this->name = name;
    }

    void set_surname(std::string surname)
    {
        this->surname = surname;
    }

    void set_age(int age)
    {
        this->age =age;
    }

    std::string get_name()
    {
        return name;
    }

    std::string get_surname()
    {
        return surname;
    }

    int get_age()
    {
        return age;
    }

    private:
    std::string name;
    std::string surname;
    int age;
};

int main()
{
    Person person;
    person.set_name("Jane");
    person.set_surname("Smith");
    person.set_age(18);

    std::cout << "Person name is " << person.get_name() << std::endl;
    std::cout << "Person surname is " << person.get_surname() << std::endl;
    std::cout << "Person age is " << person.get_age() << std::endl;

    return 0;
}