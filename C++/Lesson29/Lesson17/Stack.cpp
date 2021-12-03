#include <iostream>

class Stack
{
    public:

        Stack()
        {
            index = 0;
            size = 5;
            array = new int[size];
        }

        void push(int val)
        {
            if (isFull())
            {
                size *= 2;

                int* temp_array = new int[size];

                for ( int i = 0; i < size / 2; ++i)
                {
                    temp_array[i] = array[i];
                }

                delete[] array;
                array = temp_array;
            }

            array[index++] = val;
        }

        int pop()
        {
            return array[--index];
        }

        void print()
        {
            std::cout << "_________________Print stack_____________" << std::endl;

            int i = index;

            while(i > 0)
            {
                std::cout << array[--i] << "  ";
            }

            std::cout << std::endl;
        }

        bool isFull()
        {
            if (size == index)
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

        ~Stack()
        {
            delete[] array;
            array = nullptr;
        }

    private:

        int index;
        int size;
        int* array;
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