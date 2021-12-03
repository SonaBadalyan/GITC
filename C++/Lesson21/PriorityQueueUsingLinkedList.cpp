#include <iostream>

class PriorityQueue
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

        PriorityQueue()
        {
            m_length = 0;
            head = nullptr;
            tail = nullptr;
        }

        void push(int val)
        {
            Node* newNode = new Node(val);

            if (is_empty())
            {
                head = tail = newNode;
                return;
            }

            if (head->m_data > val) // push front
            {
                newNode->m_next = head;
                head->m_prev = newNode;
                head = newNode;

                ++m_length;

                return;
            }

            if (tail->m_data < val) // push back
            {
                tail->m_next = newNode;
                newNode->m_prev = tail;
                tail = newNode;

                ++m_length;

                return;
            }

            Node* curr = head;

            while(curr && curr->m_data < val)
            {
                curr = curr->m_next;
            }

            Node* prev = curr->m_prev;

            prev->m_next = newNode;
            newNode->m_prev = prev;

            newNode->m_next = curr;
            curr->m_prev = newNode;

            ++m_length;
        }

        int pop()
        {
            if (is_empty())
            {
                return -1; 
            }

            int return_value = tail->m_data;

            if (head == tail)
            {
                --m_length;

                head = tail = nullptr;
                return return_value;
            }

            --m_length;

            tail = tail->m_prev;
            tail->m_next = nullptr;

            return return_value;
        }

        void print()
        {
            std::cout << "_______________Print priority queue_______________" << std::endl;

            if (is_empty())
            {
                return;
            }

            Node* curr = head;

            while (curr)
            {
                std::cout << curr->m_data << "  ";
                curr = curr->m_next;
            }
            
            std::cout << std::endl;
        }

        bool is_empty()
        {
            if (!head && 0 == m_length)
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
    PriorityQueue pQueue;

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