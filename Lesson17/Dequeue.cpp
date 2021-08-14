#include <iostream>

class Dequeue
{
    public:

        void push_front(int val)
        {
            if (isFull()) 
            {
                std::cout << "Dequeue is full!" << std::endl;
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

        int pop_front()
        {
           if (isEmpty())
            {
                std::cout << "Dequeue is empty!" << std::endl;
                return -1;
            }
            else 
            {
                if (front == back)
                {
                    int val = array[front];
                    front = back = -1;
                    return val;
                }
                else if (size -1  == front)
                {
                    int val = array[front];
                    front = 0;
                    return val;
                }
                else
                {
                    int val = array[front];
                    ++front;
                    return val;
                }
            }
        }

        void push_back(int val)
        {
            if (isFull()) 
            {
                std::cout << "Dequeue is full!" << std::endl;
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

        int pop_back()
        {
            if (isEmpty())
            {
                std::cout << "Dequeue is empty!" << std::endl;
                return -1;
            }
            else 
            {
                if (back == front) 
                {
                    int val = array[back];
                    front = back = -1;
                    return val;
                }
                else if (back == 0)
                {
                    int val = array[back];
                    back = size - 1;
                    return val;
                }
                else
                {
                    int val = array[back];
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

        int array[10];
        int size = sizeof(array)/sizeof(array[1]);
        int front = -1;
        int back = -1;
};

int main()
{
    Dequeue dequeue;

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
    dequeue.push_front(5);
    dequeue.push_back(5);
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

    std::cout << "Poped back: " << dequeue.pop_back() << std::endl;
    std::cout << "Poped front: " << dequeue.pop_front() << std::endl;

    std::cout << " Is empty " << dequeue.isEmpty() << std::endl;
    std::cout << " Is full " << dequeue.isFull() << std::endl;

    return 0;
}