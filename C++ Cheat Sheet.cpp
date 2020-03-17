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
* -w		= Disables all warning messages.
* -Wall		= Produce warning messages about a number of things that are legal but unreliable. Suggested to always use this and treat every warning as an error to be fixed.
* -Wextra	= Enables some extra warning flags that are not enabled by -Wall. More Information: http://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
* -I		= Specifies an alternate include directory. Example:  -I/source/headers/  No spaces after the -I command!
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
	/*  Initialization = The object is given a known value at the point of definition.
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
	type identifier(parameters){}

/* Concatenation
	Strings can be concatenated without even putting anything in between, example: */
	"My " "Name" /* Output ---> "My Name", this can be used to split up very long strings to multiple lines. */
		/* Example: */
		std::cout << "This is a really, really, really, really, really, really, really, "
		"really long line\n"; /* Since the string is very long, we split it into 2 lines. */

/* Forward Declaration
	 Since the ordering of the functions in C++ matters, we use forward declaration to let the compiler know that an identifier exists before it is actually defined.
	 We can use forward declaration by using a system called "function prototype", example: */
	type identifier(parameters); /* Function prototype includes: return type, identifier, parameters, and a semicolon. The body of the function isn't defined here! */

/* Preprocessors - Usually starts with the symbol  #  it basically replaces or changes things in the files. */
	/* Directives are only valid from the point of definition to the end of the file in which they are defined. */
	/* They have no scope, so putting it inside a function or outside doesn't make any difference. */
	/* Preprocessor directive, it basically replaces the #include directive with the contents of the included file. */
	#include <file>		/* <> tells the preprocessor this is a file included with the compiler, so it should look for the file in the system directories. */
	#include "file.h"	/* "" tells the preprocessor this is a user-defined file, so it should look for the file in the directory containing the source code. */

	/* A macro directive, before full compilation, it gets all the tokens in the code and replaces it with the value, kind like find & replace! Macros don't replace other preprocessors! */
	#define token value

	/* Conditional Compilation Preprocessor - Allows you to specify under what conditions something will or won’t compile. */
	#ifdef token	/* Compile if the given token exists. */
	#ifndef token	/* Compile if the given token doesn't exist. */
	#if value		/* Compiles if the value is true. */
	#endif			/* Ends a conditional compilation preprocessor. */

	/* Example: */
	#define PRINT_HELLO /* Empty macro. */
	#ifdef PRINT_HELLO
		std::cout << "Hello!"; /* This will compile because PRINT_HELLO is defined! */
	#endif
	#ifdef PRINT_HI
		std::cout << "Hi!"; /* This won't compile because PRINT_HI isn't defined! */
	#endif
	#ifndef PRINT_HI
		std::cout << "Hi!\n"; /* This will compile because PRINT_HI isn't defined! */
	#endif
	#if 0
		std:cout << "I don't run =("; /* Useful to comment out code that contains nested comments. */
	#endif

/* Namespaces
	Any names not defined inside a function, class or a namespace is automatically placed inside the global namespace (aka global scope). */
	using namespace name; /* Basically tells the compiler that if it comes across a identifier without a prefix, it should check to see if it's defined locally or in the defined namespace. */

/* Header Files : Usually ends with  .h  or  .hpp  or sometimes it doesn't have an extension.
	Header files allow us to put declarations in one location and then import them wherever we need them. This can save a lot of typing (forward declarations) in multi-file programs.
	- It's better to have a separate header file for each .cpp file instead of having them all in one file (Better for compilation, especially in big files).
	- To keep things organized, name the header file the same as its paired .cpp file.
	- Highly recommended to #include the header file in its paired .cpp file, this is to avoid unexpected errors in the future!
	- For the standard library, use the no extension version (without the .h) if it exists. It's much more updated then the .h version.
	- Header files can include other header files, which will include all the definitions of the parent header file, including the parent's parent definitions!
	Header Guards - Designed to ensure that the contents of a given header file aren't copied more than once into any single file, in order to prevent duplicate definitions. */
	#ifndef FILE_NAME_H /* Create a unique name for it, best practice is to name it the same as the file. */
	#define FILE_NAME_H
			// The actual content of the header file goes here
	#endif

/* Scope Resolution Operator  ::
	The identifier to the left of the :: symbol identifies the namespace that the name to the right of the :: symbol is contained within. */
	namespace::name

/* main Function
	- Every program MUST have a main function!
	- The main function MUST return a value of type int!
	- The return value (status code) is retrieved by the operating system (and any other programs that called this program).
	- return 0 means that the program ran normally/successfully.
	- return a non-0 means that the program it encountered an error and could not complete as expected.
	- Recommended to place the main function at bottom of which ever file it's located in. */
	int main()

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