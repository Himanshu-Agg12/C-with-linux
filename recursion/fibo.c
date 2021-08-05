/*
 * Program to print the fibonacci number at the places which is divisible by 3.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 05 (Recursion) 
 *
 *01/08/2021
 *
 * Question number -> 04
 */
#include <stdio.h>

//function for finding fibonnaci number.
int fibo(int n)
{
    //if the number is 0 or 1 it will return 0 or 1 respectively,
    //as because 0th fibonacci is "0"and 1st is "1".
    //It acts as the base case for the recursion for exiting the function.
    if(n == 0 || n == 1)
        return n;
    
    //it will call the function with n-1 and n-2 as because 
    //fibonacci of n = fibonnaci of n-1 + fibonnacci of n-2.
    return (fibo(n-1) + fibo(n-2));
}

int main()
{
    //Enter the number of fibbonacci you want to find at every 3rd ocurrence.
    printf("Enter the number of elements to find\n");
    int num;
    scanf("%d", &num);
    
    //initializing the position as from 1 if equal to num it
    // will stop finding fibonacci numbers
    int position = 1;
    //count will maintain the 3rd occurrence.
    //start will give the starting fibonacci number(1st number is 1) and increment itself.
    int start = 1, count = 0;
    // loop for finding the values upto num(range).
    for(position; position <= num;)
    {
    //answer will store the fibonacci number at n,
    int answer = fibo(start);
    count++;
    //if the count is divisible by 3 and it is last number than simply print the answer
    //else if count is divisible by 3 but not last then append , with the answer 
    //else ignore and continue.
    if(count % 3 == 0 && position == num){
        printf("%d\n", answer);
        position++;
    }
    else if(count % 3 == 0) {
        printf("%d, ", answer);
        position++;
    }
    //incrementing the demanding fibonacci.
    start++;

    }

    return 0;
}

