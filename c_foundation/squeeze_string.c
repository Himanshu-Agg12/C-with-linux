/*
 * Program that deletes each character in string1 that matches any character in the string2.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 * Assignment no. -> 1 (c_foundation) 
 *
 *24/07/2021
 *
 * Question number -> 10
 */
#include <stdio.h>
#include <string.h>

void squeeze(char* string1, char* string2){
	
    //finding length of both strings.
    int string1_length = strlen(string1);
    int string2_length = strlen(string2);

    //index1 is the index to traverse string1 and index2 in for traversing string2
    //and new_index for storing the index of not occured chars.
    int index1 = 0, index2 = 0;
    int new_index=0;
    
    //checking if the index is less than the size or not(To prevent overflow).
    while (index1 < string1_length){
        
        //checking each char of string2 in string1.
        for (index2 = 0; index2 < string2_length; ){
            
            //if not equal then increase the index2
            if (*(string1+index1) != *(string2+index2)){
                index2++;
            }
            //if equal before the null character then break the loop.
            else {
                break;
            }
        }
        
        //if the index2 is equal to the length of string2 then store next char
        //and if equal found then skip that word as we are not increasing k.
        if (index2 == string2_length){
            *(string1 + new_index) = *(string1 + index1);
            new_index++;
        }
        index1++;
    }
    //storing null character to hide overflow of the string.
    *(string1 + new_index) = '\0';
}

int main()
{
    //scanning first string.
    printf("Enter string 1:\n");
    char string1[100];
    scanf("%[^\n]s", string1);

    //scaning second string.
    printf("Enter string 2.\n");
    char string2[20];
    scanf(" %[^\n]s", string2);

    //calling function for squeezing string1 according to given string2.
    squeeze(string1, string2);

    //printing squeezed string1.
    printf("string1 after squeezing:\n");
    printf("%s\n", string1);


    return 0;
}
