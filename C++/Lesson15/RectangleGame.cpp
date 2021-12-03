#include <iostream>

class Rectangle
{
    private:
    
    double length;
    double width;
    double area;
    double perimeter;

    public:

    void set_length(double length)
    {
        this->length = length;
        this->area = length * width;
        this->perimeter =  2 * ( length + width );
    }

    void set_width(double width)
    {
        this->width = width;
        this->area = length * width;
        this->perimeter =  2 * ( length + width );
    }

    double get_area()
    {
        return area;
    }

    double get_perimeter()
    {
        return perimeter;
    }
};

int main()
{
    Rectangle rectangle;
    rectangle.set_length(2.5);
    rectangle.set_width(3.5);

    std::cout << "Guess area and perimeter of rectangle when length is 2.5 and width is 3.5." << std::endl;
    
    double area;
    std::cout << "Please enter value for area: ";
    std::cin >> area;
    std::cout << std::endl;

    double perimeter;
    std::cout << "Please enter value for perimeter: ";
    std::cin >> perimeter;
    std::cout << std::endl;

    if (area == rectangle.get_area() && perimeter == rectangle.get_perimeter())
    {
        std::cout << "You are win!" << std::endl;
    }
    else
    {
        std::cout << "You are lose!" << std::endl;
    }

    return 0;
}