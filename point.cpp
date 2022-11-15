/**
 * file: point.cpp
 * type: C++ (source file)
 * date: 31_JULY_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN 
 */

#include "point.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POINT class.

/**
 * The default constructor method of the POINT class instantiates POINT type objects whose X value is set to 0 and whose Y value is set to 0.
 * 
 * The default constructor method of the POINT class is invoked when a POINT type variable is declared as follows:
 * 
 * // variable declaration one
 * POINT point_0; 
 * 
 * // variable declaration two
 * POINT point_1 = POINT();
 */
POINT::POINT()
{
    std::cout << "\n\nCreating the POINT type object whose memory address is " << this << "...";
    X = 0;
    Y = 0;
}

/**
 * The normal constructor method of the POINT class instantiates POINT type objects 
 * whose X value is set to the leftmost function input value (if that input value is in range) and 
 * whose Y value is set to the rightmost function input value (if that input value is in range).
 * 
 * If an input value is out of range, then set the corresponding int-type property of this to 0.
 * 
 * (The keyword this refers to the POINT object which is returned by this function).
 *
 * This normal constructor method of the POINT class is invoked when a POINT type variable is declared as follows:
 * 
 * // non-default POINT definition example one
 * POINT point_2 = POINT(-55,84);
 * 
 * // non-default POINT definition example two
 * POINT point_3 = POINT(3,-4);
 */
POINT::POINT(int X, int Y)
{
    std::cout << "\n\nCreating the POINT type object whose memory address is " << this << "...";
    this -> X = ((X < MINIMUM_X) || (X > MAXIMUM_X)) ? 0 : X; // Set the X property of the POINT instance being created to 0 if the function input X value is out of range.
    this -> Y = ((Y < MINIMUM_Y) || (Y > MAXIMUM_Y)) ? 0 : Y; // Set the Y property of the POINT instance being created to 0 if the function input Y value is out of range.
}

/**
 * The copy constructor method of the POINT class instantiates POINT type objects 
 * whose X value is set to the X value of the input POINT object 
 * and whose Y value is set to the Y value of the input POINT object.
 * 
 * (Note that the input POINT object named point is the predecessor to the object returned by this function).
 * 
 * (The keyword this refers to the POINT object which is returned by this function (i.e. the successor to point)).
 * 
 * The memory address of the predecessor POINT object is passed into the function as the variable named point.
 *
 * This copy constructor method of the POINT class is invoked when a POINT type variable is declared as follows:
 * 
 * // copy POINT definition example one
 * POINT point_4 = POINT(point_3);
 * 
 * // copy POINT definition example two
 * POINT point_5 = POINT(point_4);
 */
POINT::POINT(const POINT & point) 
{
    std::cout << "\n\nCreating the POINT type object whose memory address is " << this << "...";
    X = point.X;
    Y = point.Y;
}

/**
 * The getter method of the POINT class returns the value of the caller POINT object's X property.
 * 
 * X is an int type variable which stores exactly one integer value at a time which is no smaller than MINIMUM_X and which is no larger than MAXIMUM_X.
 */
int POINT::get_X()
{
    return X;
}

/**
 * The getter method of the POINT class returns the value of the caller POINT object's Y property.
 * 
 * Y is an int type variable which stores exactly one integer value at a time which is no smaller than MINIMUM_Y and which is no larger than MAXIMUM_Y.
 */
int POINT::get_Y()
{
    return Y;
}

/**
 * The setter method of the POINT class sets the POINT object's X property to the passed in value if that passed in value is in range.
 * 
 * If the input value is in range, then return true. Otherwise, do not change the caller POINT object's X value and return false.
 */
bool POINT::set_X(int X)
{
    if ((X >= MINIMUM_X) && (X <= MAXIMUM_X)) 
    {
        this -> X = X;
        return true;
    }
    return false;
}

/**
 * The setter method of the POINT class sets the POINT object's Y property to the passed in value if that passed in value is in range.
 * 
 * If the input value is in range, then return true. Otherwise, do not change the caller POINT object's Y value and return false.
 */
bool POINT::set_Y(int Y)
{
    if ((Y >= MINIMUM_Y) && (Y <= MAXIMUM_Y)) 
    {
        this -> Y = Y;
        return true;
    }
    return false;
}

