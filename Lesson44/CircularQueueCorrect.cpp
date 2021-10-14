#include <iostream>

template<class T>
class CircularQueue 
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

    void push(T val) 
    {
        if (isFull()) 
        {
            std::string exception =  "CircularQueue is full!";
            throw exception;
        }
        else 
        {
            if (front == -1)
            {
                front = 0;
            }

            back = (back + 1) % size;

            array[back] = val;
        }

    }

    T pop() 
    {

        if (isEmpty())
        {
            std::string exception =  "CircularQueue is empty!";
            throw exception;
        }
        else 
        {
            T val = array[front];

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
        std::cout << "_________________Print queue_____________" << std::endl;

        if (isEmpty())
        {
            std::cout << "Empty CircularQueue!" << std::endl;
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

        T array[10];
        int size = sizeof(array)/sizeof(array[1]);
        int front = -1;
        int back = -1;
};

int main() 
{
    CircularQueue<int> queue;

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

    try
    {
        queue.push(120);
        queue.push(130);
    }
    catch(std::string& ex)
    {
        std::cout << ex << std::endl;
    }

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

    try 
    {
        std::cout << "Queue pop " << queue.pop() << std::endl;
    }
    catch(std::string& ex)
    {
        std::cout << ex << std::endl;
    }

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