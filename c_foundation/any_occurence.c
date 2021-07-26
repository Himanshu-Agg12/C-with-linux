/*
 * Program to find any occurence of string2 in string1 and returning their index else -1.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 1 (c_foundation) 
 *
 *24/07/2021
 *
 * Question number -> 11
 */
#include <stdio.h>
#include <string.h>

int any(char* string1, char* string2){
    
    //finding length of both strings.
    int string1_length = strlen(string1);
    int string2_length = strlen(string2);
    
    //index1 is the index to traverse string1 and index2 in for traversing string2.
    int index1 = 0;
    
    //checking if the index1 is less than the size or not(To prevent overflow).
    while(index1 < string1_length){
        
        //initializing variable for traversing string2.
        int index2=0;
        
        //checking all elements of string2 in string1.
        while(index2 < string2_length){
            if(*(string1+index1) == *(string2+index2))
                return index1;
            else
                index2++;
        }
        //incrementing index1 for traversing next element.
        index1++;
    }
    
    //returning -1 if there is no occurence of string2 in string1.
    return -1;
}

int main()
{
    //scanning first string.
    printf("Enter string 1:\n");
    char string1[100];
    scanf("%[^\n]s", string1);
    
    //scaning seccond string.
    printf("Enter string 2.\n");
    char string2[20];
    scanf(" %[^\n]s", string2);
    
    //calling function for finding occurence of any character of string2 in string1.
    int answer_index = any(string1, string2);
    
    //printing answer index if found else -1.
    printf("Answer:\n");
    printf("%d\n", answer_index);
    

    return 0;
}
