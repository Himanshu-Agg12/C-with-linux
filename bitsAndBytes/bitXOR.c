/*
 * Program to find XOR of two numbers without using XOR operator.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 03 (Bits and Bytes) 
 *
 *18/08/2021
 *
 * Question number -> 02
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bitXOR (int a, int b)
{
    return ( (~(~a & ~b)) & ~(~(~a) & ~(~b) ) );
}

int main()
{
    int x, y;
    printf("Enter two number:\n");
    scanf("%d %d", &x, &y);
    printf("%d ^ %d = %d\n",x, y, bitXOR(x, y));
    return 0;
}