/**
 * The getter method of the POINT class returns the nonzero length of the shortest path 
 * between the planar point represented by the the caller POINT object (i.e. this) 
 * and the planar point represented by the input POINT instance (i.e. point).
 * 
 * Use the Pythagorean Theorem to compute the length of a right triangle's hypotenuse 
 * (where the end points of that hypotenuse are represented by this and point).
 * 
 * A hypotenuse is the only side of a right triangle which does not form a right angle 
 * with any other side of that triangle.
 * 
 * A hypotenuse is the longest side of a triangle (and a triangle is a three-sided polygon 
 * in which three unique line segments connect three unique points).
 * 
 * // c is the length of a right triangle's hypotenuse.
 * // a is the length of that right triangle's horizontal side.
 * // b is the length of that triangle's vertical side.
 * (c * c) := (a * a) + (b * b). 
 * 
 * // sqrt is a native C++ function defined in the cmath library.
 * c := square_root( (a * a) + (b * b)). 
 */
double POINT::get_distance_from(POINT & point)
{
    int horizontal_difference = 0.0, vertical_difference = 0.0;
    horizontal_difference = X - point.X;
    vertical_difference = Y - point.Y;
    return sqrt((horizontal_difference * horizontal_difference) + (vertical_difference * vertical_difference));
}

/**
 * The getter method of the POINT class returns the slope of the line which intersects 
 * the planar point represented by the caller POINT instance (i.e. this)
 * and the planar point represented by the input POINT instance (i.e. point).
 * 
 * // y := f(x), 
 * // b := f(0), 
 * // f is a function whose input is an x-axis position and whose output is a y-axis position.
 * y := mx + b.
 * 
 * // m is a constant which represents the rate at which y changes as x changes.
 * // y is the output to linear function f. 
 * // b is a constant.
 * m := (y - b) / x. 
 * 
 * // m represents the difference of the y-values divided by the difference of the x-values
 * m := (point_1.y_coordinate - point_0.y_coordinate) / (point_1.x_coordinate - point_0.x_coordinate).
 */
double POINT::get_slope_of_line_to(POINT & point)
{
    double vertical_difference = 0.0, horizontal_difference = 0.0, result = 0.0;
    vertical_difference = point.Y - Y;
    horizontal_difference = point.X - X;
    result = vertical_difference / horizontal_difference;
    if (result == -0) result = 0; // Signed zeros sometimes occur inside of C++ program runtime instances.
    return result;
}

/**
 * The print method of the POINT class prints a description of the caller POINT object to the output stream.
 * 
 * Note that the default value of the function input parameter is the standard command line output stream (std::cout).
 * The default parameter is defined in the POINT class header file (i.e. point.h).
 */
void POINT::print(std::ostream & output)
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis := " << this << ". // The keyword named this is a pointer to the memory address of the first cell of a POINT-sized block of memory cells which are allocated to the instantiation of some POINT-type object.";
    output << "\n&X = " << &X << ". // The operation returns the memory address of the first memory cell of an int-sized block of memory cells which are allocated to the instantiation of some int-type variable named X.";
    output << "\n&Y = " << &Y << ". // The operation returns the memory address of the first memory cell of an int-sized block of memory cells which are allocated to the instantiation of some int-type variable named Y.";    
    output << "\nsizeof(int) = " << sizeof(int) << ". // The operation returns the number of bytes of memory which an int-type variable occupies. Each memory cell has a data capacity of 1 byte.";
    output << "\nsizeof(POINT) = " << sizeof(POINT) << ". // The operation returns the number of bytes of memory which a POINT-type object occupies. Each memory cell has a data capacity of 1 byte.";
    output << "\nX := " << X << ". // X stores an int-type value which represents the horizontal position of a two-dimensional point plotted on a Cartesian grid.";
    output << "\nY := " << Y << ". // Y stores an int-type value which represents the vertical position of a two-dimensional point plotted on a Cartesian grid.";
    output << "\n--------------------------------------------------------------------------------------------------";
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (<<).
 * 
 * (Overloading an operator is assigning a different function to a native operator other than the function which that operator is used to represent by default).
 * 
 * Note that the default value of the leftmost function input parameter is the standard command line output stream (std::cout).
 * The default parameter is defined in the POINT class header file (i.e. point.h).
 * 
 * The friend function is not a member of the POINT class, but the friend function has access to the private and protected members 
 * of the POINT class and not just the public members of the POINT class.
 * 
 * The friend keyword only prefaces the function prototype for this function (which is declared in the header file named point.h). 
 * The friend keyword does not preface the definition for this function (which is defined immediately below this comment).
 */
std::ostream & operator << (std::ostream & output, POINT & point)
{
    point.print(output);
    return output;
}

/**
 * The destructor method of the POINT class de-allocates memory which was used to instantiate the POINT object which is calling this function.
 * 
 * The destructor method of the POINT class is implicitly invoked as soon as the program scope in which the caller POINT object was instantiated terminates.
 * In other words, no C++ command is needed to call this function. The destructor is called automatically by the event of the caller object's scope terminating.
 */
POINT::~POINT()
{
    std::cout << "\n\nDeleting the POINT type object whose memory address is " << this << "...";
}
