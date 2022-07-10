// Student name: Luke Delzer
// Course: CS2060
// Semester: Summer 2022
// Due date: 07/11/2022
// The purpose of this code is to complete #5 of the guided exploration in order to explain what we understand about the program.
/*
	if (inputStr[strlen(inputStr) - 1] == '\n')
	{
		inputStr[strlen(inputStr) - 1] = '\0';
	}
*/

// Several essential libraries are imported to use functions later in the program. 
#include <stdio.h> // Required to use stdin
#include <errno.h> // Required to use errno and 
#include <limits.h> // Required to import limit symbolic constants
#include <stdlib.h> // Required to use size_t
#include <string.h> // Required to use size_t data type and NULL macro
#include <stdbool.h> // Required to use boolean values 'true' and 'false' keywords as well as the bool data type

// The following defines the symbolic constant 'LENGTH' for the char array buffer.
// The buffer size will be 13, but could be easiy modified here.
#define LENGTH 13

// The following are the function prototypes for the three functions used in the program.
// This function prototype returns a boolean value and has a formal parameter for a character array pointer.
// Note the 'const' qualifier, which makes it so that the pointer cannot be modified.
bool exploreValidateInt(const char* buff);

// This function prototype returns a boolean value and has a formal parameter for a character array pointer and an integer pointer
// Note the 'const' qualifier in this scenario. 
// The character array pointer has no 'const' qualifiers, meaning that the pointer can be modified and the data it points to can be modified.
// The integer pointer has 1 'const' qualifier in the middle, meaning the pointer can be modified, but the data it points to cannot be modified.
bool validateInt(char* buff, int* const validInt);

// This function is a void function, which returns no value. It also has no formal parameters.
void printLimits();

// Beginning of main. Program execution begins here.
int main(void)
{	
	// The following declares a character array using the symbolic constant 'LENGTH'. This "string" buffer has a size of 13 for user input.
	char inputStr[LENGTH]; // create char arintray

	// This is a boolean flag, which signals if the returned value from exploreValidateInt is valid 'true' or not 'false'.
	bool isValid = false;

	// This is a long data type declaration. A long is selected because the standard library function strtol() is used later, which converts a string to a long.
	long integerValue = 0;

	// This is a character pointer with no passed-in address value. Its use is in the function strtol(), which is discussed below.
	char* end;

	// The following is an integer pointer declaration that assigns the address to the value integerValue
	// This pointer variable is no longer used in this program. It was used to answer question #4 of the guided exploration,
	// where the value for integerValue had to be updated in exploreValidateInt without using a boolean flag.
	int* integerValuePtr = &integerValue;

	// This is a declaration for an unsigned integer of type size_t. It is not used in this program currently. Size_t integers are best used for iterating through arrays.
	size_t inputLength = 0;

	// The following statement calls the printLimits function. A detailed explanation is presented above the function declaration.
	// No arguments are passed-in and no value requires capturing (it is a void function).
	printLimits();

	// Prompt the user to enter an integer and read it into the variable inputStr.
	puts("\nEnter an integer");

	// fgets() is used to read-in the the value for inputStr. fgets requires some explanation.
	// fgets() takes three arguments. The first is the pointer to a char array to store the string. inputStr is used, which has a total size of 13 (declared above)
	// The second argument represents how many characters can be placed into the string inputStr includding \0. We can use the same symbolic constant LENGTH, which is conventional.
	// Finally, the third argument specifies where information is to be read from. This program uses stdin, which reads input from the keyboard.
	fgets(inputStr, LENGTH, stdin);

	// The following is code that I placed in the program, which has a detailed explanation in the exploration.
	// I used a new function strtok() to oremove the '\n' from the character array. The first argument is the string to modify, and the second is the delimiter.
	// strtok() extracts the string tokens and replaces the first instance of the delimiter (here defined as '\n') with \0 since we must press the enter key on the keyboard.
	// The string is automatically modified. The return value reurns a pointer to the character where the delimiter last appeared. Using strtok again would remove the next delimiter.
	char *tokenPtr = strtok(inputStr, "\n");

	// The following for-loop has no functionality in this program, and contains no code. 
	// Originally, exploreValidateInput was placed inside, but I moved it outside of the loop to understand the program better.
	for (unsigned int counter = 1; counter < 6; counter++){}

	// The following is code that I added to satisfy question 4  of the exploration. 
	// By updating exploreValidateInt to return a boolean, the value 'isValid' is set to true if a valid integer is entered using the variable inputStr.
	// inputStr is passed into the function, which is a pointer to the character array. inputStr is tested for validity in the function
	isValid = exploreValidateInt(inputStr);

	// isValid can then be used in a selection statement to update integerValid only if the inputted value is valid. This is explaiined in detail in the exploration.
	// strtol() is a new function used here. strtol() takes three arguments. First, it takes the pointer to the string representing a number.
	// The middle argument '&end' is set to the value after numeric input is read. For example, if a dash follows a number, &end would be set to the position where the dash is.
	// The third argument is the base of the converted number. Base 10 is used for this case because this is a conventional number. Hexadecimal would be base 16. Binary is base 2.
	// strtol converts the string representing the number to the number itself and returns it. The returned number is stored in a variable of the appropriate data type.
	if (isValid) {
		integerValue = strtol(inputStr, &end, 10);
		printf("\n\nBack in main, integer value is %ld\n\n", integerValue);
	}
	
}

