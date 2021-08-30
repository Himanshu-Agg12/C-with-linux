/* Program to implement stack using linked list.
 *
 *Assignment No -> (06) 
 *Assignment Name -> Linked List
 *
 *ID -> 1911981022
 *
 *Question No -> (01)
 *
 *Date -> 24/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */
#include <stdio.h>
#include <stdlib.h>

struct linkedlist{
    int value;
    struct linkedlist* next;
};

struct linkedlist *head = NULL;
//struct linkedlist *temp = (struct linkedlist *)malloc(sizeof(struct linkedlist *));  

void push(int val){
    struct linkedlist *new_node, *iter;

    new_node = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    new_node -> value = val;
    new_node -> next = NULL;

    if(head == NULL){
         head = new_node;
    }
    else{
        iter = head;
        while(iter -> next != NULL){
            iter = iter -> next;      
        }
        iter -> next = new_node;
    }
}

void pop(){
    struct linkedlist *traverse, *ptr;
    traverse = head;
    if(head == NULL)
        printf("Stack is already empty!\n\n");
    else if(head -> next == NULL){
        ptr = head;
        head = NULL;
        printf("Popped element is: %d\n\n", ptr -> value);
        free(ptr);
    }
    else{
        while(traverse -> next != NULL){
            ptr = traverse;
            traverse = traverse -> next;
        }
        ptr -> next = NULL;
        printf("Popped element is: %d\n\n", traverse -> value);
        free(traverse);
    }
}

void peek(){
    struct linkedlist *traverse = head;
    if(head == NULL)
        printf("Stack is empty!\n\n");
    else if(head -> next == NULL){
        printf("Peeked value is: %d\n\n", head -> value);
    }
    else{
        while(traverse -> next != NULL){
            traverse = traverse -> next;
        }
        printf("Peeked value: %d\n\n", traverse -> value );
    }
}

void is_empty(){
    if(head == NULL)
         printf("Stack is Empty!!\n\n");
    else
        printf("Stack is Not Empty!!\n\n");
}

void print(struct linkedlist *front){
    if(front == NULL)
         printf("Empty Stack\n\n");
    if(front -> next == NULL)
         printf("value: %d \n", front -> value);
    else{
//        struct linkedlist *front = head;
       // while(front -> next != NULL){
            print(front -> next);
            printf("value: %d \n", front -> value);
           //  front = front -> next;
       // }
//        printf("value: %d \n", front -> value);
 //       printf("\n");
    }
}



int main()
{
    int choice;

while(1){
    printf("Enter your choice\n 1.Push\t 2.Pop\t 3.Peek\t 4.is_empty\t 5.Print\t 0.Exit\n");
    scanf("%d", &choice);
    if(choice == 1){
        int val;
        printf("Enter the value\n");
        scanf("%d", &val);
        push(val);
    }
    else if(choice == 2){
        pop();
    }
    else if(choice == 3){
        peek();
    }
    else if(choice == 4){
        is_empty();
    }
    else if(choice == 5){
        print(head);
    }
    else if(choice == 0)
        break;
    else{
        printf("Invalid choice!!\n");
    }
}
printf("Exit successfully\n");
    return 0;
}

