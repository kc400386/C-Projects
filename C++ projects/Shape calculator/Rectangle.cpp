/**********************************************************
 File: Rectangle.cpp
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: a cpp file for the Rectangle class
**********************************************************/

#include "Rectangle.h"

//Constructors--------------------

Rectangle::Rectangle() {

    length = 0;
    width = 0;
    point_one = {0,0};

} // default constructor

Rectangle::Rectangle(Point point_one, int length, int width) {

    this->length = length;
    this->width = width;
    points.push_back(point_one); // moves point variable to vector array
    points.push_back(point_calc_bottom_left(width));
    points.push_back(point_calc_bottom_right(length));
    points.push_back(point_calc_top_right(width));

}

//Accessors--------------------

//Methods--------------------

int Rectangle::perimeter_calc(int width, int length) { // calculates the perimeter of a user defined shape

    int perimeter = 2 * width + 2 * length;

    return perimeter;

} // end perimeter_calc

int Rectangle::area_calc(int width, int length) { // calculates the area of a user defined shape

    int area = width * length;

    return area;

} // end area_calc

Point Rectangle::point_calc_bottom_left(int width) { // calculates the bottom left point of a user defined shape

    Point point_two;
    point_two.set_x_value(points[0].get_x_value());
    point_two.set_y_value(points[0].get_y_value() - width);

    return point_two;

} // end point_calc_bottom_left

Point Rectangle::point_calc_bottom_right(int length) { // calculates the bottom right point of a user defined shape

    Point point_three;
    point_three.set_x_value(points[1].get_x_value() + length);
    point_three.set_y_value(points[1].get_y_value());

    return point_three;

} // end point_calc_bottom_right

Point Rectangle::point_calc_top_right(int width) { // calculates the top right of a user defined shape

    Point point_four;
    point_four.set_x_value(points[2].get_x_value());
    point_four.set_y_value(points[2].get_y_value() + width);

    return point_four;

}  // end point_calc_top_right

std::string Rectangle::shape_description() { // uses the virtual function defined in shape.h to describe the user defined shape

    std::string shapes_description = "Rectangle:\n"; // defines a string to print the data for the user defined shape
    shapes_description = shapes_description + "\tPoints {(";
    // converts the x and y value of a point to a string value
    shapes_description = shapes_description + std::to_string(points[0].get_x_value()) + ", " +
                         std::to_string(points[0].get_y_value());
    shapes_description = shapes_description + "), (";
    shapes_description = shapes_description + std::to_string(points[1].get_x_value()) + ", " +
                         std::to_string(points[1].get_y_value());
    shapes_description = shapes_description + "), (";
    shapes_description = shapes_description + std::to_string(points[2].get_x_value()) + ", " +
                         std::to_string(points[2].get_y_value());
    shapes_description = shapes_description + "), (";
    shapes_description = shapes_description + std::to_string(points[3].get_x_value()) + ", " +
                         std::to_string(points[3].get_y_value());
    shapes_description = shapes_description + "), (";
    shapes_description = shapes_description + ")}\n";
    shapes_description = shapes_description + "Length: " + std::to_string(length) + "\n";
    shapes_description = shapes_description + "Width: " + std::to_string(width) + "\n";
    shapes_description = shapes_description + "Perimeter = " + std::to_string(perimeter_calc(width, length)) + "\n";
    shapes_description = shapes_description + "Area = " + std::to_string(area_calc(width, length)) + "\n";

    return shapes_description;

} // end shape_description