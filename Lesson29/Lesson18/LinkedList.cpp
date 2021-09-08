#include <iostream>

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

                    delete curr;
                    curr = nullptr;

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

            delete curr;
            curr = nullptr;

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

                delete head;
                head = tail = nullptr;
                return true;
            }

            --m_length;

            tail = tail->m_prev;
            delete tail->m_next;
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
            delete head->m_prev;
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

        ~LinkedList()
        {
            if (head)
            {
                while(head->m_next)
                {
                    head = head->m_next;
                    delete head->m_prev;
                }

                delete head;
                head = tail = nullptr;
            }
        }

    private:

        int m_length;
        Node* head;
        Node* tail;
};

int main()
{
    LinkedList list;

    list.add(10);
    list.add(20);
    list.addFront(0);
    list.addFront(-10);
    list.add(30);
    list.add(60);
    
    list.print();
    list.reversePrint();
    
    std::cout << "Is empty " << list.isEmpty() << std::endl;
    
    list.insert(4, 40);
    list.print();
    list.insert(5, 50);
    list.print();
    
    std::cout << list.removeByValue(0) << std::endl;
    list.print();
    
    list.remove(5);
    list.print();
    
    list.deleteFront();
    list.print();

    list.deleteBack();
    list.print();
    
    std::cout << "list[5] " << list[5] << std::endl;
    std::cout << "list[0] " << list[0] << std::endl;
    std::cout << "list[3] " << list[3] << std::endl;
    std::cout << "ist[4] " << list[4] << std::endl;
    
    std::cout << "list.find(10) " << list.find(10) << std::endl;
    std::cout << "list.find(20) " << list.find(20) << std::endl;
    std::cout << "list.find(-10) " << list.find(-10) << std::endl;
    std::cout << "list.find(100) " << list.find(100) << std::endl;
    
    std::cout << list.length() << std::endl;

    LinkedList list1(list);
    list1.print();
    list.print();
    
    std::cout << "list1 == list : " << (list1 == list) << std::endl;
 
    // list.deleteBack();
    // list.deleteBack();
    // list.deleteFront();
    // list.deleteFront();
    
    std::cout << "list1 == list : " << (list1 == list) << std::endl;
    std::cout << list.length() << std::endl;
    
    return 0;
}