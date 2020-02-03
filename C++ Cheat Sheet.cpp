//////////////////////// C++ Cheat Sheet \\\\\\\\\\\\\\\\\\\\\\\\
	///// Created by DrVrej | Since January 30, 2020! \\\\\




/*********************** Compiler Notes ***********************/
/*
* -Wall = Produce warning messages about a number of things that are legal but unreliable. Suggested to always use this and treat every warning as an error to be fixed.
* -Wextra = Enables some extra warning flags that are not enabled by -Wall. More Information: http://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
*/




/*********************** Coding Notes ***********************/
/* Preprocessor directive, it indicates that we would like to use the contents of the given library. */
#include <value>

/* A macro, basically before full compilation, it gets all the tokens in the code and replaces it with the value, kind like find & replace! */
#define token value

/* Stands for "Character Output", it's used to basically print. */
std::cout << "Sample Text!";




/*********************** Coding Examples ***********************/
/* Small code, mostly used for terminal based programs, it basically won't close the terminal until the user enters a character. */
#include <limits>
std::cin.clear(); // Reset any error flags
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any characters in the input buffer until we find an enter character
//std::cin.get(); // get one more char from the user