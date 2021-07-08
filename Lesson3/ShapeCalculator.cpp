#include <iostream>
#include <math.h>

int main()
{
    bool flag = true;

    while (flag)
    {
        std::cout << "Please choose the shape and the program will calculate the area and perimeter of that shape." << std::endl;
        
        std::cout << "1. Triangle." << std::endl;
        std::cout << "2. Circle." << std::endl;
        std::cout << "3. Square." << std::endl;
        std::cout << "3. Rectangle." << std::endl;

        int shape = 0;
        std::cin >> shape;

        if (1 == shape)
        {
            std::cout << "Please enter the triangle base and height values for calculating the area." << std::endl;
            
            double base, height;
            std::cin >> base;
            std::cin >> height;
            
            std::cout << "The triangle area is equla to " << (height * base) / 2 << std::endl;
            
            std::cout << "Please enter the triangle sides values for calculating the perimeter." << std::endl;
            
            double side1, side2;
            std::cin >> side1;
            std::cin >> side2;
            
            std::cout << "The triangle perimeter is equla to " << side1 + base + side2 << std::endl;
            
        }
        else if (2 == shape)
        {
            std::cout << "Please enter the circle radius value for calculating the area." << std::endl;
            
            double radius;
            std::cin >> radius;
            
            std::cout << "The circle area is equla to " << M_PI * radius * radius << std::endl;
            
            std::cout << "The circle perimeter is equla to " << 2 * M_PI * radius << std::endl;
            
            std::cout << "The circle diameter is equla to " << 2 * radius << std::endl;
        }
        else if (3 == shape)
        {
            std::cout << "Please enter the square side value for calculating the area." << std::endl;
            
            double side;
            std::cin >> side;
            
            std::cout << "The square area is equla to " << side * side << std::endl;
            
            std::cout << "The square perimeter is equla to " << 4 * side << std::endl;
        }
        else if (4 == shape)
        {
            
            std::cout << "Please enter the rectangle length and width values for calculating the area." << std::endl;
            
            double length, width;
            std::cin >> length;
            std::cin >> width;
            
            std::cout << "The rectangle area is equla to " << length * width << std::endl;;
            
            std::cout << "The rectangle perimeter is equla to " << 2 * ( length + width ) << std::endl;
        }
        else
            std::cout << "Wrong input!" << std::endl;
         
         
        std::cout << "Do you want to continue? \n Type \"yes\" to continue or anything to terminate the program." << std::endl;  

        std::string answer;
        std::cin >> answer;

        if ("yes" != answer)
            flag = false;
                    
    }

    return 0;
}