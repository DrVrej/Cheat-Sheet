//////////////////////// C++ Cheat Sheet \\\\\\\\\\\\\\\\\\\\\\\\
	///// Created by DrVrej | Since January 30, 2020! \\\\\

/********************************************************************************************************************************************************************
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Compiler Notes --------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
********************************************************************************************************************************************************************/
/*
* -w		= Disables all warning messages.
* -Wall		= Produce warning messages about a number of things that are legal but unreliable. Suggested to always use this and treat every warning as an error to be fixed.
* -Wextra	= Enables some extra warning flags that are not enabled by -Wall. More Information: http://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
* -I		= Specifies an alternate include directory. Example:  -I/source/headers/  No spaces after the -I command!
* -g		= Used to allow debugging. Without setting this flag, the debugging process may have issues running!
* -static	= Includes all the needed dll files into the exe, making it a semi-independent application
*/
/********************************************************************************************************************************************************************
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Concept ---------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
********************************************************************************************************************************************************************/
/***** Preprocessor ********************************************************/
/*	- Usually starts with the symbol  #  it basically replaces or changes things in the files.
	- Directives are only valid from the point of definition to the end of the file in which they are defined.
	- They have no scope, so putting it inside a function or outside doesn't make any difference.

	/* [Preprocessor Directive]
		- Basically replaces the #include directive with the contents of the included file. */
	#include <file>		/* <> tells the preprocessor this is a file included with the compiler, so it should look for the file in the system directories. */
	#include "file.h"	/* "" tells the preprocessor this is a user-defined file, so it should look for the file in the directory containing the source code. */

	/* [Macro Directive]
		- Before full compilation, it gets all the tokens in the code and replaces it with the value, kind like find & replace!
		- Macros don't replace other preprocessors! */
	#define token value

	/* [Conditional Compilation Preprocessor]
		- Allows you to specify under what conditions something will or won�t compile. */
	#ifdef token	/* Compile if the given token exists. */
	#ifndef token	/* Compile if the given token doesn't exist. */
	#if value		/* Compile if the value is true. */
	#endif			/* Ends a conditional compilation preprocessor. */
		/* Example #1: */
		#define PRINT_TEST1 /* Empty macro. */
		#ifdef PRINT_TEST1
			std::cout << "I run!"; /* This will compile because PRINT_TEST1 is defined! */
		#endif
		/* Example #2: */
		#ifdef PRINT_TEST2
			std::cout << "I don't run!"; /* This won't compile because PRINT_TEST2 isn't defined! */
		#endif
		#ifndef PRINT_TEST2
			std::cout << "I run!"; /* This will compile because PRINT_TEST2 isn't defined! */
		#endif
		/* Example #3: */
		#if 0
			std:cout << "I don't run!"; /* Useful to comment out code that contains nested comments. */
		#endif

/***** Header Files ********************************************************/
/*	- Usually ends with ".h" or ".hpp" or sometimes it doesn't have an extension.
	- Header files allow us to put declarations in one location and then import them wherever we need them. This can save a lot of typing (forward declarations) in multi-file programs.
	- It's better to have a separate header file for each .cpp file instead of having them all in one file (Better for compilation, especially in big files).
	- To keep things organized, name the header file the same as its paired .cpp file.
	- Highly recommended to #include the header file in its paired .cpp file, this is to avoid unexpected errors in the future!
	- For the standard library, use the no extension version (without the .h) if it exists. It's much more updated then the .h version.
	- Header files can include other header files, which will include all the definitions of the parent header file, including the parent's parent definitions!
	
	/* [Header Guards]
		- Designed to ensure that the contents of a given header file aren't copied more than once into a single file in order to prevent duplicate definitions. */
	#ifndef FILE_NAME_H /* Create a unique name for it, best practice is to name it the same as the file. */
	#define FILE_NAME_H
			// The actual content of the header file goes here
	#endif

/***** Namespace ********************************************************/
/*	- Any names not defined inside a function, class or a namespace is automatically placed inside the global namespace (aka global scope). */
	/* [Using a Namespace]
		- If the compiler comes across na identifier without a prefix, it will check if it's defined locally or in the defined namespace. */
	using namespace name;

