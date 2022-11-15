/**
 * file: point_driver.cpp
 * type: C++ (source file)
 * date: 31_JULY_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN 
 */

#include "point.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POINT class.

/** Declare function prototypes (function declarations and not function definitions) which pertain to program unit tests. */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);
void unit_test_2(std::ostream & output);
void unit_test_3(std::ostream & output);
void unit_test_4(std::ostream & output);
void unit_test_5(std::ostream & output);
void unit_test_6(std::ostream & output);
void unit_test_7(std::ostream & output);
void unit_test_8(std::ostream & output);
void unit_test_9(std::ostream & output);
void unit_test_10(std::ostream & output);
void unit_test_11(std::ostream & output);
void unit_test_12(std::ostream & output);

// Unit Test # 0: POINT class default constructor, POINT class print method, and POINT class destructor.
void unit_test_0(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 0: POINT class default constructor, POINT class print method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point;";
    output << "\npoint.print(output);";
    POINT point;
    point.print(output);
}

// Unit Test # 1: POINT class default constructor, POINT class print method (with default parameter), and POINT class destructor.
void unit_test_1(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 1: POINT class default constructor, POINT class print method (with default parameter), and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point;";
    output << "\npoint.print(); // Standard command line output (std::cout) is the default parameter for the POINT print method.";
    POINT point;
    point.print(); // Standard command line output (std::cout) is the default parameter for the POINT print method.
}

// Unit Test # 2: POINT class default constructor, POINT class overloaded ostream operator method (which is functionally the same as POINT class print method), and POINT class destructor.
void unit_test_2(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 2: POINT class default constructor, POINT class overloaded ostream operator method (which is functionally the same as POINT class print method), and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point;";
    output << "\noutput << point; // functionally equivalent to: point.print(output);";
    POINT point;
    output << point;
}

// Unit Test # 3: POINT class default constructor (using the function explicity rather than implicitly), POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_3(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 3: POINT class default constructor (using that function explicity rather than implicitly), POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point = POINT(); // functionally equivalent to: POINT point;";
    output << "\noutput << point;";
    POINT point = POINT();
    output << point;
}

// Unit Test # 4: POINT class normal constructor (using only valid function inputs), POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_4(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 4: POINT class normal constructor (using only valid function inputs), POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point = POINT(-503,404);";
    output << "\noutput << point;";
    POINT point = POINT(-503,404);
    output << point;
}

// Unit Test # 5: POINT class normal constructor (using only valid function inputs), POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_5(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 5: POINT class normal constructor (using only valid function inputs), POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point_0 = POINT(-999,-999);";
    output << "\nPOINT point_1 = POINT(999, 999);";
    output << "\nPOINT point_2 = POINT(-999, 999);";
    output << "\nPOINT point_3 = POINT(999, -999);";
    output << "\noutput << point_0;";
    output << "\noutput << point_1;";
    output << "\noutput << point_2;";
    output << "\noutput << point_3;";
    POINT point_0 = POINT(-999,-999);
    POINT point_1 = POINT(999, 999);
    POINT point_2 = POINT(-999, 999);
    POINT point_3 = POINT(999, -999);
    output << point_0;
    output << point_1;
    output << point_2;
    output << point_3;
}

// Unit Test # 6: POINT class normal constructor (using both valid and invalid function inputs), POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_6(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 6: POINT class normal constructor (using both valid and invalid function inputs), POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point_0 = POINT(-1000, -999);";
    output << "\nPOINT point_1 = POINT(999, 1000);";
    output << "\noutput << point_0;";
    output << "\noutput << point_1;";
    POINT point_0 = POINT(-1000, -999);
    POINT point_1 = POINT(999, 1000);
    output << point_0;
    output << point_1;
}

// Unit Test # 7: POINT class normal constructor, POINT class copy constructor, POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_7(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 7: POINT class normal constructor, POINT class copy constructor, POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point_0 = POINT(333, -666);";
    output << "\nPOINT point_1 = POINT(point_0);";
    output << "\noutput << point_0;";
    output << "\noutput << point_1;";
    POINT point_0 = POINT(333, -666);
    POINT point_1 = POINT(point_0);
    output << point_0;
    output << point_1;
}

// Unit Test # 8: POINT class normal constructor, POINT class distance getter method, POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_8(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 8: POINT class normal constructor, POINT class distance getter method, POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point_0 = POINT(1, 1);";
    output << "\nPOINT point_1 = POINT(-1, -1);";
    output << "\noutput << point_0;";
    output << "\noutput << point_1;";
    POINT point_0 = POINT(1, 1);
    POINT point_1 = POINT(-1, -1);
    output << point_0;
    output << point_1;
    output << "\npoint_0.get_distance_from(point_1) = " << point_0.get_distance_from(point_1) << ".";
    output << "\npoint_1.get_distance_from(point_0) = " << point_1.get_distance_from(point_0) << ".";
    output << "\npoint_0.get_distance_from(point_0) = " << point_0.get_distance_from(point_0) << ".";
    output << "\npoint_1.get_distance_from(point_1) = " << point_1.get_distance_from(point_1) << ".";
}

