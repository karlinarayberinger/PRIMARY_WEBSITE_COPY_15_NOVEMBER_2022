/**
 * file: triangle.h
 * type: C++ (header file)
 * author: Karlina Ray Beringer
 * date: 01_AUGUST_2022
 * license: PUBLIC_DOMAIN
 */

// If TRIANGLE.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef TRIANGLE_H 
#define TRIANGLE_H

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POINT class.
#include "point.h" 

/**
 * Define a class which is used to instantiate TRIANGLE type software objects.
 * 
 * (object : class :: variable : data_type).
 * 
 * A TRIANGLE object is a specific data model of three unique two-dimensional points occurring within the same Cartesian plane.
 * 
 * A represents one POINT instance whose coordinate pair is not the same coordinate pair as the coordinate pair which B represents.
 * 
 * A represents one POINT instance whose coordinate pair is not the same coordinate pair as the coordinate pair which C represents.
 * 
 * B represents one POINT instance whose coordinate pair is not the same coordinate pair as the coordinate pair which A represents.
 * 
 * B represents one POINT instance whose coordinate pair is not the same coordinate pair as the coordinate pair which C represents. 
 * 
 * C represents one POINT instance whose coordinate pair is not the same coordinate pair as the coordinate pair which A represents.
 * 
 * C represents one POINT instance whose coordinate pair is not the same coordinate pair as the coordinate pair which B represents.
 */
class TRIANGLE
{
private:
    POINT A, B, C; // data attributes
    bool points_represent_unique_coordinate_pairs(POINT point_0, POINT point_1, POINT point_2); // helper method
    bool points_form_nondegenerate_triangle(POINT point_0, POINT point_1, POINT point_2); // helper method
public:
    TRIANGLE(); // default constructor
    TRIANGLE(int A_x, int A_y, int B_x, int B_y, int C_x, int C_y); // normal constructor
    TRIANGLE(POINT A, POINT B, POINT C); // normal constructor
    TRIANGLE(const TRIANGLE & triangle); // copy constructor
    POINT get_A(); // getter method
    POINT get_B(); // getter method
    POINT get_C(); // getter method
    double get_side_length_AB(); // getter method
    double get_side_length_BC(); // getter method
    double get_side_length_CA(); // getter method
    double get_interior_angle_ABC(); // getter method
    double get_interior_angle_BCA(); // getter method
    double get_interior_angle_CAB(); // getter method
    double get_perimeter(); // getter method
    double get_area(); // getter method
    void print(std::ostream & output = std::cout); // descriptor method
    friend std::ostream & operator << (std::ostream & output, TRIANGLE & triangle); // descriptor method
    ~TRIANGLE(); // destructor
};

// end of header file
#endif
