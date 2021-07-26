/*
 * Program to find if string2 occurs in the end of string1 or not.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 1 (c_foundation) 
 *
 *24/07/2021
 *
 * Question number -> 13
 */
#include <stdio.h>
#include <string.h>

int strend(char* string1, char* string2){
    
    //finding length of both strings.
    int string1_length = strlen(string1);
    int string2_length = strlen(string2);
    
    //if length of string1 is lesser than length of string2 than simply return 0.
    if(string1_length < string2_length)
        return 0;
    //index1 is the index to traverse string1 and index2 is for traversing string2.
    //count_of_occured_chars is for counting how many words occured in string1.
    int index1 = string1_length-1,index2 = string2_length-1;
    while(index2 >= 0){
        
        //for checking if chars are equal, if not equal than return 0.
        if(*(string1 + index1) != *(string2 + index2)){
            return 0;
        }else{
            index1--;
            index2--;
        }
    }
    //if all character of string2 occured in end of string1 returning 1.
    return 1;
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
    
    //calling function for finding rightmost occurence of string2 in string1.
    int answer_index = strend(string1, string2);
    
    //printing 1 if string2 occured in the end of string1 else 0.
    printf("Answer:\n");
    printf("%d\n", answer_index);
    

    return 0;
}
