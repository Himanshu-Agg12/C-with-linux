/*
 * Program to find Highest commone factor of two number using recursion.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 05 (Recursion) 
 *
 *05/08/2021
 *
 * Question number -> 02
 */
#include <stdio.h>

//recursive function for finding gcd/hcf.
int find_gcd(int num1, int num2)
{
//if remainder becomes zero then we return quotient stored as num1.
    if(num2 == 0)
        return num1;
//else we divide two numbers and find quotient and remainder respectively.
    return find_gcd(num1 / num2, num1 % num2);
}

int main()
{
    int num1, num2;
//Takes input from the user as num1 and num2
    printf("Enter two numbers\n");
    scanf("%d %d", &num1, &num2);
//assigning large number first and smaller as second for ease of calculation
int max = num1 > num2 ? num1 : num2;
int min = num1 + num2 - max;
//passing both numbers to a function
   int answer = find_gcd(max, min);
//printing answer
    printf("Gcd of %d and %d is: %d\n", num1, num2, answer);
    return 0;
}

