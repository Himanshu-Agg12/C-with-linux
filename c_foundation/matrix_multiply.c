/*
 * Program to multiply two matrix of given size.
 *
 * @Himanshu Aggarwal ID -> 1911981022
 * Assignment -> 1(C Foundation) 
 * Question -> 5
 */
#include <stdio.h>

int main()
{
    int size;
    printf("Enter size of the matrices: \n");

    scanf("%d", &size);

    int matrix1[size][size], matrix2[size][size];
    printf("Enter first matrix element\n");

    //(row = no of rows, and col = no of columns of the matrix)
    //scaning matrix1

    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
	    scanf("%d", &matrix1[row][col]);
	}
    }
    printf("Enter second matrix element\n");

    //scanning matrix2.

    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
	    scanf("%d", &matrix2[row][col]);
	}
    }
    int answer[size][size];
    //two loops for rows and columns
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
	    answer[row][col] = 0;
	    
	    //This loop is for multiplyig rows of one matrix to the columns of the other matrix.

	    for(int col2 = 0; col2 < size; col2++){
		    answer[row][col] += matrix1[row][col2] * matrix2[col2][row];
	    }
	}
    }
    printf("Matrix after multiplication\n");

    //Printing the multiplied matrix.

    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
	    printf("%d ", answer[row][col]);
	}
	printf("\n");
    }

    return 0;
}
