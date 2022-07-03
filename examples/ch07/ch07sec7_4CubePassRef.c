// Student Name: Luke Delzer
// Course: CS2060
// Semester: Summer 2022
// Due: 07/04/2022

// Passing Primitive Data Types and pointers
//Add comments to explain the code

#include <stdio.h>	
#include <stdlib.h>

// Function prototypes for cubePass1 and cubePass2.
// cubePass1 expects an integer argument and returns an integer result.
// cubePass2 receives an address argument, indicated by the '*' pointer definition. It returns an integer.
int cubePass1(int number);
int cubePass2(int * numberPtr);

int main(void) {

	// Integer variables numberMain and result are declared and set to 5 and 0, respectively.
	int numberMain = 5;
	int result = 0;
	
	// The following prints the value numberMain before passing it to the function cubePass1. The value '5' prints. '%d' formats the integer value in the statement.
	printf ("In main before cubePass1  numberMain = %d\n", numberMain);

	// The following prints the address for numberMain using the address operator '&'. The address, 000000F2FF91F7D4, should be noted as it will be different when passing to a function (discussed below).
	printf("&numberMain = %p\n", &numberMain);

	// The following calls the function cubePass1, storing the returned integer result in 'result'. numberMain, an integer, is passed in as an argument. Control is switched to cubePass1
	result = cubePass1(numberMain);

	// The following prints the value in 'numberMain' after cubePass1. numberMain was passed-by-value and a copy was made. Therefore 'numberMain' never changed and is the same as before cubePass1.
	printf ("In main after cubePass1  numberMain = %d\n", numberMain);

	// The returned integer 'result' is printed.
	printf ("Result = %d\n", result);

	// 'numberMain' is printed again to compare its value before and after cubePass2. numberMain stores the value '5', which will change after cubePass2.
	printf("\nIn main before cubePass2  numberMain = %d\n", numberMain);

	// cubePass2 is called, passing in the address of 'numberMain' as an argument. The address operator '&' is used to get the address of 'numberMain'.
	// cubePass2 expects an address argument, indicated by the '*' definition in the formal parameters. The returned integer result is assigned to 'result'.
	result = cubePass2(&numberMain);

	// This statment prints the new value for 'numberMain', which has been persistently changed by the function.
	// We see that the value is different when printing it. Now the value is '125' from the cube operation in cubePass2. This is distinct from what we saw above in the pass-by-value example.
	printf("\nIn main after cubePass2  numberMain = %d\n", numberMain);

	// The newly assigned 'result' is printed using the '%d' format specifier.
	// The value assigned to 'result' is from the returned 'cube' value from the function cubePass2. Returning is one way that values are passed back to main.
	// We see that the values in memory can be directly modified inside of the function as well by passing the address of the memory to the function.
	printf("result = %d\n", result);

} // main

//Funtion cubePass1 takes an integer value, cubes it, and returns the result. This function passes-by-value, so the passed-in number does not change once the function completes.
int cubePass1 (int number) 
{
	// Automatic integer variable 'cube' is declared and set to '0'.
	int cube = 0;

	// Prints an introduction to the results.
	puts("\nIn cubePass1");

	// Local variable 'number' is printed in the statement. number is an integer and the format specifier '%d' is used to display it in the statement.
	printf("number = %d\n", number);

	// The address for the local variable number is now displayed using the address operator '&' and the '%p' format specifier. 
	// The printed address, 000000F2FF91F7B0, is different than the address for numberMain above, which is passed in as the argument.
	// This demonstrates that local variables have memory allocated for them unique to a function, reinforcing the concept that values are pass-by-value in which a copy is passed, not the value itself.
	printf("&number = %p\n", &number);

	// An arithmetic operation finds the cubed value of local variable 'number' by multiplying itself three times. The resulting value is assigned to 'cube'.
	cube = number * number * number;

	// THe following prints the value in 'cube' using the integer '%d' format specifier.
	printf("cube  = %d\n", cube);

	// The variable 'number' is assigned the value of 'cube'. 'number' is a local variable whose memory will be deallocated when the frame is removed from the stack.
	number = cube;

	// The new value in 'number' is printed.
	printf("number = %d\n", number);

	// The integer value in 'cube' is returned to main and stored in the value 'result'. Control returns to main.
	return cube;
} // End of cubePass1

// Function cubePass2 takes an address and uses it in the function to update the actual value in that address.
int cubePass2 (int * numberPtr) 
{
	// Automatic variable 'cube' is declared and assigned the number '0'.
	int cube = 0;

	// Prints an introduction to the results.
	puts ("\nIn cubePass2");

	// This statement prints the passed-in address, which is the local variable numberPtr, which stores the address '&numberMain' 
	// It is important to note that the address passed in is the same address as &numberMain from above because the local address is initialized as the passed-in address.
	printf("numberPtr = %p\n", numberPtr);

	// The following dereferences numberPtr using '*' and prints the integer result. The passed-in address is the same as the originally assigned address, therefore '5' still results from dereferencing it.
	printf ("*numberPtr = %d\n", *numberPtr);

	// The following prints the address of numberPtr using the address operator '&'.
	// We see that the address is actually different this time because numberPtr has its own address, not the same address as the address it stores.
	printf("&numberPtr = %p\n", &numberPtr);

	// The '*' symbol is used in two different ways here. numberPtr is dereferenced 3 times, each in parenthesis, to obtain the value stored in numberPtr (which is 5).
	// The '*' is used between parenthesis to multiply the dereferenced value 3 times. The result, '125' is stored in 'cube'.
	cube = (* numberPtr )* (* numberPtr )* (* numberPtr);

	// This statement takes the variable numberPtr, an address to a primitive data type, and assigns it the value 'cube'.
	// This time, the actual value contained in that memory location is updated by using the '*' on the left side of the assignment.
	// This will persist even after the function ends as demonstrated above.
	*numberPtr = cube;

	// The value in numberPtr is printed to demonstrate that the value is the same inside and outside of the function.
	printf ("*numberPtr = %d\n", *numberPtr);

	// The value of 'cube' is returned.
	return cube;
} // End of function cubePass2


