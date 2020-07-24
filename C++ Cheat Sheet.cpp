//////////////////////// C++ Cheat Sheet \\\\\\\\\\\\\\\\\\\\\\\\
	///// Created by DrVrej | Since January 30, 2020! \\\\\
	///// NOTE: It's highly recommended to open this file in an editor! Many of the tabs & spacings may not display properly on the web! \\\\\
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
-- Concepts ---------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
********************************************************************************************************************************************************************/
/***** Data Types ********************************************************/
/*	- Data types are used to tell the compiler how to interpret the contents of a memory.
	- When a data type is assigned, the value is converted to a sequence of bits and will convert back to its normal form when it's being evaluted to produce a value.
	- Many of the types defined in newer versions of C++ use a _t suffix, it means “type” and it’s usually applied to modern types.
	
	/* [Fundamental / Primitive Data Types]
		- The basic built-in data types.
		- (-/+) --> The negative side always has 1 extra number! (Ex: -128 to 127 for 8-bits)
		- Integer types can contain the keyword "int", but it's recommended not to put it! (Ex: long = long int  OR  short = short int)
	- signed = Default type. The number’s sign is preserved, so it an hold negative, positive, and 0.
	- unsigned = Integers that can only hold non-negative whole numbers.
	  -> Wrap around: When the number is to small or to large, it wraps around. Example 8-bit integer (max 255): -2 --> 254 | -1 --> 255 | 256 --> 0 | 257 --> 1
	[Year]	[Type]					[Size]		[Range]				[Category]				[Examples]*/
			short					16-bits		-+ 32,767			Integral (Integer)		-1, 0, 1, 64
			unsigned short			16-bits		+  65,535
			int						16-bits		-+ 32,767
			unsigned int			16-bits		+  65,535
			long					32-bits		-+ 2,147,483,647
			unsigned long			32-bits		+  4,294,967,295
	C++11	long long				64-bits		-+ 9,223,372,036,854,775,807
	C++11	unsigned long long		64-bits		+  18,446,744,073,709,551,615
			std::size_t				Defined to hold the largest object creatable on the system and it is a unsigned integer.
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/* Floating point numbers are always signed! */
			float					32-bits		-+ 3.4 * 10^38		Floating Point			-3.14159f, 1.0f, 3.2F, 5.01F
			double					64-bits		-+ 1.7 * 10^308		Floating Point			-3.14159, 1.0, 3.2, 1.6e-19, 6.02e23
			long double				64-bits		-+ 1.7 * 10^308		Floating Point			-3.14159l, 1.0l, 3.2L, 5.01L
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/* - A char value is interpreted as an ASCII character. */
			char					8-bits		-+ 127				Integral (Character)	'c', 'a', '?', '\n'
			unsigned char			8-bits		+  255
			wchar_t					16-bits		+  65,535
	C++20	char8_t					8-bits		-+ 127
	C++11	char16_t				16-bits		+  65,536
	C++11	char32_t				32-bits		+  4,294,967,295
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			void					n/a			n/a					Void					n/a
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			bool					8-bits		0 or 1				Integral (Boolean)		0 (false) or 1 (true)	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	C++11	std::nullptr_t											Null Pointer			nullptr
	
	/* [Fixed-Width Integer Data Types]
		- These should be avoided for multiple reasons:
		  1. They are optional and only exist if there are fundamental types matching their widths.
		  2. Makes the code less portable and may not even compile on some systems.
		  3. It may be slower because some CPUs are better at processing a 32-bit wide integer.
		- Avoid the 8-bit fixed-width integer types. They are often treated like chars!
	[Year]	[Type]					[Size]		[Range]				[Category]				[Examples]*/
	C++11	int8_t					8-bits		-+ 127				Integer					-1, 0, 1, 64
	C++11	uint8_t					8-bits		+  255
	C++11	int16_t					16-bits		-+ 32,767
	C++11	uint16_t				16-bits		+  65,535
	C++11	int32_t					32-bits		-+ 2,147,483,647
	C++11	uint32_t				32-bits		+  4,294,967,295
	C++11	int64_t					64-bits		-+ 9,223,372,036,854,775,807
	C++11	uint64_t				64-bits		+  18,446,744,073,709,551,615
	
	/* [Fast Integer Data Types]
		- Provides the fastest integer type with a width of at least # bits (where # = 8, 16, 32, or 64).
		  -> Example: std::int_fast32_t will give you the fastest signed integer type that’s at least 32 bits.
		- Uses: If you need a variable guaranteed to be a particular size and want to favor performance, use this!
		- Avoid the 8-bit fixed-width integer types. They are often treated like chars!
	[Year]	[Type]					[Size]		[Range]				[Category]				[Examples]*/
	C++11	int_fast8_t				8-bits		-+ 127				Integer					-1, 0, 1, 64
	C++11	uint_fast8_t			8-bits		+  255
	C++11	int_fast16_t			16-bits		-+ 32,767
	C++11	uint_fast16_t			16-bits		+  65,535
	C++11	int_fast32_t			32-bits		-+ 2,147,483,647
	C++11	uint_fast32_t			32-bits		+  4,294,967,295
	C++11	int_fast64_t			64-bits		-+ 9,223,372,036,854,775,807
	C++11	uint_fast64_t			64-bits		+  18,446,744,073,709,551,615
	
	/* [Least Integer Data Types]
		- Provides the smallest integer type with a width of at least # bits (where # = 8, 16, 32, or 64).
		  -> Example: std::int_least32_t will give you the smallest signed integer type that’s at least 32 bits.
		- Uses: If you need a variable guaranteed to be a particular size and want to favor memory conservation over performance, use this! This is used most often when allocating lots of variables.
		- Avoid the 8-bit fixed-width integer types. They are often treated like chars!
	[Year]	[Type]					[Size]		[Range]				[Category]				[Examples]*/
	C++11	int_least8_t				8-bits		-+ 127				Integer					-1, 0, 1, 64
	C++11	uint_least8_t			8-bits		+  255
	C++11	int_least16_t			16-bits		-+ 32,767
	C++11	uint_least16_t			16-bits		+  65,535
	C++11	int_least32_t			32-bits		-+ 2,147,483,647
	C++11	uint_least32_t			32-bits		+  4,294,967,295
	C++11	int_least64_t			64-bits		-+ 9,223,372,036,854,775,807
	C++11	uint_least64_t			64-bits		+  18,446,744,073,709,551,615
	
