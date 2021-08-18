/*
 * Program to find the sign of the give number.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 02 (Bits And Bytes) 
 *
 *08/08/2021
 *
 * Question number -> 03
 */
#include <stdio.h>

int sign(int x){
    return (x >> 31) | (!!x);
}

int main()
{
    int x;
    printf("Enter the number:\n");
    scanf("%d", &x);
    printf("Sign of %d is: %d\n",x, sign(x));

    return 0;
}
