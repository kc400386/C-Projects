/**********************************************************
 File: Line.cpp
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: a cpp file for the Line class
**********************************************************/

#include "Point.h"
#include "Line.h"
#include <cmath>

//Constructors--------------------

Line::Line() {

     point_one = {0,0};
     point_two = {0,0};

} // default constructor

Line::Line(Point point_one, Point point_two) {

    points.push_back(point_one); // moves point variable to vector array
    points.push_back(point_two); // moves point variable to vector array

}

//Accessors--------------------

//Methods-----------------

float Line::slope_calc() { // calculates the slope of a user defined shape

    float top_slope = points[1].get_y_value() - points[0].get_y_value();
    float bottom_slope = points[1].get_x_value() - points[0].get_x_value();
    float slope = top_slope / bottom_slope;

    return slope;

} // end slope_calc

float Line::angle_calc() { // calculates the angle of a user defined shape

    float x_distance = points[1].get_x_value() - points[0].get_x_value();
    float y_distance = points[1].get_y_value() - points[0].get_y_value();

    float angle = atan(y_distance / x_distance) * 180.0 / M_PI;

    return angle;

} // end angle_calc

double Line::distance_calc() { // calculates the distance of a user defined shape

    int x_distance = points[1].get_x_value() - points[0].get_x_value();
    int y_distance = points[1].get_y_value() - points[0].get_y_value();
    double distance = sqrt(pow(x_distance,2) + pow(y_distance,2));

    return distance;

} // end distance_calc

std::string Line::shape_description() { // uses the virtual function defined in shape.h to describe the user defined shape

    std::string shapes_description = "Line:\n"; // defines a string to print the data for the user defined shape
    shapes_description = shapes_description + "\tPoints {(";
    // converts the x and y value of a point to a string value
    shapes_description = shapes_description + std::to_string(points[0].get_x_value()) + ", " +
            std::to_string(points[0].get_y_value());
    shapes_description = shapes_description + "), (";
    shapes_description = shapes_description + std::to_string(points[1].get_x_value()) + ", " +
            std::to_string(points[1].get_y_value());
    shapes_description = shapes_description + ")}\n";
    shapes_description = shapes_description + "Slope = " + std::to_string(slope_calc()) + "\n";
    shapes_description = shapes_description + "Angle = " + std::to_string(angle_calc()) + "\n";
    shapes_description = shapes_description + "Distance = " + std::to_string( distance_calc()) + "\n";

    return shapes_description;

} // end shape_description
