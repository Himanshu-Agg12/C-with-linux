#include <stdio.h>

int compare(int arr[], int s, int m, int e)
{
    int left_size = m - s + 1;
    int right_size = e - m;
    int left_arr[left_size];
    int right_arr[right_size];
    for(int i = 0; i < left_size; i++){
        left_arr[i] = arr[i + s];
    }
    for(int i = 0; i < right_size; i++){
        right_arr[i] = arr[m + 1 + i];
    }
    int l_ind = 0, r_ind = 0, ind = s;
    int count = 0;
    while(l_ind < left_size && r_ind < right_size)
    {
        if(left_arr[l_ind] <= right_arr[r_ind]){
            arr[ind++] = left_arr[l_ind++];
        }
        else{
             arr[ind++] = right_arr[r_ind++];
             count += (left_size - l_ind);
        }
    }

    while(l_ind < left_size){
         arr[ind++] = left_arr[l_ind++];
    }

    while(r_ind < right_size){
         arr[ind++] = right_arr[r_ind++];
    }

    return count;
}

int count_inversion(int arr[], int start, int end)
{   int count = 0;
    if(start >= end)
        return count;

    int mid = (start + end) / 2;

    count += count_inversion(arr, start, mid);
    count += count_inversion(arr, mid + 1, end);
    count += compare(arr, start, mid, end);
}

int main()
{
    printf("Enter the array size\n");
    int size;
    scanf("%d", &size);
    printf("Enter array elements: \n");
    int array[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    int ans = count_inversion(array, 0, size);
    printf("%d\n", ans);
    return 0;
}
