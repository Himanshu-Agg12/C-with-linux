/*
 * Program to observe execution time of sorting algorithms for different type of inputs.
 *
 * @Himanshu Aggarwal  ID -> 1911981022
 *
 * Assignment no. -> 1 (Day_2) 
 *
 *25/07/2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>

void initialize_random_array_input(int array[], int size) {
	for(int index = 0; index < size; index++) {
		array[index] = rand() % size + 1;
	}
}

void initialize_ascending_array_input(int array[], int size) {
	for(int index = 0; index < size; index++) {
		array[index] = index + 1;
	}
}

void initialize_descending_array_input(int array[], int size) {
	int value = size;
	for(int index = 0; index < size; index++) {
		array[index] = value--;
	}
}

void swap(int array[], int index1, int index2) {
	int temporary = array[index1];
	array[index1] = array[index2];
	array[index2] = temporary;
}

void bubble_sort(int array[], int size) {
	for (int index = 0; index < size - 1; index++) {
		for (int inner_index = 0; inner_index < size - index - 1; inner_index++) {
			if (array[inner_index] > array[inner_index + 1])
				swap(array, inner_index, inner_index + 1);
		}
	}
}
void observer(int starting_size, int increment_size){
	struct timeval t;
	printf("\n********************************************************\n");
	for(int index = 0; index < 8; index++) {
        int size = starting_size + increment_size * index;
        int array[size];
        initialize_random_array_input(array, size);
        gettimeofday(&t, NULL);
        long long start_time = t.tv_sec *1000LL + t.tv_usec / 1000;
		
/*		if(index==0)
		printf("\n Press 1/2/3 for bubble/selection/insertion sort respectively..\n");
		int choice;
		scanf("%d", &choice);
		switch(choice){
		case 1:
			printf("Bubble sort\n");
*/        	bubble_sort(array, size);
/*			break;
		default:
			printf("\nIncorrect choice\n");
		}
*/        gettimeofday(&t, NULL);
        long long end_time = t.tv_sec * 1000LL + t.tv_usec / 1000;
        printf("Execution time for random input of size %d : %lld\n", size, end_time - start_time);
    }
	printf("\n********************************************************\n");
	for(int index = 0; index < 8; index++) {
        int size = starting_size + increment_size * index;
        int array[size];
        initialize_ascending_array_input(array, size);
        gettimeofday(&t, NULL);
        long long start_time = t.tv_sec *1000LL + t.tv_usec / 1000;
        bubble_sort(array, size);
        gettimeofday(&t, NULL);
        long long end_time = t.tv_sec * 1000LL + t.tv_usec / 1000;
        printf("Execution time for ascending input of size %d : %lld\n", size, end_time - start_time);
    }
	printf("\n********************************************************\n");
	for(int index = 0; index < 8; index++) {
        int size = starting_size + increment_size * index;
        int array[size];
        initialize_descending_array_input(array, size);
        gettimeofday(&t, NULL);
        long long start_time = t.tv_sec *1000LL + t.tv_usec / 1000;
        bubble_sort(array, size);
        gettimeofday(&t, NULL);
        long long end_time = t.tv_sec * 1000LL + t.tv_usec / 1000;
        printf("Execution time for descending input of size %d : %lld\n", size, end_time - start_time);
   	}
	printf("\n********************************************************\n");
}

int main()
{
    int starting_input = 8000;
    int increment_size = 4000;
    printf("\nStart observing...\n");
    observer(starting_input, increment_size);
    
    printf("\n");
	  
   return 0;
}