/***** Literals ********************************************************/
/*	- Just like objects have a type, all literals have a type. The type of a literal is assumed from the value and format of the literal itself.
	/* [Default Literal Types]
		- These are the types applied by default when the compiler sees certain data types.
	[Name]				[Example]			[Default Type]*/
	Integral			-3, 0, 8			int
	Boolean				true, false			bool
	Floating Point		-2.5, 0.0, 5.1		double
	Character			'a', 'k', 'w'		char
	C-Style String		"Hello, world!"		const char[14]
	
	/* [Literal Suffixes]
		- Makes readability much better.
		- Can be useful when giving a direct input to overloaded functions (Ex: To make the "long" version of the function run, you put "3L" instead of "3").
		- Highly recommended to use a suffix for "float" data type!
	[Data]	[Suffix]								[Meaning]				[Example]*/
	int		u, U									unsigned int			5U, 8U
	int		l, L									long					-1L, 10L
	int		ul, uL, Ul, UL, lu, lU, Lu, LU			unsigned long			5UL, 9UL
	int		ll, LL									long long				-5LL, 10LL
	int		ull, uLL, Ull, ULL, llu, llU, LLu, LLU	unsigned long long		5ULL, 7ULL
	double	f, F									float					-2.4f, 0.8f
	double	l, L									long double				-9.245L, 6.2743L
	
	/* [Literal Prefixes]
		- Used to define different base numbers.
	[Name]			[Prefix]	[Range]		[Example]*/
	Binary			0b			0 and 1		0b1111 --> 15 (decimal)
	Octal			0			0 to 7		017 --> 15 (decimal)
	Hexadecimal		0x			0 to F		0xF --> 15 (decimal)
	
