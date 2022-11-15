/**
 * file: fibonacci_sequence.cpp
 * type: C++ (source file)
 * date: 24_JULY_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // command line input and output
#include <fstream> // file input and output
#define MAXIMUM_N 45 // constant which represents maximum N value

/* function prototypes */
int compute_Nth_fibonacci_sequence_term_using_recursion(int N, std::ostream & output, int & C);
int compute_Nth_fibonacci_sequence_term_using_iteration(int N, std::ostream & output);

/**
 * Compute the Nth term of the Fibonacci Sequence using a recursive algorithm.
 * 
 * Assume that N is an integer value and that output is an output stream object.
 * 
 * Assume that C is a reference to an int type variable whose initial value is zero.
 * 
 * C is assumed to represent the total number of times this function is called during 
 * a particular function call chain which is initiated when this function is called
 * inside the scope in which C is declared.
 * 
 * If this function is going to be called more than one time from inside of the same
 * scope in which C is declared, C will need to be reset to 0 before each of those
 * function calls is implemented to ensure that C stores the correct number of time this 
 * function calls itself during a particular function call from within C's program scope.
 * 
 * For each function call, print an algebraic expression which represents the Nth term of the Fibonacci Sequence.
 * 
 * ----------------------------------------------------------------------
 * 
 * The first term of the Fibonacci Sequence is one.
 * 
 * fibonacci(0) := 1. 
 * 
 * ----------------------------------------------------------------------
 * 
 * The second term of the Fibonacci Sequence is one.
 * 
 * fibonacci(1) := 1. 
 * 
 * ----------------------------------------------------------------------
 * 
 * If N is a natural number larger than or equal to two,
 * then the Nth term of the Fibonacci Sequence is the sum 
 * of the previous two terms of the Fibonacci Sequence.
 * 
 * fibonacci(N) := fibonacci(N - 2) + fibonacci(N - 1). 
 * 
 * ----------------------------------------------------------------------
 */
int compute_Nth_fibonacci_sequence_term_using_recursion(int N, std::ostream & output, int & C)
{
    /**
     * base case: 
     * 
     * If N is smaller than 2 or if N is larger than MAXIMUM_N, 
     * then return 1.
     */
    if ((N < 2) || (N > MAXIMUM_N))
    {
        N = (N == 0) ? N : 1; // If N is not equal to 0, then set N to 1.
        C += 1;
        output << "\n\nfibonacci(" << N << ") = 1. // base case";
        return 1;
    }
    /**
     * recursive case: 
     * 
     * If N is a natural number larger than 2 and no larger than MAXIMUM_N, 
     * then return the sum of the (N - 2)th term and the (N - 1)nth term of the Fibonacci Sequence.
     */
    else
    {
        C += 1;
        output << "\n\nfibonacci(" << N << ") = fibonacci(" << N - 2 << ") + fibonacci(" << N - 1 << "). // recursive case" ;
        return compute_Nth_fibonacci_sequence_term_using_recursion(N - 2, output, C) + compute_Nth_fibonacci_sequence_term_using_recursion(N - 1, output, C);
    }
}

/**
 * Compute the Nth term of the Fibonacci Sequence using an iterative algorithm.
 * 
 * Assume that N is an integer value and that output is an output stream object.
 * 
 * For each while loop iteration, 
 * print an algebraic expression which represents the ith term of the Fibonacci Sequence.
 * 
 * fibonacci(0) := 1. // The first term of the Fibonacci Sequence is 1.
 * fibonacci(1) := 1. // The second term of the Fibonacci Sequence is 1.
 * fibonacci(i) := fibonacci(i - 2) + fibonacci(i - 1). //...if i is a natural number larger than 1.
 */
int compute_Nth_fibonacci_sequence_term_using_iteration(int N, std::ostream & output)
{
    int i = 0, A = 0, B = 1, C = 0;
    /**
     * base case: 
     * 
     * If N is smaller than 2 or if N is larger than MAXIMUM_N, 
     * then return 1.
     */
    if ((N < 2) || (N > MAXIMUM_N)) 
    {
        N = 0;
        output << "\n\nfibonacci(" << N << ") = 1. // base case";
        return 1;
    }
    /**
     * recursive case: 
     * 
     * If N is a natural number larger than 2 and no larger than MAXIMUM_N, 
     * then return the sum of the (N - 2)th term and the (N - 1)nth term of the Fibonacci Sequence.
     */
    while (i < N) 
    {
        C = A;
        A = B;
        B += C;
        output << "\n\nfibonacci(" << i << ") = ";
        output << B << " = fibonacci(" << i - 2 << ") + fibonacci(" << i - 1 << ") = ";
        output << A << " + " << C;
        output << ". // i := " << i << ".";
        i += 1; 
    }
    return B;
}

