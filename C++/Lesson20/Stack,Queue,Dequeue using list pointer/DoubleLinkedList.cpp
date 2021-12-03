#include <iostream>

class DoubleLinkedList
{
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
    
    public:

        DoubleLinkedList()
        {
            m_length = 0;
            head = nullptr;
            tail = nullptr; 
        }

        int operator[](int index)
        {
            if (index < 0 || index > m_length)
            {
                return -1;
            }

            Node* curr = head;

            for(int i = 0; i < index; ++i)
            {
                curr = curr->m_next;  
            }

            return curr->m_data;
        }

        bool remove_back()
        {
            if (!head)
            {
                return false; 
            }

            if (head == tail)
            {
                --m_length;

                head = tail = nullptr;
                return true;
            }

            --m_length;

            tail = tail->m_prev;
            tail->m_next = nullptr;
            return true;
        }

        bool remove_front()
        {
            if (!head)
            {
                --m_length;
                
                return false;
            }
            if (head == tail)
            {
                head = tail = nullptr;
                return true;
            }

            --m_length;

            head = head->m_next;
            head->m_prev = nullptr;
            return true;  
        }

        void insert_back(int data)
        {
            Node* temp = new Node(data);

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

        void insert_front(int data)
        {
            Node* temp = new Node(data);

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

        int length()
        {
            return m_length;
        }

    private:

        int m_length;
        Node* head;
        Node* tail;
};