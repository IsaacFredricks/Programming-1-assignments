#include "Rectangle.h"

Rectangle::Rectangle(double h, double w) : height(h), width(w) {}

double Rectangle::maxDimension = 100.0;

Rectangle::Rectangle() {}

double Rectangle::getHeight() const {
    return height;
    //double Rectangle::maxDimension = 100.0;//for testing
}
 
double Rectangle::getWidth() const {
    return width;
}

double Rectangle::area() const {
    return height * width;
}
 
double Rectangle::perimeter() const {
    return 2 * (height + width);
}
 
void Rectangle::scale(double factor) {
    setHeight(height * factor);
    setWidth(width * factor);
    
    //bad coding practice below:
    //height *= factor;
    //width *= factor;
}

void Rectangle::setHeight(double h) {
    
    if(h < 0){
        height = 0;
    }
    
    else if (h <= maxDimension) {
        height = h;
    }
    
    else {//can also add in the if statement if h <= 0
        height = maxDimension;
    }
}
 
void Rectangle::setWidth(double w) {
    
    if(w < 0){
        width = 0;
    }
    
    else if (w <= maxDimension) {
        width = w;
    }
        
    else {//can also add in the if statement if w <= 0
        width = maxDimension;
    }
}

//commenting this function out would give a compiler error
void Rectangle::setMaxDimension(double maxDim) {
    //can set restraint where maxDim >= 0
    if(maxDim > 0){
        maxDimension = maxDim;
    }
    
    else{
         maxDimension = 0;
    }
}