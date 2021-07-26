/*
 * Program to reverse the given string.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 1 (C_Foundation) 
 *
 *24/07/2021
 *
 * Question number -> 08
 */
#include <stdio.h>

void reverse(char* string){

    //counting size of the string.
    int size = 0;
    while(*(string+size) != '\0'){
        size++;
    }

    //front and back are two indices for reversing.
    int front = 0, back = size - 1;

    //function for reversing the given string.
    while(front <= back){
        char temp = *(string+front);
        *(string+front) = *(string+back);
        *(string+back) = temp;
        front++;
        back--;
    }
}
        

int main()
{
    int size;

    //input size of string.
    printf("Enter the size of the string\n");
    scanf("%d", &size);

    //input string.
    char input[size];
    printf("Enter your string\n");
    scanf(" %[^\n]s", input);

    //calling function for reverse
    reverse(input);

    //printing the reversed string.
    printf("%s\n", input);
    return 0;
}