/***** Variable Initialization ********************************************************/
/*	- Uninitialized = A variable that hasn't been given a value (Usually through initialization or assignment). Using the value stored in an uninitialized variable will result in undefined behavior.
	- Initialization = The object is given a known value at the point of definition.
	- Assignment = The object is given a known value beyond the point of definition.*/
	type identifier{expression};
	
	/* [Copy Initialization]
		- Inherited from the C language. This is the most basic way of initializing a variable. */
	int var = 5;

	/* [Direct Initialization]
		Introduced by C++. It's a bit more efficient then copy initialization.*/
	int var(5);

	/* [Brace/Uniform Initialization]
		- Introduced in C++ 2011. It's the preferred way of initializing because it doesn't allow narrowing. */
	int var{5}; /* Direct, preferred method. */
	int var = {5}; /* Copy, less preferred method. */

	/* [Narrowing Example]
		- Copy or direct initialization will set the value as 3 and remove the rest, where as brace initialization will produce an error in the compiler. */
	int var = 3.7;	/* Output ---> 3 */
	int var(3.7);	/* Output ---> 3 */
	int var{3.7};	/* Output ---> Compiler Error! Narrowing isn't allowed! */

/***** Function ********************************************************/
	type identifier(parameters){}

/***** Forward Declaration ********************************************************/
/*	- Since the ordering of the functions in C++ matters, we use forward declaration to let the compiler know that an identifier exists before it is actually defined.
	
	/* [Function Prototype]
		- Function prototype includes: return type, identifier, parameters, and a semicolon.
		- The body of the function isn't defined here! */
	type identifier(parameters);

/***** Concatenation ********************************************************/
	/* Strings can be concatenated without even putting anything in between, example: */
	"My " "Name" /* Output ---> "My Name", this can be used to split up very long strings to multiple lines. */
		/* Example: */
		std::cout << "This is a really, really, really, really, really, really, really, "
		"really long line\n"; /* Since the string is very long, we split it into 2 lines. */

/***** main Function ********************************************************/
/*	- Every program MUST have a main function!
	- The main function MUST return a value of type int!
	- The return value (status code) is retrieved by the operating system (and any other programs that called this program).
	- return 0 means that the program ran normally/successfully.
	- return a non-0 means that the program it encountered an error and could not complete as expected.
	- Recommended to place the main function at bottom of which ever file it's located in. */
	int main()

/***** Scope Resolution Operator  :: ********************************************************/
/*	- The identifier to the left of the :: symbol identifies the namespace that the name to the right of the :: symbol is contained within. */
	namespace::name

/********************************************************************************************************************************************************************
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- General Notes ---------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
********************************************************************************************************************************************************************/
/*
- "\n" is slower then '\n' because it treats it as a string and has to run a loop.
*/

/********************************************************************************************************************************************************************
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Library Notes ---------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
********************************************************************************************************************************************************************/
/***** std::cout ********************************************************/
/*	- "Character Output"
	- It's used to print something out. */
	std::cout << "Sample Text!";

/***** std::cin ********************************************************/
/*	- "Character Input"
	- Reads input from the user, usually by using the extraction operator (>>). The input MUST be stored in a variable! */
	std::cin >> var;

/***** std::endl ********************************************************/
/*	- "end line"
	- Similar to '\n' but it also flushes (Which cout already does)
	- It's more efficient to use '\n' instead. */
	std::endl

/********************************************************************************************************************************************************************
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- General Examples ------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
********************************************************************************************************************************************************************/
/***** Wait for User Input ********************************************************/
/*	- Used for terminal-based programs, it basically won't close the terminal until the user enters a character. */
	#include <limits>
	std::cin.clear(); /* Reset any error flags. */
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /* Ignore any characters in the input buffer until we find an enter character. */
	//std::cin.get(); /* get one more char from the user. */

/***** Common Terminal Colors ********************************************************/
#define COLOR_DEFAULT "\033[0m" /* Default */
#define COLOR_BLACK "\033[30m" /* Black */
#define COLOR_RED "\033[31m" /* Red */
#define COLOR_GREEN "\033[32m" /* Green */
#define COLOR_YELLOW "\033[33m" /* Yellow */
#define COLOR_BLUE "\033[34m" /* Blue */
#define COLOR_MAGENTA "\033[35m" /* Magenta */
#define COLOR_CYAN "\033[36m" /* Cyan */
#define COLOR_WHITE "\033[37m" /* White */
#define COLOR_BOLDBLACK "\033[1m\033[30m" /* Bold Black */
#define COLOR_BOLDRED "\033[1m\033[31m" /* Bold Red */
#define COLOR_BOLDGREEN "\033[1m\033[32m" /* Bold Green */
#define COLOR_BOLDYELLOW "\033[1m\033[33m" /* Bold Yellow */
#define COLOR_BOLDBLUE "\033[1m\033[34m" /* Bold Blue */
#define COLOR_BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define COLOR_BOLDCYAN "\033[1m\033[36m" /* Bold Cyan */
#define COLOR_BOLDWHITE "\033[1m\033[37m" /* Bold White */