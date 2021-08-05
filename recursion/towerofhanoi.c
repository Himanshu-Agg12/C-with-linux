/*
 * Program to transfer all discs from tower A(source) to C(destination) using tower B(helper).
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 05 (Recursion) 
 *
 *05/ 08/ 2021
 *
 * Question number -> 03
 */
#include <stdio.h>
#include <math.h>

//recursive function for finding steps.
void tower_of_hanoi(int discs, char source, char helper, char destination)
{
//if number of discs is greater than 0.
    if(discs > 0)
    {
        //moving all discs except the largest(n-1) from source tower(A) to 
        //helper/auxilary tower(B) using destination tower(C). 
        //in this source acts as source destination act as helper and helper act as destination.
        tower_of_hanoi(discs - 1, source, destination, helper);

        //moving the last disc(largest) from source tower(A) to destination tower(C).
        //in this source act as source and destination act as destination(we dont need helper tower for moving one disc).
        printf("%c to %c\n", source, destination);

        //now the moved discs in tower B aacts as source and we have to 
        //transfer them to odestination tower that is tower C woth help of emoty tower A.
        //in this helper acts as source destination act as destination and source act as helper.
        tower_of_hanoi(discs - 1, helper, source, destination);
    }
    return;
}

int main()
{
//taking input from users how many discs need to transfer from tower 'A' to tower 'C'.
    printf("Enter number of discs\n");
    int discs;
    scanf("%d", &discs);

//calling the function tower_of_hanoi for printing the steps required in transferring.
    printf("Steps to move discs from tower A to C\n"); 
    tower_of_hanoi(discs, 'A', 'B', 'C');

//calculating and printing total number of steps in transferring discs from tower 'A' to tower 'C'.
    printf("\nTotal movments required = %d\n\n",(int)pow(2, discs) - 1 );
    
    return 0;
}

