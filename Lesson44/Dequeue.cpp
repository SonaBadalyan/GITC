#include <iostream>

template <typename T>
class Dequeue
{
    public:

        void push_front(T val)
        {
            if (isFull()) 
            {
                throw "Dequeue is full!";
            }
            else 
            {
                if (isEmpty())
                {
                    front = 0;
                }
                if (0 == front)
                {
                    front = size - 1;
                }
                else
                {
                    --front;
                }
                array[front] = val;
            }
        }

        T pop_front()
        {
           if (isEmpty())
            {
                throw "Dequeue is empty!";
            }
            else 
            {
                if (front == back)
                {
                    T val = array[front];
                    front = back = -1;
                    return val;
                }
                else if (size -1  == front)
                {
                    T val = array[front];
                    front = 0;
                    return val;
                }
                else
                {
                    T val = array[front];
                    ++front;
                    return val;
                }
            }
        }

        void push_back(T val)
        {
            if (isFull()) 
            {
                throw  "Dequeue is full!";
            }
            else 
            {
                if (isEmpty())
                {
                    front = back = 0;
                }
                if (size - 1 == back)
                {
                    back = 0;
                }
                else
                {
                    ++back;
                }
                array[back] = val;
            }
        }

        T pop_back()
        {
            if (isEmpty())
            {
                throw "Dequeue is empty!";
            }
            else 
            {
                if (back == front) 
                {
                    T val = array[back];
                    front = back = -1;
                    return val;
                }
                else if (back == 0)
                {
                    T val = array[back];
                    back = size - 1;
                    return val;
                }
                else
                {
                    T val = array[back];
                    --back;
                    return val;
                }
            }
        }

        bool isFull()
        {
            if ((front == 0 && back == size - 1) ||
                (front == back + 1))
            {
                return true;
            }

            return false;
        }

        bool isEmpty()
        {
            if (-1 == front && -1 == back)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void print() 
        {
            std::cout << "_________________Print dequeue_____________" << std::endl;

            if (isEmpty())
            {
                std::cout << "Empty dequeue!" << std::endl;
            }
            else 
            {
                int i = front;

                while(i != back)
                {
                    std::cout << array[i] << "  ";
                    i = (i + 1) % size;
                }

                std::cout << array[back] << std::endl;
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
    Dequeue<int> dequeue;

    dequeue.push_front(1);
    dequeue.push_front(10);
    dequeue.push_back(1);
    dequeue.push_back(10);
    dequeue.push_front(2);
    dequeue.push_back(2);
    dequeue.push_front(3);
    dequeue.push_back(3);
    dequeue.print();

    dequeue.push_front(4);
    dequeue.push_back(4);
    try
    {
        dequeue.push_front(5);
        dequeue.push_back(5);
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
    }
    
    dequeue.print();

    std::cout << " Is empty " << dequeue.isEmpty() << std::endl;
    std::cout << " Is full " << dequeue.isFull() << std::endl;

    std::cout << "Poped front: " << dequeue.pop_front() << std::endl;
    std::cout << "Poped front: " << dequeue.pop_front() << std::endl;
    std::cout << "Poped front: " << dequeue.pop_front() << std::endl;
    dequeue.print();

    std::cout << "Poped back: " << dequeue.pop_back() << std::endl;
    dequeue.print();

    std::cout << "Poped front: " << dequeue.pop_front() << std::endl;
    dequeue.print();

    std::cout << "Poped back: " << dequeue.pop_back() << std::endl;
    std::cout << "Poped back: " << dequeue.pop_back() << std::endl;
    std::cout << "Poped back: " << dequeue.pop_back() << std::endl;
    std::cout << "Poped back: " << dequeue.pop_back() << std::endl;
    std::cout << "Poped back: " << dequeue.pop_back() << std::endl;
    dequeue.print();

    try
    {
        std::cout << "Poped back: " << dequeue.pop_back() << std::endl;
        std::cout << "Poped front: " << dequeue.pop_front() << std::endl;
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }

    std::cout << " Is empty " << dequeue.isEmpty() << std::endl;
    std::cout << " Is full " << dequeue.isFull() << std::endl;

    return 0;
}