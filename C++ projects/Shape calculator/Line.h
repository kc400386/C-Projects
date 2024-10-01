/**********************************************************
 File: Line.h
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: a header file for the Line class
**********************************************************/

#include "Shape.h"
#ifndef SHAPE_CALC_LINE_H
#define SHAPE_CALC_LINE_H

class Line: public Shape {  // makes a class that inherits data from class shape

public:

    //Constructors--------------------

    Line();
    Line(Point point_one, Point point_two);

    //Accessors--------------------

    //Methods-----------------

    float slope_calc();
    float angle_calc();
    double distance_calc();
    std::string shape_description();

private:

    Point point_one;
    Point point_two;
    int slope;
    int angle;
    int distance;

}; // end class line


#endif //SHAPE_CALC_LINE_H
