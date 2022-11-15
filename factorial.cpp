/**
 * file: factorial.cpp
 * type: C++ (source file)
 * date: 22_JULY_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // command line input and output
#include <fstream> // file input and output
#define MAXIMUM_N 12 // constant which represents maximum N value

/* function prototypes */
int compute_factorial_of_N_using_recursion(int N, std::ostream & output);
int compute_factorial_of_N_using_iteration(int N, std::ostream & output);

/**
 * Compute N factorial using a recursive algorithm.
 * Assume that N is an integer value and that output is an output stream object.
 * For each function call, print an algebriac expression which represents N factorial.
 * 
 * 0! := 1. // base case: when N is smaller than 1 or when N is larger than MAXIMUM_N.
 * N! := N * (N - 1)! // recursive case: when N is no smaller than 1 and when N is no larger than MAXIMUM_N.
 */
int compute_factorial_of_N_using_recursion(int N, std::ostream & output)
{
	// base case: if N is less than 1 or if N is greater than MAXIMUM_N, then return 1.
	if ((N < 1) || (N > MAXIMUM_N))
	{
		output << "\n\nfactorial(" << N << ") = 1. // base case";
		return 1;
	}
	// recursive case: if N is not less than 1 and if N is not greater than MAXIMUM_N, then return N multiplied by (N - 1) factorial.
	else
	{
		output << "\n\nfactorial(" << N << ") = " << N << " * factorial(" << N - 1 << "). // recursive case" ;
		return N * compute_factorial_of_N_using_recursion(N - 1, output);
	}
}

/**
 * Compute N factorial using an iterative algorithm.
 * Assume that N is an integer value and that output is an output stream object.
 * For each while loop iteration, i,  print the ith multiplicative term of N factorial.
 * 
 * If N is a natural number, then N! is the product of exactly one instance 
 * of each unique natural number which is less than or equal to N. 
 * N! := N * (N - 1) * (N - 2) * (N - 3) * ... * 3 * 2 * 1. 
 * 
 * If N is zero, then N! is one.
 * 0! := 1.
 */
int compute_factorial_of_N_using_iteration(int N, std::ostream & output)
{
	int i = 0, F = 0; 
	i = ((N > 0) && (N <= MAXIMUM_N)) ? N : 0; 
	F = (N > 0) ? N : 1; 
	output << "\n\nfactorial(" << i << ") = ";
	while (i > 0) // Execute the code block encapsulated by the while loop while the condition "i > 0" is true.
	{
		output << i << " * "; // Print " * " to the output stream.
		if (i > 1) F *= i - 1; // If i is larger than 1, then multiply F by (i - 1).
		i -= 1; // Decrement i by 1.
	}
	output << "1.";
	return F;
}

/* program entry point */
int main()
{
	// Declare three int type variables and set each of their initial values to 0.
	int N = 0, A = 0, B = 0;

	// Declare a file output stream object.
	std::ofstream file;

	/**
	 * If factorial_output.txt does not already exist in the same directory as factorial.cpp, 
	 * then create a new file named factorial_output.txt.
	 * 
	 * Then open the plain-text file named factorial_output.txt 
	 * and set that file to be overwritten with program data.
	 */
	file.open("factorial_output.txt");

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

	// Print "Computing factorial N using recursion:" to the command line terminal.
	std::cout << "\n\nComputing factorial N using recursion:";

	// Print "Computing factorial N using recursion:" to the file output stream.
	file << "\n\nComputing factorial N using recursion:";

	// Compute N factorial using recursion, store the result in A, and print each function call in the recursive function call chain to the command line terminal.
	A = compute_factorial_of_N_using_recursion(N, std::cout);

	// Compute N factorial using recursion and print each function call in the recursive function call chain to the file output stream.
	compute_factorial_of_N_using_recursion(N, file);

	// Print the value of A to the command line terminal.
	std::cout << "\n\nA := factorial(" << N << ") = " << A << ". // " << N << "! := " << A << ".";

	// Print the value of A to the file output stream.
	file << "\n\nA := factorial(" << N << ") = " << A << ". // " << N << "! := " << A << ".";

	// Print a horizontal line to the command line terminal.
	std::cout << "\n\n--------------------------------";

	// Print a horizontal line to the command line terminal.
	file << "\n\n--------------------------------";

	// Print "Computing factorial N using iteration:" to the command line terminal.
	std::cout << "\n\nComputing factorial N using iteration:";

	// Print "Computing factorial N using iteration:" to the file output stream.
	file << "\n\nComputing factorial N using iteration:";

	// Compute N factorial using iteration and print each multiplicative term of N! to the command line terminal.
	B = compute_factorial_of_N_using_iteration(N, std::cout);

	// Compute N factorial using iteration and print each multiplicative term of N! to the file output stream.
	compute_factorial_of_N_using_iteration(N, file);

	// Print the value of B to the command line terminal.
	std::cout << "\n\nB := factorial(" << N << ") = " << B << ". // " << N << "! := " << B << ".";

	// Print the value of B to the file output stream.
	file << "\n\nB := factorial(" << N << ") = " << B << ". // " << N << "! := " << B << ".";

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
