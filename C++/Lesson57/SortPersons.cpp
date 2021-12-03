#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Person
{
    protected:
        std::string name;
        std::string surname;
        int age;
        int iq;
        int experiance;


    public:

        Person() {}

        Person(std::string name, std::string surname, int age, int iq, int experiance)
        {
            this->name = name;
            this->surname = surname;
            this->age = age;
            this->iq = iq;
            this->experiance = experiance;
        }

        friend bool operator<(const Person& a, const Person&  b)
        {
            return a.age < b.age;
        }

        friend bool byIq(const Person& a, const Person&  b);

        friend bool byExperiance(const Person& a, const Person&  b);

        friend std::ostream& operator<<(std::ostream& output, const Person& p)
        {
            output << "Person parameters are: " << std::endl;
            output << "Name : " << p.name << std::endl;
            output << "Surname : " << p.surname << std::endl;
            output << "Age : " << p.age << std::endl;
            output << "Iq : " << p.iq << std::endl;
            output << "Experiance : " << p.experiance << std::endl;

            return output;
        }

        friend std::istream& operator>>(std::istream& input, Person& p)
        {
            std::cout << "Please enter perosn`s parameters." << std::endl;

            std::cout << "Name : " ;
            input >> p.name;

            std::cout << "Surname : ";
            input >> p.surname;

            std::cout << "Age : ";
            input >> p.age;

            std::cout << "Iq : ";
            input >> p.iq;

            std::cout << "Experiance : ";
            input >> p.experiance;

            return input;
        }
};

bool byIq(const Person& a, const Person&  b)
{
    return a.iq < b.iq;
}

bool byExperiance(const Person& a, const Person&  b)
{
    return a.experiance < b.experiance;
}

int main()
{
    std::vector<Person> vp;

    vp.push_back(Person("Armen", "Hambardzumyan", 12, 100, 3));
    vp.push_back(Person("Ashot", "Kirakosyan", 45, 90, 10));
    vp.push_back(Person("Gexam", "Martirosyan", 67, 130, 18));
    vp.push_back(Person("Sirarpi", "Danielyan", 78, 120, 40));
    vp.push_back(Person("Anush", "Qasyan", 5, 10, 0));
    vp.push_back(Person("Gexecik", "Amatuni", 67, 190, 24));

    Person p;
    std::cin >> p;
    vp.push_back(p);

    std::cout << "Before sorting." <<std::endl;

    for(auto const& elem : vp)
    {
        std::cout << elem << std::endl;
    }

    std::sort(vp.begin(), vp.end());

    std::cout << "After sorting by age." <<std::endl;
    
    for(auto const& elem : vp)
    {
        std::cout << elem << std::endl;
    }

    std::sort(vp.begin(), vp.end(), byIq);

    std::cout << "After sorting byIq." <<std::endl;
    
    for(auto const& elem : vp)
    {
        std::cout << elem << std::endl;
    }

    std::sort(vp.begin(), vp.end(), byExperiance);

    std::cout << "After sorting by experiance." <<std::endl;
    
    for(auto const& elem : vp)
    {
        std::cout << elem << std::endl;
    }

    return 0;
}