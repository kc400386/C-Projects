/**********************************************************
 File: shape.h
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: a header file for the shape class
**********************************************************/

//HEADER GUARD
#ifndef SHAPE_CALC_SHAPE_H
#define SHAPE_CALC_SHAPE_H
#include <string>
#include <vector>
#include "Point.h"

class Shape {

public:

    //Constructors--------------------

    Shape(); // default constructor
    Shape(std::string shape_name);

    //Accessors--------------------

    //Methods--------------------

   virtual std::string shape_description() {} // defines a virtual function that will be filled in each subclass of shape

protected:

    std::string shape_name;
    std::vector<Point> points; // is an array that stores all the points variables sent to it

}; // end class shape

#endif

