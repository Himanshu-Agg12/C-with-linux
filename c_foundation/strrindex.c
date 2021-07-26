/*
 * Program to find rightmost occurence of string2 in string1.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 1 (c_foundation) 
 *
 *24/07/2021
 *
 * Question number -> 12
 */
#include <stdio.h>
#include <string.h>

int strrindex(char* string1, char* string2){
    
    //finding length of both strings.
    int string1_length = strlen(string1);
    int string2_length = strlen(string2);
    
    //if size of string1 is less than size of string1 than string2 cannot occur in string1.
    if(string1_length <string2_length)
        return -1;
    //index1 is the index to traverse string1 and index2 is for traversing string2.
    //count_of_occured_chars is for counting how many words occured in string1.
    int index1 = string1_length-1,index2 = string2_length-1, count_of_occured_chars = 0;
    while(index1 >= 0){
        
        //for checking if chars are equal, if equal than increment count and compare for the size of string2.
        if(*(string1 + index1) == *(string2 + index2)){
            count_of_occured_chars++;
            
            //if count equals string2 size it means all string2 occurs in string1.
            if(count_of_occured_chars == string2_length)
                return index1;
                
            //decreenting indices for traversing.
            index1--;
            index2--;
        }else{
            
            //if atleast one character is equal and other not than to remain 
            //on the same position we have incremented one in index1.
            if(count_of_occured_chars != 0)
                index1++;
                
            //also if not equal than again count_of_occured_chars = 0 
            //and again start comparing string2 from ending.
            index1--;
            index2 = string2_length-1;
            count_of_occured_chars = 0;
        }
    }
    //if not occured returning -1.
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
    
    //calling function for finding rightmost occurence of string2 in string1.
    int answer_index = strrindex(string1, string2);
    
    //printing index if string2 occured in string1 else -1.
    printf("Answer:\n");
    printf("%d\n", answer_index);
    

    return 0;
}

