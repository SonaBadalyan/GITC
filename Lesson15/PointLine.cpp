#include<iostream>

class Point
{
    private:
        double m_x;
        double m_y;
    
    public:
        Point()
        {
            std::cout << "Point()" << std::endl;
        }

        Point(double x)
        {
            std::cout << "Point(x)" << std::endl;
            m_x = x;
        }

        Point(double y, bool)
        {
            std::cout << "Point(y, bool)" << std::endl;
            m_y = y;
        }

        Point(double y, double x)
        {
            std::cout << "Point(y, x)" << std::endl;
            m_x = x;
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
    Line()
    {
        std::cout << "Line()" << std::endl;
    }

    Line(Point start)
    {
        std::cout << "Line(start)" << std::endl;
        m_start = start;
    }

    Line(Point end, bool)
    {
        std::cout << "Line(end, bool)" << std::endl;
        m_end = end;
    }

    Line(Point start, Point end)
    {
        std::cout << "Line(start, end)" << std::endl;
        m_start = start;
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
    // Point start(0, (double)0);
    // Point end (9, (double)9);
    // Line line (start, end);
    // line.print();

    // Point start(0);
    // Point end (9);
    // Line line (start, end);
    // line.print();

    Point start(0, (double)0);
    Line line (start);
    line.print();

    return 0;
}