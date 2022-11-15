/**
 * file: probability.cpp
 * type: C++ (source file)
 * date: 10_OCTOBER_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN 
 */

/**
 * Preprocessing Directives
 */
#include <iostream> // standard input and output operations (command line terminal and keyboard)
#include <fstream> // file input and output operations (text file generation)
#include <stdio.h> // library which contains NULL macro
#include <stdlib.h> // library for srand() and rand() functions
#include <time.h> // library for time() function
#define MAXIMUM_S 1000 // upper limit constant for values of S
#define MAXIMUM_T 1000 // upper limit constant for values of T

/**
 * Function Prototypes
 */
void bubble_sort(int * A, int S);
int ** get_frequency_array(int * A, int S, int T);
double get_average_array_value(int * A, int S);
int get_smallest_array_value(int * A, int S);
int get_largest_array_value(int * A, int S);
void print_histogram(int * A, int S, int T, std::ostream & output);

/**
 * Use the Bubble Sort sorting algorithm to arrange the elements of array A in ascending order.
 * 
 * Note that, even though this function returns no value, the array which the pointer variable points to is updated.
 * 
 * Assume that there are at least S consecutive int-sized chunks of memory allocated to array A
 * (and that S is a natural number no larger than MAXIMUM_S).
 */
void bubble_sort(int * A, int S)
{
    int i = 0, placeholder = 0; 
    bool array_is_sorted = false, adjacent_elements_were_swapped = false;
    while (!array_is_sorted)
    {
        adjacent_elements_were_swapped = false;
        for (i = 1; i < S; i += 1)
        {
            if (A[i] < A[i - 1])
            {
                placeholder = A[i];
                A[i] = A[i - 1];
                A[i - 1] = placeholder;
                adjacent_elements_were_swapped = true;
            }
        }
        if (!adjacent_elements_were_swapped) array_is_sorted = true;
    }
}

/**
 * Return a pointer to a two-dimensional array which represents the number of times each unique 
 * int-type value of array A occurs inside of array A.
 * 
 * (The maximum number of times a unique integer value may occur as a data element of array A is S).
 * 
 * (The minimum number of times a unique integer value may occur as a data element of array A is 0).
 * 
 * (The maximum number of times a unique integer value may occur as a data element of array B is T).
 * 
 * (The minimum number of times a unique integer value may occur as a data element of array B is 0).
 * 
 * The returned array is a dynamically allocated variable (i.e. a variable which is 
 * instantiated during program runtime instead of during program compile time 
 * (which means that the amount of memory to allocate to array A (and, hence, to array B) is unknown
 * until the program user inputs the total number of elements to include in array A during program runtime)).
 * 
 * Assume that there are at least S consecutive int-sized chunks of memory allocated to array A
 * (and that S is a natural number no larger than MAXIMUM_S).
 * 
 * Assume that T is a natural number no larger than MAXIMUM_T.
 * 
 * Each element of the output array is an int-type array consisting of 2 elements:
 * 
 * The lefthand element of the ith element of the output array, B[i][0], 
 * stores a unique nonnegative integer no larger than (T - 1).
 * 
 * The righthand element of the ith element of the output array,
 * B[i][1], stores the nonnegative number of times 
 * each unique nonnegative integer no larger than T occurs in A.
 * 
 * The returned array, B, will have a total of T elements.
 * 
 * The returned array will logically resemble a two-dimensional grid 
 * whose left-column values are each nonnegative integers no larger than T
 * which are arranged in ascending order starting at the first element of B (i.e. B[0])
 * and ending at the last element of B (i.e. B[T - 1])
 * and whose right-column values are each nonnegative integers no larger than S.
 */
int ** get_frequency_array(int * A, int S, int T)
{
    int i = 0, k = 0;
    int ** B = new int * [T];
    for (i = 0; i < T; i += 1) B[i] = new int[2];
    for (i = 0; i < T; i += 1) B[i][0] = i;
    for (i = 0; i < T; i += 1)
    {
        for (k = 0; k < S; k += 1) if (A[k] == B[i][0]) B[i][1] += 1;
    }
    return B;
}

