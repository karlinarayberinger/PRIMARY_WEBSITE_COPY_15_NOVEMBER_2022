/**
 * file: point.h
 * type: C++ (header file)
 * author: Karlina Ray Beringer
 * date: 30_JULY_2022
 * license: PUBLIC_DOMAIN
 */

// If point.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef POINT_H 
#define POINT_H

#include <iostream> // Include the library which defines command line input and output operations.
#include <fstream> // Include the library which defines file input and output operations.
#include <cmath> // Include the library which defines the square root function, trigonometric functions, and the floor function (i.e. the native C++ function which rounds a number down to its nearest integer).
#include <string> // Include the library which defines sequences of text characters as string type variables.

#define MINIMUM_X -999 // Define the constant MINIMUM_X to represent the value -999.
#define MINIMUM_Y -999 // Define the constant MINIMUM_Y to represent the value -999.
#define MAXIMUM_X 999 // Define the constant MAXIMUM_X to represent the value 999.
#define MAXIMUM_Y 999 // Define the constant MAXIMUM_X to represent the value 999.
#define PI 3.141592653589793238462643383279502884197169399 // Define the constant PI to represent the approximate value of a circle's circumference divided by that circle's diameter.

/**
 * Define a class which is used to instantiate POINT type software objects.
 * 
 * (object : class :: variable : data_type).
 * 
 * A POINT object is a specific data model of a two-dimensional point.
 * 
 * X stores one integer value at a time which is no smaller than MINIMUM_X and which is no larger than MAXIMUM_X.
 * Y stores one integer value at a time which is no smaller than MINIMUM_Y and which is no larger than MAXIMUM_Y.
 * 
 * X represents a specific whole number position along the x-axis (i.e. horizontal dimension) of a two-dimensional Cartesian grid.
 * Y represents a specific whole number position along the y-axis (i.e. vertical dimension) of the same two-dimensional Cartesian grid.
 */
class POINT
{
private:
    int X, Y; // data attributes
public:
    POINT(); // default constructor
    POINT(int X, int Y); // normal constructor
    POINT(const POINT & point); // copy constructor
    int get_X(); // getter method
    int get_Y(); // getter method
    bool set_X(int X); // setter method
    bool set_Y(int Y); // setter method
    double get_distance_from(POINT & point); // getter method
    double get_slope_of_line_to(POINT & point); // getter method
    void print(std::ostream & output = std::cout); // descriptor method
    friend std::ostream & operator << (std::ostream & output, POINT & point); // descriptor method
    ~POINT(); // destructor
};

// end of header file
#endif
