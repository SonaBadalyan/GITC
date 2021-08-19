#include <iostream>
#include "DoubleLinkedList.cpp"

class Queue
{
    public:

        Queue()
        {
            size = 10;
            list = new DoubleLinkedList();
        }

        void push(int val)
        {
            if (!isFull())
            {
                list->insert_back(val);
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
                int removed_val = list->operator[](0);

                if (list->remove_front())
                {
                    --size;
                    return removed_val;
                }
            }
            else 
            {
                std::cout << "The queue is empty, can`t pop the element." << std::endl;
                return -1;
            }
        }

        void print()
        {
            std::cout << "_________________Print queue_____________" << std::endl;

            list->print();
        }

        bool isFull()
        {
            if(size == list->length())
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

            return false; 
        }

    private:
    
        int size;
        DoubleLinkedList* list;
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