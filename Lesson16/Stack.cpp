#include <iostream>

class Stack
{
    public:

        void push(int val)
        {
            array[index] = val;
            ++index;
        }

        int pop()
        {
            return array[--index];
        }

        void print()
        {
            int i = index - 1;

            while(i >= 0)
            {
                std::cout << array[i] << "  ";
                --i;
            }

            std::cout << std::endl;
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

    return 0;
}