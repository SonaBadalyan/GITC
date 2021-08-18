#include <iostream>
#include "DoubleLinkedList.cpp"

class Stack
{
    public:

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
            int result = list->operator[](list->size());

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
            if (list->size() == size)
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

    private:
        int size = 10;
        DoubleLinkedList* list;
};

int main()
{
    Stack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    std::cout << "stack.isFull() " << stack.isFull() << std::endl;

    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);
    std::cout << "stack.isFull() " << stack.isFull() << std::endl;

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