#include <iostream>
#include <math.h>

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
            std::cout << "2. Circle." << std::endl;
            std::cout << "3. Square." << std::endl;
            std::cout << "4. Rectangle." << std::endl;
    
            int shape = 0;
            std::cin >> shape;
    
            switch (shape)
            {
            case 1:
            {
                shape_flag = false;
                
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
                break;
            }
            case 2:
            {   
                shape_flag = false;
                
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
                break;
            }
            case 3:
            {
                shape_flag = false;
                
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
                        std::cout << "Positive number must be assigned to side. Please enter positive number." << std::endl;
                    }
                    else
                    {
                        side_flag = false;
                        
                        std::cout << "The square area is equla to " << side * side << std::endl;
                        
                        std::cout << "The square perimeter is equla to " << 4 * side << std::endl;
                    }
                }
                break;
            }
            case 4:
            {
                shape_flag = false;
                
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
                    
                    if (length <= 0)
                    {
                        std::cout << "Positive number must be assigned to length. Please enter positive number." << std::endl;
                    }
                    else
                    {
                        length_flag = false;
                    }

                    std::cout << "The rectangle area is equla to " << length * width << std::endl;;
                    
                    std::cout << "The rectangle perimeter is equla to " << 2 * ( length + width ) << std::endl;
        
                    break;
                }
                break;
            }
            default:
            {
                std::cout << "Wrong input! Please choose from suggested options." << std::endl;
                break;
            }
            }
        }
         
        bool answer_flag = true;
        while (answer_flag)
        {
            std::cout << "Do you want to continue? \n Type 1 to continue or 2 to terminate the program." << std::endl;
            
            int answer;
            std::cin >> answer;
            
            switch (answer)
            {
            case 1:
            {
                answer_flag = false;
                break;
            }
            case 2:
            {
                answer_flag = false;
                general_flag = false;
                break;
            }
            default:
            {
                std::cout << "Your input is wrong! Please be careful." << std::endl;
                break;
            }
            }

        }
                    
    }
    
    return 0;
}
