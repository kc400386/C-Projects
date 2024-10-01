/**********************************************************
 File: shape_calc
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: creating a shape calculator
**********************************************************/

#include <iostream>
#include "Rectangle.h" // includes the rectangle class in this file
#include "Line.h" // includes the line class in this file
#include "Circle.h" // includes the circle class in this file
#include <vector>


Point point_collector();
Line* get_line();
Rectangle* get_rectangle();
Circle* get_circle();

int main() { // goes through and loops through the other functions that help the fill and calculate shape values

    std::cout << "Hello user welcome to Caleb's shape calculator!" << std::endl;
    char shape_decider;
    std::vector<Shape*> shapes; // declares the vector array of shapes that stores all the shapes made by the user

    do {

        std::cout << "Please type the first letter of the following words to begin the calculation!" << std::endl;
        std::cout << " Line" << std::endl;
        std::cout << " Rectangle" << std::endl;
        std::cout << " Circle" << std::endl;
        std::cout << " Print" << std::endl;
        std::cout << " And finally type B for bye to exit the program!" << std::endl;
        std::cin >> shape_decider;

        Line *a_line; // declares that an object variable of type line will be made
        Rectangle *a_rectangle; // declares that an object variable of type rectangle will be made
        Circle *a_circle; // declares that an object variable of type circle will be made

        switch (shape_decider) {

            case 'L':
            case 'l':

                // declares that a new line will be made and pushes it back into the shapes vector array.
                a_line = get_line();
                shapes.push_back(a_line);

                break;

            case 'R':
            case 'r':

                a_rectangle = get_rectangle();
                shapes.push_back(a_rectangle);

                break;

            case 'C':
            case 'c':

                 a_circle = get_circle();
                shapes.push_back(a_circle);

                break;

            case 'P':
            case 'p':

                std::cout << "Here are the shapes you have printed!" << std::endl;
                // the below code goes through the shapes vector array and prints the stored shapes
                for (int shape_printer = 0; shape_printer < shapes.size(); shape_printer++) {

                    std::cout << shapes[shape_printer]->shape_description() << std::endl;

                } // end shape_printer for loop

        } // end shape_decider switch statement

    } while (shape_decider != 'B'); // end shape_decider while loop

    return 0;

} // end main

Point point_collector() { // calculates the user's points


    Point* point_value; // declares that an object variable of type point will be made

    int x_value;
    int y_value;
    std::cout << "Please enter the x value of your point." << std::endl;
    std::cin >> x_value;
    std::cout << "Please enter the y value of your point." << std::endl;
    std::cin >> y_value;

    point_value =  new Point(x_value, y_value); // makes the new object variable of type point

    return *point_value;

} // end point collector

Line* get_line() { // calculates a line of type Line

    Line* line;

    std::cout << "Enter your first point on the line" << std::endl;
    Point point1 = point_collector();
    std::cout << "Enter your second point on the line" << std::endl;
    Point point2 = point_collector();

    line = new Line(point1, point2);

    return line;

}// end get_line

Rectangle* get_rectangle() { // calculates a rectangle of type Rectangle

    Rectangle* rectangle;

    int length;
    int width;
    std::cout << "Please enter the width of you rectangle." << std::endl;
    std::cin >> width;
    std::cout << "Please enter the length of you rectangle." << std::endl;
    std::cin >> length;
    std::cout << "Please enter the top left point of your rectangle." << std::endl;
    Point point_one = point_collector();

    rectangle = new Rectangle(point_one, width, length);

    return rectangle;

} // end get_rectangle

Circle* get_circle() { // calculates a circle of type circle

    Circle* circle;

    int radius;
    std::cout << "Please enter the radius of you circle." << std::endl;
    std::cin >> radius;
    std::cout << "Please enter the center point of your circle." << std::endl;
    Point center = point_collector();

    circle = new Circle(radius, center);

    return circle;

} // end get_circle

