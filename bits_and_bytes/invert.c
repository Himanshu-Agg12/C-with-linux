/* Program to invert n bits from p position of x and then return x.
 *
 *Assignment No -> (03) 
 *Assignment Name -> Bits and Bytes
 *
 *Question No -> (08)
 *
 *Date -> 18/08/2021
 *
 *author@Himanshu Aggarwal
 *
 *source: geeks for geeks and stackoverflow.
 */
#include <stdio.h>
#include <stdlib.h>

int invert(int num, int pos, int no_of_bits)
{
    return num ^ (~(~0 << no_of_bits) << pos); 
}

int main()
{
    printf("Enter number, position, and number of bits respectively\n");
    int num, pos, bits;
    scanf("%d %d %d", &num, &pos, &bits);
    printf("Invert of %d with number of bits %d from position %d is = %d\n", num, bits, pos, invert(num,pos, bits));
    return 0;
}

