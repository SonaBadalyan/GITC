#include <iostream>

template<typename T>
class Queue
{
    public:

        struct Node
        {
            public:

                Node (T data)
                {
                    m_data = data;
                }

                T m_data;
                Node* m_next = nullptr;
                Node* m_prev = nullptr; 
        };

        Queue()
        {
            m_length = 0;
            head = nullptr;
            tail = nullptr;
        }

        void push(T val)
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

        T pop()
        {
            T data = head->m_data;

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