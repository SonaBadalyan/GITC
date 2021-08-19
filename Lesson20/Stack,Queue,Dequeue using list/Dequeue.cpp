#include <iostream>

class Dequeue
{
    public:

        class Node
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

        Dequeue()
        {
            m_length = 0;
            head = nullptr;
            tail = nullptr; 
        }

        void push_front(int val)
        {
            Node* temp = new Node(val);

            if (isEmpty())
            {
                head = tail = temp;
                return;
            }

            temp->m_next = head;
            head->m_prev = temp;
            head = temp;

            ++m_length;
        }

        int pop_front()
        {
           if (isEmpty())
            {               
                return -1;
            }

            int data = head->m_data;

            if (head == tail)
            {
                --m_length;

                head = tail = nullptr;
                return data;
            }

            --m_length;

            head = head->m_next;
            head->m_prev = nullptr;
            return data;
        }

        void push_back(int val)
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

        int pop_back()
        {
            if (isEmpty())
            {
                return -1; 
            }

            int data = tail->m_data;

            if (head == tail)
            {
                --m_length;

                head = tail = nullptr;
                return data;
            }

            --m_length;

            tail = tail->m_prev;
            tail->m_next = nullptr;

            return data;
        }

        bool isEmpty()
        {
            if (nullptr == head)
            {
                return true;
            }

            return false;
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

    private:

        int m_length;
        Node* head;
        Node* tail;
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

    return 0;
}