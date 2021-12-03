#include <iostream>

class CircularQueue
{
public:

    void push(int val)
    {
        if (!isFull())
        {
            if (front == size && back != 0)
            {
                front = 0;
                flag = true;
            }

            array[front++] = val;
        }
        else 
        {
            std::cout << "CircularQueue is full!" << std::endl;
        }
    }

    int pop()
    {
        if (!isEmpty())
        {
            if( back == size && front != 0)
            {
                back = 0;
            }

            return array[back++];
        }
        else 
        {
            std::cout << "CircularQueue is empty!" << std::endl;
        }
    }

    void print()
    {
        std::cout << "_________________Print queue_____________" << std::endl;

        if (front > back)
        {
            int i = back;

            while(i < front)
            {
                std::cout << array[i++] << "  ";
            }

            std::cout << std::endl;
            std::cout << std::endl;
        }
        else
        {
            int i = back;

            while(i < size)
            {
                std::cout << array[i++] << "  ";
            }

            i = 0;

            while(i < front)
            {
                std::cout << array[i++] << "  ";
            }

            std::cout << std::endl;
            std::cout << std::endl;
        }
    }

    bool isFull()
    {
        if((front == size && 0 == back) ||
            (flag  && back == front))
        {
            return true;
        }

        return false;
    }

    bool isEmpty()
    {
        if (!flag && front == back)
        {
            back = front = 0;
            return true;
        }

        return false; 
    }

private:

    int back = 0;
    int front = 0;
    bool flag = false;
    int array[10];
    int size = sizeof(array)/sizeof(array[0]);
};

int main()
{
    CircularQueue queue;

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

    queue.push(130);

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