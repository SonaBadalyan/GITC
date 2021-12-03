#include <string>
#include <iostream>

 // The compiler needs to have access to the implementation of the methods, to instantiate them with the template argument.
 // If these implementations were not in the header, they wouldn't be accessible, and therefore the compiler wouldn't be able to instantiate the template.

// Template Declaration
template<typename T>
class Person
{
    public:
        Person();

        Person(std::string name, std::string surename, T age);

        void setName(std::string name);

        void setSurname(std::string surname);

        void setAge(T age);

        const std::string& getName() const;

        const std::string& getSurname() const;

        const T getAge() const;

        void print() const;

    protected:
        std::string name;
        std::string surename;
        T age;
};


// Template Definition

template<typename T>
Person<T>::Person()
{
    std::cout << "Person class default constructor." << std::endl;
}

template<typename T>
Person<T>::Person(std::string name, std::string surename, T age)
{
    std::cout << "Person class constructor with parameters." << std::endl;

    this->name = name;
    this->surename = surename;
    this->age = age;
}

template<typename T>
void Person<T>::setName(std::string name)
{
    this->name = name;
}

template<typename T>
void Person<T>::setSurname(std::string surname)
{
    this->surename = surename;
}

template<typename T>
void Person<T>::setAge(T age)
{
    this->age = age;
}

template<typename T>
const std::string& Person<T>::getName() const
{
    return name;
}

template<typename T>
const std::string& Person<T>::getSurname() const
{
    return surename;
}

template<typename T>
const T Person<T>::getAge() const
{
    return age;
}

template<typename T>
void Person<T>::print() const
{
    std::cout << "Person class print function." << std::endl;

    std::cout << "name = " << name << std::endl;
    std::cout << "surname = " << surename << std::endl;
    std::cout << "age = " << age << std::endl;
}
