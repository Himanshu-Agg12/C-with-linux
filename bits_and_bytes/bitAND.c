/*
 * Program to find bitwise AND without using &.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 03 (Bits and Bytes)
 *
 *08/08/2021
 *
 * Question number -> 01
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*int max(int a, int b){
    if(a >= b)
    return a;
    else 
    return b;
}

int NOT(int a){
    int size = max(floor(log2(a)) + 1, 4);
    int temp = ((1 << size) - 1);
    return a ^ temp;
}

int bitAND(int a, int b)
{
    return NOT(NOT(a) | NOT(b));
}
*/
int bitAND(int a, int b)
{
    return ~((~a) | (~b));
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", bitAND(x, y));
    return 0;
}
