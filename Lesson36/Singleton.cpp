#include <iostream>

template <typename T>
class Singleton
{
    public:
        static Singleton* create(int id)
        {
            if (!instance)
            {
                instance = new Singleton(id);
            }

            return instance;
        }

        void print()
        {
            std::cout << "id = " << id << std::endl;
        }

    private:
    
        Singleton(int id) : id (id) {};
        static Singleton* instance;
        T id = 1;
};

template<>
Singleton<int>* Singleton<int>::instance = nullptr;

int main()
{
    auto s1 = Singleton<int>::create(1);
    std::cout << "s1 = " << s1 << std::endl;
    s1->print();

    auto s2 = Singleton<int>::create(2);
    std::cout << "s2 = " << s2 << std::endl;
    s2->print();

    auto s3 = Singleton<int>::create(3);
    std::cout << "s3 = " << s3 << std::endl;
    s3->print();

    auto  s4 = Singleton<int>::create(4);
    std::cout << "s4 = " << s4 << std::endl;
    s4->print();

    return 0;
}