/* program entry point */
int main()
{
    // Declare four int type variables and set each of their initial values to 0.
    int N = 0, A = 0, B = 0, C = 0;

    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If fibonacci_sequence_output.txt does not already exist in the same directory as fibonacci_sequence.cpp, 
     * then create a new file named fibonacci_sequence_output.txt.
     * 
     * Then open the plain-text file named fibonacci_sequence_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("fibonacci_sequence_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "Enter a nonnegative integer which is no larger than {MAXIMUM_N}: " to the command line terminal.
    std::cout << "\n\nEnter a nonnegative integer which is no larger than " << MAXIMUM_N << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> N;

    // Print "The value which was entered for N is {N}." to the command line terminal.
    std::cout << "\nThe value which was entered for N is " << N << ".";

    // Print "The value which was entered for N is {N}." to the file output stream.
    file << "\n\nThe value which was entered for N is " << N << ".";

    // If N is less than 0 or larger than MAXIMUM_N, then set N to 0.
    N = ((N < 0) || (N > MAXIMUM_N)) ? 0 : N;

    // Print "N := {N}." to the command line terminal.
    std::cout << "\n\nN := " << N << ".";

    // Print "N := {N}." to the file output stream.
    file << "\n\nN := " << N << ".";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Computing the Nth term of the Fibonacci using recursion:" to the command line terminal.
    std::cout << "\n\nComputing the Nth term of the Fibonacci Sequence using recursion:";

    // Print "Computing the Nth term of the Fibonacci using recursion:"to the file output stream.
    file << "\n\nComputing the Nth term of the Fibonacci Sequence using recursion:";

    /**
     * Compute the Nth term of the Fibonacci Sequence using recursion, 
     * store the result in A, and print each function call in the recursive 
     * function call chain to the command line terminal.
     */
    A = compute_Nth_fibonacci_sequence_term_using_recursion(N, std::cout, C);

    /**
     * Compute the Nth term of the Fibonacci Sequence using recursion and 
     * print each function call in the recursive function call chain to 
     * the file output stream.
     */
    C = 0;
    compute_Nth_fibonacci_sequence_term_using_recursion(N, file, C);

    // Print the value of A to the command line terminal.
    std::cout << "\n\nA := fibonacci(" << N << ") = " << A << ".";

    // Print the value of A to the file output stream.
    file << "\n\nA := fibonacci(" << N << ") = " << A << ".";

    // Print "The number of times which the recursive Fibonacci Sequence term function was called during this program runtime instance is {C}." to the command line terminal.
    std::cout << "\n\nThe number of times which the recursive Fibonacci Sequence term function was called during this program runtime instance is " << C << ".";

    // Print "The number of times which the recursive Fibonacci Sequence term function was called during this program runtime instance is {C}." to the file output stream.
    file << "\n\nThe number of times which the recursive Fibonacci Sequence term function was called during this program runtime instance is " << C << ".";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Computing the Nth term of the Fibonacci using iteration:" to the command line terminal.
    std::cout << "\n\nComputing the Nth term of the Fibonacci Sequence using iteration:";

    // Print "Computing the Nth term of the Fibonacci using iteration:"to the file output stream.
    file << "\n\nComputing the Nth term of the Fibonacci Sequence using iteration:";

    /**
     * Compute the Nth term of the Fibonacci Sequence using iteration and 
     * print an algebraic expression which represents the ith term of the Fibonacci Sequence
     * in a while loop which iterates N times while incrementing 1 by exactly one during each while loop iteration
     * to the command line terminal.
     */
    B = compute_Nth_fibonacci_sequence_term_using_iteration(N, std::cout);

    /**
     * Compute the Nth term of the Fibonacci Sequence using iteration and 
     * print an algebraic expression which represents the ith term of the Fibonacci Sequence
     * in a while loop which iterates N times while incrementing 1 by exactly one during each while loop iteration
     * to the file output stream.
     */    
    compute_Nth_fibonacci_sequence_term_using_iteration(N, file);

    // Print the value of B to the command line terminal.
    std::cout << "\n\nB := fibonacci(" << N << ") = " << B << ".";

    // Print the value of B to the file output stream.
    file << "\n\nB := fibonacci(" << N << ") = " << B << ".";

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
