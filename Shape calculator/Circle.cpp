/**********************************************************
 File: Circle.cpp
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: a cpp file for the Circle class
**********************************************************/


#include "Circle.h"
#include <cmath>

//Constructors--------------------
Circle::Circle() {

    radius = 0;

}// default constructor

Circle::Circle(int radius, Point point) {

    this->radius = radius;
    points.push_back(point); // moves point variable to vector array

}


//Accessors--------------------

//Methods-----------------

int Circle::diameter_calc(int radius) { // calculates and returns the diameter of a user made circle

    int diameter = radius * 2;

    return diameter;

}// end diameter_calc

int Circle::area_calc(int radius) { // calculates and returns the area of a user made circle

    int area = M_PI * (radius * radius);

    return area;

}// end area_calc

int Circle::circumference_calc(int radius) { // calculates and returns the circumference of a user made circle

    int circumference = 2 * M_PI * radius;

    return circumference;

} // end circumference_calc

std::string Circle::shape_description() { // uses the virtual function defined in shape.h to describe the user defined shape

    std::string shapes_description = "Circle:\n"; // defines a string to print the data for the user defined shape
    shapes_description = shapes_description + "\tCenter {(";
    shapes_description = shapes_description + std::to_string(points[0].get_x_value()) + ", " +
                         std::to_string(points[0].get_y_value());
    shapes_description = shapes_description + ")}\n";
    // converts radius to string to print it
    shapes_description = shapes_description + "Radius: " + std::to_string(radius) + "\n";
    shapes_description = shapes_description + "Diameter = " + std::to_string(diameter_calc(radius)) + "\n";
    shapes_description = shapes_description + "Area = " + std::to_string(area_calc(radius)) + "\n";
    shapes_description = shapes_description + "Circumference = " + std::to_string( circumference_calc(radius)) + "\n";

    return shapes_description;

} // end shape description
