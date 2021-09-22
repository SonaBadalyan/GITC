#include<iostream>

class Item
{
    public:

        Item()
        {
            std::cout << "Item default constructor." << std::endl;
        }

        void* operator new(size_t size)
        {
            std::cout << "Item new operator overloaded." << std::endl;
            void *p = malloc(size);
            return p;
        }
  
        void operator delete(void *ptr)
        {
            std::cout << "Item delete operator overloaded." << std::endl;
            free(ptr);
        }

        void* operator new[](size_t size)
        {
            std::cout << "Item new operator overloaded." << std::endl;
            void *p = malloc(size);
            return p;
        }
  
        void operator delete[](void *ptr)
        {
            std::cout << "Item delete operator overloaded." << std::endl;
            free(ptr);
        }
};

int main()
{
    Item* item = new Item();

    delete item;

    return 0;
}