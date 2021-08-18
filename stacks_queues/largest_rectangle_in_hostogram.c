/* Program to largest area in histogram.
 *
 *Assignment No -> (04) 
 *Assignment Name -> stacks and queues.
 *
 *Question No -> (04)
 *
 *Date -> 18/08/2021
 *
 *ID -> 1911981022
 *
 *author@Himanshu Aggarwal
 *
 */


/****************************PSEUDO CODE FOR LEETCODE************************/

#define max(a, b) a>b?a:b/
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the last item from stack
int back(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

int largestRectangleArea(int* heights, int heightsSize) {
    //heights bar
    heightsSize += 1;
    //realloc(heights, sizeof(int)*heightsSize);
    //heights[heightsSize-1] = 0;
    int* tempArray = (int*)malloc(sizeof(int)*heightsSize);
    for(int j=0; j<heightsSize-1; j++)
        tempArray[j] = heights[j];
    tempArray[heightsSize-1] = 0;
    struct Stack* stack = createStack(heightsSize);
    int sum = 0;
    int i = 0;
    while(i < heightsSize) {
        if(isEmpty(stack) || tempArray[i] > tempArray[back(stack)]) {
            push(stack, i);
            i++;
        } else {
            int t = back(stack);
            //printf("%d\n", t);
            pop(stack);
            // stack
            int temp = tempArray[t]*(isEmpty(stack)?i:i-back(stack)-1);
            sum = max(sum, temp);
        }
    }
    free(tempArray);
    return sum;
}

/**************************END************************/

