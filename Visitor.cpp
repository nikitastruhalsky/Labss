#include <iostream>

class Point
{
public:
    int _x = 0;
    int _y = 0;
    Point(int x, int y)
    {
        _x = x;
        _y = y;
    }
};

class Vector;
class Circle;
class Square;

class Visitor
{
public:
    virtual void visit(Vector &vector) = 0;
    virtual void visit(Circle &circle) = 0;
    virtual void visit(Square &square) = 0;
};

class Element
{
public:
    virtual void accept(Visitor &v) = 0;
    virtual void to_console() = 0;
};

class Vector : public Element
{
public:
    Point point = Point(0,0);

    void accept(Visitor &v) override
    {
        v.visit(*this);
    }

    Vector(Point p)
    {
        point = p;
    }

    void to_console() override
    {
        std::cout << "Vector: ( " << point._x << ", " << point._y << ")";
    }
};

class Circle : public Element
{
public:
    Point _center = Point(0,0);
    int _radius = 0;

    void accept(Visitor &v) override
    {
        v.visit(*this);
    }

    Circle(Point center, int radius)
    {
        _center = center;
        _radius = radius;
    }

    void to_console() override
    {
        std::cout << "Circle: center in point ( " << _center._x << ", " << _center._y << "), radius is " << _radius;
    }
};

class Square : public Element
{
public:
    Point A = Point(0,0);
    Point C = Point(0,0);

    void accept(Visitor &v) override
    {
        v.visit(*this);
    }

    Square(Point a, Point c)
    {
        A = a;
        C = c;
    }

    void to_console() override
    {
        std::cout << "Square bottom left point is: ( " << A._x << ", " << A._y <<
                  "), square top right point is: (" << C._x << ", " << C._y << ")";
    }
};

class ParallelTransfer : public Visitor
{
    Point moveVector = Point(0,0);

public:
    ParallelTransfer(Point point)
    {
        this -> moveVector._x = point._x;
        this -> moveVector._y = point._y;
    }

    void visit(Vector &vector) override
    {
        vector.point._x += moveVector._x;
        vector.point._y += moveVector._y;
    }

    void visit(Circle &circle) override
    {
        circle._center._x += moveVector._x;
        circle._center._y += moveVector._y;
    }

    void visit(Square &square) override
    {
        square.A._x += moveVector._x;
        square.A._y += moveVector._y;
        square.C._x += moveVector._x;
        square.C._y += moveVector._y;
    }
};

class Scaling : public Visitor
{
    int size = 0;

public:
    Scaling(int _size)
    {
        size = _size;
    }

    void visit(Vector &vector) override
    {
        vector.point._x *= this -> size;
        vector.point._y *= this -> size;
    }

    void visit(Circle &circle) override
    {
        circle._radius *= this -> size;
    }

    void visit(Square &square) override
    {
        if (square.C._x < 0 || square.C._y < 0)
        {
            square.A._x *= this->size;
            square.A._y *= this->size;
        }
        else
        {
            square.C._x *= this->size;
            square.C._y *= this->size;
        }
    }
};

class ReflectionRelativeToAxes : public Visitor
{
    /// true - OX, false - OY
    bool axes = true;

public:
    ReflectionRelativeToAxes(bool _axes)
    {
        axes = _axes;
    }

    void visit(Vector &vector) override
    {
        if (axes)
        {
            vector.point._y = -vector.point._y;
        }
        else
        {
            vector.point._x = -vector.point._x;
        }
    }

    void visit(Circle &circle) override
    {
        if (axes)
        {
            circle._center._y = -circle._center._y;
        }
        else
        {
            circle._center._x = -circle._center._x;
        }
    }

    void visit(Square &square) override
    {
        if (axes)
        {
            square.A._y = -square.A._y;
            square.C._y = -square.C._y;
        }
        else
        {
            square.A._x = -square.A._x;
            square.C._x = -square.C._x;
        }
    }
};

int main()
{
    Point p(1, 1);
    Circle circle(p, 2);
    ParallelTransfer parallelTransfer = ParallelTransfer(p);
    circle.accept(parallelTransfer);
    circle.to_console();
    return 0;
}
