#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle(double radius) {
    this->radius = new double(radius);
}

double Circle::calc_area() {
    double area = M_PI * *radius * *radius;
    return area;
}

void Circle::show() {
    cout << "Circle" << "\n"
    << "radius: " << *radius << "\n"
    << "area = " << Circle::calc_area() << "\n"
    << '\n';
}

Circle::~Circle() {
    delete radius;
}
