/* Program to printf n even fibonacci numbers.
 *
 *Assignment No -> (08) 
 *Assignment Name -> Algorithms
 *
 *ID -> 1911981022
 *
 *Question No -> (01)
 *
 *Date -> 19/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */
#include <stdio.h>
#include <stdlib.h>

//we observed that all the even numbers are occuring at the positions which are
//multiples of three, so new fibonacci formula becomes -> Fibo(n) = 4 * Fibo(n - 3) + Fibo(n - 6).
void fibo(int n, int t1, int t2, int sum)
{
    if(n <= 2)
        return;
    
    printf("%d ", sum);
    t1 = t2;
    t2 = sum;
    fibo(n - 1, t1, t2, 4 * t2 + t1);
}

int main()
{
    printf("Enter how many even fibonacci you want?\n");
    int n;
    scanf("%d", &n);
    int t1 = 2, t2 = 8, sum = t1 + 4 * t2;
    if(n >= 1)
        printf("2 ");
    if(n >= 2)
        printf("8 ");
    fibo(n, t1, t2, sum);
   /*     printf("%d, %d, ",t1, t2);
    for(int i = 2; i < n; i++){
        sum = 4 * t2 + t1;
        t1 = t2;
        t2 = sum;
        printf("%d, ", sum);
    }
    */
    
    return 0;
}

