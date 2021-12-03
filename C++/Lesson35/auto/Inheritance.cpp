#include<iostream>

template<typename X>
class Person
{
    public:
        Person()
        {
            std::cout << "Person class default constructor." << std::endl;
        }

        Person(std::string name, std::string surename, X age)
        {
            std::cout << "Person class constructor with parameters." << std::endl;

            this->name = name;
            this->surename = surename;
            this->age = age;
        }

        void setName(std::string name)
        {
            this->name = name;
        }

        void setSurname(std::string surname)
        {
            this->surename = surename;
        }

        void setAge(X age)
        {
            this->age = age;
        }

        const std::string& getName() const
        {
            return name;
        }

        const std::string& getSurname() const
        {
            return surename;
        }

        const X getAge() const
        {
            return age;
        }

        virtual void print() const
        {
            std::cout << "Person class print function." << std::endl;

            std::cout << "name = " << name << std::endl;
            std::cout << "surname = " << surename << std::endl;
            std::cout << "age = " << age << std::endl;
        }

    protected:
        std::string name;
        std::string surename;
        X age;
};

class Specialist : public Person<int>
{
    public:
        Specialist()
        {
            std::cout << "Specialis class default constructor." << std::endl;
        }

        Specialist(std::string name, std::string surename, int age, int iq, int languages) 
                    : Person(name, surename, age)
        {
            std::cout << "Specialist class constructor with parameters." << std::endl;

            this->iq = iq;
            this->languages = languages;
        }

        void setIQ(int iq)
        {
            this->iq = iq;
        }

        void setLanguages()
        {
            this->languages = languages;
        }

        const int getIQ() const
        {
            return iq;
        }

        const int getLanguages() const
        {
            return languages;
        }

        void print() const
        {
            Person::print();
            std::cout << "Specialist class print function." << std::endl;

            std::cout << "iq = " << iq <<std::endl;
            std::cout << "languages = " << languages << std::endl;
        }

        double coefficient()
        {
            return iq * languages / age;
        }

    protected:
        int iq;
        int languages;
};

int main()
{
    Specialist specialist("Vahag", "Gexamyan", 30, 120, 3);
    std::cout << "specialist.coefficient() " << specialist.coefficient() << std::endl;

    Person<int>* p;
    p = &specialist;
    p->print();

    auto ap = &specialist; // ap type is Person<int>*, auto keyword deduce type automatically
    ap->print();

    return 0;
}