// This function prints each of the limits imported with the limits.h library. While the values are interesting to analyze, they are most useful when validating input
// Using the limits of each data type as ranges in validation prevents the variable from overflowing, which could produce errors. 
// Limits are used in exploreValidateInt to validate the inputted string as an integer.
void printLimits()
{
	// There are 8 bits in a byte
	printf("The number of bits in a byte %d\n", CHAR_BIT);

	// Range is -128 to 127 for ASCII values (1 byte)
	printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
	printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);

	// Unsigned values approximately double the maximum value, but eliminate negative values.
	printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

	// Approximately -32k to 32k
	printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
	printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

	// Approximately -2x10^9 to 2x10^9
	printf("The minimum value of INT = %d\n", INT_MIN);
	printf("The maximum value of INT = %d\n", INT_MAX);

	// Range is -128 to 127 for ASCII values (1 byte)
	printf("The minimum value of CHAR = %d\n", CHAR_MIN);
	printf("The maximum value of CHAR = %d\n", CHAR_MAX);
 
	printf("The minimum value of LONG = %ld\n", LONG_MIN);
	printf("The maximum value of LONG = %ld\n", LONG_MAX);
}

// This function employs the compliant method of validating and converting string input to a numeric value.
// A character array pointer is passed in (local variable 'buff').
bool exploreValidateInt(const char* buff)
{
	// This character pointer is explained in detail abov in line 92. It has the same functionality here.
	char* end;

	// errno is a macro which stores error codes. It is used once below, and is explained there.
	errno = 0;

	// This variable is no longer used because #4 in the exploration asks us to have the value for integerValue updated in main.
	int validInt = 0;

	// This is a boolean flag which is returned to signal whether a valid integer was inputted.
	bool inputValid = false;

	// As explained in detail on line 91, strtol converts a string representing a number to the number itself.
	// Here, the passed in string is converted to intTest for validity testing below.
	long intTest = strtol(buff, &end, 10);

	// 'end' is set to the value following numeric input in strtol. Buff is the first position in the string.
	// If the character following numeric input is the first character in the array, there were no numbers entered.
	// Therefore the input is not a decimal number.
	if (end == buff) {
		fprintf(stderr, "%s: not a decimal number\n", buff);
	}

	// else there is numeric data, if the value stored in the position after numeric input (accessed by dereferencing 'end') is not the NULL character,
	// Additional characters were added after the numeric input. \0 ends the inputted string by default. If the first character aftert numeric input is not the NULL character,
	// there were other additional characters added.
	else if ('\0' != *end) {
		fprintf(stderr, "%s: extra characters at end of input: %s\n", buff, end);
	}

	// else if the integer value is greater or less than the maximum or minimum (respectively) value accepted by the data type, it is out-of-range
	// This test prevents overflow errors by preventing the inputted number from being outside of the range accepted for the data type.
	// ERANGE is a macro which indicates that a range error occurred. If the inputted integer is out of range, ERANGE will populate with an error code
	// If that error code is the same as errno's error, it means that the range error did occur. 
	// If outside of the range, both conditions evaluate to true and the compound boolean expression is true.
	else if ((LONG_MIN == intTest || LONG_MAX == intTest) && ERANGE == errno) {
		fprintf(stderr, "%s out of range of type long\n", buff);
	}

	// else if the value is greater than what can be stored as an integer (not a long), it cannot be type-casted to an inter.
	else if (intTest > INT_MAX) {
		fprintf(stderr, "%ld greater than INT_MAX\n", intTest);
	}
	// else if the value is less than what can be stored as an integer (not a long), it cannot be type-casted to an inter.
	else if (intTest < INT_MIN) {
		fprintf(stderr, "%ld less than INT_MIN\n", intTest);
	}

	// Finally, the numeric value is validated. At this point, it can be casted to an integer.
	// Due to #4 in the exploration, the value for integerValue is updated in main, therefore casting here has no purpose.
	else {
		validInt = (int)intTest;
		printf("%ld is integer value ", intTest);
		// The input is valid, therefore the function can return a value of true to signal valid input back in main.
		// This signals that the integerValue can be updated.
		inputValid = true;
	}

	// return the boolean flag value.
	return inputValid;
}