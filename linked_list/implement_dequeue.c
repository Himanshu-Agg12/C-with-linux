/* Program to implement Dequeue using linked list.
 *
 *Assignment No -> (06) 
 *Assignment Name -> Linked List
 *
 *ID -> 1911981022
 *
 *Question No -> (03)
 *
 *Date -> 24/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */

#include <stdio.h>
#include <stdlib.h>

//defining structure of the linked list...
struct linkedlist{
    int value;
    struct linkedlist* next;
};

struct linkedlist *head = NULL;
struct linkedlist *tail = NULL;

//it adds the element at last place...
//Time Compexit: O(1)
void push_back(int val){
    struct linkedlist *new_node = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    new_node -> value = val;
    new_node -> next = NULL;

    if(tail == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        tail -> next = new_node;
        tail = new_node; 
    }
}

//it adds the element at first place...
//Time Compexit: O(1)
void push_front(int val){
    struct linkedlist *new_node =  (struct linkedlist *)malloc(sizeof(struct linkedlist));
    new_node -> value = val;
    new_node -> next = NULL;

    if(head == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        new_node -> next = head;
        head =  new_node;
    }
}

//it removes the last element...
//Time Compexity: O(n)....can be done in O(1) if we use doubly linked list.
void pop_back(){
    struct linkedlist *ptr;
    ptr = head;

    if(tail == NULL)
        printf("\nDequeue is empty!!\n\n");
    else if(head == tail){
        free(tail);
        tail = head = NULL;
    }


    else{
        while(ptr -> next != tail){
            ptr = ptr -> next;
        }
        struct linkedlist *temp =  (struct linkedlist *)malloc(sizeof(struct linkedlist));
        temp = tail;
        ptr -> next = NULL;
        tail = ptr;
        printf("\nDequeued element is %d\n", temp->value);
        free(temp);
    }
}

//it removes the frist element...
//Time Compexit: O(1)
void pop_front(){
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    if(head == NULL)
        printf("\nDequeue is already empty!\n\n");
    else{
        ptr = head;
        head = head -> next;
        ptr -> next = NULL;
        printf("\nDequeued element is: %d\n\n", ptr -> value);
        free(ptr);
    }
}

//it returns the first element...
//Time Compexit: O(1)
void peek_front(){
    if(head == NULL)
        printf("\nDequeue is empty!\n\n");
    else{
        printf("\nPeek front is: %d\n\n", head -> value);
    }
}

//it returns the last element...
//Time Compexit: O(1)
void peek_back(){
    if(tail == NULL)
        printf("\nDequeue is empty!\n\n");
    else{
        printf("\nPeek back is: %d\n\n", tail -> value);
    }
}

//It will find the element in the deque...
//Time Compexit: O(n)
void find_element(int val){
    if(head == NULL || tail == NULL)
        printf("\nDeque is Empty\n");
    else if(tail -> value == val || head -> value == val)
        printf("\n %d Found!!\n", val);
   else{
       struct linkedlist *iter = (struct linkedlist*) malloc(sizeof(struct linkedlist*));
       iter = head;
       while(iter != tail){
           if(iter -> value == val){
               printf("\n %d Found!!\n", val);
               break;
           }
           iter = iter -> next;
       }
       if(iter == tail)
           printf("\n %d NOT Found!!\n", val);
   }
}

//it will tell wether the deque is empty or not
//Time compexity: O(1)
void is_empty(){
    if(head == NULL)
         printf("\nDequeue is Empty!!\n\n");
    else
        printf("\nDequeue is Not Empty!!\n\n");
}

//it will print the deque...
void print(struct linkedlist *front){
    if(front == NULL)
         printf("\n\nEmpty Dequeue\n\n");
    if(front -> next == NULL)
         printf("\nvalue: %d \n", front -> value);
    else{
        while(front -> next != NULL){
            printf("\nvalue: %d \n", front -> value);
            front = front -> next;
        }
        printf("\nvalue: %d \n", front -> value);
        printf("\n");
    }
}


//here we ask the user choice and then call the function accordingly...

int main()
{
    int choice;

while(1){
    printf("\nEnter your choice\n 1.Push Back   2.Push Front   3.Pop Back   4.Pop Front   5.Peek Front   6.Peek Back   7.is_empty   8.Print   9.Find an Element   0.Exit\n\n");
    scanf("%d", &choice);
    if(choice == 1){
        int val;
        printf("\nEnter the value\n\n");
        scanf("%d", &val);
        push_back(val);
    }
    else if(choice == 2){
        int val;
        printf("\nEnter the value\n\n");
        scanf("%d", &val);
        push_front(val);
    }
    else if(choice == 3){
        pop_back();
    }
    else if(choice == 4){
        pop_front();
    }
    else if(choice ==5){
        peek_front();
    }
    else if(choice == 6){
        peek_back();
    }
    else if(choice == 7){
        is_empty();
    }
    else if(choice == 8){
        print(head);
    }
    else if(choice == 9){
        printf("\nEnter the value you want to find\n");
        int num;
        scanf("%d", &num);
        find_element(num);
    }
    else if(choice == 0){
        break;
    }
    else{
        printf("\n\nInvalid choice!!\n");
    }
}
printf("\nExit successfully\n");
    return 0;
}

