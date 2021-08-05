/*
 * Program for selection sort using recursion.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 05 (Recursion) 
 *
 *03/08/2021
 *
 * Question number -> 01
 */
#include <stdio.h>

//recursive sort function.
void sort(int i, int j, int arr[], int size){
//for checking if the number of elements is greater than 1
//bcoz 1 element is already sorted.
    if(i < size - 1){
//if i and j are equal then start j from i + 1.
        if(i == j){
            j = i + 1;
        }
//for checking that we traversed the full array or not.
        if(j < size){
//if ith element is greater than swap ith element with jth element.
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
//increasing index j for checking next minimum index.
        sort(i, j + 1, arr, size);
        }
//now minimum elemet will be at ith index or we can say elements till i are now sorted
//now we inrease i by 1.
        sort(i + 1, j, arr, size);
    }
    return ;
}

//it will print the given array.
void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
//initialized array.
    int array[5] = {5, 2, 3, 4, 1};
    int i = 0;
//calling sort function to sort data.
    sort(i, i, array, 5);
//for printing data.
    print(array, 5);
    return 0;
}

