#include <iostream>

class Queue
{
    public:

        void push(int val)
        {
            array[index_push++] = val;
        }

        int pop()
        {
            return array[index_pop++];
        }

        void print()
        {
            std::cout << "_________________Print queue_____________" << std::endl;

            int i = index_pop;

            while(i < index_push)
            {
                std::cout << array[i++] << "  ";
            }

            std::cout << std::endl;
            std::cout << std::endl;
        }

    private:

        int index_pop = 0;
        int index_push = 0;
        int array[10];
};

int main()
{
    Queue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);

    queue.print();

    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;

    queue.print();

    queue.push(50);
    queue.push(60);
    queue.push(70);
    queue.push(80);
    queue.push(90);
    queue.push(100);

    queue.print();

    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;
    std::cout << "Queue pop " << queue.pop() << std::endl;

    queue.print();

    return 0;
}