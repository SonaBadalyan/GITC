#include <iostream>

class Queue
{
    public:

        struct Node
        {
            public:

                Node (int data)
                {
                    m_data = data;
                }

                int m_data = 0;
                Node* m_next = nullptr;
                Node* m_prev = nullptr; 
        };

        Queue()
        {
            m_length = 0;
            head = nullptr;
            tail = nullptr;
        }

        void push(int val)
        {
            Node* temp = new Node(val);

            if (isEmpty())
            {
                head = tail = temp;
                return;
            }

            tail->m_next = temp;
            temp->m_prev = tail;
            tail = temp;

            ++m_length;
        }

        int pop()
        {
            if (isEmpty())
            {               
                return -1;
            }

            int data = head->m_data;

            if (head == tail)
            {
                head = tail = nullptr;
                --m_length;
                return data;
            }

            --m_length;

            head = head->m_next;
            head->m_prev = nullptr;
            return data;  
        }

        void print()
        {
            std::cout << "_______________Print linked list_______________" << std::endl;

            if (isEmpty())
            {
                return;
            }

            Node* curr = head;

            while (curr)
            {
                std::cout << curr->m_data << "   ";
                curr = curr->m_next;
            }
            
            std::cout << std::endl;
        }

        bool isEmpty()
        {
            if (nullptr == head)
            {
                return true;
            }

            return false;
        }

    private:
    
        int m_length;
        Node* head;
        Node* tail;
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

    return 0;
}