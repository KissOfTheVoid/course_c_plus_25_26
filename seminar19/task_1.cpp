/*
    Works with vector, cmath, chrono, functional libraries
    Create a triangle structure (a, b, c) with a constructor, output method, and area method.
    Create a vector of 20 objects (any values).
    For each, output the area and find the triangle with the largest area.
    Create a vector (push_back) of 1000 triangle values ​​by pointers and references.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <functional>
using namespace std; // BAD
using namespace chrono;

struct Triangle {
    int a, b, c;
    vector<int> dummy;
    Triangle(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c), dummy(100000) {}
    void print() const {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    double square() const {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};
// Compare passing to methods.
// 1) passing by value
// 2) by reference
// 3) by pointer
// Do this 10,000 times and print the time
void pass_by_value(Triangle t) {}
void pass_by_ref(Triangle& t) {}
void pass_by_p(Triangle* t) {}

int main() {
    vector<Triangle> trs;
    for (int i = 1; i <= 20; ++i) trs.emplace_back(i, i + 1, i + 2);
    double max_area = 0;
    int max_idx = 0;
    for (int i = 0; i < (int)trs.size(); ++i) {
        double area = trs[i].square();
        cout << "Triangle " << i << " area: " << area << '\n';
        if (area > max_area) {
            max_area = area;
            max_idx = i;
        }
    }
    cout << "Largest triangle index: " << max_idx << " with area: " << max_area << "\n";
    vector<Triangle*> trs_pt;
    vector<reference_wrapper<Triangle>> triangle_refs_sim;
    for (int i = 0; i < 1000; ++i) {
        Triangle* ptr = new Triangle(i, i + 1, i + 2);
        trs_pt.push_back(ptr);
        triangle_refs_sim.push_back(*ptr);
    }
    Triangle sample(3, 4, 5);
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        pass_by_value(sample);
    }
    auto end = high_resolution_clock::now();
    cout << "Pass by value time: " << duration_cast<microseconds>(end - start).count() << '\n';

    start = high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        pass_by_ref(sample);
    }
    end = high_resolution_clock::now();
    cout << "Pass by reference time: " << duration_cast<microseconds>(end - start).count() << '\n';

    start = high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        pass_by_p(&sample);
    }
    end = high_resolution_clock::now();
    cout << "Pass by pointer time: " << duration_cast<microseconds>(end - start).count() << '\n';
    for (auto ptr : trs_pt) {
        delete ptr;
    }
    /*
    ---output---
    Triangle 1 area: 2.90474
    Triangle 2 area: 6
    Triangle 3 area: 9.92157
    Triangle 4 area: 14.6969
    Triangle 5 area: 20.3332
    Triangle 6 area: 26.8328
    Triangle 7 area: 34.197
    Triangle 8 area: 42.4264
    Triangle 9 area: 51.5212
    Triangle 10 area: 61.4817
    Triangle 11 area: 72.3079
    Triangle 12 area: 84
    Triangle 13 area: 96.5579
    Triangle 14 area: 109.982
    Triangle 15 area: 124.272
    Triangle 16 area: 139.427
    Triangle 17 area: 155.449
    Triangle 18 area: 172.337
    Triangle 19 area: 190.091
    Largest triangle index: 19 with area: 190.091
    Pass by value time: 1933241
    Pass by reference time: 21
    Pass by pointer time: 9
    */
    return 0;
}
