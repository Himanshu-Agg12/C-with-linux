/*
 * Program to reverse a 1D array passing by refrence.
 *
 * @Himanshu Aggarwal ID -> 1911981022
 *  
 *  23/07/2021
 *  Assignment -> 1(C Foundations) 
 *  Question -> 4
 */
#include <stdio.h>

//function for reversal.
void reverse(int* array, int size){
    int back = size;
	
    //swapping first and last elements till reaches middle.
    for(int front=0; front<size/2; front++){
        int temporary = *(array+front);
	*(array+front) = *(array+back-1);
	*(array+back-1) = temporary;
	back--;
    }
}

int main()
{
    
    //declaring array
    int array[5] = {1, 2, 3, 4, 5};

    printf("Array before reverse:\n");

    for(int index = 0; index<5; index++){
	printf("%d ", array[index]);
    }
	
    //passing by refrence.
    reverse(array, 5);

    printf("\nArray after reverse:\n");

    for(int index = 0; index < 5; index++){
        printf("%d ", array[index]);
    }

    printf("\n");
    return 0;
}
