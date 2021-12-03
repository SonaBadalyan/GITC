#include <iostream>
#include <sstream>
#include <cstdlib>

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

        void print(std::ostream& output = std::cout) const
        {
            output << "_________________Print stack_____________" << std::endl;
            
            int i = index - 1;

            while(i >= 0)
            {
                output << array[i--] << "  ";
            }

            output << std::endl;
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

        friend std::ostream& operator<<(std::ostream& output, const Stack& stack);
        friend std::istream& operator>>(std::istream& input, Stack& stack);

    private:

        int index = 0;
        int array[10];
};

std::ostream& operator<<(std::ostream& output, const Stack& stack)
{
    stack.print(output);
    return output;
}

std::istream& operator>>(std::istream& input, Stack& stack)
{
    std::cout << "Please input numbers for inserting in to the stack." << std::endl;

    std::string numbers;
    std::getline(input, numbers);

    std::stringstream ss(numbers);
    std::string number;

    while(std::getline(ss, number, ' '))
    {
        stack.push(atoi(number.c_str()));
    }

    return input;
}

int main()
{
    Stack stack;
    std::cin >> stack;
    std::cout << stack;
    
    return 0;
}