/**
 * file: triangle.cpp
 * type: C++ (source file)
 * date: 01_AUGUST_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN 
 */

#include "triangle.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRIANGLE class.

/**
 * Determine whether or not point_0, point_1, and point_2 each represent unique coordinate pairs.
 * 
 * (Assume that point_0, point_1, and point_2 each represent valid POINT instances).
 * 
 * If each of the three POINT objects represent unique coordinate pairs, then return true.
 * 
 * Otherwise, return false.
 */
bool TRIANGLE::points_represent_unique_coordinate_pairs(POINT point_0, POINT point_1, POINT point_2)
{
    if ((point_0.get_X() == point_1.get_X()) && (point_0.get_Y() == point_1.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_1 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        return false;
    }
    if ((point_0.get_X() == point_2.get_X()) && (point_0.get_Y() == point_2.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_2 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        return false;
    }
    if ((point_1.get_X() == point_2.get_X()) && (point_1.get_Y() == point_2.get_Y())) 
    {
        std::cout << "\n\npoint_1 and point_2 appear to represent the same coordinate pair.";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        return false;
    }
    if ((point_2.get_X() == point_0.get_X()) && (point_2.get_Y() == point_0.get_Y())) 
    {
        std::cout << "\n\npoint_2 and point_0 appear to represent the same coordinate pair.";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        return false;
    }
    return true;
}

/**
 * Determine whether or not point_0, point_1, and point_2 collectively form a non-degenerate triangle.
 * 
 * (Assume that point_0, point_1, and point_2 each represent valid POINT instances).
 * 
 * A non-degenerate triangle is a triangle whose area is some positive real number quantity.
 * 
 * A degenerate triangle is a triangle whose area is zero (due to the fact that one line intersects each of the three points).
 * 
 * If each of the three POINT objects represent a non-degenerate triangle, then return true.
 * 
 * Otherwise, return false.
 */
bool TRIANGLE::points_form_nondegenerate_triangle(POINT point_0, POINT point_1, POINT point_2)
{
    if (!points_represent_unique_coordinate_pairs(point_0, point_1, point_2))
    {
        std::cout << "\n\npoint_0, point_1, and point_2 do not each represent unique coordinate pairs.";
        std::cout << "\nHence, points_form_degenerate_triangle(point_0, point_1, point_2) is returning false.";
        return false;
    }
    A = point_0;
    B = point_1;
    C = point_2;
    if (get_area() <= 0) 
    {
        std::cout << "\n\nWhen setting the POINT values of the caller TRIANGLE object to the function parameters, get_area() returned a non-positive number result.";
        std::cout << "\nHence, points_form_nondegenerate_triangle(POINT point_0, POINT point_1, POINT point_2) is returning false.";
        return false;
    }
    return true;
}

/**
 * The default constructor method of the TRIANGLE class returns a TRIANGLE object 
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 */
TRIANGLE::TRIANGLE()
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << "...";
    A = POINT(0, 0);
    B = POINT(0, 1);
    C = POINT(1, 0);
}

/**
 * The normal constructor method of the TRIANGLE class which takes six int values as its only parameters returns a TRIANGLE object 
 * whose POINT property named A represents the coordinate pair (A_x, A_y),
 * whose POINT property named B represents the coordinate pair (B_x, B_y), and
 * whose POINT property named C represents the coordinate pair (C_x, C_y)
 * if POINT(A_x, A_y), POINT(B_x, B_y), and POINT(C_x, C_y) represent a non-degenerate triangle.
 * 
 * If POINT(A_x, A_y), POINT(B_x, B_y), and POINT(C_x, C_y) do not represent a non-degenerate triangle,
 * then this function will return a TRIANGLE object
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 */
TRIANGLE::TRIANGLE(int A_x, int A_y, int B_x, int B_y, int C_x, int C_y)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << "...";
    POINT input_A = POINT(A_x, A_y);
    POINT input_B = POINT(B_x, B_y);
    POINT input_C = POINT(C_x, C_y);
    if (points_form_nondegenerate_triangle(input_A, input_B, input_C))
    {
        A = input_A;
        B = input_B;
        C = input_C;
    }
    else
    {
        A = POINT(0, 0);
        B = POINT(0, 1);
        C = POINT(1, 0);
    }
}

/**
 * The normal constructor method of the TRIANGLE class which takes three POINT objects as its only parameters returns a TRIANGLE object 
 * whose POINT property named A represents the same coordinate pair as the parameter named A,
 * whose POINT property named B represents the same coordinate pair as the parameter named B, and
 * whose POINT property named C represents the same coordinate pair as the parameter named C
 * if parameter A, parameter B, and parameter C represent a non-degenerate triangle.
 * 
 * If parameter A, parameter B, and parameter C do not represent a non-degenerate triangle,
 * then this function will return a TRIANGLE object
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 */
TRIANGLE::TRIANGLE(POINT A, POINT B, POINT C)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << ".";
    if (points_form_nondegenerate_triangle(A, B, C))
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
    }
    else
    {
        this -> A = POINT(0, 0);
        this -> B = POINT(0, 1);
        this -> C = POINT(1, 0);
    }
}