// Unit Test # 9: POINT class normal constructor, POINT class distance getter method, POINT class slope getter method, POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_9(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 9: POINT class normal constructor, POINT class distance getter method, POINT class slope getter method, POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point_0 = POINT(0, 4);";
    output << "\nPOINT point_1 = POINT(3, 0);";
    output << "\nPOINT point_2 = POINT(0, 0);";
    output << "\noutput << point_0;";
    output << "\noutput << point_1;";
    output << "\noutput << point_2;";
    POINT point_0 = POINT(0, 4);
    POINT point_1 = POINT(3, 0);
    POINT point_2 = POINT(0, 0);
    output << point_0;
    output << point_1;
    output << "\npoint_0.get_distance_from(point_1) = " << point_0.get_distance_from(point_1) << ".";
    output << "\npoint_1.get_distance_from(point_2) = " << point_1.get_distance_from(point_2) << ".";
    output << "\npoint_2.get_distance_from(point_0) = " << point_2.get_distance_from(point_0) << ".";
    output << "\npoint_0.get_slope_of_line_to(point_1) = " << point_0.get_slope_of_line_to(point_1) << ".";
    output << "\npoint_1.get_slope_of_line_to(point_2) = " << point_1.get_slope_of_line_to(point_2) << ".";
    output << "\npoint_2.get_slope_of_line_to(point_0) = " << point_2.get_slope_of_line_to(point_0) << ".";
}

// Unit Test # 10: POINT class normal constructor, POINT class data attribute getter methods, POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_10(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 10: POINT class normal constructor, POINT class data attribute getter methods, POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point = POINT(33.3, 88.8);";
    output << "\noutput << point;";
    POINT point = POINT(33.3, 88.8);
    output << point;
    output << "\npoint.get_X() = " << point.get_X() << ".";
    output << "\npoint.get_Y() = " << point.get_Y() << ".";
}

// Unit Test # 11: POINT class normal constructor, POINT class distance getter method, POINT class slope getter method, POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_11(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 11: POINT class normal constructor, POINT class distance getter method, POINT class slope getter method, POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point = POINT(-1, 1);";
    output << "\noutput << point;";
    POINT point = POINT(-1, 1);
    output << point;
    output << "\npoint.get_distance_from(point) = " << point.get_distance_from(point) << ". // point refers to exactly one object";
    output << "\npoint.get_slope_of_line_to(point) = " << point.get_slope_of_line_to(point) << ". // point refers to exactly one object";
}

// Unit Test # 12: POINT class normal constructor, POINT class setter methods, POINT class overloaded ostream operator method, and POINT class destructor.
void unit_test_12(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 12: POINT class normal constructor, POINT class setter methods, POINT class overloaded ostream operator method, and POINT class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nPOINT point = POINT(3, 3);";
    output << "\noutput << point;";
    POINT point = POINT(3, 3);
    output << point;
    output << "\nbool status = point.set_X(-1000);";
    output << "\noutput << std::endl << status << std::endl;";
    output << "\noutput << point;";
    bool status = point.set_X(-1000);
    output << std::endl << status << std::endl;
    output << point;
    output << "\nstatus = point.set_X(-999);";
    output << "\noutput << std::endl << status << std::endl;";
    output << "\noutput << point;";
    status = point.set_X(-999);
    output << std::endl << status << std::endl;
    output << point;
    output << "\nstatus = point.set_Y(-1000);";
    output << "\noutput << std::endl << status << std::endl;";
    output << "\noutput << point;";
    status = point.set_Y(-1000);
    output << std::endl << status << std::endl;
    output << point;
    output << "\nstatus = point.set_Y(-999);";
    output << "\noutput << std::endl << status << std::endl;";
    output << "\noutput << point;";
    status = point.set_Y(-999);
    output << std::endl << status << std::endl;
    output << point;
    output << "\nstatus = point.set_X(1000);";
    output << "\noutput << std::endl << status << std::endl;";
    output << "\noutput << point;";
    status = point.set_X(1000);
    output << std::endl << status << std::endl;
    output << point;
    output << "\nstatus = point.set_X(999);";
    output << "\noutput << std::endl << status << std::endl;";
    output << "\noutput << point;";
    status = point.set_X(999);
    output << std::endl << status << std::endl;
    output << point;
    output << "\nstatus = point.set_Y(1000);";
    output << "\noutput << std::endl << status << std::endl;";
    output << "\noutput << point;";
    status = point.set_Y(1000);
    output << std::endl << status << std::endl;
    output << point;
    output << "\nstatus = point.set_Y(999);";
    output << "\noutput << std::endl << status << std::endl;";
    output << "\noutput << point;";
    status = point.set_Y(999);
    output << std::endl << status << std::endl;
    output << point;
}

/** program entry point */
int main()
{
    // Declare a file output stream object.
    std::ofstream file;

    /**
     * Set the number of digits of floating point numbers which are printed to the command line to 50.
     * Set the number of digits of floating point numbers which are printed to the file output stream to 50.
     */
    std::cout.precision(50);
    file.precision(50);

    /**
     * If point_driver_output.txt does not already exist in the same directory as point_driver.cpp, 
     * then create a new file named point_driver_output.txt.
     * 
     * Then open the plain-text file named point_driver_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("point_driver_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    /** 
     * Run each one of the unit test functions for this program.
     * 
     * Call each unit test function twice such that the first function call prints text results to the command line terminal
     * and the second function call prints text results to the output file stream.
     */
    unit_test_0(std::cout);
    unit_test_0(file);
    unit_test_1(std::cout);
    unit_test_1(file);
    unit_test_2(std::cout);
    unit_test_2(file);
    unit_test_3(std::cout);
    unit_test_3(file);
    unit_test_4(std::cout);
    unit_test_4(file);
    unit_test_5(std::cout);
    unit_test_5(file);
    unit_test_6(std::cout);
    unit_test_6(file);
    unit_test_7(std::cout);
    unit_test_7(file);
    unit_test_8(std::cout);
    unit_test_8(file);
    unit_test_9(std::cout);
    unit_test_9(file);
    unit_test_10(std::cout);
    unit_test_10(file);
    unit_test_11(std::cout);
    unit_test_11(file);
    unit_test_12(std::cout);
    unit_test_12(file);

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}
