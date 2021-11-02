#include <string>
#include <stdexcept>
#include <iostream>
#include <cstring>

class OutOfBoundException : public std::out_of_range
{
    public:

        OutOfBoundException(std::string message, int index, int start, int end) : std::out_of_range(message)
        {
            this->message = message;
            this->index = index;
            this->start = start;
            this->end = end;
        }

        const char* what() const noexcept
        {
            std::string result = message + "index: " + std::to_string(index) + ", start: " + std::to_string(start) + ", end: " + std::to_string(end);
            return result.c_str();
        }

    private:

        std::string message;
        int index;
        int start;
        int end;
};

int main()
{
    int SIZE = 5;
    int arr[SIZE] = {0};

    std::cout << "Please enter the index for inserting one to the array." << std::endl;

    int index;

    std::cin >> index;

    try
    {
        if (index < 0 || index > SIZE - 1)
        {
            throw OutOfBoundException("Can`t insert into the incorrect position.", index, 0, SIZE - 1);
        }

        arr[index] = 1;
    }
    catch(const OutOfBoundException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}