#include <iostream>

class Map
{
    public: 

        bool push_front(int key, int value)
        {
            if (is_full())
            {
                return false;
            }

            if (-1 == find(key))
            {
                for (int i = m_size; i > 0; --i)
                {
                    values[i] = values[i - 1];
                    keys[i] = keys[i - 1];
                }

                values[0] = value;
                keys[0] = key;

                ++m_size;

                return true;
            }
            return false;
        }

        bool push_index(int index, int key, int value)
        {
            if (index <= 0 || index > m_size)
            {
                return false;
            }

            if (is_full())
            {
                return false;
            }

            if (-1 == find(key))
            {
                if (1 == index)
                {
                    return push_front(key, value);
                }

                if (m_size == index)
                {
                    return push_back(key, value);
                }

                for (int i = m_size; i > index; --i)
                {
                    values[i] = values[i - 1];
                    keys[i] = keys[i - 1];
                }

                values[index] = value;
                keys[index] = key;

                ++m_size;

                return true;
            }
            return false;
        }

        bool push_back(int key, int value)
        {
            if (is_full())
            {
                return false;
            }
            
            if (-1 == find(key))
            {
                keys[m_size] = key;
                values[m_size] = value;
                ++m_size;

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

            int return_value = values[0];

            for(int i = 0; i < m_size; ++i)
            {
                keys[i] = keys[i + 1];
                values[i] = values[i + 1];
            }
            --m_size;

            return return_value; 
        }

        int pop_index(int index)
        {
            if (index <= 0 || index > m_size)
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

            if (m_size == index)
            {
                return pop_back();
            }

            int return_value = values[index - 1];

            for (int i = index - 1; i < m_size; ++i)
            {
                keys[i] = keys[i + 1];
                values[i] = values[i + 1];
            }

            --m_size;
            return return_value;
        }

        int pop_back()
        {
            if (is_empty())
            {
                return -1;
            }

            return values[--m_size];
        }

        int find(int key)
        {
            for (int i = 0; i < m_size; ++i)
            {
                if (keys[i] == key)
                {
                    return values[i];
                }
            }
            return -1; 
        }

        bool is_empty()
        {
            if ( 0 == m_size)
            {
                return true;
            }
            return false;
        }

        bool is_full()
        {
            if (m_size == m_capacity)
            {
                return true;
            }
            return false;
        }

        void print()
        {
            std::cout << "___________Print map ___________" << std::endl;

            for (int i = 0; i < m_size; ++i)
            {
                std::cout << "Key : " << keys[i] <<",  values : " << values[i] << std::endl;
            }

            std::cout << std::endl;
        }

    private:

        int m_capacity = sizeof(keys)/sizeof(keys[0]);
        int m_size = 0;
        int keys[20];
        int values[20];
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