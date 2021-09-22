#include <iostream>
#include <string>

class Map
{
    public:

        struct Node
        {
            public:

                Node (int key, int value)
                {
                    m_key = key;
                    m_value = value;
                }

                int m_value = 0 ;
                int m_key = 0;

                Node* m_next = nullptr;
                Node* m_prev = nullptr; 
        };

        Map()
        {
            m_length = 0;
            head = nullptr;
            tail = nullptr;
        }

        bool push_front(int key, int value)
        {
            if (is_empty())
            {
                Node* newNode = new Node(key, value);
                head = tail = newNode;
                ++m_length;

                return true;
            }

            if (-1 == find(key))
            {
                Node* newNode = new Node(key, value);
                newNode->m_next = head;
                head->m_prev = newNode;
                head = newNode;

                ++m_length;

                return true;
            }

            return false;
        }

        bool push_index(int index, int key, int value)
        {
            if (0 >= index || index > m_length)
            {
                return false;
            }

            if (is_empty())
            {
                Node* newNode = new Node(key, value);
                head = tail = newNode;
                ++m_length;

                return true;
            }

            if (-1 == find(key))
            {
                if (1 == index)
                {
                    push_front(key, value);
                    return true;
                }
                if (m_length == index)
                {
                    push_back(key, value);
                    return true;
                }

                Node* curr = head;

                for(int i = 1; i < index; ++i)
                {
                    curr = curr->m_next;
                }

                Node* newNode = new Node(key, value);

                Node* next = curr->m_next;
                curr->m_next = newNode;
                newNode->m_prev = curr;
                newNode->m_next = next;
                next->m_prev = newNode;
                
                ++m_length;
                
                return true;
            }

            return false;

        }

        bool push_back(int key, int value)
        {
            Node* newNode = new Node(key, value);

            if (is_empty())
            {
                head = tail = newNode;
                ++m_length;

                return true;
            }

            if (-1 == find(key))
            {
                tail->m_next = newNode;
                newNode->m_prev = tail;
                tail = newNode;

                ++m_length;
                
                return true;
            }

            return false;
        }

        int pop_front()
        {
            if (is_empty())
            {
                return -1; 
            }

            int return_value = head->m_value;

            if (head == tail)
            {
                --m_length;
                head = tail = nullptr;

                return return_value;
            }

            --m_length;

            head = head->m_next;
            head->m_prev = nullptr;

            return return_value;

        }

        int pop_index(int index)
        {
            if (0 >= index || index > m_length)
            {
                return -1;
            }

            if (is_empty())
            {
                return -1; 
            }

            if (1 == index)
            {
                return pop_front();
            }

            if (m_length == index)
            {
                return pop_back();
            }

            Node* curr = head;

            for(int i = 1; i < index; ++i)
            {
                curr = curr->m_next;  
            }

            int return_value = curr->m_value;

            curr->m_prev->m_next = curr->m_next;
            curr->m_next->m_prev = curr->m_prev;

            --m_length;

            return return_value;
        }

        int pop_back()
        {
            if (is_empty())
            {
                return -1; 
            }

            int return_value = tail->m_value;

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

        int find(int key)
        {
            Node* curr = head;

            while(curr)
            {
                if(key == curr->m_key)
                {
                    return curr->m_value;
                }

                curr = curr->m_next;
            }

            return -1;
        }

        bool is_empty()
        {
            if (!head && 0 == m_length)
            {
                return true;
            }
            return false;
        }

        void print()
        {

            std::cout << "_______________Print map_______________" << std::endl;

            if (is_empty())
            {
                return;
            }

            Node* curr = head;

            while (curr)
            {
                std::cout << "Key : " << curr->m_key << ",  ";
                std::cout << "Value : " << curr->m_value << std::endl;
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
    Map map;

    if (map.push_front(2, 2) &&
        map.push_front(1, 1) &&
        map.push_back(5, 5) &&
        map.push_index(2, 3, 3) &&
        map.push_index(3, 4, 4))
    {
        std::cout << "pushed" <<std::endl;
    }

    if (!map.push_front(1, 10))
    {
        std::cout << 1 << " key alredy exist." <<std::endl;
    }

    if (-1 != map.find(5))
    {
        std::cout << 5 << " key found." << std::endl;
    }

    map.print();

    std::cout << map.pop_front() << std::endl;
    std::cout << map.pop_back() << std::endl;
    map.print();

    std::cout << map.pop_index(2) << std::endl;
    std::cout << map.pop_index(5) << std::endl;
    std::cout << map.pop_index(0) << std::endl;

    map.print();

    return 0;
}

