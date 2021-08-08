/*
 * Program to calculate the expr function also known as reverse polish expression.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 01 (c_foundation)
 *
 *07/08/2021
 *
 * Question number -> 15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declared a global stack
int stack[8];
int top = -1;

//pop function for deletion of the element
int pop() {
   int data;
      data = stack[top];
      top = top - 1;
      return data;
}

//push function for insertion in the stack
void push(int data) {
      top = top + 1;
      stack[top] = data;
}

int main() {
    
    //it will scan a string with upto 10 characters.
    //to prevent long expression 
    char exp[10];
    
    scanf("%[^\n]s", exp);
    
    //it will find the length of the string
       int len = strlen(exp);
       
       //it will traverse through the string and if we found a number than we push it in 
       //stack else if we found any operator we will pop two elements and operate with that operator 
       //and then push the results again in the stack.
       for(int i = 0; i < len; i++){

           if(*(exp + i) >= '0' && *(exp + i) <= '9') {
               push( *(exp + i) - '0');
           }       
           if(*(exp + i) == '+') {
               push( pop() + pop() );
           }
           else if(*(exp + i) == '-') {
               push( pop() - pop() );
           }
           else if(*(exp + i) == '*') {
               push( pop() * pop() );
           }
           else if(*(exp + i) == '/') {
               push( pop() / pop() );
           }
           else
               continue;
       }
       
   //it will print the final result.
   printf("%d\n", pop());
   return 0;
}

