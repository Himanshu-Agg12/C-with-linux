/*
 * Program to do stringCopy, stringCatenation, stringComparison with n characters.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 1 (c_foundation) 
 *
 *24/07/2021
 *
 * Question number -> 14
 */
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//function for copying two strings.
void strnncpy(char* source, char* destination,char* answer, int number){
    int length = strlen(source), index=0;

    //copying string source in answer.
    while(length-- > 0){
        *(answer + index) = *(source + index);
        index++;
    }

    //storing null character at the end to avoid overfow.
    *(answer + index) = '\0';
     int second_index=0;
  
    //copying number of character in answer of destination string.
    while(number-- > 0){
        *(answer+second_index) = *(destination+second_index);
        second_index++;
    }
}

//function for concatenating the two string with nnumber of characters.
void strnncat(char* source, char* destination, char* answer, int number){
    int length = strlen(source), index = 0;
    
    //copying source in answer.
    while(length-- > 0){
        *(answer + index) = *(source + index);
        index++;
    }
    int new_index = 0 ;
    
    //copying destination in answer.
    while(number-- > 0){
        *(answer + index) = *(destination + new_index);
        index++;
        new_index++;
    }

    //storing null character at the end to avoid overflow.
    *(answer + index) = '\0';
}

//function for comparing two strings
int strnncmp(char* source, char* destination, int number){
    int index = 0;
    while(number--){
        //if not equal than returning difference that will find if source is less than destination or not.
        if(*(source + index) != *(destination + index))
            return *source - *destination;
        index++;
    }
    //returning 0 if all are equals.
    return 0;
}

int main(){

    //Enter the string1 as source.
    printf("Enter the source string\n");
    char source[100];
    scanf("%[^\n]s", source);
    
    //Enter the string2 as destination.
    printf("Enter the destination string\n");
    char destination[100];
    scanf(" %[^\n]s", destination);
    
    //Enter number of character on which we have to operate.
    printf("Enter number of character you want to copy/concatnate/compare: ");
    int number;
    scanf("%d", &number);
    
    //Answer1 is the final answer after copying.
    char* answer1;
    answer1 = (char*)malloc((strlen(source)+1) * sizeof(char*));
    strnncpy(source, destination, answer1, number);
    printf("String after copy: %s\n", answer1);
    
    //answer2 is the final answer after concatenating.
    char* answer2;
    answer2 = (char*)malloc((strlen(source)+number+1) * sizeof(char*));
    strnncat(source, destination, answer2, number);
    printf("String after catenation: %s\n", answer2);
    

    //answer3 is the answer after comparing the two strings.
    int answer3 = strnncmp(source, destination, number);
    
    //if string1 is less than string2 print -1.
    if(answer3 < 0)
    printf("After comapring source string is smaller than destination: -1\n");

    //if string1 is larger than string2 print 1.
    else if(answer3 > 0)
    printf("After comapring source string is larger than destination: 1\n");

    //if both strings are equal print 0.
    else
    printf("After comapring source string is equal to destination: %d\n", answer3);
    
    return 0;
}
