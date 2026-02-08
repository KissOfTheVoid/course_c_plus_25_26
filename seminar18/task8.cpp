/*
    Works with string, vector, numbers, cmath libraries
    System that keeps objects of different shape with enum, struct and union
*/

#include <iostream>
#include <string>
#include <vector>
#include <numbers>
#include <cmath>

struct Rectangle {
    float width;
    float height;
};

struct Triangle {
    float a;
    float b;
    float c;
};

enum class ShapeType {
    CIRCLE, 
    RECTANGLE, 
    TRIANGLE
};

union ShapeData {
    float radius;
    Rectangle rec;
    Triangle tri;
};


struct Shape {
    ShapeType type;
    ShapeData data;
};

float floatArea(const Shape& _fig) {
    float _area = 0.0f;
    if (_fig.type == ShapeType::CIRCLE) _area = _fig.data.radius*(static_cast<float>(std::numbers::pi))*_fig.data.radius;
    else if (_fig.type == ShapeType::RECTANGLE) _area = _fig.data.rec.width*_fig.data.rec.height;
    else _area = sqrt(((_fig.data.tri.a + _fig.data.tri.b + _fig.data.tri.c) / 2)*(((_fig.data.tri.a + _fig.data.tri.b + _fig.data.tri.c) / 2) - _fig.data.tri.a)*(((_fig.data.tri.a + _fig.data.tri.b + _fig.data.tri.c) / 2) - _fig.data.tri.b)*(((_fig.data.tri.a + _fig.data.tri.b + _fig.data.tri.c) / 2) - _fig.data.tri.c));
    return _area;
}

std::string shapeTypeToString(ShapeType type) {
    switch (type) {
        case ShapeType::CIRCLE: return "CIRCLE";
        case ShapeType::RECTANGLE: return "RECTANGLE";
        case ShapeType::TRIANGLE: return "TRIANGLE";
    }
    return "UNKNOWN";
}

void printShape(const Shape& _fig) {
    std::cout << "the shape is a " << shapeTypeToString(_fig.type) << '\n';
    switch (_fig.type) {
        case ShapeType::CIRCLE : 
            std::cout << "the radius is " << _fig.data.radius << '\n';
            break;
        case ShapeType::RECTANGLE : 
            std::cout << "the width is " << _fig.data.rec.width << "\nthe height is " << _fig.data.rec.height << '\n';
            break;
        case ShapeType::TRIANGLE : 
            std::cout << "the a is " << _fig.data.tri.a << "\nthe b is " << _fig.data.tri.b << "\nthe c is " << _fig.data.tri.c << '\n';
            break;
        default : 
            std::cout << "smth went wrong\n";
            break;
    }
}

int main() {
    Shape s1;
    s1.type = ShapeType::CIRCLE;
    s1.data.radius = 10.0f;

    Shape s2;
    s2.type = ShapeType::RECTANGLE;
    s2.data.rec.width = 4.0f;
    s2.data.rec.height = 6.0f;

    Shape s3;
    s3.type = ShapeType::TRIANGLE;
    s3.data.tri.a = 3.0f;
    s3.data.tri.b = 4.0f;
    s3.data.tri.c = 5.0f;

    std::vector<Shape> shapes = {s1, s2, s3};

    for (const auto& s : shapes) {
        printShape(s);
        std::cout << "area = " << floatArea(s) << '\n';
    }

    float total = 0.0f;
    for (const auto& s : shapes) {
        total += floatArea(s);
    }
    std::cout << "Total area = " << total << '\n';
    /*
    ---output---
    the shape is a CIRCLE
    the radius is 10
    area = 314.159
    the shape is a RECTANGLE
    the width is 4
    the height is 6
    area = 24
    the shape is a TRIANGLE
    the a is 3
    the b is 4
    the c is 5
    area = 6
    Total area = 344.159
    */
    return 0;
}