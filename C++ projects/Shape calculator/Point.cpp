/**********************************************************
File: Point.cpp
 Class: COP 3003, Fall 2022
Author: Caleb Blackburn
Purpose: the .cpp file for the Point class
**********************************************************/

#include "Point.h"

//Constructors--------------------

Point::Point() {

    x_value = 0;
    y_value = 0;

} // default constructor

Point::Point(int x_value, int y_value) {

    this->x_value = x_value; // sends the x value made by the user into the x value declared here
    this->y_value = y_value;

}

//Accessors--------------------

int Point::get_x_value(){return x_value;}
void Point::set_x_value(int value){ x_value = value;}

int Point::get_y_value(){return y_value;}
void Point::set_y_value(int value){ y_value = value;}

//Methods-----------------

