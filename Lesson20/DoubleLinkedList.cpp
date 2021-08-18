#include<iostream>

class DoubleLinkedList
{
    class Node 
    {
        public:

            Node(int data)
            {
                this->data = data;
            }

            int data = 0;
            Node* next = nullptr;
            Node* prev = nullptr;

    };

    public:

        DoubleLinkedList(const DoubleLinkedList& rhs)
        {
            if (this == &rhs || isEmpty())
            {
                return;
            }

            head = tail = new Node(rhs.head->data);

            if (1 == rhs.m_size)
            {   
                m_size = 1;
                return;
            }

            Node* curr = rhs.head->next;

            while(curr)
            {
                Node* newNode = new Node(curr->data);

                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;

                curr = curr->next;
            }

            m_size = rhs.m_size;
        }

        void insert_front(int value)
        {
            if (isEmpty())
            {
                head = tail = new Node(value);
                ++m_size;
                return;
            }

            Node* newNode = new Node(value);
            head->prev = newNode;
            newNode->next = head;

            head = newNode;

            ++m_size;
        }

        void insert(int value, int pos)
        {
            if (pos <= 0 && pos > m_size)
            {
                std::cout << "Unable to insert!" << std::endl;
                return;
            }

            if( 1 == pos)
            {
                insert_front(value);
                return;
            }
            if (m_size = pos)
            {
                insert_back(value);
                return;
            }

            Node* curr = head;

            for (int i = 0; i < pos; ++i)
            {
                curr = curr->next;
            }

            Node* newNode = new Node(value);

            curr->next->prev = newNode;
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next = newNode;

            ++m_size;
        }

        void insert_back(int value)
        {
            if (isEmpty())
            {
                head = tail = new Node(value);
                ++m_size;
                return;
            }

            Node* newNode = new Node(value);

            tail->next = newNode;
            newNode->prev = tail;

            tail = newNode;
            ++m_size;
        }

        bool remove_front()
        {
            if (isEmpty())
            {
                std::cout << "List is empty!" << std::endl;
                return false;
            }

            head = head->next;
            --m_size;

            return true;
        }

        bool remove(int pos)
        {
            if (pos <= 0 && pos > m_size)
            {
                std::cout << "Unable to insert!" << std::endl;
                return false;
            }

            if (1 == pos)
            {
                remove_front();
                return true;
            }
            if(m_size == pos)
            {
                remove_back();
                return true;
            }

            Node* curr = head;

            for (int i = 0; i < pos; ++i)
            {
                curr = curr->next;
            }

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            --m_size;

            return true;
        }

        bool remove_back()
        {
            if (isEmpty())
            {
                std::cout << "List is empty!" << std::endl;
                return false;
            }

            tail = tail->prev;
            --m_size;

            return true;
        }

        bool removeByValue(int value)
        {
            if (isEmpty())
            {
                std::cout << "List is empty!" << std::endl;
                return false;
            }

            Node* curr = head;

            while(curr)
            {
                if(curr->data == value)
                {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    break;
                }

                curr = curr->next;
            }
            --m_size;

            return true;
        }

        bool find(int value)
        {
            if (isEmpty())
            {
                std::cout << "List is empty!" << std::endl;
                return false;
            }

            Node* curr = head;

            while(curr)
            {
                if(curr->data == value)
                {
                    return true;
                }

                curr = curr->next;
            }

            return false;
        }

        bool isEmpty()
        {
            if (!head && 0 == m_size)
            {
                return true;
            }
            return false;
        }

        int size()
        {
            return m_size;
        }

        void print()
        {
            std::cout << "_______________Print double linked list_______________" << std::endl;

            if (isEmpty())
            {
                std::cout << "List is empty!" << std::endl;
                return;
            }
            
            Node* curr = head;

            while(curr)
            {
                std::cout << curr->data << "   ";
                curr = curr->next;
            }

            std::cout << std::endl;

        }
        void reverse_print()
        {
            std::cout << "_______________Reverse print double linked list_______________" << std::endl;

            if (isEmpty())
            {
                std::cout << "List is empty!" << std::endl;
                return;
            }
            
            Node* curr = tail;

            while(curr)
            {
                std::cout << curr->data << "   ";
                curr = curr->prev;
            }

            std::cout << std::endl;

        }
        int operator[](int pos)
        {
            if (pos <= 0 && pos > m_size)
            {
                std::cout << "Unable to insert!" << std::endl;
                return -1;
            }

            if (isEmpty())
            {
                std::cout << "List is empty!" << std::endl;
                return -1;
            }

            Node* curr = head;

            for(int i = 0; i < pos; ++i)
            {
                curr = curr->next;
            }

            return curr->data;
        }

        bool operator==(const DoubleLinkedList& rhs)
        {
            if(this == &rhs)
            {
                return true;
            }

            if (rhs.m_size != m_size)
            {
                return false;
            }

            Node* curr = head;
            Node* rhsCurr = rhs.head;

            for(int i = 0; i < m_size; ++i)
            {
                if(curr->data != rhsCurr->data)
                {
                    return false;
                }
            }

            return true;
        }

    private:
        int m_size = 0;
        Node* head = nullptr;
        Node* tail = nullptr;
};