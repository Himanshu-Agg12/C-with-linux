/*
 * Program to take input from a file and print the lines longer than 80 lines.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 01 (c_foundation)
 *
 *07/08/2021
 *
 * Question number -> 07
 */
#include <stdio.h>

int main()
{
    //it will take input of a single character.
    char ch;
    //it will store all the characters in a single line below length 1000
    //length more than 1000 leads to buffer overflow.
    char line[1000] = "";
    //it will used to count the length of a single line.
    int length = 0;

//scan character till'end of file reaches.'
    while( (ch = getchar()) != EOF ) {
//store the character in the line array
        line[length++] = ch;

//if the length is more than 1000 it leads to buffer overflow.
        if(length >=1000)
            break;

//if we encounter a next line character(line-break) than we check for the length of that line
//if the length is more than 80 than we print the line else ignore that buffer.
//also we will do length = 0 when we ncounter \n as from now we calculate new line length.
        if(ch == '\n') {
           if( length >= 80 ) {
               printf("Line longer than 80\n");
               printf("%s", line);
           }
        length = 0;
        }
    }
    return 0;
}

