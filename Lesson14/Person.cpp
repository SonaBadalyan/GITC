#include<iostream>
#include<string>

class Person
{
    public:
    std::string name;
    std::string surename;
    int age;
    
    void print()
    {
        std::cout << "------------------------------" << std::endl;
        std::cout << "Name is " << name << std::endl;
        std::cout << "Surname is " << surename << std::endl;
        std::cout << "Age is " << age << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
};

int main()
{
    Person neighbour1;
    neighbour1.name = "Ferdinant";
    neighbour1.surename = "Inskandaryan";
    neighbour1.age = 73;
    
    Person neighbour2;
    neighbour2.name = "Adolf";
    neighbour2.surename = "Xachatryan";
    neighbour2.age = 67;
    
    Person neighbour3;
    neighbour3.name = "Surik";
    neighbour3.surename = "Kirakosyan";
    neighbour3.age = 54;
    
    neighbour1.print();
    neighbour2.print();
    neighbour3.print();
    
    return 0;
}