/**
 * Return the sum of each of the S int-type values which are stored in the array named A divided by S.
 * 
 * Assume that there are at least S consecutive int-sized chunks of memory allocated to array A
 * (and that S is a natural number no larger than MAXIMUM_S).
 */
double get_average_array_value(int * A, int S) 
{
    int i = 0, sum_of_values = 0;
    for (i = 0; i < S; i += 1) sum_of_values += A[i];
    return sum_of_values / S;
}

/**
 * Return the smallest integer value occurring inside of the array named A.
 * 
 * Assume that there are at least S consecutive int-sized chunks of memory allocated to array A
 * (and that S is a natural number no larger than MAXIMUM_S).
 */
int get_smallest_array_value(int * A, int S) 
{
    int i = 0, smallest_value = 0;
    int * A_copy = new int[S];
    for (i = 0; i < S; i += 1) A_copy[i] = A[i];
    bubble_sort(A_copy, S);
    smallest_value = A_copy[0];
    delete [] A_copy;
    return smallest_value;
}

/**
 * Return the largest integer value occurring inside of the array named A.
 * 
 * Assume that there are at least S consecutive int-sized chunks of memory allocated to array A
 * (and that S is a natural number no larger than MAXIMUM_S).
 */
int get_largest_array_value(int * A, int S) 
{
    int i = 0, largest_value = 0;
    int * A_copy = new int[S];
    for (i = 0; i < S; i += 1) A_copy[i] = A[i];
    bubble_sort(A_copy, S);
    largest_value = A_copy[S - 1];
    delete [] A_copy;
    return largest_value;
}

/**
 * Print a histogram which displays the number of times each unique integer value occurs inside of the array named A.
 * 
 * Assume that there are at least S consecutive int-sized chunks of memory allocated to array A
 * (and that S is a natural number no larger than MAXIMUM_S).
 * 
 * Assume that T is a natural number no larger than MAXIMUM_T 
 * (and that each of the values of A is no smaller than 0 and no larger than (T - 1)).
 * 
 * The maximum number of histogram rows to print is T (i.e. the number unique states which each element of A may represent).
 * If T histogram rows are printed by the time this function terminates, then each element of A stores a unique int-type value.
 * 
 * The minimum number of histogram rows to print is 1.
 * If 1 histogram row is printed by the time this function terminates, then each element of A stores the same int-type value.
 */
void print_histogram(int * A, int S, int T, std::ostream & output)
{
    int i = 0, k = 0;
    int * A_copy = new int [S];
    int ** B = new int * [T];
    for (i = 0; i < S; i += 1) A_copy[i] = A[i];
    bubble_sort(A_copy, S);
    B = get_frequency_array(A, S, T);
    output << "\n\nHistogram of Unique Array Value Frequencies:";
    for (i = 0; i < T; i += 1)
    {
        output << "\n" << B[i][0] << ": ";
        for (k = 0; k < B[i][1]; k += 1) output << "X";
        output << " (" << B[i][1] << ")";
    }
    delete [] A_copy;
    for (int i = 0; i < T; i += 1) delete [] B[i];
    delete [] B;
}

/**
 * Program Entry Point
 */
