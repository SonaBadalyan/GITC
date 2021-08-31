#include <iostream>

class AVL
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

        void insert(int val)
        {
            return add(val, root);
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



        std::pair<int, Node*> isBalanced(Node* startNode)
        {
            if (!startNode)
            {
                return std::make_pair(0, nullptr);
            }

            int leftHeight;

            if (!startNode->left)
            {
                leftHeight = 0;
            }
            else
            {
                leftHeight = height(startNode->left);
            }

            int rightHeight;
            
            if (!startNode->right)
            {
                rightHeight = 0;
            }
            else
            {
                rightHeight = height(startNode->right);
            }

            int balanceFactor = leftHeight - rightHeight;
            bool isUnbalanced = balanceFactor < -1 || balanceFactor > 1;

            if (isUnbalanced)
            {
                return std::make_pair(balanceFactor, startNode);
            }
            else
            {
                auto result = isBalanced(startNode->left);
                int leftSubtreeBalanceFactor = result.first;
                bool isLeftUnbalanced = leftSubtreeBalanceFactor <-1 || leftSubtreeBalanceFactor > 1;

                if (isLeftUnbalanced)
                {
                    return std::make_pair(leftSubtreeBalanceFactor, result.second);
                }
                else
                {
                    auto result = isBalanced(startNode->right);
                    int rightSubtreeBalanceFactor = result.first;
                    bool isRightUnbalanced = rightSubtreeBalanceFactor < -1 || rightSubtreeBalanceFactor > 1;

                    if(isRightUnbalanced)
                    {
                        return std::make_pair(rightSubtreeBalanceFactor, result.second);
                    }
                }  
            }

            return std::make_pair(balanceFactor, startNode);;
        }

        int height(Node* startNode)
        {
            if (!startNode)
            {
                return 0;
            }

            int leftHight;

            if (!startNode->left)
            {
                leftHight = 0;
            }
            else
            {
                leftHight = height(startNode->left);
            }

            int rightHight;

            if (!startNode->right)
            {
                rightHight = 0;
            }
            else
            {
                rightHight = height(startNode->right);
            }

            int max = leftHight > rightHight ? leftHight : rightHight;
            
            return ++max;
        }

        void balance(std::pair<int, Node*> pair)
        {
            if (pair.first > 1 && pair.second->data > pair.second->left->data) 
            {
                rightRotate(pair.second);
                return;
            }

            if (pair.first < -1 && pair.second->data > pair.second->right->data) 
            {
                leftRotate(pair.second);
                return;
            }

            if (pair.first > 1 && pair.second->data <  pair.second->left->data) 
            {
                pair.second->left = leftRotate(pair.second->left);
                rightRotate(pair.second);
                return;
            }

            if (pair.first < -1 && pair.second->data < pair.second->right->data) 
            {
                pair.second->right = rightRotate(pair.second->right);
                leftRotate(pair.second);
                return;
            }
        }

    Node* rightRotate(Node* maximum) 
    {
        maximum->parent->left = maximum->left;
        maximum->left->right = maximum;
        maximum->right = nullptr;
        maximum->left = nullptr;

        return maximum;
	}

	Node* leftRotate(Node* minimum) 
    {
		minimum->parent->right = minimum->right;
        minimum->right->left = minimum;
        minimum->right = nullptr;
        minimum->left = nullptr;

		return minimum;
	}

    private:
        Node* root = nullptr;
};

int main()
{
    AVL tree;

    tree.insert(14);
    tree.insert(17);
    tree.insert(11);
    tree.insert(7);
    tree.insert(53);
    tree.insert(4);

    
    tree.insert(13);
    tree.insert(12);
    tree.insert(8);
    tree.insert(60);
    tree.insert(19);
    tree.insert(16);
    tree.insert(20);

    return 0;

}