/**
 * The copy constructor method of the TRIANGLE class returns a TRIANGLE object 
 * whose POINT property named A represents the same coordinate pair as the POINT property named A which belongs to the parameter TRIANGLE object,
 * whose POINT property named B represents the same coordinate pair as the POINT property named B which belongs to the parameter TRIANGLE object, and
 * whose POINT property named C represents the same coordinate pair as the POINT property named C which belongs to the parameter TRIANGLE object. 
 */
TRIANGLE::TRIANGLE(const TRIANGLE & triangle)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << ".";
    this -> A = triangle.A;
    this -> B = triangle.B;
    this -> C = triangle.C;
}

/** 
 * The getter method of the TRIANGLE class named get_A() returns the value of the caller TRIANGLE object's A property.
 */
POINT TRIANGLE::get_A()
{
    return A;
}

/** 
 * The getter method of the TRIANGLE class named get_B() returns the value of the caller TRIANGLE object's B property.
 */
POINT TRIANGLE::get_B()
{
    return B;
}

/** 
 * The getter method of the TRIANGLE class named get_C() returns the value of the caller TRIANGLE object's C property.
 */
POINT TRIANGLE::get_C()
{
    return C;
}

/** 
 * The getter method of the TRIANGLE class named get_side_length_AB() returns the length of the shortest path between points A and B.
 */
double TRIANGLE::get_side_length_AB()
{
    return A.get_distance_from(B);
}

/** 
 * The getter method of the TRIANGLE class named get_side_length_BC() returns the length of the shortest path between points B and C.
 */
double TRIANGLE::get_side_length_BC()
{
    return B.get_distance_from(C);
}

/** 
 * The getter method of the TRIANGLE class named get_side_length_CA() returns the length of the shortest path between points C and A.
 */
double TRIANGLE::get_side_length_CA()
{
    return C.get_distance_from(A);
}

/**
 * The getter method of the TRIANGLE class named get_interior_angle_ABC() returns the angle measurement in degrees of the angle
 * formed by connecting points A, B, anc C in that order.
 * 
 * This function uses Law of Cosines to compute the angle measurement of an angle given that triangle's side lengths as function inputs.
 */
double TRIANGLE::get_interior_angle_ABC()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    b = get_side_length_CA(); // b represents the length of the line segment whose endpoints are C and A.
    c = get_side_length_AB(); // c represents the length of the line segment whose endpoints are A and B.
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_b;
}

/**
 * The getter method of the TRIANGLE class named get_interior_angle_BCA() returns the angle measurement in degrees of the angle
 * formed by connecting points B, C, and A in that order.
 * 
 * This function uses Law of Cosines to compute the angle measurement of an angle given that triangle's side lengths as function inputs.
 */
double TRIANGLE::get_interior_angle_BCA()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    b = get_side_length_CA(); // b represents the length of the line segment whose endpoints are C and A.
    c = get_side_length_AB(); // c represents the length of the line segment whose endpoints are A and B.
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_c;
}

/**
 * The getter method of the TRIANGLE class named get_interior_angle_CAB() returns the angle measurement in degrees of the angle
 * formed by connecting points C, A, and B in that order.
 * 
 * This function uses Law of Cosines to compute the angle measurement of an angle given that triangle's side lengths as function inputs.
 */   
double TRIANGLE::get_interior_angle_CAB()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    b = get_side_length_CA(); // b represents the length of the line segment whose endpoints are C and A.
    c = get_side_length_AB(); // c represents the length of the line segment whose endpoints are A and B.
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_a;
}

/** 
 * The getter method of the TRIANGLE class named get_perimeter() returns the sum of the three side lengths which the caller TRIANGLE object represents.
 */
double TRIANGLE::get_perimeter()
{
    return get_side_length_AB() + get_side_length_BC() + get_side_length_CA();
}

/** 
 * The getter method of the TRIANGLE class named get_area() returns the quantity of the two-dimensional space bound by the shortest 
 * paths between points A, B, and C which the caller TRIANGLE object represents.
 * 
 * This function uses Heron's Formula to compute the area of any triangle given that triangle's side lengths as function inputs.
 */
double TRIANGLE::get_area()
{
    double s = 0.0, a = 0.0, b = 0.0, c = 0.0;
    s = get_perimeter() / 2; // s is technically referred to as the semiperimter of the triangle represented by this (i.e. the TRIANGLE object which is calling this function).
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    b = get_side_length_CA(); // b represents the length of the line segment whose endpoints are C and A.
    c = get_side_length_AB(); // c represents the length of the line segment whose endpoints are A and B.
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Use Heron's Formula to compute the area of the triangle whose points are A, B, and C.
}

