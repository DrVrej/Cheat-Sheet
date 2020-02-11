//////////////////////// C++ Cheat Sheet \\\\\\\\\\\\\\\\\\\\\\\\
	///// Created by DrVrej | Since January 30, 2020! \\\\\

/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
/*********************** Compiler Notes ***********************/
/*
* -Wall = Produce warning messages about a number of things that are legal but unreliable. Suggested to always use this and treat every warning as an error to be fixed.
* -Wextra = Enables some extra warning flags that are not enabled by -Wall. More Information: http://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
*/
/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
/*********************** General Notes ***********************/
/* "\n" is slower then '\n' because it treats it as a string and has to run a loop. */

/* Variable Initialization */
	type identifier{expression};
	/* Initialization = The object is given a known value at the point of definition.
	Assignment = The object is given a known value beyond the point of definition.
	Uninitialized = A variable that hasn't been given a value (Usually through initialization or assignment). Using the value stored in an uninitialized variable will result in undefined behavior. */
	
	/* Copy Initialization, inherited from the C language. This is the most basic way of initializing a variable. */
	int var = 5;

	/* Direct Initialization, introduced by C++. It's a bit more efficient then copy initialization.*/
	int var(5);

	/* Brace/Uniform Initialization, introduced in C++ 2011. It's the preferred way of initializing because it doesn't allow narrowing. */
	int var{5}; /* Direct, preferred method. */
	int var = {5}; /* Copy, less preferred method. */

	/* Narrowing example below, a copy or direct initialization will set the value as 3 and remove the rest, where was brace initialization will produce an error in the compiler. */
	int var = 3.7; /* Output ---> 3 */
	int var(3.7); /* Output ---> 3 */
	int var{3.7}; /* Output ---> Compiler Error! Narrowing isn't allowed! */

/* Functions */
	return-type identifier()
/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
/*********************** Function / Method Notes ***********************/
/* Preprocessor directive, it indicates that we would like to use the contents of the given library. */
	#include <value>

/* A macro, basically before full compilation, it gets all the tokens in the code and replaces it with the value, kind like find & replace! */
	#define token value

/* Stands for "Character Output", it's used to basically print. */
	std::cout << "Sample Text!";

/* Stand for "Character Input", it reads inputs from keyboard using the extraction operator (>>). The input MUST be stored in a variable! */
	std::cin >> var;

/* Stands for "end line", it's similar to \n but it also flushes (Which cout already does), it's more efficient to use \n instead. */
	std::endl
/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
/*********************** Coding Examples ***********************/
/* Small code, mostly used for terminal based programs, it basically won't close the terminal until the user enters a character. */
	#include <limits>
	std::cin.clear(); /* Reset any error flags. */
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /* Ignore any characters in the input buffer until we find an enter character. */
	//std::cin.get(); /* get one more char from the user. */