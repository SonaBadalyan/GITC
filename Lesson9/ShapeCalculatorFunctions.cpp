#include <iostream>
#include <math.h>


void triangle()
{
    bool base_height_flag = true;
                
    double base;
    
    while (base_height_flag)
    {
        std::cout << "Please enter the triangle base and height values for calculating the area." << std::endl;
        
        std::cout << "Base = ";
        std::cin >> base;
        std::cout << std::endl;
        
        double height;
        std::cout << "Height = ";
        std::cin >> height;
        std::cout << std::endl;
        
        if (base <= 0.0 || height <= 0.0)
        {
            std::cout << "Positive numbers should be assigned to base and height. Please enter positive numbers." << std::endl;
        }
        else
        {
            base_height_flag = false;
            
            std::cout << "The triangle area is equla to " << (height * base) / 2 << std::endl;
        }
        
    }
    
    bool side_flag = true;
    
    while (side_flag)
    {
        std::cout << "Please enter the triangle sides values for calculating the perimeter." << std::endl;
        
        double side1, side2;
        
        std::cout << "First side = ";
        std::cin >> side1;
        std::cout << std::endl;
        
        std::cout << "Second side = ";
        std::cin >> side2;
        std::cout << std::endl;
        
        if (side1 <= 0.0 || side2 <= 0.0)
        {
            std::cout << "Positive numbers should be assigned to sides. Please enter positive numbers." << std::endl;
        }
        else
        {
            side_flag = false;
            
            std::cout << "The triangle perimeter is equla to " << side1 + base + side2 << std::endl;
        }
    }
}

void right_triangle()
{
    bool sides_flag = true;
                
    double side1;
    
    while (sides_flag)
    {
        std::cout << "Please enter the right triangle sides values for calculating the area." << std::endl;
        
        std::cout << "First side = ";
        std::cin >> side1;
        std::cout << std::endl;
        
        double side2;
        std::cout << "Secod side = ";
        std::cin >> side2;
        std::cout << std::endl;
        
        if (side1 <= 0.0 || side2 <= 0.0)
        {
            std::cout << "Positive numbers should be assigned to sides. Please enter positive numbers." << std::endl;
        }
        else
        {
            sides_flag = false;
            
            std::cout << "The right triangle area is equla to " << (side1 * side2) / 2 << std::endl;
            std::cout << "The right triangle perimeter is equla to " << side1 + side2  + sqrt(pow(2, side1) + pow(2, side2)) << std::endl;
        }
        
    }
}

void circle()
{
    bool radius_flag = true;
                
    while (radius_flag)
    {
        std::cout << "Please enter the circle radius value for calculating the area." << std::endl;
        
        double radius;
        
        std::cout << "Radius = ";
        std::cin >> radius;
        std::cout << std::endl;
        
        if (radius <= 0)
        {
            std::cout << "Positive number must be assigned to radius. Please enter positive number." << std::endl;
        }
        else
        {
            radius_flag = false;
            
            std::cout << "The circle area is equla to " << M_PI * radius * radius << std::endl;
        
            std::cout << "The circle perimeter is equla to " << 2 * M_PI * radius << std::endl;
            
            std::cout << "The circle diameter is equla to " << 2 * radius << std::endl;
        }
    }
}

void square()
{
    bool side_flag = true;
                
    while (side_flag)
    {
        std::cout << "Please enter the square side value for calculating the area." << std::endl;
        
        double side;
        std::cout << "Side = ";
        std::cin >> side;
        std::cout << std::endl;
        
        if (side <= 0)
        {
            std::cout << "Positive number must be assigned to radius. Please enter positive number." << std::endl;
        }
        else
        {
            side_flag = false;
            
            std::cout << "The square area is equla to " << side * side << std::endl;
            
            std::cout << "The square perimeter is equla to " << 4 * side << std::endl;
        }
    }
}

void rectangle()
{
    double length;
                
    bool length_flag = true;
    
    while (length_flag)
    {
        std::cout << "Please enter the rectangle length for calculating the area." << std::endl;
        
        std::cout << "Length = ";
        std::cin >> length;
        std::cout << std::endl;
        
        if (length <= 0)
        {
            std::cout << "Positive number must be assigned to length. Please enter positive number." << std::endl;
        }
        else
        {
            length_flag = false;
        }
    }
    
    double width;
    
    bool width_flag = true;
    
    while (width_flag)
    {
        std::cout << "Please enter the rectangle width for calculating the area." << std::endl;
        
        std::cout << "Width = ";
        std::cin >> width;
        std::cout << std::endl;
        
        if (width <= 0)
        {
            std::cout << "Positive number must be assigned to width. Please enter positive number." << std::endl;
        }
        else
        {
            width_flag = false;
        }
    }
                    
    std::cout << "The rectangle area is equla to " << length * width << std::endl;;
    
    std::cout << "The rectangle perimeter is equla to " << 2 * ( length + width ) << std::endl;
}

int main()
{
    bool general_flag = true;

    while (general_flag)
    {
        bool shape_flag = true;
        
        while (shape_flag)
        {
            std::cout << "Please choose the shape and the program will calculate the area and perimeter of that shape." << std::endl;
            
            std::cout << "1. Triangle." << std::endl;
            std::cout << "2. Right triangle." << std::endl;
            std::cout << "3. Circle." << std::endl;
            std::cout << "4. Square." << std::endl;
            std::cout << "5. Rectangle." << std::endl;

    
            int shape = 0;
            std::cin >> shape;
    
            switch (shape)
            {
            case 1:
            {
                shape_flag = false;
                triangle();
                break;
            }
            case 2:
            {
                shape_flag = false;
                right_triangle();
                break; 
            }
            case 3:
            {
                shape_flag = false;
                circle();
                break;
            }
            case 4:
            {
                shape_flag = false;
                square();
                break;
            }
            case 5:
            {
                shape_flag = false;
                rectangle();
                break;
            }
            default:   
            {
                std::cout << "Wrong input! Please choose from suggested options." << std::endl;
                break;
            }
        }
         
        while (general_flag)
        {
            std::cout << "Do you want to continue? \n Type 1 to continue or 2 to terminate the program." << std::endl;
            
            int answer;
            std::cin >> answer;
            
            if (2 == answer)
            {
                general_flag = false;
            }
            else if (1 == answer)
            {
                break;
            }
            else
            {
                std::cout << "Your input is wrong! Please be careful." << std::endl;
            }
        }
                    
    }
    }

    return 0;
}
