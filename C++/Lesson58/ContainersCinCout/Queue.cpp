#include <iostream>
#include <sstream>
#include <cstdlib>

class Queue
{
public:

    void push(int val)
    {
        if (!isFull())
        {
            array[index_push++] = val;
        }
        else 
        {
            std::cout << "The queue is full, can`t push the element." << std::endl;
        }
    }

    int pop()
    {
        if (!isEmpty())
        {
            return array[index_pop++];
        }
        else 
        {
            std::cout << "The queue is empty, can`t pop the element." << std::endl;
            index_pop = index_push = 0;
        }
    }

    void print(std::ostream& output = std::cout) const
    {
        output << "_________________Print queue_____________" << std::endl;

        int i = index_pop;

        while(i < index_push)
        {
            output << array[i++] << "  ";
        }

        output << std::endl;
        output << std::endl;
    }

    bool isFull()
    {
        if(index_push == sizeof(array)/sizeof(array[0]))
        {
            return true;
        }

        return false;
    }

    bool isEmpty()
    {
        if (index_push == index_pop)
        {
            return true;
        }

        return false; 
    }

    friend std::ostream& operator<<(std::ostream& output, const Queue& queue);
    friend std::istream& operator>>(std::istream& input, Queue&);

private:

    int index_pop = 0;
    int index_push = 0;
    int array[10];
};

std::ostream& operator<<(std::ostream& output, const Queue& queue)
{
    queue.print(output);

    return output;
}

std::istream& operator>>(std::istream& input, Queue& queue)
{
    std::cout << "Please enter numbers for inserting in to the queue." << std::endl;

    std::string numbers;
    std::getline(input, numbers);
    std::stringstream ss(numbers);
    std::string number;

    while(std::getline(ss, number, ' '))
    {
        queue.push(atoi(number.c_str()));
    }

    return input;
}

int main()
{
    Queue queue;

    std::cin >> queue;
    std::cout << queue;
    
    return 0;
}