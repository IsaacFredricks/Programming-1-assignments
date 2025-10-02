#include "Circle.h"
#include <cmath> //for pow function

//constructor
Circle::Circle() {}

//max radius
double Circle::maxRadius = 100.0;

//PI
constexpr double PI_CONSTANT {3.14159};

//getters
double Circle::getRadius() const {
    return radius;
}

double Circle::getMaxRadius() {
    return maxRadius;
}

double Circle::area() const{
    return (PI_CONSTANT * pow(radius, 2.0));
}

double Circle::perimeter() const{
    return (2.0 * PI_CONSTANT * radius);
}

void Circle::setRadius(double rad){
    if(radius < 0){
        radius = 0;
    }
    
    else if(rad > maxRadius){
        radius = maxRadius;    
    }
    
    else{
        radius = rad;
    }
    
}

void Circle::setMaxRadius(double maxRad){
    maxRadius = maxRad;
}
    
void Circle::scale(double factor){
        setRadius(radius * factor);
}