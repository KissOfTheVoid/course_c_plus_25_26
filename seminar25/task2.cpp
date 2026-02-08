/*
    Works with string, cmath libraries
    Continuation of the previous task (logically)
*/

#include <iostream>
#include <string>
#include <cmath>

class Shape {
protected:
    std::string name;
public:
    Shape(const std::string& _name) : name(_name) {}

    virtual double area() const {
        return 0.0;
    }

    virtual void printInfo() const {
        std::cout << "Shape: " << name << std::endl;
    }

    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(const std::string& _name, double _width, double _height)
        : Shape(_name), width(_width), height(_height) {}

    double area() const override {
        return width * height;
    }

    void printInfo() const override {
        std::cout << "Rectangle: " << name << " width=" << width << " height=" << height << " area=" << area() << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(const std::string& _name, double _radius)
        : Shape(_name), radius(_radius) {}

    double area() const override {
        return 3.141592653589793 * radius * radius;
    }

    void printInfo() const override {
        std::cout << "Circle: " << name << " radius=" << radius << " area=" << area() << std::endl;
    }
};

void printShapeDetails(const Shape& s) {
    s.printInfo();
    std::cout << "Area via Shape&: " << s.area() << "\n\n";
}

int main() {
    Rectangle rect("MyRectangle", 3.0, 4.0);
    Circle    circ("MyCircle", 5.0);

    printShapeDetails(rect);
    printShapeDetails(circ);

    Shape* shapes[2];
    shapes[0] = &rect;
    shapes[1] = &circ;

    std::cout << "Loop over Shape* array:\n";
    for (Shape* s : shapes) {
        s->printInfo();
        std::cout << "Area via ptr: " << s->area() << "\n\n";
    }
    /*
    ---output---
    Rectangle: MyRectangle width=3 height=4 area=12
    Area via Shape&: 12

    Circle: MyCircle radius=5 area=78.5398
    Area via Shape&: 78.5398

    Loop over Shape* array:
    Rectangle: MyRectangle width=3 height=4 area=12
    Area via ptr: 12

    Circle: MyCircle radius=5 area=78.5398
    Area via ptr: 78.5398
    */
    return 0;
}
