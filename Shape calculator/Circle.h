/**********************************************************
 File: Circle.h
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: a header file for the Circle class
**********************************************************/

#include "Shape.h"
#ifndef SHAPE_CALC_CIRCLE_H
#define SHAPE_CALC_CIRCLE_H



class Circle: public Shape { // makes a class that inherits data from class shape


public:

    //Constructors--------------------
    Circle(); // default constructor
    Circle(int radius, Point point);

    //Accessors--------------------

     //Methods-----------------

    int diameter_calc(int radius);
    int area_calc(int radius);
    int circumference_calc(int radius);
    std::string shape_description();

private:

    int radius;
    Point point;
    int diameter;
    int area;
    int circumference;

}; // end circle class


#endif //SHAPE_CALC_CIRCLE_H
