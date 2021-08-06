#include <iostream>
#include <string>

class Person
{
    private:

        std::string name;
        std::string surname;
        int age;

    public:

        //constructor's overloading

        Person()
        {
            std::cout<<"Default constructor's call."<< std::endl;
        }

        Person(std::string name)
        {
            std::cout<< "Constructor(name)" << std::endl;

            this->name = name;
        }

        Person(std::string surname, bool)
        {
            std::cout<< "Constructor(surname, bool)" << std::endl;

            this->surname = surname;
        }

        Person(int age)
        {
            std::cout<< "Constructor(age)" << std::endl;

            this->age = age;
        }

        Person(std::string name, std::string surname, bool)
        {
            std::cout<< "Constructor(name, surname)" << std::endl;

            this->name = name;
            this->surname = surname;
        }

        Person(std::string name, int age)
        {
            std::cout<< "Constructor(name, age)" << std::endl;

            this->name = name;
            this->age = age;
        }

        Person(int age, std::string surname)
        {
            std::cout<< "Constructor(age, surname)" << std::endl;

            this->surname = surname;
            this->age = age;
        }

        Person(std::string name, std::string surname, int age)
        {
            std::cout<< "Constructor(name, surname, age)" << std::endl;

            this->name = name;
            this->surname = surname;
            this->age = age;
        }

        void print()
        {
            std::cout << "----------------------" << std::endl;
            std::cout << "name " << name << std::endl;
            std::cout << "surname " << surname << std::endl;
            std::cout << "age " << age << std::endl;
            std::cout << std::endl;
        }

        //---------getters------------

        std::string getName()
        {
            return name;
        }

        std::string getSurname()
        {
             return surname;
        }

        int getAge()
        {
             return age;
        }

        //----------setters------------

        void setName(std::string name)
        {
            this->name = name;
        }

        void setSurname(std::string surname)
        {
            this->surname = surname;
        }

        void setAge(int age)
        {
            this->age = age;
        }
};

int main()
{
    Person unnamed;
    unnamed.print();

    Person lilith("Lilith");
    lilith.print();

    Person gevorkian("Gevorkian", true);
    gevorkian.print();

    Person child(18);
    child.print();

    Person lilithGevorkian("Lilit", "Gevorkian", true);
    lilithGevorkian.print();

    Person lilith18("Lilit", 18);
    lilith18.print();

    Person gevorkian18(18, "Gevorkian");
    gevorkian18.print();

    Person lilithGevorkian18("Lilit", "Gevorkian", 18);
    lilithGevorkian18.print();

    return 0;
}