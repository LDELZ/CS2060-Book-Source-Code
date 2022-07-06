// Student: Luke Delzer
// Course: CS2060
// Semester: Summer 2022
// Due: 07/07/2022
// Fig. 7.28: fig07_28.c
// Demonstrating an array of pointers to functions.
#include <stdio.h>

// prototypes
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);

int main(void)
{
   size_t choice = 0; // variable to store user choice
   double inputOne = 0; // variable to hold first input
   double inputTwo = 0; // variable to hold second input
   double result = 0; // variable to store mathematical result

   // initialize array of 3 pointers to functions that each take an
   double (*f[4])(double, double) = { add, subtract, multiply, divide };

   // Display a menu for the user to select mathematical operations from
   puts("Enter a number to select a mathematical operation from the following list. Select 4 to end: ");
   puts("0 - Add");
   puts("1 - Subtract");
   puts("2 - Multiply");
   puts("3 - Divide");
   puts("4 - End program");

   scanf("%llu", &choice);

   // process user's choice
   while (choice >= 0 && choice < 4) {

      // choice as an argument 
      printf("You entered %llu. Now enter two numbers.\n", choice);

      // Obtain two inputs
      scanf("%lf", &inputOne);
      scanf("%lf", &inputTwo);

      // Calculate result and store in result
      result = (*f[choice])(inputOne, inputTwo);

      printf("The result is %g\n", result);
      
      // Repeat question
      printf("%s", "Enter a number between 0 and 3, 4 to end: ");
      scanf("%llu", &choice);
      
   } 
   
   puts("Program execution completed.");
} 

double add(double num1, double num2)
{
    double sum = 0.0;
    sum = num1 + num2;
    return sum;
}

double subtract(double num1, double num2)
{
    double difference = 0.0;
    difference = num1 - num2;
    return difference;
}

double multiply(double num1, double num2)
{
    double product = 0.0;
    product = num1 * num2;
    return product;
}

double divide(double num1, double num2)
{
    double quotient = 0.0;
    quotient = num1 / num2;
    return quotient;
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

