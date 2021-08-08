/*
 * Program to implement stack functions.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 04 (Stacks_and_Queues) 
 *
 *02/08/2021
 *
 * Question number -> 01
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size = 5;
int* stack;
int top = -1;

//time complexity is O(1)
bool is_empty()
{
    if (top == -1)
        return true;
    else
        return false;
}

//time complexity is O(1)
void resize_stack(){
    stack = (int*) realloc(stack, (size*2)*sizeof(int));
    size = (size * 2);
}

//time complexity is O(1)
void push(int value){
    if(top != size - 1){
        top = top + 1;
        *(stack + top) = value;
    }
    else{
        printf("\nResizing the stack to its double.{Overflow}\n");
        resize_stack();
    }
}

//time complexity is O(1)
void pop() {
    if (is_empty())
        printf("\nCan't delete as Stack is already empty.{Underflow}\n");
    else {
        int value = *(stack + top);
        top = top - 1;
        printf("%d is deleted\n", value);
    }
}

//time complexity is O(1)
int peek() {
    if (top != -1)
        return *(stack + top);
    else
        return -1;
}

//time complexity is O(1)
void print() {
    int i = top;
    while(i >= 0){
        printf("%d ", stack[i]);
        i--;
    }
    printf("\n");
}

int main()
{  
    stack = (int*) calloc(size, sizeof(int));
    int next = 1;

    while(next){
        printf("Press 1/2/3/4 for insert/delete/top/empty respectivaly...\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter a value to insert\n");
            int value;
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Most recently used element will be deleted\n");
            pop();
            break;
        case 3:
            printf("Top most element is: %d \n", peek());
            break;
        case 4:
            printf("Stack is %s \n", is_empty() ? "empty" : "not empty");
            break;
        default:
            printf("Invalid choice\n");
            break;
        } 
        printf("\nDo you want to continue: 1/0\n");
        scanf("%d", &next);
    }
    
    print();

    printf("Exit success\n");
    free(stack);

    return 0;
}