/***** Constants  ********************************************************/
/*	- If something is initialized as a constant, it can't be changed!
	- All constants must be initialized with a value.
	
	- Compile Time Constants: Constants whose value can be determined during compile time. (Ex: Initializing a constant variable that holds Earth's gravity, 9.81).
	- Run Time Constants: Constants whose value can only be determined during runtime. (Ex: Initializing a constant variable that requires a user input).
	
	/* [const] 
		- Inherited from C, it can be used for both compile & run time.
		- Note: Use constexpr when the initializer is not known at compile time and must be determined at run time. */
	const int name{1} /* Initializes a constant variable of type int with the value 1. */
	int const name{1} /* Same as above, not recommended to write it in this format! */
	
	/* [constexpr] 
		- Introduced in C++11, it can ONLY be used for compile time. Using this will enable the compiler to perform more optimizations. 
		- Note: Use constexpr when the initializer is known at compile-time. */
	constexpr int name{1} /* Initializes a constant variable of type int with the value 1. */
	int constexpr name{1} /* Same as above, not recommended to write it in this format! */
	
/***** Operators ********************************************************/
/*	- Precedence: Level 1 is the highest precedence level and level 17 is the lowest. Operators with a higher precedence level get evaluated first.
	- Associativity: Determines which side of the operator gets evaluated first. (Ex: If 2 operators have the same precedence, it will determine which evaluates first).
	[Precedence] [Associativity] [Operator]			[Description]				[Example]*/
	1            N/A             ::					Namespace Scope				::name, class::member
		/*	- If the left side is empty then it refers to the global scope (ex: ::var).
			- The identifier to the left of the :: symbol identifies the namespace that the name to the right of the :: symbol is contained within. */
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	2            L->R            ()					Parentheses					(expression)
	2            L->R            ()					Function Call				function(parameters)
	2            L->R            ()   {}			Initialization				var(), var{}
	2            L->R            ()   {}			Functional Cast				type(), type{}
	2            L->R            []					Array subscript				pointer[expression]
	2            L->R            .					Member Access 				object.member
	2            L->R            ->					Member Access Pointer 		object_pointer->member
	2            L->R            ++					Post-increment				value++
	2            L->R            --					Post-decrement				value--
	2            L->R            typeid				Run-time type Information	typeid(expression)
	2            L->R            const_cast			Cast Away const				const_cast<type>(expression)
	2            L->R            dynamic_cast		Run-time cast				dynamic_cast<type>(expression)
	2            L->R            static_cast		Compile-time cast			static_cast<type>(expression)
	2            L->R            reinterpret_cast	Cast to another type		reinterpret_cast<type>(expression)
	2            L->R            noexcept			Compile-time Exception		noexcept(expression)
	2            L->R            alignof			Get Type Alignment			alignof(Type)
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	3            R->L            +  -				Unary Plus / Minus			+expression, -expression
		/* + operator is rarely used (it's redundant), but - operator widely used to multiply something to be negative. */
	3            R->L            ++					Pre-increment				++value
	3            R->L            --					Pre-decrement				--value
	3            R->L            !					Logical NOT					!expression
	3            R->L            ~					Bitwise NOT					~expression
	3            R->L            &					Memory Address				&value
	3            R->L            *					Dereference					*expression
	3            R->L            (type)				C-style Cast				(type)expression
	3            R->L            new				Dynamic Memory Allocation	new type
	3            R->L            new[]				Dynamic Array Allocation	new type[expression]
	3            R->L            delete				Dynamic Memory Deletion		delete pointer
	3            R->L            delete[]			Dynamic Array Deletion		delete[] pointer
	3            R->L            sizeof				Size in Bytes				sizeof(type) or sizeof(expression)
		/*	- The sizeof operator is a unary operator that takes either a type or a variable and returns its size in bytes. */
	3            R->L            co_await			Await Asynchronous Call		co_await expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	4            L->R            .*					Member Object selector		object.*pointer_to_member
	4            L->R            ->*				Member Pointer Selector		object_pointer->*pointer_to_member
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	5            L->R            *					Multiplication				expression * expression
	5            L->R            /					Division					expression / expression
	5            L->R            %					Modulus						expression % expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	6            L->R            +					Addition					expression + expression
	6            L->R            -					Subtraction					expression - expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	7            L->R            <<					Bitwise Shift Left			expression << expression
	7            L->R            >>					Bitwise Shift Right			expression >> expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	8            L->R            <=>				Three Way Comparison		expresstion <=> expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	9            L->R            <					Less than					expression < expression
	9            L->R            <=					Less than or equals			expression <= expression
	9            L->R            >					Greater than				expression > expression
	9            L->R            >=					Greater than or equals		expression >= expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	10           L->R            ==					Equality					expression == expression
	10           L->R            !=					Inequality					expression != expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	11           L->R            &					Bitwise AND					expression & expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	12           L->R            ^					Bitwise XOR					expression ^ expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	13           L->R            |					Bitwise OR					expression | expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	14           L->R            &&					Logical AND					expression && expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	15           L->R            ||					Logical OR					expression || expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	16           R->L            =					Assignment					var = expression
	16           R->L            *=					Multiplication Assignment	var *= expression
	16           R->L            /=					Division Assignment			var /= expression
	16           R->L            %=					Modulus Assignment			var %= expression
	16           R->L            +=					Addition Assignment			var += expression
	16           R->L            -=					Subtraction Assignment		var -= expression
	16           R->L            <<=				Bitwise Shift Left Assign	var <<= expression
	16           R->L            >>=				Bitwise Shift Right Assign	var >>= expression
	16           R->L            &=					Bitwise AND Assignment		var &= expression
	16           R->L            |=					Bitwise OR Assignment		var |= expression
	16           R->L            ^=					Bitwise XOR Assignment		var ^= expression
	16           R->L            ?:					Ternary Conditional			expression ? expression : expression
	16           R->L            throw				Throw						throw expression
	16           R->L            co_yield			Yield						co_yield expression
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	17           L->R            ,					Comma						expression, expression
	
