/**********************************************************
File: Point.h
Class: COP 3003, Fall 2022
Author: Caleb Blackburn
Purpose: the header file for the Point class
**********************************************************/

#ifndef SHAPE_CALC_POINT_H
#define SHAPE_CALC_POINT_H


class Point {

public:

    //Constructors--------------------

    Point(); // default constructor
    Point(int x_value, int y_value);

    //Accessors--------------------

    int get_x_value(); // gets the x value from a predefined point
    void set_x_value(int value); // sets the x value of an undefined point

    int get_y_value();
    void set_y_value(int value);

    //Methods-----------------

private:

    int x_value;
    int y_value;

}; // end class point


#endif //SHAPE_CALC_POINT_H
