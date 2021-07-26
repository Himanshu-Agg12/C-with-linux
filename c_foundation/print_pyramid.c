/*
 * Program to print the pyramid pattern.
 *
 * @Himanshu Aggarwal 1911981022
 * 23/07/2021
 * Assignment -> 1(C Foundations)
 * Question number ->2
 */
#include <stdio.h>

int main()
{
    int steps;
    printf("Enter Number of steps: \n");
    scanf("%d",&steps);

    for(int row=1;row<=steps;row++){

        for(int space=steps-row;space>0;space--){
            printf(" ");
        }

        for(int column=1;column<=row;column++){
            if(column==row)
                printf("#");
            else
            printf("# ");
        }

        printf("\n");
    }
    return 0;
}
