class RBT
{
    class Node
    {
        public:

            Node(int data) : m_data{data}
            {}

            int m_data;
            bool color = 1; // 0 - black, 1 - red, all newly created nodes must have red color, so I set up it 1 (red) by default.
            Node* left = nullptr;
            Node* right = nullptr;
            Node* parent;
    };

    void insert(int data)
    {
        if (!root)
        {
            root = new Node(data);
            root->color = 0; // root node must be black, it is a condition of being the RBT tree
            return;
        }


    }

    private:
        Node* root = nullptr;
};