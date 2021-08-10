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

        Point getStart()
        {
            return m_start;
        }

        Point getEnd()
        {
            return m_end;
        }

        void setStart(Point start)
        {
            m_start = start;
        }

        void setEnd(Point end)
        {
            m_end = end;
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

    Line line;
    line.setStart(start);
    line.setEnd(end);
    
    line.print();

    return 0;
}