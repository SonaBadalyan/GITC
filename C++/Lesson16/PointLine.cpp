#include<iostream>

class Point
{
    private:
        double m_x;
        double m_y;
    
    public:
        void setX(double x)
        {
            m_x = x;
        }

        void setY(double y)
        {
            m_y = y;
        }

        double getX()
        {
            return m_x;
        }

        double getY()
        {
            return m_y;
        }

        void print()
        {
            std::cout << "________________Print point_______________________" << std::endl;
            std::cout << "x = " << m_x << std::endl;
            std::cout << "y = " << m_y << std::endl;
            std::cout << "__________________________________________________" << std::endl;
            std::cout << std::endl;
        }
};

class Line
{
    private:
        Point m_start;
        Point m_end;

    public:
    Line(Point start, Point end)
    {
        std::cout << "Line(start, end)" << std::endl;
        
        m_start.setX(start.getX());
        m_start.setY(start.getY());

        m_end.setX(end.getX()); 
        m_end.setY(end.getY());
    }

    void print ()
    {
        std::cout << "________________Print Line________________________" << std::endl;
        std::cout << "________________Start Point_______________________" << std::endl;
        m_start.print();
        std::cout << std::endl; 

        std::cout << "________________End Point_________________________" << std::endl;
        m_end.print();
        std::cout << std::endl; 
    }
};

int main()
{
    Point start;
    start.setX(0);
    start.setY(0);

    Point end;
    end.setX(9);
    end.setY(9);

    Line line (start, end);
    line.print();

    return 0;
}