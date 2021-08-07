/*
 * Program to implement circular queue.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 04 (Stacks_and_Queues) 
 *
 *07/08/2021
 *
 * Question number -> 02
 */
#include <stdio.h>
#define size 5

void enqueue(int[], int);
void dequeue(int[]);
void display(int[]);
int peek(int[]);
int is_empty();

int front =  - 1;
int rear =  - 1;

int main()
{
    int n, ch;
    int queue[size];
    do
    {
        printf("\n\n Circular Queue:\n1. Insert \n2. Delete\n3. Display\n4. Peek\n5. is_empty\n0. Exit");
        printf("\nEnter Choice 0-5? : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                enqueue(queue, n);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("%d\n", peek(queue));
                break;
            case 5:
                printf("%s\n", is_empty() ? "Queue is Empty!" : "Queue is not Empty");
                break;
        }
    }while (ch != 0);
}

int peek(int queue[])
{
    return queue[front];
}

int is_empty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int queue[], int item)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("queue is full");
        return;
    }
    else if (rear ==  - 1)
    {
        rear++;
        front++;
    }
    else if (rear == size - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
}

void display(int queue[])
{
    int i;
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < size; i++)
        {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

void dequeue(int queue[])
{
    if (front ==  - 1)
    {
        printf("Queue is empty ");
    }
    else if (front == rear)
    {
        printf("\n %d deleted", queue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else
    {
        printf("\n %d deleted", queue[front]);
        front++;
    }
}
