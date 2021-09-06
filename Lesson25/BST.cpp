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
            return deleteNode(val, root);
        }

        bool operator==(const BST& other)
        {
            if (this == &other)
            {
                return true;
            }

            if (size != other.size)
            {
                return false;
            }

            if(!root && !other.root) 
            {
                return true;
            }

            if(!root && other.root) 
            {
                return false;
            }

            if(root && !other.root) 
            {
                return false;
            }

            return subtreesEquality(root, other.root);
        }

    private:

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
        

        bool isLeaf(Node* node)
        {
            return !node->right && !node->left;
        }

        bool isRoot(Node* node)
        {
            return !node->parent;
        }

        bool deleteNode(int val, Node* startNode, bool overloaded)
        {
            Node* temp = find(startNode, val, true);

            if (!temp) 
            {
                return false;
            }

            if (isLeaf(temp))
            {
                if (isRoot(temp)) 
                {
                    root = nullptr;
                    --size;
                    return true; 
                }

                if(temp->parent->left == temp)
                {
                    temp->parent->left = nullptr;
                    --size;
                    return true;
                }
                else if(temp->parent->right == temp)
                {
                    temp->parent->right = nullptr;
                    --size;
                    return true;
                }
            }

            if(temp->left && !temp->right)
            {
                temp->parent = temp->left;
                temp->left->parent = temp->parent;
                --size;
                return true;
            }
            if(!temp->left && temp->right)
            {
                temp->parent = temp->right;
                temp->right->parent = temp->parent;
                --size;
                return true;
            }

            // Algorithm guarantee that node has two children.
            
            // Node* temp2;

            // if(temp->left)
            // {
            //     temp2 = temp->left;

            //     while(temp2->right)
            //     {
            //         temp2 = temp2->right; 
            //     }
            // }
            // temp->data = temp2->data;

            Node* temp3;

            if(temp->right)
            {
                temp3 = temp->right;

                while(temp3->left)
                {
                    temp3 = temp3->left; 
                }
            }

            temp->data = temp3->data;

            return deleteNode(temp3->data, temp3, true); 
            // At this point, tamp3 have one child.
            // It doesn't matter where located temp3, in pre leaf level, or in somewhere higher level - 
            // If it`s have one chile, we must just redirect temp3 parent pointer to temp3 child pointer. Thats all.

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
                    --size;
                    return true; 
                }

                if (temp->parent->data > val) // remove left leaf
                {
                    temp->parent->left = nullptr;
                    --size;
                    return true;
                }
                if (temp->parent->data < val) // remove right leaf
                {
                    temp->parent->right = nullptr;
                    --size;
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

                    --size;
                    return true;
                }
                else if (temp->parent->right == temp) // if remove node is right node for it`s parent node
                {
                    temp->parent->right = temp->left;
                    temp->right->parent = temp->parent;

                    --size;
                    return true;
                }
            }

            if (!temp->left && temp->right) // if node have only right child
            {
                if (temp->parent->left == temp) // if remove node is left node for it`s parent node
                {
                    temp->parent->left = temp->right;
                    temp->left->parent = temp->parent;

                    --size;
                    return true;
                }
                else if (temp->parent->right == temp) // if remove node is right node for it`s parent node
                {
                    temp->parent->right = temp->right;
                    temp->right->parent = temp->parent;

                    --size;
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
                --size;
                return true;
            }
            else if (maxElem->parent->right == maxElem)
            {
                maxElem->parent->right = nullptr;
                --size;
                return true;
            }

            // 2. right subtree minimum element.

            // Node* minElem = min(temp->right);

            // temp->data = minElem->data;

            // if (minElem->parent->left == minElem)
            // {
            //     minElem->parent->left = nullptr;
            //     --size;
            //     return true;
            // }
            // else if (minElem->parent->right == minElem)
            // {
            //     minElem->parent->right = nullptr;
            //     --size;
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

        bool subtreesEquality(const Node* lhs, const Node* rhs)
        {
            if(!lhs && !rhs) 
            {
                return true;
            }

            if(!lhs && rhs) 
            {
                return false;
            }

            if(lhs && !rhs) 
            {
                return false;
            }

            if(lhs->data == rhs->data)
            {
                if (subtreesEquality(lhs->left, rhs->left) && 
                    subtreesEquality(lhs->right, rhs->right))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            return false;
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
    bst.add(900);
    bst.add(830);
    bst.add(820);
    bst.add(850);
    bst.add(950);
    bst.add(940);
    bst.add(975);
    bst.add(760);
    bst.add(780);
    bst.add(790);
    bst.add(765);
    bst.add(767);
    bst.add(764);
    bst.add(763);

    // if(bst.find(200))
    // {
    //     std::cout << "found" << std::endl;
    // }

    // bst.deleteNode(800);

    // bst.print();

    BST bst1;

    bst1.add(500);
    bst1.add(250);
    bst1.add(750);
    bst1.add(800);
    bst1.add(770);
    bst1.add(900);
    bst1.add(830);
    bst1.add(820);
    bst1.add(850);
    bst1.add(950);
    bst1.add(940);
    bst1.add(975);
    bst1.add(760);
    bst1.add(780);
    bst1.add(790);
    bst1.add(765);
    bst1.add(767);
    bst1.add(764);
    bst1.add(763);

    bst1.add(678);

    if (bst == bst1)
    {
        std::cout << "Binary search trees are equal." << std::endl;
    }
    else if (!(bst == bst1))
    {
        std::cout << "Binary search trees are not equal." << std::endl;
    }

    return 0;

}