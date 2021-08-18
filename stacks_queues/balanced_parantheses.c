/*
 * Program to check if the string contains balanced parantheses or not.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 04 (Stacks_and_Queues) 
 *
 *10/08/2021
 *
 * Question number -> 01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//declared a global stack
char stack[8];
int top = -1;

//pop function for deletion of the element
char pop() {
   char data;
      data = stack[top];
      top = top - 1;
      return data;
}

//tops function for retriviving top element of stack.
char tops() {
    return stack[top];
}

//push function for insertion in the stack
void push(char data) {
      top = top + 1;
      stack[top] = data;
}

//for checking if the stack is empty or not.
bool is_empty() {
    if (top < 0)
        return true;
    else
        return false;
}

int main() {

    //it will scan a string with upto 10 characters.
    //to prevent long expression we only scanning 10 characters.
    char exp[10];

    scanf("%[^\n]s", exp);

    //it will find the length of the string
       int len = strlen(exp);

       //it will traverse through the string and if we found a opening bracket than we push it in
       //stack else if we found any closing bracket we will check if the top is same bracket but type of closing
       //then we pop from stack and then at last if stack is empty we return true else false
       for(int i = 0; i < len; i++){

           if(*(exp + i) == '(' || *(exp + i) == '{' || *(exp + i) == '[') {
               push(*(exp + i));
           }
           else{
           char tope = tops();
               if(*(exp + i) == ')' && tope  == '(') {
                   pop();
               }
               if(*(exp + i) == ']' && tope  == '[') {
                   pop();
               }
               if(*(exp + i) == '}' && tope  == '{') {
                   pop();
               }
          }
       }

   //it will print the final result.
   printf("%s\n", is_empty() ? "true" : "false");
   return 0;
}


