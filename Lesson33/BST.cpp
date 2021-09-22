#include <iostream>

class BST
{
    public:

        struct Node
        {
            public:
                Node(int data)
                {
                    this->data = data;
                }

                int data;

                Node* left = nullptr;
                Node* right = nullptr;
                Node* parent = nullptr;
        };

        BST() = default;

        BST(const BST& rhs)
        {
            deepCopy(rhs.root);
        }

        BST& operator=(const BST& rhs)
        {
            if (this == &rhs)
            {
                return *this;
            }

            clear();

            deepCopy(rhs.root);

            return *this;
        }

        void add(int val)
        {
            return add(val, root);
        }

        void print()
        {
            print(root);
        }

    private:

        void deepCopy(Node* startNode)
        {
            if(startNode != nullptr)
            {
                add(startNode->data);
                deepCopy(startNode->left);
                deepCopy(startNode->right);
            }
        }

        void clear()
        {
            destroy(root);
            size = 0;
        }

        void destroy(Node* startNode)
        {
            if(startNode != nullptr)
            {
                destroy(startNode->left);
                destroy(startNode->right);
                delete startNode;
            }
        }
        
        void add(int val, Node* temp)
        {
            if(temp == nullptr)
            {
                root = new Node(val);
                ++size;
            }
            else if(temp->data > val)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(val);
                    temp->left->parent = temp;
                    ++size;
                }
                else
                {
                    add(val, temp->left);
                }
                
            }
            else if(temp->data < val)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(val);
                    temp->right->parent = temp;
                    ++size;
                }
                else
                {
                    add(val, temp->right);
                }
                
            }
        }

        void print(Node* temp)
        {
            if(temp != nullptr)
            {
                print(temp->left);
                std::cout << temp->data << std::endl;
                print(temp->right);
            }
        }

    private:
        Node* root = nullptr;
        int size = 0;
};

int main()
{
    BST bst;

    bst.add(500);
    bst.add(250);
    bst.add(750);
    bst.add(800);
    bst.add(770);

    BST bst1(bst);

    bst1.add(100);
    bst1.add(1000);

    bst1 = bst;

    return 0;
}