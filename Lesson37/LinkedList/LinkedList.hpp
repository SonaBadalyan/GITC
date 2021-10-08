template<class T>
class LinkedList
{
    class Node
    {
        public:

            Node (T data)
            {
                m_data = data;
            }

            T m_data = 0;
            Node* m_next = nullptr;
            Node* m_prev = nullptr; 
    };
    
    public:

        LinkedList();

        LinkedList(const LinkedList& rhs);

        bool operator==(const LinkedList& rhs);

        bool find(T val);

        bool removeByValue(T value);

        bool remove(int index);
        
        T operator[](int index);

        bool deleteBack();

        bool deleteFront();

        void add(T data);

        void addFront(T data);

        bool insert(int index, T val);

        bool isEmpty();

        void print();

        void reversePrint();

        int length();

        ~LinkedList();

    private:

        int m_length;
        Node* head;
        Node* tail;
};
