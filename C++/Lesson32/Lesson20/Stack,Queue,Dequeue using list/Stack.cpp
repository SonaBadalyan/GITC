#include <iostream>

class Stack
{
    public:

        struct Node
        {
            public:

                Node (int data)
                {
                    m_data = data;
                }

                int m_data = 0;
                Node* m_next = nullptr;
                Node* m_prev = nullptr; 
        };

        Stack()
        {
            m_length = 0;
            head = nullptr;
            tail = nullptr;
        }

        void push(int val)
        {
            Node* temp = new Node(val);

            if (isEmpty())
            {
                head = tail = temp;
                return;
            }

            tail->m_next = temp;
            temp->m_prev = tail;
            tail = temp;

            ++m_length;
        }

        int pop()
        {
            if (isEmpty())
            {
                return -1; 
            }

            int data = tail->m_data;

            if (head == tail)
            {
                --m_length;

                head = tail = nullptr;
                return data;
            }

            --m_length;

            tail = tail->m_prev;
            tail->m_next = nullptr;

            return data;
        }

        void print()
        {
            std::cout << "_________________Print stack_____________" << std::endl;

            if (isEmpty())
            {
                return;
            }

            Node* curr = head;

            while (curr)
            {
                std::cout << curr->m_data << "   ";
                curr = curr->m_next;
            }
            
            std::cout << std::endl;
        }

        bool isEmpty()
        {
            if (nullptr == head)
            {
                return true;
            }

            return false;
        }

    private:

        int m_length;
        Node* head;
        Node* tail;
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);
    stack.push(110);
    stack.print();

    std::cout << "stack.isEmpty() " << stack.isEmpty() << std::endl;

    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;
    std::cout << "stack pop " << stack.pop() << std::endl;

    std::cout << "stack.isEmpty() " << stack.isEmpty() << std::endl;

    stack.print();

    return 0;
}