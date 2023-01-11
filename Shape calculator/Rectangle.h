/**********************************************************
 File: Rectangle.h
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: a header file for the Rectangle class
**********************************************************/

#include "Shape.h"
#ifndef SHAPE_CALC_RECTANGLE_H
#define SHAPE_CALC_RECTANGLE_H

class Rectangle: public Shape  {  // makes a class that inherits data from class shape

public:

    //Constructors--------------------

    Rectangle(); // default constructor
    Rectangle(Point point_one, int width, int length);

    //Accessors--------------------


    //Methods-----------------

    int perimeter_calc(int width, int length);
    int area_calc(int width, int length);
    Point point_calc_bottom_left(int width);
    Point point_calc_bottom_right(int length);
    Point point_calc_top_right(int width);
    std::string shape_description();

private:

    int width;
    int length;
    Point point_one;
    Point point_two;
    Point point_three;
    Point point_four;

}; // end class rectangle


#endif //SHAPE_CALC_RECTANGLE_H
