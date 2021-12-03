#include <iostream>
#include "DoubleLinkedList.cpp"

class Stack
{
    public:

        Stack()
        {
            size = 10;
            list = new DoubleLinkedList();
        }

        void push(int val)
        {
            if (isFull())
            {
                std::cout << "Stack is full!" << std::endl;
                return;
            }

            list->insert_back(val);
        }

        int pop()
        {
            int result = list->operator[](list->length() - 1);

            if (list->remove_back())
            {
                return result;
            }
            
            return -1;
        }

        void print()
        {
            std::cout << "_________________Print stack_____________" << std::endl;

            list->print();
        }

        bool isFull()
        {
            if (list->length() == size)
            {
                return true;
            }

            return false;
        }

        bool isEmpty()
        {
            if (list->isEmpty())
            {
                return true;
            }

            return false;
        }

        ~Stack()
        {
            delete list;
        }

    private:

        int size;
        DoubleLinkedList* list;
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    std::cout << "stack.isFull() " << stack.isFull() << std::endl;
    stack.print();

    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);
    std::cout << "stack.isFull() " << stack.isFull() << std::endl;
    stack.print();

    stack.push(110);

    std::cout << "stack.isEmpty() " << stack.isEmpty() << std::endl;

    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;

    std::cout << "stack.isFull() " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() " << stack.isEmpty() << std::endl;

    stack.print();

    return 0;
}