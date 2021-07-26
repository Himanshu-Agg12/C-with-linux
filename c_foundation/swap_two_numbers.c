/* 
 * Program to swap two numbers without using third variable
 *
 * @Himanshu Aggarwal  ID->1911981022
 * 23/07/2021
 * Assignment->1 (C Foundations)
 *
 * Question number -> 1
 */
#include <stdio.h>

int main()
{
    int number1, number2;
    printf("Enter two numbers: \n");
    //scaning two numbers as input
    scanf("%d %d", &number1, &number2);

    printf("\nNumber before swaping \n number1 = %d, number2 = %d", number1, number2);
    //we are adding both numbers and assign it to number1
    number1 = number1 + number2;

    //we are subtracting number2 from the sum of both and assign it to number2 so now number2 contains number1
    number2 = number1 - number2;

    //we are subtracting number2 from the sum of both and assign it to number1 so now number1 contains number2
    number1 = number1 - number2;

    //Now numbers are swaped and we are printing the swapped numbers
    printf("\nNunbers after swaping: \n number1 = %d, number2 = %d\n", number1, number2);

    return 0;
}
