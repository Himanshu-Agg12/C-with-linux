/*Program to find mth smallest element from the given array.
 *
 *Assignment No -> (08) 
 *Assignment Name -> Algorithm_Assignment
 *
 *Question No -> (02)
 *
 *Date -> 19/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */
#include <stdio.h>
#include <stdlib.h>

//it will swap the array elements.
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}    

//this is the partition function for comapring each element against
//pivot and arrange it to its correc position by swapping
int partition(int arr[], int l, int h){

//selecting pivot element as last element of array.
    int pivot = arr[h];

//let we will start it from left
    int i=l;

//we compare each element of array against pivot, arrange al the smaller
//elemts then pivot to one side and greater to the other.
    for(int j=l;j <= h - 1;j++){
        if(pivot >= arr[j]){
            swap(arr, i, j);
            i++;
        }
    }

//now we arrange pivot to its right position, now the element left to
//the pivot are smaller then pivot while at the right all are greater then pivot.
    swap(arr, i, h);
 
    return i;
}


//it will return the mth smallest element in the given array
//works as the quick sort, we find the pivot-index(pi) 
//if it will be equal to the m then return 
//else again find on the either half of the array.
int quickSort(int arr[], int l, int h, int m){

//here we are checking that the index we have to find is in between the range
//of the array.    
    if(m > 0 && m <= h - l + 1){

//it holdes the index of pivot element.
        int pi = partition(arr, l, h);

//if the required index is equalt to pivot index(pi) we return the value at that index.
        if(pi - l == m - 1)
            return arr[pi];
       
//if the required index is less then pi then we will find in the left half
//else will find in the right half.
        if(m - 1 < pi - l)
            return quickSort(arr, l, pi-1, m);
//in right half now the required index(m) is not remain same as our left(l) will be change
//so m becomes -> m - pi + l - 1
        return quickSort(arr, pi+1, h, m - pi + l - 1);
    }

//if required index is invalid we return -1.
    return -1;
}

//print function
/*void print(int arr[], int n)
{
    for(int i = 0; i < n ; i++)
        printf("%d ",arr[i]);
    printf("\n");
}*/


int main()
{  
//scaning input....
    printf("Enter the size of the array:");
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the mth element you want to find:");
    int m;
    scanf("%d", &m);

   /* printf("Unsorted array:\n");
    print(arr, size);
*/

//calling function for mh smallest
    int ans = quickSort(arr, 0, size - 1, m);

  /*  printf("Sorted array\n");
    print(arr, size);
*/

//printing answer...
    if(ans == -1)
        printf("Invalid Choice!!");
    else
    printf("%dth smallest element in the given array is: %d\n",m, ans);

    return 0;
}

