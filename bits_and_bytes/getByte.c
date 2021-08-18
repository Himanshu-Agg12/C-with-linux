/* Program to find the nth byte in a number..
 *
 *Assignment No -> (03) 
 *Assignment Name -> Bits And Bytes.
 *
 *Question No -> (04)
 *
 *Date -> 14/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */
#include <stdio.h>
#include <stdlib.h>

int getByte(int num, int n)
{
    //basically we are shifting 8*n(n<<3) times the original number towards right so the required 
    //byte become LSB and the we and with 255(0xFF) i.e (11111111) so we can extract the LSB.
    //num -> 00001100 00100010 00111000 01001110

    return num >> (n << 3) & 0xFF; // num >> (1*8) where 1 == n 
}

int main()
{
    int num = 0x12345678;
    int byte;
    printf("Enter the byte number you want to extract from 0x12345678\n");
    scanf("%d", &byte);
    if(byte > 3 || byte < 0)
        printf("Invalid byte!!\n");
    printf("0x%x\n", getByte(num, byte));
    return 0;
}

