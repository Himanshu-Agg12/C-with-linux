/*
 * Program to convert hexadecimal to integer(htoi implementation).
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 1 (c_foundation) 
 *
 *27/07/2021
 *
 * Question number -> 9
 */
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter the hexadecimal value:\n");
    //scan for the hexadecimal input.
    scanf("%[^\n]s", input);
    
    int index = 0;
    
    //ignoring '0x' or '0X' because it is used only for representation of hexadecimal number.
    if (input[index]=='0')
        index++;
    if (input[index]=='x' || input[index] == 'X')
        index++;
        
    //it stroes the final calculated decimal value.
    int answer = 0;
    
    //scans the whole input string.
    for (;index<strlen(input); index++) {
        
        //if digits in between 0 to 9 then convert in decimal by multiply 16 
        //and subtracting '0' for converting string to int.
        if (input[index] >= '0' && input[index] <= '9') {
            answer = answer*16 + input[index] - '0';
        }
        
        //if digits in between A to F then convert in decimal by multiply 16 
        //and subtracting 'A' for converting string to int.
        if (input[index] >= 'A' && input[index] <= 'F') {
            answer = answer * 16 + input[index] - 'A' + 10;
        }
        
        //if digits in between a to f then convert in decimal by multiply 16 
        //and subtracting 'a' for converting string to int.
        if (input[index] >= 'a' && input[index] <= 'f') {
            answer = answer * 16 + input[index] - 'a' + 10;
        }
    }

    //prints the decimal value.
    printf("Decimal value: %d\n", answer);

    return 0;
}


