// Student Name: Luke Delzer
// Course: CS2060
// Semester: Summer 2022
// Due: 07/04/2022

/*******************
 Understanding pointers

 Add comments to explain the code
**************/

#include <stdio.h>


int main ()
{
	// Initalize houseNum
	// This is the ordinary method for declaring and initializing a variable
	// Memory for houseNum is allocated and, in the memory, the nuber 13 is stored
	// The identifier houseNum contains the address to the memory allocated
	int houseNum = 13;

	// Similar to the above explanation, calcHouseNum1 and calcHouseNum2 are declared
	// Memory is allocated for each, and in each memory location the number 0 is stored
	// calcHouseNum1 and calcHouseNum2 are not contiguous, meaning memory is stored at different, unrelated addresses
	int calcHouseNum1 = 0;
	int calcHouseNum2 = 0;

	// A pointer is declared called houseNumPtr. The '*' in the declaration indicates that the proceeding identifier contains the memory address assigned to it.
	// &houseNum is assigned to *houseNumPtr. The address operator preceeding houseNum returns the address of the memory allocated for houseNum, and this address is stored in *houseNumPtr.
	// In other words, *houseNumPtr points to the address of the memory allocated for houseNum.
	int *houseNumPtr = &houseNum;
	
	// The following statement prints the value in houseNum. The houseNum identifier contains the address to the memory allocated for it. In that memory the number 13 is stored.
	// Printing houseNum returns the value stored in that address, passing in the value '13' to the printf function. The format specifier '%d' expects an integer and '13' is diplayed in the statement.
	printf("houseNum %d\n", houseNum);

	// The following printf statement is the same as above but now uses the address operator '&'. The address operator returns the memory address for the memory allocated for that variable.
	// In this case, the memory address for the memory allocated for houseNum will be passed into the printf. The format specifier '%p' displays the address in the printf statement.
	printf("&houseNum %p\n\n", &houseNum);

	// This statement contains the indirection operator '*', which returns the value stored inside the address the pointer is pointing to.
	// We know from above that houseNumPtr points to the address of houseNum. Inside of that memory is the value 13. Therefore dereferencing houseNumPtr using '*' returns the value 13 contained there.
	// The %d format specifier indicates that an integer value will be passed into the printf.
	printf ("*houseNumPtr  %d\n", *houseNumPtr);

	// This statement no longer dereferences houseNumPtr, therefore the address assigned will be returned and printed in the statement. '%p' is used to print addresses.
	// What is important here is that the SAME address will display as in the statement above. houseNumPointer contains the address to houseNum. So printing &houseNum and houseNumPtr shows the same address.
	printf ("houseNumPtr %p\n\n", houseNumPtr);

	// This statement now applies the address operator to houseNumPtr. houseNumPtr is a pointer declared above, and although it is assigned an address, its memory allocation is in a different address.
	// What is important is that houseNumPtr is a variable with its own memory allocation, and inside that memory is the address to the memory of a different variable (in this case &houseNum).
	// Declaring a pointer and assigning an address does not make the address of the pointer the same as the pointed to address. We can see this is true from the printed memory address being different.
	printf ("&houseNumPtr %p\n\n", &houseNumPtr);

	// Dereferencing is used in a binary arithmetic operation in the following statement. The value in houseNumPtr is obtained using '*' and those values are summed, then assigned to calcHouseNum2.
	// What is important here is that we can treat dereferenced pointer expressions as the data type cointained within them. In this case, arithmetic operations can be performed because they are integers.
	calcHouseNum1 =  *houseNumPtr + *houseNumPtr;

	// This statment prints the sum calcHouseNum1, which is set to '26' in the arithmetic statement above.
	printf("*houseNumPtr + *houseNumPtr is %d\n\n", calcHouseNum1);

	// The following arithmetic statment uses the same concept as above where houseNumPtr is dereferenced, and the integer value is multiplied by 2. The result is assigned to calcHouseNum2.
	// It is important to understand whether '*' is being used to dereference a pointer or to multiply values in a binary arithmetic operation.
	// I removed the parenthesis to show that the function still works but can be made much more confusing. This must be kept in mind to keep code readable.
	calcHouseNum2 = 2 **houseNumPtr;

	// The following prints the value in calcHouseNum2 in the same way as above. The same value, '26' will display.
	printf("2 * (*houseNumPtr) is %d\n\n", calcHouseNum2);

	// The following statement demonstrates the result of differently ordered address and indirection operators when used at the same time.
	// When used together, the result is the same, regardless of operator order. As we see in the output, the address is printed both times.
	printf("\n&*houseNumPtr = %p"
		"\n*&houseNumPtr = %p\n", &*houseNumPtr, *&houseNumPtr);
			
	return 0;
}
