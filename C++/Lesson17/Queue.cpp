#include <iostream>

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

    void print()
    {
        std::cout << "_________________Print queue_____________" << std::endl;

        int i = index_pop;

        while(i < index_push)
        {
            std::cout << array[i++] << "  ";
        }

        std::cout << std::endl;
        std::cout << std::endl;
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

private:

    int index_pop = 0;
    int index_push = 0;
    int array[10];
};

int main()
{
    Queue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);

    queue.print();

    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;

    queue.print();

    queue.push(50);
    queue.push(60);
    queue.push(70);
    queue.push(80);
    queue.push(90);
    queue.push(100);
    queue.push(110);
    queue.push(120);

    queue.print();

    std::cout << "Queue.isFull() " << queue.isFull() << std::endl;

    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;

    std::cout << "Queue pop " << queue.pop() << std::endl;

    std::cout << "Queue.isEmpty() " << queue.isEmpty() << std::endl;

    queue.print();

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);

    queue.print();

    std::cout << "Queue.isFull() " << queue.isFull() << std::endl;

    return 0;
}