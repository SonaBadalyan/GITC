#include <iostream>
#include "DoubleLinkedList.cpp"

class Dequeue
{
    public:
        Dequeue()
        {
            list = new DoubleLinkedList();
            size = 10;
        }

        void push_front(int val)
        {
            if (isFull()) 
            {
                std::cout << "Dequeue is full!" << std::endl;
            }
            else 
            {
                list->insert_front(val);
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
                int removed_val = list->operator[](0);

                if(list->remove_front())
                {
                    return removed_val;
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
               list->insert_back(val);
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
                int removed_val = list->operator[](list->length());
                if(list->remove_back())
                {
                    return removed_val;
                }
            }
        }

        bool isFull()
        {
            if (list->length() == size)
            {
                return true;
            }

            return false;
        }

        bool isEmpty()
        {
            if (list->isEmpty())
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
                list->print();
            }
        }

    private:

        DoubleLinkedList* list;
        int size;
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