/***** Preprocessors ********************************************************/
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
		- If the compiler comes across a identifier without a prefix, it will check if it's defined locally or in the defined namespace. */
	using namespace name;

/***** Variable Initialization ********************************************************/
/*	- Uninitialized = A variable that hasn't been given a value (Usually through initialization or assignment). Using the value stored in an uninitialized variable will result in undefined behavior.
	- Initialization = The object is given a known value at the point of definition.
	- Assignment = The object is given a known value beyond the point of definition.
	- NOTE: Can't be defined type void! */
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

/***** Functions ********************************************************/
	type identifier(parameters){}
	
	/* [Deprecated: Void parameter]
		- Comes from C, void indicates that the function takes no parameter.
		- This is deprecated and recommended to just leave the parameter section empty instead. */
	int function(void){}

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

/********************************************************************************************************************************************************************
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- General Notes ---------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
********************************************************************************************************************************************************************/
/*
	- Using the operator ' it can be used as a digit separator (Ex: 1000 = 1'000 = 1'0'0'0). This is used to make readability better.
*/

/***** Escape sequences ********************************************************/
/*	- These can be used as a character or in strings.
	[Sequence]	[Name]				[Purpose]*/
	'\a'		Alert				Makes an alert, usually accompanied by a beep sound.
	'\b'		Backspace			Moves the cursor back one space.
	'\r'		Carriage Return		Moves cursor to the beginning of the line.
	'\n'		New Line			Moves cursor to next line, much faster than "\n" because the other one is treated as a string and has to run a loop to print!
	'\f'		Form Feed			Moves the cursor to the next page. Used for printing, inserts a blank page.
	'\t'		Horizontal tab		Prints a horizontal tab.
	'\v'		Vertical tab		Prints a vertical tab.
	'\''		Single quote		Prints a single quote.
	'\"'		Double quote		Prints a double quote.
	'\\'		Backslash			Prints a backslash.
	'\?'		Question Mark		Prints a question mark. No longer relevant as ? can now be used unescaped in a regular character or string.
	'\(#)'		Octal Number		Translates into char represented by octal
	'\x(#)'		Hex Number			Translates into char represented by hex number

/***** Unique Numbers ********************************************************/
/*	- Numbers that are unique and can result from certain arithmetics.
	[Name]			[Meaning]*/
	nan, NAN		Not a number (mathematically invalid)
	inf				Positive infinity
	-inf			Negative infinity

/***** Merge Lines Character: \ ********************************************************/
/*	- \ tells the compiler that the current line continues to the next line and it should compile them as one by merging them. */
	if(1 \
		  \
		   \
		    == 1){
		std::cout << "MAGIC\n";
	}

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