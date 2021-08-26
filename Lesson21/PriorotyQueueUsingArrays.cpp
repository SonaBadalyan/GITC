#include <iostream>

class CircularPriorityQueue 
{
   public:

    bool isFull() 
    {
        if (front == 0 && back == size - 1)
        {
            return true;
        }

        if (front == back + 1) 
        {
            return true;
        }

        return false;
    }

    bool isEmpty() 
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int val) 
    {

        if (isFull()) 
        {
            std::cout << "CircularPriorityQueue is full!" << std::endl;
        }
        else 
        {
            if (front == -1)
            {
                front = 0;
            }
            // TO DO
            back = (back + 1) % size;

            array[back] = val;
        }

    }

    int pop() 
    {
        if (isEmpty())
        {
            std::cout << "CircularPriorityQueue is empty!" << std::endl;
            return -1;
        }
        else 
        {
            int val = array[front];

            if (front == back) 
            {
                front = -1;
                back = -1;
            }
            else 
            {
                front = (front + 1) % size;
            }

            return val;
        }
    }

    void print() 
    {
        std::cout << "_________________Print circular priority queue_____________" << std::endl;

        if (isEmpty())
        {
            std::cout << "Empty CircularPriorityQueue!" << std::endl;
        }
        else 
        {
            if (back > front)
            {
                int i = front;

                while(i <= back)
                {
                    std::cout << array[i++] << "  ";
                }

                std::cout << std::endl;
                std::cout << std::endl;
            }
            else
            {
                int i = front;

                while(i < size)
                {
                    std::cout << array[i++] << "  ";
                }

                i = 0;

                while(i <= back)
                {
                    std::cout << array[i++] << "  ";
                }

                std::cout << std::endl;
                std::cout << std::endl;
            }
        }
    }

    private:

        int array[10];
        int size = sizeof(array)/sizeof(array[1]);
        int front = -1;
        int back = -1;
};


int main()
{
    CircularPriorityQueue pQueue;

    pQueue.push(10);
    pQueue.push(5);
    pQueue.push(7);
    pQueue.push(20);
    pQueue.push(15);
    
    pQueue.print();

    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;

    pQueue.print();

    pQueue.push(50);
    pQueue.push(24);
    pQueue.push(0);
    pQueue.push(12);
    pQueue.push(190);
    pQueue.push(100);

    pQueue.print();

    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;

    pQueue.print();

    return 0;
}