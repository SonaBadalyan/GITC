#include <iostream>
#include <algorithm>
#include <vector>

class Person
{
    private:

        std::string name;
        std::string surname;
        int age;
        int IQ;
        int experiance;

    public:

        Person(std::string name, std::string surname, int age, int IQ, int experiance)
        {
            this->name = name;
            this->surname = surname;
            this->age = age;
            this->IQ = IQ;
            this->experiance = experiance;
        }

        Person() = default;

        friend std::ostream& operator<<(std::ostream& output, const Person& p)
        {
            output << "__________________________________" << std::endl;
            output << "Name : " << p.name << std::endl;
            output << "Surname : " << p.surname << std::endl;
            output << "Age : " << p.age << std::endl;
            output << "IQ : " << p.IQ << std::endl;
            output << "Experiance : " << p.experiance << std::endl;

            return output;

        }

        friend bool operator==(const Person& p1, const Person& p2)
        {
            if (&p1 == &p2)
            {
                return true;
            }

            if (    
                    p1.name == p2.name &&
                    p1.surname == p2.surname &&
                    p1.age == p2.age &&
                    p1.IQ == p2.IQ && 
                    p1.experiance == p2.experiance
                )
                {
                    return true;
                }

            return false;
        }

};

int main()
{
    std::vector<Person> vp;

    vp.push_back(Person("Anna", "Abrahamyan", 22, 120, 3));
    vp.push_back(Person("Anna", "Abrahamyan", 22, 120, 3));
    vp.push_back(Person("Anna", "Abrahamyan", 22, 120, 3));
    vp.push_back(Person("Asot", "Kirakosyan", 22, 120, 3));
    vp.push_back(Person("Valod", "Mzmalyan", 22, 120, 3));
    vp.push_back(Person("Vahan", "Khachatryan", 22, 120, 3));

    auto i = std::count(vp.begin(), vp.end(), Person("Anna", "Abrahamyan", 22, 120, 3));

    std::cout << "Count is equal to "<< i <<std::endl;

    return 0;
}