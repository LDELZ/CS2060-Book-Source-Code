// Fig. 6.13: fig06_13.c
// Passing arrays and individual array elements to functions.
#include <stdio.h>
#define SIZE 5
#define ROWS 3
#define COLUMNS 4
// function prototypes
void modifyArray(int b[], size_t size);
void modifyElement(int e);
void printArray(const int array[]); //Function prototype added above main
void testNames(int passedArray[]);
void fillArray(int passedArray2D[][COLUMNS]);
void printArray2D(const int passedArray2D[][COLUMNS], size_t tier, size_t contents);
int testScalars(const int number);
// function main begins program execution
int main(void)
{
    int array2D[ROWS][COLUMNS];
    fillArray(array2D);
    printArray2D(array2D, ROWS, COLUMNS);



   int a[SIZE] = { 0, 1, 2, 3, 4 }; // initialize array a
 
   printArray(a); // Call to function printArray passing in array 'a'
   puts("");
   puts("");
   puts("Effects of passing entire array by reference:\n\nThe "
      "values of the original array are:");

   // output original array
   for (size_t i = 0; i < SIZE; ++i) { 
      printf("%3d", a[i]);
   } 

   puts(""); // outputs a newline

   modifyArray(a, SIZE); // pass array a to modifyArray by reference                         
   puts("The values of the modified array are:");

   // output modified array
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%3d", a[i]);
   } 

   // output value of a[3]
   printf("\n\n\nEffects of passing array element "
      "by value:\n\nThe value of a[3] is %d\n", a[3]);
   
   modifyElement(a[3]); // pass array element a[3] by value

   // output value of a[3]
   printf("The value of a[3] is %d\n", a[3]);
}

// in function modifyArray, "b" points to the original array "a" 
// in memory                                                     
void modifyArray(int b[], size_t size)                               
{                                                                   
   // multiply each array element by 2                         
   for (size_t j = 0; j < size; ++j) {                                 
      b[j] *= 2; // actually modifies original array               
   }                                                 
} 

// in function modifyElement, "e" is a local copy of array element
// a[3] passed from main                                     
void modifyElement(int e)                                       
{                                                                 
   // multiply parameter by 2                                  
   printf("Value in modifyElement is %d\n", e *= 2);            
} 
  
void printArray(const int array[]) {
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%2d", array[i]);
    }
}
void printArray2D(const int passedArray2D[][COLUMNS], size_t tier, size_t contents) {
    printf("\n\n%s\n\n", "Output of the newly filled array");
    for (size_t i = 0; i < tier; i++) {
        for (size_t j = 0; j < contents; j++) {
            printf("%13d ", passedArray2D[i][j]);
        }
        puts("");
    }
    puts("\n");
}
void testNames(int passedArray[]) {
    printf("%-40s%p\n", "The value of the array name is: ", passedArray);
    printf("%-40s%p\n", "The value of the first element in a is: ", &passedArray[0]);
    printf("%-40s%p\n", "The value of the array address is: ", &passedArray);
    puts("");
}
void fillArray(int passedArray2D[][COLUMNS]) {
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLUMNS; j++) {
            scanf("%d", &passedArray2D[i][j]);
        }
    }
}
int testScalars(const int number) {
    number += 2;
    return number;
}



/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

