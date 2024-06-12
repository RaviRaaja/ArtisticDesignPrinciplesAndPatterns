#include <iostream>

class Shape {
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(int width, int height) : m_width(width), m_height(height) {}

    void setWidth(int width) { m_width = width; }
    void setHeight(int height) { m_height = height; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int area() const override { return m_width * m_height; }

private:
    int m_width;
    int m_height;
};

class Square : public Shape {
public:
    Square(int side) : m_side(side) {}

    void setSide(int side) { m_side = side; }
    int getSide() const { return m_side; }
    int area() const override { return m_side * m_side; }

private:
    int m_side;
};

void printArea(Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    Rectangle rect(5, 10);
    Square sq(5);
    printArea(rect); // Expected: Area: 50
    printArea(sq);   // Expected: Area: 25
    return 0;
}
