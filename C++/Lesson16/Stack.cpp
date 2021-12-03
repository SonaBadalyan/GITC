#include <iostream>

class Stack
{
    public:

        void push(int val)
        {
            array[index++] = val;
        }

        int pop()
        {
            return array[--index];
        }

        void print()
        {
            std::cout << "_________________Print stack_____________" << std::endl;
            
            int i = index - 1;

            while(i >= 0)
            {
                std::cout << array[i--] << "  ";
            }

            std::cout << std::endl;
        }

        bool isFull()
        {
            if (sizeof(array)/sizeof(array[0]) == index)
            {
                return true;
            }

            return false;
        }

        bool isEmpty()
        {
            if (0 == index)
            {
                return true;
            }

            return false;
        }

    private:

        int index = 0;
        int array[10];
};

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.print();

    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;

    stack.print();

    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);

    stack.print();

    std::cout << "stack.isFull() " << stack.isFull() << std::endl;
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

    std::cout << "stack.isFull() " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() " << stack.isEmpty() << std::endl;

    return 0;
}