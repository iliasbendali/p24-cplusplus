#include <iostream>
#include <vector>

class Form
{
protected:
    int abscisse;
    int ordonnee;

public:
    Form(int x, int y) : abscisse(x), ordonnee(y) {}

    void move(int new_x, int new_y)
    {
        abscisse = new_x;
        ordonnee = new_y;
    }

};

class Square : public Form
{
    int side;

public:
    Square(int x, int y, int n) : Form(x, y), side(n) {}

    float area() const
    {
        return side * side;
    }
};

class Rectangle : public Form
{
    int width;
    int height;

public:
    Rectangle(int x, int y, int a, int b) : Form(x, y), width(a), height(b) {}

    float area() const
    {
        return width * height;
    }
};

class Circle : public Form
{
    int radius;

public:
    Circle(int x, int y, int r) : Form(x, y), radius(r) {}

    float area() const
    {
        return 3.1415f * radius * radius;
    }
};

int main()
{
    Circle c(5, 10, 2);
    Rectangle r(10, 15, 15, 30);

    std::vector<Form*> v;
    v.push_back(&c);
    v.push_back(&r);

    v[0]->move(2, 3);
    v[1]->move(1, 4);

    std::cout << static_cast<Circle*>(v[0])->area() << std::endl;
    std::cout << static_cast<Rectangle*>(v[1])->area() << std::endl;

    return 0;
}
