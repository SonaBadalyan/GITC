#include<iostream>

class Person
{
    public:
        Person()
        {
            std::cout << "Person class default constructor." << std::endl;
        }

        Person(std::string name, std::string surename, int age)
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

        void setAge(int age)
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

        const int getAge() const
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

    private:
        std::string name;
        std::string surename;
        int age;
};

class Specialist : public Person
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

    private:
        int iq;
        int languages;
};

class Psychologist : public Specialist
{
    public:
        Psychologist()
        {
            std::cout << "Psychologist class default constructor." <<  std::endl;
        }

        Psychologist(std::string name, std::string surename, int age, int iq, int languages, std::string clinic)
                    : Specialist(name, surename, age, iq, languages)
        {
            std::cout << "Psychologist class constructor with parameters." <<  std::endl;
            this->clinic = clinic;
        }

        void setClinic(std::string clinic)
        {
            this->clinic = clinic;
        }

        const std::string getClinic() const
        {
            return clinic;
        }

        void print() const
        {
            Specialist::print();
            std::cout << "Psychologist class print function." << std::endl;

            std::cout << "clinic = " << clinic << std::endl;
        }

    private:
        std::string clinic;
};

class Musician : public Specialist
{
    public:
        Musician()
        {
            std::cout << "Musician class default constructor." << std::endl;
        }

        Musician(std::string name, std::string surename, int age, int iq, int languages, std::string workingPlace, int numberOfMusicalInstruments)
                    : Specialist(name, surename, age, iq, languages)
        {
            std::cout << "Musician class constructor with parameters." << std::endl;

            this->workingPlace = workingPlace;
            this->numberOfMusicalInstruments = numberOfMusicalInstruments;
        }

        void setWorkingPlace(std::string workingPlace)
        {
            this->workingPlace = workingPlace;
        }

        void setNumberOfMusicalInstruments(int numberOfMusicalInstruments)
        {
            this->numberOfMusicalInstruments = numberOfMusicalInstruments;
        }

        const std::string getWorkingPlace() const
        {
            return workingPlace;
        }

        const int getNumberOfMusicalInstruments() const
        {
            return numberOfMusicalInstruments;
        }

        void print() const
        {
            Specialist::print();
            std::cout << "Musician class print function." << std::endl;

            std::cout << "workingPlace = " << workingPlace << std::endl;
            std::cout << "numberOfMusicalInstruments = " << numberOfMusicalInstruments << std::endl;
        }

    private:
        std::string workingPlace;
        int numberOfMusicalInstruments;
};

class Medic : public Specialist
{
    public:
        Medic()
        {
            std::cout << "Medic class default constructor." << std::endl;
        }

        Medic(std::string name, std::string surename, int age, int iq, int languages, int experience, int salary) 
                : Specialist(name, surename, age, iq, languages)
        {
            std::cout << "Medic class constructor with parameters." << std::endl;

            this->experience = experience;
            this->salary = salary;
        }

        void setExperience(int experience)
        {
            this->experience = experience;
        }

        void setSalary(int salary)
        {
            this->salary = salary;
        }

        const int getExperience() const
        {
            return experience;
        }

        const int getSalary() const
        {
            return salary;
        }

        void print() const
        {
            Specialist::print();
            std::cout << "Medic print function." << std::endl;

            std::cout << "experience = " << experience << std::endl;
            std::cout << "salary = " << salary << std::endl;
        }

    private:
        int experience;
        int salary;
};

class Therapist : public Medic
{
    public:
        Therapist()
        {
            std::cout << "Therapist class default constructor." << std::endl;
        }

        Therapist(std::string name, std::string surename, int age, int iq, int languages, int experience, int salary, int patientCount)
                    : Medic(name, surename, age, iq, languages, experience, salary)
        {
            std::cout << "Therapist class constructor with parameters." << std::endl;

            this->patientCount = patientCount;
        }

        void setPatientCount(int patientCount)
        {
            this->patientCount = patientCount;
        }

        const int getPatientCount() const
        {
            return patientCount;
        }

        void print() const
        {
            Medic::print();
            std::cout << "Therapist print function." << std::endl;

            std::cout << "patientCount = " << patientCount << std::endl;
        }

    private:
        int patientCount;

};

class CardioSurgeon : public Medic
{
    public:
        CardioSurgeon()
        {
            std::cout << "CardioSurgeon class default constructor." << std::endl;
        }

        CardioSurgeon(std::string name, std::string surename, int age, int iq, int languages, int experience, int salary, std::string specialization, int surgeriesCount) 
                    : Medic(name, surename, age, iq, languages, experience, salary)
        {
            std::cout << "CardioSurgeon class constructor with parameters." << std::endl;

            this->specialization = specialization;
            this->surgeriesCount = surgeriesCount;
        }

        void setSpecialization(std::string specialization)
        {
            this->specialization = specialization;
        }

        void setSurgeriesCount(int surgeriesCount)
        {
            this->surgeriesCount = surgeriesCount;
        }

        const std::string getSpecialization() const
        {
            return specialization;
        }

        const int getSurgeriesCount() const
        {
            return surgeriesCount;
        }

        void print() const
        {
            Medic::print();
            std::cout << "Cardiothoracic surgeon print function." << std::endl;

            std::cout << "specialization = " << specialization << std::endl;
            std::cout << "surgeriesCount = " << surgeriesCount << std::endl;
        }

    private:
        std::string specialization;
        int surgeriesCount;
};

int main()
{
    // Person p;
    // p.name = "Armine";
    // p.surename = "Abrahamyan";
    // p.age = 30;
    // p.print();

    // Specialist specialist;
    // specialist.iq = 120;
    // specialist.languages = 3;
    // specialist.print();

    // Medic medic;
    // medic.experience = 5;
    // medic.salary = 50000;
    // medic.print();

    // CardioSurgeon surgeon;
    // surgeon.name = "Armine";
    // surgeon.surename = "Abrahamyan";
    // surgeon.age = 30;
    // surgeon.iq = 120;
    // surgeon.languages = 3;
    // surgeon.experience = 5;
    // surgeon.salary = 50000;
    // surgeon.specialization = "heart and chest";
    // surgeon.surgeriesCount = 50;
    // surgeon.print();

    // std::cout << "________________________" << std::endl;

    // Person* person = &surgeon;
    // person->print();

    // person = &medic;
    // person->print();

    // Medic* med = &surgeon;
    // med->print();

    CardioSurgeon card("Armine", "Abrahamyan", 30, 120, 3, 5, 50000, "heart and chest", 50);
    card.print();

    Medic medic("Gevorg", "Kostanyan", 30, 120, 3, 5, 50000);
    medic.print();

    Specialist specialist("Vahag", "Gexamyan", 30, 120, 3);
    specialist.print();

    Therapist therapist("Albert", "Alexanyan", 30, 120, 3, 5, 50000, 12);
    therapist.print();

    Psychologist psychologist("Zvart", "Antanesyan", 30, 120, 3, "NorMed");
    psychologist.print();

    Musician musician("Anushik", "Manucharyan", 20, 120, 3, "Conservatory", 4);
    musician.print();

    Person person("Fenul", "Kiraosyan", 30);
    person.print();

    Person* p = &card;
    p = &medic;
    p = &specialist;
    p = &person;
    p->print();

    return 0;
}