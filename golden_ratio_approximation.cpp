/**
 * file: golden_ratio_approximation.cpp
 * type: C++ (source file)
 * date: 24_JULY_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // command line input and output
#include <fstream> // file input and output
#define MAXIMUM_N 93 // constant which represents maximum N value

/* function prototypes */
unsigned long long int fibonacci_sequence_term(int N);
double golden_ratio_approximation(int N, std::ostream & output);

/**
 * Compute the Nth term of the Fibonacci Sequence using an iterative algorithm.
 * This function takes an int type value as the only input value.
 * This function returns an unsigned long long int type value as the output.
 * 
 * If N is smaller than 2 or larger than MAXIMUM_N, then return 1.
 * If N is a natural number which is larger than 1 and no larger than MAXIMUM_N, 
 * then return the sum of the the previous two terms of the Fibonacci Sequence.
 * 
 * fibonacci(0) := 1. // The first term of the Fibonacci Sequence is 1.
 * fibonacci(1) := 1. // The second term of the Fibonacci Sequence is 1.
 * fibonacci(i) := fibonacci(i - 2) + fibonacci(i - 1). //...if i is a natural number larger than 1.
 */
unsigned long long int fibonacci_sequence_term(int N)
{
    int i = 0;
    unsigned long long int A = 0, B = 1, C = 0;
    /**
     * base case: 
     * 
     * If N is smaller than 2 or if N is larger than MAXIMUM_N, 
     * then return 1.
     */
    if ((N < 2) || (N > MAXIMUM_N)) return 1;
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
        i += 1; 
    }
    return B;
}

/**
 * Approximate the Golden Ratio by dividing the Nth term of the Fibonacci Sequence by the (N - 1)th term of the Fibonacci Sequence.
 * Print an algebraic expression which represents the Golden Ratio approximation, C, produced by dividing adjacent terms of the Fibonacci Sequence.
 * 
 * A := fibonacci(N).
 * B := fibonacci(N - 1).
 * C := A / B. 
 * 
 * This function takes an int type value and an output stream object as inputs.
 * This function returns a double type value as the output.
 * 
 * golden_ratio := (1 + square_root(2)) / 5. 
 * golden_ratio_approximation(N) := fibonacci(N) / fibonacci(N - 1). 
 */
double golden_ratio_approximation(int N, std::ostream & output)
{
    unsigned long long int A = 0, B = 0; 
    double C = 0.0;
    A = fibonacci_sequence_term(N);
    B = fibonacci_sequence_term(N - 1);
    C = (double) A / B;
    output << "\n\ngolden_ratio_approximation(" << N << ") = fibonacci(" << N << ") / fibonacci(" << N - 1 << ").";
    output << "\ngolden_ratio_approximation(" << N << ") = " << A << " / " << B << ".";
    output << "\ngolden_ratio_approximation(" << N << ") = " << C << ".";
    return C;
}

/* program entry point */
int main()
{
    /**
     * Declare an int (i.e. integer) type variable named N and set its initial value to 0.
     * 
     * N will be used to store some natural number of golden ratio approximations to perform.
     */
    int N = 0;

    /**
     * Declare an int (i.e. integer) type variable named i and set its initial value to 0.
     * 
     * i will be used to increment the for loop for a total of N iterations.
     */
    int i = 0;

    /**
     * Declare a double (i.e. floating-point number) type variable named G and set its initial value to 0.0.
     * 
     * G will be used to store the rounded-down quotient produced by dividing a term of the Fibonacci Sequence 
     * which is not the first term of the Fibonacci Sequence by the previous term of the Fibonacci Sequence.
     * 
     * Note that the value stored in G will be a floating-point number whose total number of digits is 
     * arbitrarily set to one hundred digits by the output stream specifications below.
     */
    double G = 0.0;

    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If golden_ratio_approximation_output.txt does not already exist in the same directory as golden_ratio_approximation.cpp, 
     * then create a new file named golden_ratio_approximation_output.txt.
     * 
     * Then open the plain-text file named golden_ratio_approximation_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("golden_ratio_approximation_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "Enter a natural number which is no larger than {MAXIMUM_N}: " to the command line terminal.
    std::cout << "\n\nEnter a natural number which is no larger than " << MAXIMUM_N << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> N;

    // Print "The value which was entered for N is {N}." to the command line terminal.
    std::cout << "\nThe value which was entered for N is " << N << ".";

    // Print "The value which was entered for N is {N}." to the file output stream.
    file << "\n\nThe value which was entered for N is " << N << ".";

    // If N is less than 1 or larger than MAXIMUM_N, then set N to 1.
    N = ((N < 1) || (N > MAXIMUM_N)) ? 1 : N;

    // Print "N := {N}." to the command line terminal.
    std::cout << "\n\nN := " << N << ".";

    // Print "N := {N}." to the file output stream.
    file << "\n\nN := " << N << ".";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Approximating the Golden Ratio by dividing the Nth term of the Fibonacci Sequence by the (N - 1)th term of the Fibonacci Sequence:" to the command line terminal.
    std::cout << "\n\nApproximating the Golden Ratio by dividing the Nth term of the Fibonacci Sequence by the (N - 1)th term of the Fibonacci Sequence:";

    // Print "Approximating the Golden Ratio by dividing the Nth term of the Fibonacci Sequence by the (N - 1)th term of the Fibonacci Sequence:" to the file output stream.
    file << "\n\nApproximating the Golden Ratio by dividing the Nth term of the Fibonacci Sequence by the (N - 1)th term of the Fibonacci Sequence:";

    // Print the first N Golden Ratio approximations to the command line terminal and to the file output stream.
    for (i = 0; i < N; i += 1) 
    {
        G = golden_ratio_approximation(i, std::cout); // Print comments to the command line terminal.
        golden_ratio_approximation(i, file); // Print comments to the file output stream.
        std::cout << "\nG := golden_ratio_approximation(" << i << ") = " << G << ".";
        file << "\nG := golden_ratio_approximation(" << i << ") = " << G << ".";
    }

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
