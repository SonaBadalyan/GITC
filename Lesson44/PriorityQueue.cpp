#include <iostream>

template<typename T>
class PriorityQueue
{
    public:

        void push(T val)
        {
            if (index_push  == sizeof(array)/sizeof(array[0]))
            {
                throw  "Priority queue is full!";
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

        T pop()
        {
            if (10 <= index_pop)
            {
                throw "Trying to pop element from empty priority queue!"; 
            }

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
        T array[10];
};

int main()
{
    PriorityQueue<int> pQueue;

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
    pQueue.push(120);
    pQueue.push(4);
    pQueue.push(354);

    try
    {
        pQueue.push(140);
    }
    catch(char const * e)
    {
        std::cout << e<< std::endl;
    }
    
    pQueue.print();

    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;
    std::cout << "Queue pop " << pQueue.pop() << std::endl;

    try
    {
        std::cout << "Queue pop " << pQueue.pop() << std::endl;
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
    }
    
    pQueue.print();

    return 0;
}