int main()
{
    // Declare a write-only file stream object.
    std::ofstream fout;

    // Declare a pointer to an int-sized block of memory.
    int * A;

    // Declare a pointer to a pointer to an int-sized block of memory.
    int ** B;

    // Declare and initialize 4 int type variables.
    int i = 0, S = 1, T = 1, N = 0;

    // Set the number of digits of floating point numbers which are printed to the command line to 50.
    // Set the number of digits of floating point numbers which are printed to the output file stream to 50.
    std::cout.precision(50);
    fout.precision(50);

    /**
     * If the plain-text file named probability_output.txt exists in the same file directory as probability.cpp, 
     * then set probability_output.txt to be overwritten with program data. 
     * 
     * Otherwise, create a plain-text file named probability_output.txt in the same file directory as probability.cpp
     * and set probability_output.txt to be overwritten with program data. 
     */
    fout.open("probability_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    fout << "--------------------------------";
    fout << "\nStart Of Program";
    fout << "\n--------------------------------";

    // Print the declare the int pointer named A to the command line terminal.
    // Print the declare the int pointer named A to the file output stream.
    std::cout << "\n\n// Declare a pointer to an int-sized block of memory.";
    std::cout << "\nint * A;";
    fout << "\n\n// Declare a pointer to an int-sized block of memory.";
    fout << "\nint * A;";

    // Print the declare the double int pointer named B to the command line terminal.
    // Print the declare the doubke int ointer named B to the file output stream.
    std::cout << "\n\n// Declare a pointer to a pointer to an int-sized block of memory.";
    std::cout << "\nint ** B;";
    fout << "\n\n// Declare a pointer to a pointer to an int-sized block of memory.";
    fout << "\nint ** B;";

    // Print a message to the command line terminal which asks the user to enter a natural number value for S.
    // Print a message to the command line terminal which asks the user to enter a natural number value for S.
    std::cout << "\n\nEnter a natural number value, S, which is no larger than " << MAXIMUM_S << " (and which will be used as the number of elements to include in an array of random integers): ";
    fout << "\n\nEnter a natural number value, S, which is no larger than " << MAXIMUM_S << " (and which will be used as the number of elements to include in an array of random integers): ";

    // Scan the command line for keyboard input and store that value inside the int type variable named S.
    std::cin >> S;

    // If S is smaller than 1 or if S is larger than MAXIMUM_S, then set S to 1.
    S = ((S < 1) || (S > MAXIMUM_S)) ? 1 : S;

    // Print a message describing the value of the variable named S to the command line terminal.
    // Print a message describing the value of the variable named S to to the output file stream.
    std::cout << "\n\nS := " << S << ".";
    fout << "\n\nS := " << S << ".";

    // Print a message to the command line terminal which asks the user to enter a natural number value for T.
    // Print a message to the command line terminal which asks the user to enter a natural number value for S.
    std::cout << "\n\nEnter a natural number value, T, which is no larger than " << MAXIMUM_T << " (and which will be used as the maximum number of unique states which each array element may represent): ";
    fout << "\n\nEnter a natural number value, T, which is no larger than " << MAXIMUM_T << " (and which will be used as the maximum number of unique states which each array element may represent): ";

    // Scan the command line for keyboard input and store that value inside the int type variable named T.
    std::cin >> T;

    // If T is smaller than 1 or if S is larger than MAXIMUM_T, then set T to 1.
    T = ((T < 1) || (T > MAXIMUM_T)) ? 1 : T;

    // Print a message describing the value of the variable named T to the command line terminal.
    // Print a message describing the value of the variable named T to to the output file stream.
    std::cout << "\n\nT := " << T << ".";
    fout << "\n\nT := " << T << ".";

    // Allocate S consecutive int-sized blocks of memory to the instantiation of array A.
    // A is a pointer which stores the address of the first memory cell of that chunk of S consecutive int-sized blocks of memory.
    A = new int[S];

    // Print the command to instatiate dynamic array A to the command line terminal.
    // Print the command to instatiate dynamic array A to the file output stream.
    std::cout << "\n\n// Allocate S consecutive int-sized blocks of memory to the instantiation of array A.";
    std::cout << "\n// A is a pointer which stores the address of the first memory cell of that chunk of S consecutive int-sized blocks of memory.";
    std::cout << "\nA = new int[S];";
    fout << "\n\n// Allocate S consecutive int-sized blocks of memory to the instantiation of array A.";
    fout << "\n// A is a pointer which stores the address of the first memory cell of that chunk of S consecutive int-sized blocks of memory.";
    fout << "\nA = new int[S];";

    // Print "Display the Initial Contents of Array A:" to the command line terminal.
    // Print "Display the Initial Contents of Array A:" to the file output stream.
    std::cout << "\n\nDisplay the Initial Contents of Array A:\n";
    fout << "\n\nDisplay the Initial Contents of Array A:\n";

    // For each element A[i] of array A (whose length is S),
    // increment i by one
    // starting at i = 0 
    // and ending at i = (S - 1)...
    for (i = 0; i < S; i += 1)
    {
        // Print a description of the ith element of array A to the command line terminal.
        // Print a description of the ith element of array A to the file output stream.
        // (The default value of each array element should be 0).
        std::cout << "\nA[" << i << "] := " << A[i] << ". (memory address of A[" << i << "] is " << &A[i] << ").";
        fout << "\nA[" << i << "] := " << A[i] << ". (memory address of A[" << i << "] is " << &A[i] << ").";
    }

    // Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).
    srand(time(NULL));

    // Print the command to seed the pseudo random number generator to the command line.
    // Print the command to seed the pseudo random number generator to the file output stream.
    std::cout << "\n\n// Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).";
    std::cout << "\nsrand(time(NULL));";
    fout << "\n\n// Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).";
    fout << "\nsrand(time(NULL));";

    // Print "Set Each Element of Array A to a Random Nonnegative Integer No Larger Than T:" to the command line terminal.
    // Print "Set Each Element of Array A to a Random Nonnegative Integer No Larger Than T:" to the file output stream.
    std::cout << "\n\nSet Each Element of Array A to a Random Nonnegative Integer No Larger Than T:\n";
    fout << "\n\nSet Each Element of Array A to a Random Nonnegative Integer No Larger Than T:\n";

    // For each element A[i] of array A (whose length is S),
    // increment i by one
    // starting at i = 0 
    // and ending at i = (S - 1)...
    for (i = 0; i < S; i += 1)
    {
        // Randomly select one of T possible states from a set of T unique states (i.e. the first T nonnegative integers). 
        // Store that value inside of variable the int type variable named N.
        // The modulo operator (%) is used to compute the remainder of dividing the lefthand operand (rand()) by the righthand operand (T). That remainder is an integer value.
        N = rand() % T;

        // Set the value of the ith element of A to N.
        A[i] = N;

        // Print a description of the ith element of array A to the command line terminal.
        // Print a description of the ith element of array A to the file output stream.
        std::cout << "\nA[" << i << "] := rand() % T := " << A[i] << ". (memory address of A[" << i << "] is " << &A[i] << ").";
        fout << "\nA[" << i << "] := rand() % T := " << A[i] << ". (memory address of A[" << i << "] is " << &A[i] << ").";
    }

    // Sort the integer values stored in array A in ascending order.
    bubble_sort(A, S);

    // Print the command to sort the integer values stored in array A in ascending order to the command line.
    // Print the command to sort the integer values stored in array A in ascending order to the file output stream.
    std::cout << "\n\n// Sort the integer values stored in array A in ascending order.";
    std::cout << "\nbubble_sort(A, S);";
    fout << "\n\n// Sort the integer values stored in array A in ascending order.";
    fout << "\nbubble_sort(A, S);";

    // Print "Display the Contents of Array A in Ascending Order:" to the command line terminal.
    // Print "Display the Contents of Array A in Ascending Order:" to the file output stream.
    std::cout << "\n\nDisplay the Contents of Array A in Ascending Order:\n";
    fout << "\n\nDisplay the Contents of Array A in Ascending Order:\n";

    // For each element A[i] of array A (whose length is S),
    // increment i by one
    // starting at i = 0 
    // and ending at i = (S - 1)...
    for (i = 0; i < S; i += 1)
    {
        // Print a description of the ith element of array A to the command line terminal.
        // Print a description of the ith element of array A to the file output stream.
        std::cout << "\nA[" << i << "] := " << A[i] << ". (memory address of A[" << i << "] is " << &A[i] << ").";
        fout << "\nA[" << i << "] := " << A[i] << ". (memory address of A[" << i << "] is " << &A[i] << ").";
    }

    // Assign double pointer B to address of the first memory cell constituting a two-dimensional array.
    // B represents a grid consisting of T rows and 2 columns.
    B = get_frequency_array(A, S, T);

    // Print the command to instantiate a two-dimensional array and store its address in B to the command line.
    // Print the command to instantiate a two-dimensional array and store its address in B to the file output stream.
    std::cout << "\n\n// Assign double pointer B to address of the first memory cell constituting a two-dimensional array.";
    std::cout << "\n// B represents a grid consisting of T rows and 2 columns.";
    std::cout << "\nB = get_frequency_array(A, S, T);";
    fout << "\n\n// Assign double pointer B to address of the first memory cell constituting a two-dimensional array.";
    fout << "\n// B represents a grid consisting of T rows and 2 columns.";
    fout << "\nB = get_frequency_array(A, S, T);";

    // Print "Display the Contents of Two-Dimensional Array B:" to the command line terminal.
    // Print "Display the Contents of Two-Dimensional Array B:" to the file output stream.
    std::cout << "\n\nDisplay the Contents of Two-Dimensional Array B:\n";
    fout << "\n\nDisplay the Contents of Two-Dimensional Array B:\n";

    // For each element B[i] of array B (whose length is T),
    // increment i by one
    // starting at i = 0 
    // and ending at i = (T - 1)...
    for (i = 0; i < T; i += 1)
    {
        // Print a description of the ith element of array B to the command line terminal.
        // Print a description of the ith element of array B to the file output stream.
        std::cout << "\n------------------------------------------------";
        std::cout << "\nFrequency of value " << B[i][0] << " in array A is " << B[i][1] << ".";
        std::cout << "\n------------------------------------------------";
        std::cout << "\nB[" << i << "][0] := " << B[i][0] << ". (memory address of B[" << i << "][0] is " << &B[i][0] << ").";
        std::cout << "\nB[" << i << "][1] := " << B[i][1] << ". (memory address of B[" << i << "][1] is " << &B[i][1] << ").";
        fout << "\n------------------------------------------------";
        fout << "\nFrequency of value " << B[i][0] << " in array A is " << B[i][1] << ".";
        fout << "\n------------------------------------------------";
        fout << "\nB[" << i << "][0] := " << B[i][0] << ". (memory address of B[" << i << "][0] is " << &B[i][0] << ").";
        fout << "\nB[" << i << "][1] := " << B[i][1] << ". (memory address of B[" << i << "][1] is " << &B[i][1] << ").";
    }

    // Verify that the sum of the frequencies of unique values in A is the same as the total number of elements in A.
    N = 0;
    for (i = 0; i < T; i += 1) N += B[i][1];

    // Print the sum of the counts of each unique value which is stored in array B to the command line.
    // Print the sum of the counts of each unique value which is stored in array B to the file output stream.
    std::cout << "\n\n// Verify that the sum of the frequencies of unique values in A is the same as the total number of elements in A.";
    std::cout << "\nN = 0;";
    std::cout << "\nfor (i = 0; i < T; i += 1) N += B[i][1];";
    std::cout << "\nN := " << N << ". // which should be identical to S.";
    fout << "\n\n// Verify that the sum of the frequencies of unique values in A is the same as the total number of elements in A.";
    fout << "\nN = 0;";
    fout << "\nfor (i = 0; i < T; i += 1) N += B[i][1];";
    fout << "\nN := " << N << ". // which should be identical to S.";

    // Print the average value of A to the command line terminal.
    // Print the average value of A to the file output steam.
    std::cout << "\n\nget_average_array_value(A, S) := " << get_average_array_value(A, S) << ".";
    fout << "\n\nget_average_array_value(A, S) := " << get_average_array_value(A, S) << ".";

    // Print the smallest value of A to the command line terminal.
    // Print the smallest value of A to the file output steam.
    std::cout << "\n\nget_smallest_array_value(A, S) := " << get_smallest_array_value(A, S) << ".";
    fout << "\n\nget_smallest_array_value(A, S) := " << get_smallest_array_value(A, S) << ".";

    // Print the largest value of A to the command line terminal.
    // Print the largest value of A to the file output steam.
    std::cout << "\n\nget_largest_array_value(A, S) := " << get_largest_array_value(A, S) << ".";
    fout << "\n\nget_largest_array_value(A, S) := " << get_largest_array_value(A, S) << ".";

    // Print a description about how much data each of the dynamocally allocated arrays represents to the command line terminal.
    std::cout << "\n\n* * *";
    std::cout << "\nsizeof(int) := " << sizeof(int) << " byte(s).";
    std::cout << "\nThe number of bytes of contiguous memory allocated to array A is: (sizeof(int) * S) = (" << sizeof(int) << " * " << S << ") = " << sizeof(int) * S << ".";
    std::cout << "\nThe number of bytes of contiguous memory allocated to array B is: (sizeof(int) * T) = (" << sizeof(int) << " * " << T << ") = " << sizeof(int) * T << ".";
    std::cout << "\n* * *";

    // Print a description about how much data each of the dynamocally allocated arrays represents to the file output stream.
    fout << "\n\n* * *";
    fout << "\nsizeof(int) := " << sizeof(int) << " byte(s).";
    fout << "\nThe number of bytes of contiguous memory allocated to array A is: (sizeof(int) * S) = (" << sizeof(int) << " * " << S << ") = " << sizeof(int) * S << ".";
    fout << "\nThe number of bytes of contiguous memory allocated to array B is: (sizeof(int) * T) = (" << sizeof(int) << " * " << T << ") = " << sizeof(int) * T << ".";
    fout << "\n* * *";

    // Print a histogram which visually depicts the frequency distribution of unique integer values in A to the command line terminal.
    // Print a histogram which visually depicts the frequency distribution of unique integer values in A to the file output stream.
    // print_histogram(A, S, T, std::cout); // WARNING: Calling the print_histogram function twice in a row using different ostream operators tends to cause the second ostream stream to be populated with garbage data. For that reason, the print_hisogram function call which uses std::cout as the ostream parameter is commented out so that the file output is not polluted. 
    std::cout << "\n\nCheck the output file to see a histogram of frequencies for each of the unique integer values stored in array A.";
    print_histogram(A, S, T, fout);

    // Deallocate memory which was assigned to the instantiation of array A during program runtime.
    delete [] A;

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of S int type values to the command line terminal.
    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of S int type values to the file output stream.
    std::cout << "\n\n// Deallocate memory which was assigned to the instantiation of array A during program runtime.";
    std::cout << "\ndelete [] A;";
    fout << "\n\n// Deallocate memory which was assigned to the instantiation of array A during program runtime.";
    fout << "\ndelete [] A;";

    // Deallocate memory which was assigned to the instantiation of array B during program runtime.
    for (int i = 0; i < T; i += 1) delete [] B[i];
    delete [] B;

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated two-dimensional array named B to the command line terminal.
    // Print the command to de-allocate memory which was assigned to the dynamically-allocated two-dimensional array named B to the file output stream.
    std::cout << "\n\n// Deallocate memory which was assigned to the instantiation of array B during program runtime.";
    std::cout << "\nfor (int i = 0; i < T; i += 1) delete [] B[i];";
    std::cout << "\ndelete [] B;\n";
    fout << "\n\n// Deallocate memory which was assigned to the instantiation of array B during program runtime.";
    fout << "\nfor (int i = 0; i < T; i += 1) delete [] B[i];";
    fout << "\ndelete [] B;\n";

    // Print a closing message to the command line terminal.
    std::cout << "\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    fout << "\n--------------------------------";
    fout << "\nEnd Of Program";
    fout << "\n--------------------------------";

    // Terminate the file output stream. Close the file so that program data is saved as lines of plain text in that file.
    fout.close();

    // program exit point
    return 0;
}
