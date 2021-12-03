#include <iostream>

class BST
{
    public:

        class Node
        {
            public:
                Node(int data)
                {
                    this->data = data;
                }

                int data;
                Node* left = nullptr;
                Node* right = nullptr;
        };

        bool isEmpty()
        {
            return root == nullptr;
        }

        bool find(int val)
        {
            return find(root, val);
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

        void add(int val, Node* temp)
        {
            if(isEmpty())
            {
                root = new Node(val);
            }
            else if(val > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(val);
                }
                else
                {
                    add(val, temp->right);
                }
                
            }
            else if(val < temp->data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(val);
                }
                else
                {
                    add(val, temp->left);
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

        bool find(Node* temp, int val)
        {
            if (temp == nullptr)
            {
                return false;
            }

            if (temp->data == val)
            {
                return true;
            }
            else if (temp->data > val)
            {
                return find(temp->left, val);
            }
            else if (temp->data < val)
            {
                return find(temp->right, val);
            }

            return false;
        }

    private:
        Node* root = nullptr;

};

int main()
{
    BST bst;

    bst.add(100);
    bst.add(50);
    bst.add(200);
    bst.add(0);

    if(bst.find(200))
    {
        std::cout << "found" << std::endl;
    }

    bst.print();

    return 0;
}