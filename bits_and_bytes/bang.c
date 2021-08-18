/*
 * Program to find bang without !.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 03 (Bits and Bytes) 
 *
 *18/08/2021
 *
 * Question number -> 07
 */
#include <stdio.h>

int invert(int x)
{
    int invx = ~x; //it will find the negation of the number
    int opp = invx + 1; // it will make the same value as x but with opposite sign.so that 0 will again turn to 0.
    return (( ~opp & invx) >> 31) & 1; //here we negate the opp then & with negation of x and will find msb then & with 1.
}

int main()
{
    int x;
    printf("Enter the number:\n");
    scanf("%d", &x);
    
    printf("!%d = %d\n",x, invert(x));
    return 0;
}

