class Node
{
    public:

        Node()
        {
            m_data = 0;
            m_next = nullptr;
            m_prev = nullptr;
        }

        Node (int data, Node* next, Node* prev)
        {
            m_data = data;
            m_next = next;
            m_prev = prev;
        }

    private:
    
        int m_data;
        Node* m_next;
        Node* m_prev;
};

int main()
{

    return 0;
}