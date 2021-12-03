#include <iostream>
#include <cstdlib>
#include <sstream>

class Dequeue
{
    public:

        void push_front(int val)
        {
            if (isFull()) 
            {
                std::cout << "Dequeue is full!" << std::endl;
            }
            else 
            {
                if (isEmpty())
                {
                    front = 0;
                }
                if (0 == front)
                {
                    front = size - 1;
                }
                else
                {
                    --front;
                }
                array[front] = val;
            }
        }

        int pop_front()
        {
           if (isEmpty())
            {
                std::cout << "Dequeue is empty!" << std::endl;
                return -1;
            }
            else 
            {
                if (front == back)
                {
                    int val = array[front];
                    front = back = -1;
                    return val;
                }
                else if (size -1  == front)
                {
                    int val = array[front];
                    front = 0;
                    return val;
                }
                else
                {
                    int val = array[front];
                    ++front;
                    return val;
                }
            }
        }

        void push_back(int val)
        {
            if (isFull()) 
            {
                std::cout << "Dequeue is full!" << std::endl;
            }
            else 
            {
                if (isEmpty())
                {
                    front = back = 0;
                }
                if (size - 1 == back)
                {
                    back = 0;
                }
                else
                {
                    ++back;
                }
                array[back] = val;
            }
        }

        int pop_back()
        {
            if (isEmpty())
            {
                std::cout << "Dequeue is empty!" << std::endl;
                return -1;
            }
            else 
            {
                if (back == front) 
                {
                    int val = array[back];
                    front = back = -1;
                    return val;
                }
                else if (back == 0)
                {
                    int val = array[back];
                    back = size - 1;
                    return val;
                }
                else
                {
                    int val = array[back];
                    --back;
                    return val;
                }
            }
        }

        bool isFull()
        {
            if ((front == 0 && back == size - 1) ||
                (front == back + 1))
            {
                return true;
            }

            return false;
        }

        bool isEmpty() const
        {
            if (-1 == front && -1 == back)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void print(std::ostream& output = std::cout) const
        {
            output << "_________________Print dequeue_____________" << std::endl;

            if (isEmpty())
            {
                output << "Empty dequeue!" << std::endl;
            }
            else 
            {
                int i = front;

                while(i != back)
                {
                    output << array[i] << "  ";
                    i = (i + 1) % size;
                }

                output << array[back] << std::endl;
            }
        }

        friend std::ostream& operator<<(std::ostream& output, const Dequeue& deque);
        friend std::istream& operator>>(std::istream& input, Dequeue& deque);

    private:

        int array[10];
        int size = sizeof(array)/sizeof(array[1]);
        int front = -1;
        int back = -1;
};
std::ostream& operator<<(std::ostream& output, const Dequeue& deque)
{
    deque.print(output);
    return output;
}

std::istream& operator>>(std::istream& input, Dequeue& deque)
{
    std::cout << "Please enter numbers for inserting in to the dequeue." << std::endl;

    std::string numbers;
    std::getline(input, numbers);

    std::stringstream ss(numbers);
    std::string number;

    while(std::getline(ss, number, ' '))
    {
        deque.push_back(atoi(number.c_str()));
    }

    return input;
}

int main()
{
    Dequeue dequeue;
    
    std::cin >> dequeue;
    std::cout << dequeue;

    return 0;
}