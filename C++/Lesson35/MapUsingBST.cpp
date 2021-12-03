#include <iostream>

template<class X, class Y>
class Map
{
    public:

        class Node
        {
            public:
                Node(X key, Y value)
                {
                    this->key = key;
                    this->value = value;
                }

                X key;
                Y value;

                Node* left = nullptr;
                Node* right = nullptr;
                Node* parent = nullptr;
        };

        bool isEmpty()
        {
            return root == nullptr;
        }

        bool find(X key)
        {
            if(find(root, key))
            {
                return true;
            }

            return false;
        }

        bool findByValue(Y value)
        {
            if(findByValue(root, value))
            {
                return true;
            }

            return false;
        }

        void add(X key, Y value)
        {
            return add(key, value, root);
        }

        void print()
        {
            print(root);
        }

        bool deleteNode(X key)
        {
            return deleteNode(key, root);
        }

        bool operator==(const Map& other)
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

        ~Map()
        {
            destructor(root);
        }

    private:

        void add(X key, Y value, Node* temp)
        {
            if(temp == nullptr)
            {
                root = new Node(key, value);
                ++size;
                return;
            }

            Node* temp1 = find(temp, key, true);

            if(temp1)
            {
                temp1->value = value; // update value
                // temp1->key = key; // update key
                // If we don`t want to update the value, we can simply return without assignment.
                return;
            }

            if(temp->key > key)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(key, value);
                    temp->left->parent = temp;
                    ++size;
                }
                else
                {
                    add(key, value, temp->left);
                }
                
            }
            else if(temp->key < key)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(key, value);
                    temp->right->parent = temp;
                    ++size;
                }
                else
                {
                    add(key, value, temp->right);
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

        bool deleteNode(X key, Node* startNode, bool overloaded)
        {
            Node* temp = find(startNode, key, true);

            if (!temp) 
            {
                return false;
            }

            if (isLeaf(temp))
            {
                if (isRoot(temp)) 
                {
                    delete root;
                    root = nullptr;

                    --size;

                    return true; 
                }

                if(temp->parent->left == temp)
                {
                    delete temp->parent->left;
                    temp->parent->left = nullptr;

                    --size;

                    return true;
                }
                else if(temp->parent->right == temp)
                {
                    delete temp->parent->right;
                    temp->parent->right = nullptr;

                    --size;

                    return true;
                }
            }

            if(temp->left && !temp->right)
            {
                temp->parent = temp->left;
                temp->left->parent = temp->parent;

                delete temp;
                temp = nullptr;

                --size;

                return true;
            }
            if(!temp->left && temp->right)
            {
                temp->parent = temp->right;
                temp->right->parent = temp->parent;

                delete temp;
                temp = nullptr;

                --size;
                return true;
            }

            Node* temp3;

            if(temp->right)
            {
                temp3 = temp->right;

                while(temp3->left)
                {
                    temp3 = temp3->left; 
                }
            }

            temp->key = temp3->key;
            temp->value = temp3->value;

            return deleteNode(temp3->key, temp3, true); 
        }

        bool deleteNode(X key, Node* startNode)
        {
            Node* temp = find(startNode, key, true);

            if (!temp)
            {
                return false;
            }

            if (!temp->left && !temp->right) 
            {
                if (!temp->parent)
                {
                    delete root;
                    root = temp = nullptr;

                    --size;

                    return true; 
                }

                if (temp->parent->key > key)
                {
                    delete temp->parent->left;
                    temp->parent->left = nullptr;

                    --size;

                    return true;
                }
                if (temp->parent->key < key)
                {
                    delete temp->parent->right;
                    temp->parent->right = nullptr;
                    
                    --size;

                    return true;
                } 
            }
            if (temp->left && !temp->right)
            {
                if (temp->parent->left == temp)
                {
                    temp->parent->left = temp->left; 
                    temp->left->parent = temp->parent;

                    delete temp;
                    temp = nullptr;

                    --size;

                    return true;
                }
                else if (temp->parent->right == temp)
                {
                    temp->parent->right = temp->left;
                    temp->right->parent = temp->parent;

                    delete temp;
                    temp = nullptr;

                    --size;
                    return true;
                }
            }

            if (!temp->left && temp->right)
            {
                if (temp->parent->left == temp)
                {
                    temp->parent->left = temp->right;
                    temp->left->parent = temp->parent;

                    delete temp;
                    temp = nullptr;

                    --size;
                    return true;
                }
                else if (temp->parent->right == temp)
                {
                    temp->parent->right = temp->right;
                    temp->right->parent = temp->parent;

                    delete temp;
                    temp = nullptr;

                    --size;
                    return true;
                }
            }

            Node* maxElem = max(temp->left);

            temp->key = maxElem->key;
            temp->value = maxElem->value;

            if (maxElem->parent->left == maxElem)
            {
                delete maxElem->parent->left;
                maxElem->parent->left = nullptr;

                --size;

                return true;
            }
            else if (maxElem->parent->right == maxElem)
            {
                delete maxElem->parent->right;
                maxElem->parent->right = nullptr;

                --size;

                return true;
            }

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

            if (leftSubtreeMax->key > rightSubtreeMax->key)
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

            if (leftSubtreeMin->key < rightSubtreeMin->key)
            {
                return leftSubtreeMin;
            }
            else
            {
                return rightSubtreeMin;
            }
        }

        void print(Node* temp)
        {
            if(temp != nullptr)
            {
                print(temp->left);
                std::cout <<"KEY : " << temp->key;
                std::cout <<"  VALUE : " << temp->value;
                std::cout << std::endl;
                print(temp->right);
            }
        }

        bool find(Node* temp, X key)
        {
            if (temp == nullptr)
            {
                return false;
            }

            if (temp->key == key)
            {
                return true;
            }
            else if (temp->key > key)
            {
                return find(temp->left, key);
            }
            else if (temp->key < key)
            {
                return find(temp->right, key);
            }

            return false;
        }

        Node* find(Node* temp, X key, bool overloaded)
        {
            if (temp == nullptr)
            {
                return nullptr;
            }

            if (temp->key == key)
            {
                return temp;
            }
            else if (temp->key > key)
            {
                return find(temp->left, key, overloaded);
            }
            else if (temp->key < key)
            {
                return find(temp->right, key, overloaded);
            }

            return nullptr;
        }

        bool findByValue(Node* temp, Y value)
        {
            bool leftFound;
            bool rightFound;

            if(temp != nullptr)
            {
                leftFound = findByValue(temp->left, value);
                rightFound = findByValue(temp->right, value);

                if (temp->value == value)
                {
                    return true;
                }
            }

            if(leftFound || rightFound)
            {
                return true;
            }
            else
            {
                return false;
            }
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

            if(lhs->key == rhs->key && lhs->value == rhs->value)
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

        void destructor(Node* startNode)
        {
            if(startNode != nullptr)
            {
                destructor(startNode->left);
                destructor(startNode->right);
                delete startNode;
                startNode = nullptr;
            }
        }

    private:
        Node* root = nullptr;
        int size = 0;
};

int main()
{
    Map<int, int> map;

    map.add(1, 500);
    map.add(2, 250);
    map.add(3, 750);
    map.add(3, 800);
    map.add(6, 770);
    map.add(89, 900);
    map.add(100, 830);
    map.add(0, 820);
    map.add(4, 850);
    map.add(67, 950);
    map.add(924, 40);
    map.add(975, 975);
    // map.print();

    // if(map.find(100))
    // {
    //     std::cout << "found" << std::endl;
    // }

    if(map.findByValue(40))
    {
        std::cout << "found" << std::endl;
    }
    else
    {
        std::cout << "did not found" << std::endl;
    }

    map.deleteNode(800);
    map.deleteNode(89);
    // map.print();

    return 0;

}