/*
 * Program to count the number of vowels and consonants in the given string.
 *
 * @Himanshu Aggarwal ID-> 1911981022
 * 23/07/2021
 *
 * Assignment->1(C Foundations)
 * Question->3
 */
#include <stdio.h>

int main()
{
    printf("Enter the input string\n");
    char input[200];
    scanf("%[^\n]s", input);

    int no_of_vowels = 0, no_of_consonants = 0;
    int index=0;
    while( input[index] != '\0' ) {
	/*Checking for vowels in lowe_case*/
        if( input[index] == 'a' || input[index] == 'e' || input[index] == 'i' || input[index] == 'o' || input[index] == 'u' )  
		no_of_vowels++;
	/*Checking for vowels in upper_case*/
	else if(input[index] == 'A' || input[index] == 'E' || input[index] == 'I' || input[index] == 'O' || input[index] == 'U' )
		no_of_vowels++;
	/*remaining are the consonants left*/
	else if( input[index] != ' ' )
		no_of_consonants++;

	index++;
    }

    printf("Number of vowels: %d \n", no_of_vowels);
    printf("Number of consonants: %d \n", no_of_consonants);

    return 0;
}
