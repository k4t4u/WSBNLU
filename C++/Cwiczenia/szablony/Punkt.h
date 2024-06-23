#include <iostream>
using namespace std;

template <typename T>
class Punkt
{
private:
    T x;
    T y;

public:
    Punkt(T x, T y) : x(x), y(y) {}

    T getX() const
    {
        return x;
    }

    T getY() const
    {
        return y;
    }

    void setX(T newX)
    {
        x = newX;
    }

    void setY(T newY)
    {
        y = newY;
    }

    friend ostream& operator<<(ostream& out, const Punkt& p)
    {
        out << "[" << p.x << " " << p.y << "]";
        return out;
    }
};