/**
 * The print method of the TRIANGLE class prints a description of the caller TRIANGLE object to the output stream.
 * 
 * Note that the default value of the function input parameter is the standard command line output stream (std::cout).
 * The default parameter is defined in the TRIANGLE class header file.
 */
void TRIANGLE::print(std::ostream & output)
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis := " << this << ". // The keyword named this is a pointer to the memory address of the first cell of a TRIANGLE-sized block of memory cells which are allocated to the instantiation of some TRIANGLE-type object.";
    output << "\n&A = " << &A << ". // The operation returns the address of the first memory cell of a POINT-sized block of memory cells which are allocated to the instantiation of some POINT-type object named A.";
    output << "\n&B = " << &B << ". // The operation returns the address of the first memory cell of a POINT-sized block of memory cells which are allocated to the instantiation of some POINT-type object named B.";
    output << "\n&C = " << &C << ". // The operation returns the address of the first memory cell of a POINT-sized block of memory cells which are allocated to the instantiation of some POINT-type object named C.";
    output << "\nsizeof(int) = " << sizeof(int) << ". // The operation returns the number of bytes of memory which an int-type variable occupies. Each memory cell has a data capacity of 1 byte.";
    output << "\nsizeof(POINT) = " << sizeof(POINT) << ". // The operation returns the number of bytes of memory which a POINT-type object occupies. Each memory cell has a data capacity of 1 byte.";
    output << "\nsizeof(TRIANGLE) = " << sizeof(TRIANGLE) << ". // The operation returns the number of bytes of memory which a TRIANGLE-type object occupies. Each memory cell has a data capacity of 1 byte.";
    output << "\nA := POINT(" << A.get_X() << ", " << A.get_Y() << "). // POINT( { X : (int) horizontal_coordinate }, { Y : (int) vertical_coordinate } )";
    output << "\nB := POINT(" << B.get_X() << ", " << B.get_Y() << "). // POINT( { X : (int) horizontal_coordinate }, { Y : (int) vertical_coordinate } )";
    output << "\nC := POINT(" << C.get_X() << ", " << C.get_Y() << "). // POINT( { X : (int) horizontal_coordinate }, { Y : (int) vertical_coordinate } )";
    output << "\nget_side_length_BC() = " << get_side_length_BC() << ". // The method returns the nonnegative number of Cartesian grid unit lengths which span the length of the shortest path between point B and point C.";
    output << "\nget_side_length_CA() = " << get_side_length_CA() << ". // The method returns the nonnegative number of Cartesian grid unit lengths which span the length of the shortest path between point C and point A.";
    output << "\nget_side_length_AB() = " << get_side_length_AB() << ". // The method returns the nonnegative number of Cartesian grid unit lengths which span the length of the shortest path between point A and point B.";
    output << "\nget_interior_angle_CAB() =  " << get_interior_angle_CAB() << ". // The method returns the acute angle formed by the intersection of the line segment whose endpoints are A and C with the line segment whose endpoints are A and C at intersection point A in degrees and not in radians.";
    output << "\nget_interior_angle_ABC() =  " << get_interior_angle_ABC() << ". // The method returns the acute angle formed by the intersection of the line segment whose endpoints are A and B with the line segment whose endpoints are B and C at intersection point B in degrees and not in radians.";
    output << "\nget_interior_angle_BCA() =  " << get_interior_angle_BCA() << ". // The method returns the acute angle formed by the intersection of the line segment whose endpoints are B and C with the line segment whose endpoints are A and C at intersection point C in degrees and not in radians.";
    output << "\nget_perimeter() = " << get_perimeter() << ". // The method returns the sum of the three side lengths which the caller TRIANGLE object represents.";
    output << "\nget_area() = " << get_area() << ". // The method returns the number of Cartesian grid unit squares which are enclosed inside of the two-dimensional region formed by the three line segments which connect points A, B, and C.";
    output << "\n--------------------------------------------------------------------------------------------------";
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (<<).
 * 
 * Note that the default value of the leftmost function input parameter is the standard command line output stream (std::cout).
 * The default parameter is defined in the TRIANGLE class header file.
 * 
 * The friend function is not a member of the TRIANGLE class, but the friend function has access to the private and protected members 
 * of the TRIANGLE class and not just the public members of the TRIANGLE class.
 * 
 * The friend keyword only prefaces the function prototype for this function. 
 * The friend keyword does not preface the definition for this function.
 */
std::ostream & operator << (std::ostream & output, TRIANGLE & triangle)
{
    triangle.print(output);
    return output;
}

/**
 * The destructor method of the TRIANGLE class de-allocates memory which was used to instantiate the TRIANGLE object which is calling this function.
 * The destructor method of the TRIANGLE class is invoked as soon as the program scope in which the caller TRIANGLE object was instantiated terminates.
 */
TRIANGLE::~TRIANGLE()
{
    std::cout << "\n\nDeleting the TRIANGLE type object whose memory address is " << this << "...";
}
