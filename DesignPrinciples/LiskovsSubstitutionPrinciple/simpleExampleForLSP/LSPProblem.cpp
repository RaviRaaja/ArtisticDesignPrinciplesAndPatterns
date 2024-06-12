#include <iostream>

class Rectangle {
public:
  void setWidth(int width) { m_width = width; }
  void setHeight(int height) { m_height = height; }
  int getWidth() const { return m_width; }
  int getHeight() const { return m_height; }
  int area() const { return m_width * m_height; }

private:
  int m_width;
  int m_height;
};

class Square : public Rectangle {
public:
  void setWidth(int width) {
    Rectangle::setWidth(width);
    Rectangle::setHeight(width);
  }

  void setHeight(int height) {
    Rectangle::setWidth(height);
    Rectangle::setHeight(height);
  }
};

void printArea(Rectangle &r) {
  r.setWidth(5);
  r.setHeight(10);
  std::cout << "Area: " << r.area() << std::endl;
}

int main() {
  Rectangle rect;
  Square sq;
  printArea(rect); // Expected: Area: 50
  printArea(sq);   // Expected: Area: 50, but prints Area: 100
  return 0;
}
