#include <iostream>
#include <cstdlib>
#include <sstream>

class LinkedList
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

        LinkedList()
        {
            m_length = 0;
            head = nullptr;
            tail = nullptr; 
        }

        LinkedList(const LinkedList& rhs)
        {
            if (this == &rhs)
            {
                return;
            }

            m_length = 0;
            head = nullptr;
            tail = nullptr; 
        
            Node* newNode = rhs.head;

            while(newNode)
            {
                Node* temp = new Node(newNode->m_data);

                if (!head)
                {
                    head = tail = temp;
                    newNode = newNode->m_next;
                    continue;
                }

                tail->m_next = temp;
                temp->m_prev = tail;
                tail = temp;

                ++m_length;

                newNode = newNode->m_next;
            }
        }

        bool operator==(const LinkedList& rhs)
        {
            if (this == &rhs)
            {
                return true;
            }

            if(m_length != rhs.m_length)
            {
                return false;
            }

            Node* curr = head;
            Node* rhs_curr = rhs.head;

            for (int i = 0; i < m_length; ++i)
            {
                if (curr->m_data != rhs_curr->m_data)
                {
                    return false;
                }

                curr = curr->m_next;
                rhs_curr = rhs_curr->m_next;
            }

            return true;
        }

        bool find(int val)
        {
            Node* curr = head;

            while(curr)
            {
                if(val == curr->m_data)
                {
                    return true;
                }

                curr = curr->m_next;
            }

            return false;
        }

        bool removeByValue(int value)
        {
            if(!head)
            {
                std::cout << "List is empty!" << std::endl;
                return false;
            }

            Node* curr = head;

            while(curr)
            {
                if(curr->m_data == value)
                {
                    curr->m_prev->m_next = curr->m_next;
                    curr->m_next->m_prev = curr->m_prev;
                    
                    --m_length;
                    return true;
                }
                curr = curr->m_next;
            }

            return false;
        }

        bool remove(int index)
        {
            if (index < 0 || index > m_length)
            {
                return false;
            }

            if ( 0 == index )
            {
                return deleteFront();
            }

            if (m_length == index)
            {
               return deleteBack();
            }

            Node* curr = head;

            for(int i = 0; i < index; ++i)
            {
                curr = curr->m_next;  
            }

            curr->m_prev->m_next = curr->m_next;
            curr->m_next->m_prev = curr->m_prev;

            --m_length;

            return true;
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

        bool deleteBack()
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

        bool deleteFront()
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

        void add(int data)
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

        void addFront(int data)
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

        bool insert(int index, int val)
        {
            if (index < 0 && index > m_length)
            {
                return false;
            }

            if(0 == index)
            {
                addFront(val);
                return true;
            }

            if(m_length == index)
            {
                add(val);
                return true;
            }

            Node* curr = head;

            for(int i = 0; i < index; ++i)
            {
                curr = curr->m_next;
            }

            Node* newNode = new Node(val);
            Node* next = curr->m_next;
            curr->m_next = newNode;
            newNode->m_prev = curr;
            newNode->m_next = next;
            next->m_prev = newNode;
            
            ++m_length;
            
            return true;
        }

        bool isEmpty() const
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

        void reversePrint()
        {
            std::cout << "_______________Reverse print linked list_______________" << std::endl;

            if (isEmpty())
            {
                return;
            }

            Node* curr = tail;

            while (curr)
            {
                std::cout << curr->m_data << "   ";
                curr = curr->m_prev;
            }
            
            std::cout << std::endl;
        }

        int length()
        {
            return m_length;
        }

        friend std::ostream& operator<<(std::ostream& output, const LinkedList& ll);
        friend std::istream& operator>>(std::istream& input, LinkedList& ll);

    private:

        int m_length;
        Node* head;
        Node* tail;
};

std::ostream& operator<<(std::ostream& output, const LinkedList& ll)
{
    output << "_______________Print linked list_______________" << std::endl;

    if (ll.isEmpty())
    {
        output << "Linked list is empty!" << std::endl;
        return output;
    }

    LinkedList::Node* curr = ll.head;

    while (curr)
    {
        output << curr->m_data << "   ";
        curr = curr->m_next;
    }
    
    output << std::endl;

    return output;
}

std::istream& operator>>(std::istream& input, LinkedList& ll)
{
    std::cout << "Please enter numbers for inserting in to the linked list." << std::endl;

    std::string numbers;
    std::getline(input, numbers);
    std::stringstream ss(numbers);
    std::string number;

    while(std::getline(ss, number, ' '))
    {
        ll.add(atoi(number.c_str()));
    }

    return input;
}

int main()
{
    LinkedList list;

    std::cin >> list;
    std::cout << list;
    
    return 0;
}