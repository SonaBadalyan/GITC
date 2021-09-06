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
                Node* parent = nullptr;
        };

        bool isEmpty()
        {
            return root == nullptr;
        }

        bool find(int val)
        {
            if(find(root, val))
            {
                return true;
            }

            return false;
        }

        void add(int val)
        {
            return add(val, root);
        }

        void print()
        {
            print(root);
        }

        bool deleteNode(int val)
        {
            return deleteNode(val, root, true);
        }

    private:

        void add(int val, Node* temp)
        {
            if(temp == nullptr)
            {
                root = new Node(val);
            }
            else if(temp->data > val)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(val);
                    temp->left->parent = temp;
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
                }
                else
                {
                    add(val, temp->right);
                }
                
            }
        }
        

        bool deleteNode(int val, Node* startNode, bool overloaded)
        {
            Node* temp = find(startNode, val, true);

            if (!temp) 
            {
                return false;
            }

            // Node* maxFromMins = temp->left;

            // while(maxFromMins->right)
            // {
            //     maxFromMins = maxFromMins->right;
            // }

            // temp->data = maxFromMins->data;

            // if (!maxFromMins->left && !maxFromMins->right) 
            // {
            //     if (!maxFromMins->parent) 
            //     {
            //         root = temp = maxFromMins = nullptr;
            //         return true; 
            //     }

            //     maxFromMins->parent->right = nullptr;
            //     return true;
            // }

            // if (maxFromMins->left) // && !maxFromMins->right) 
            // {
            //     maxFromMins->parent->right = maxFromMins->left;
            //     maxFromMins->left->parent = maxFromMins->parent;

            //     return true;
            // }

            Node* minFromMaxs = temp->right;

            while(minFromMaxs->left)
            {
                minFromMaxs = minFromMaxs->left;
            }

            temp->data = minFromMaxs->data;

            if (!minFromMaxs->left && !minFromMaxs->right) 
            {
                if (!minFromMaxs->parent) 
                {
                    root = temp = minFromMaxs = nullptr;
                    return true; 
                }

                minFromMaxs->parent->left = nullptr;
                return true;
            }

            if (minFromMaxs->right) // && !minFromMaxs->left) 
            {
                minFromMaxs->parent->left = minFromMaxs->right;
                minFromMaxs->right->parent = minFromMaxs->parent;

                return true;
            }

            return false;

        }

        bool deleteNode(int val, Node* startNode)
        {
            Node* temp = find(startNode, val, true);

            if (!temp) // if in the tree no such node
            {
                return false;
            }

            // We may have 3 cases.
            // Found node may have
            // 1. 0 
            // 2. 1 
            // 3. 2 
            // children.

            // Case 1, found node have zero child, it is a leaf.
            // So we simply set parent pointer to it`s child to null.

            if (!temp->left && !temp->right) // if found node is leaf node
            {
                if (!temp->parent) // if found node is root
                {
                    root = temp = nullptr;
                    return true; 
                }

                if (temp->parent->data > val) // remove left leaf
                {
                    temp->parent->left = nullptr;
                    return true;
                }
                if (temp->parent->data < val) // remove right leaf
                {
                    temp->parent->right = nullptr;
                    return true;
                } 
            }

            // Case 2, found node have one child, it is a internal node.
            // In this case, we just remove found node, by redirecting parent pointer to the subtree that point child node.

            if (temp->left && !temp->right) // if node have only left child
            {
                if (temp->parent->left == temp) // if remove node is left node for it`s parent node
                {
                    temp->parent->left = temp->left; 
                    temp->left->parent = temp->parent;

                    return true;
                }
                else if (temp->parent->right == temp) // if remove node is right node for it`s parent node
                {
                    temp->parent->right = temp->left;
                    temp->right->parent = temp->parent;

                    return true;
                }
            }

            if (!temp->left && temp->right) // if node have only right child
            {
                if (temp->parent->left == temp) // if remove node is left node for it`s parent node
                {
                    temp->parent->left = temp->right;
                    temp->left->parent = temp->parent;

                    return true;
                }
                else if (temp->parent->right == temp) // if remove node is right node for it`s parent node
                {
                    temp->parent->right = temp->right;
                    temp->right->parent = temp->parent;

                    return true;
                }
            }

            // Case 3, found node have two children.
            // It`s the most complicated case. We may choose from two options.
            // We can remove node by replacing it from.
            // 1. left subtrees maximum element,
            // or
            // 2. right subtree minimum element.

            // 1. left subtrees maximum element

            Node* maxElem = max(temp->left);

            temp->data = maxElem->data;

            if (maxElem->parent->left == maxElem)
            {
                maxElem->parent->left = nullptr;
                return true;
            }
            else if (maxElem->parent->right == maxElem)
            {
                maxElem->parent->right = nullptr;
                return true;
            }

            // 2. right subtree minimum element.

            // Node* minElem = min(temp->right);

            // temp->data = minElem->data;

            // if (minElem->parent->left == minElem)
            // {
            //     minElem->parent->left = nullptr;
            //     return true;
            // }
            // else if (minElem->parent->right == minElem)
            // {
            //     minElem->parent->right = nullptr;
            //     return true;
            // }

            return false;

        }

        Node* max(Node* startNode)
        {
            Node* leftSubtreeMax;

            if (!startNode->left)
            {
                leftSubtreeMax = startNode;
            }
            else
            {
                leftSubtreeMax = max( startNode->left );
            }

            Node* rightSubtreeMax;

            if (!startNode->right)
            {
                rightSubtreeMax = startNode;
            }
            else
            {
                rightSubtreeMax = max( startNode->right );
            }

            if (leftSubtreeMax->data > rightSubtreeMax->data)
            {
                return leftSubtreeMax;
            }
            else
            {
                return rightSubtreeMax;
            }
        }

        Node* min(Node* startNode)
        {
            Node* leftSubtreeMin;

            if (!startNode->left)
            {
                leftSubtreeMin = startNode;
            }
            else
            {
                leftSubtreeMin = min( startNode->left );
            }

            Node* rightSubtreeMin;

            if (!startNode->right)
            {
                rightSubtreeMin = startNode;
            }
            else
            {
                rightSubtreeMin = min( startNode->right );
            }

            if (leftSubtreeMin->data < rightSubtreeMin->data)
            {
                return leftSubtreeMin;
            }
            else
            {
                return rightSubtreeMin;
            }
        }

        void print(Node* temp) // It is inorder print 
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

        Node* find(Node* temp, int val, bool overloaded)
        {
            if (temp == nullptr)
            {
                return nullptr;
            }

            if (temp->data == val)
            {
                return temp;
            }
            else if (temp->data > val)
            {
                return find(temp->left, val, overloaded);
            }
            else if (temp->data < val)
            {
                return find(temp->right, val, overloaded);
            }

            return nullptr;
        }

        // bool deleteNode(int val, Node* temp)
        // {
        //     Node* parent = temp;
        //     bool isLeft = false;
            
        //     while(temp != nullptr)
        //     {
        //         if(temp->data > val)
        //         {
        //             parent = temp;
        //             temp = temp->right;
        //             isLeft = false;
        //         }
        //         if(temp->data < val)
        //         {
        //             parent = temp;
        //             temp = temp->left;
        //             isLeft = true;
        //         }
        //     }

        //     if (isLeft)
        //     {
        //         parent->left = nullptr;
        //         return true;
        //     }
        //     else
        //     {
        //         parent->right = nullptr;
        //         return true;
        //     }

        //     return false;
        // }

    private:
        Node* root = nullptr;
};

int main()
{
    BST bst;

    bst.add(500);
    bst.add(250);
    bst.add(200);
    bst.add(100);
    bst.add(220);
    bst.add(150);
    bst.add(300);
    bst.add(400);
    bst.add(1000);
    bst.add(900);
    bst.add(600);
    bst.add(950);
    bst.add(2000);
    bst.add(1500);
    bst.add(3000);

    if(bst.find(200))
    {
        std::cout << "found" << std::endl;
    }

    bst.deleteNode(250);

    bst.print();

    return 0;
}