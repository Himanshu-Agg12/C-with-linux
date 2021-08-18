/*
 * Program to check if the string contains balanced parantheses or not.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 04 (Stacks_and_Queues) 
 *
 *10/08/2021
 *
 * Question number -> 02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//testcase
//(1+((3-1)*(4/2)))

//declared a global stack
char stack[20];
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

//it will check the precedence of the operator
int precedence(char ops) {
    if(ops == '+' || ops == '-')
        return 1;
    if(ops == '*' || ops == '/')
        return 2;
    else
        return -1;
}

int main() {

    //it will scan a string with upto 10 characters.
    //to prevent long expression we only scanning 10 characters.
    char infix[20];
    char postfix[20];
    int j = 0;
    scanf("%[^\n]s", infix);

    //it will find the length of the string
    int len = strlen(infix);

//In this loop we will check the character by character and if we found any operand it
//will directly append to out put string else it will stored in the stack and when we 
//get closing bracket we pop the operators by checking the precednce till stack empty 
//or we encounter '('. 
    for(int i = 0; i < len ;i++) {
        if(infix[i] == '(')
            push(infix[i]);
       else if(infix[i] >= '0' && infix[i] <= '9')
           postfix[j++] = infix[i];
       else if(infix[i] == ')') {
           while(!is_empty() && tops() != '(') {
               postfix[j++] = tops();
               pop();
           }
           pop();
       }
       else if(infix[i] == ' ')
           continue;
       else{
           while(!is_empty() && precedence(infix[i]) <= precedence(tops())) {
               postfix[j++] = tops();
               pop();
           }
           push(infix[i]);
       }
    }
    //it will add all the remaing operators in the output string.
    while(!is_empty()){
        postfix[j++] = tops();
        pop();
    }
   //it will print the final resulti.
   for(int k = 0; k < j; k++)
       printf("%c ", postfix[k]);
   printf("\n");
   return 0;
}


