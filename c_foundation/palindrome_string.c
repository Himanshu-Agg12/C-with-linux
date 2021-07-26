/*
 * Program to find if the given string is palindrome or not, considering only alphanumeric values, ignoring the case of characters.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 1 (C_Foundation) 
 *
 *24/07/2021
 *
 * Question number -> 6
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool is_palindrome(char string[]){
    int size = 0;
//counting size of string.
    while(string[size] != '\0'){
        size++;
    }
//if size is 0 or 1 and the character is alphanumeric then return true.
if(size <= 1 && isalnum(string[0]))
    return true;

//variable to store lowercase string and new index for that.
char lower_string[size];
int index = 0, new_index = 0;

//checking all character for alphanumeric values only and also changing uppercase to lowercase.
while(index < size){
    if(isalnum(string[index]))
        lower_string[new_index++] = tolower(string[index]);
    index++;
}

int start = 0, end = new_index-1;

//checking for front and end of the string and if any one character is not equal than return false else it will be true after finishing the loop.
while(start<=end){
    if(lower_string[start] != lower_string[end])
        return false;
    else{
        start++;
        end--;
    }
}
return true;
}    

int main()
{
    int string_size;
    printf("Enter string size\n");
    scanf("%d", &string_size);

    char string[string_size];

    printf("Enter your string\n");
    scanf(" %[^\n]s", string);

//calling funtion for checking palindrome or not
    if(is_palindrome(string))
        printf("True\n");
    else
        printf("False\n");
        
    return 0;
}

