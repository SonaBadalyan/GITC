#include <iostream>

class PriorityQueue
{
    public:

        void push(int val)
        {
            if (index_push  == sizeof(array)/sizeof(array[0]))
            {
                std::cout << "Priority queue is full!" << std::endl;
                return;
            }

            if( 0 == index_push )
            {
                array[index_push++] = val;
                return;
            } 

            for (int i = index_pop; i <= index_push; ++i)
            {
                if (array[i] > val)
                {
                    for(int j = index_push; j != i; --j)
                    {
                        array[ j ] = array[j - 1];
                    }

                    array[i] = val;
                    index_push++;
                    break;
                }
            }
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
    PriorityQueue pQueue;

    pQueue.push(10);
    pQueue.push(5);
    pQueue.push(7);
    pQueue.push(20);
    pQueue.push(15);
    
    pQueue.print();

    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;

    pQueue.print();

    pQueue.push(50);
    pQueue.push(24);
    pQueue.push(0);
    pQueue.push(12);
    pQueue.push(190);
    pQueue.push(100);

    pQueue.print();

    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;

    pQueue.print();

    return 0;
}