/* Program to implement a min stack
 *
 *Assignment No -> (04) 
 *Assignment Name -> stacks and queues.
 *
 *Question No -> (05)
 *
 *Date -> 17/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */

//CODE LINK : https://leetcode.com/problems/min-stack/

/***************************PSEUDO CODE FROM LEETCODE*****************************/

typedef struct {
    int *st;
    int top;
    int *min;
    int mt;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *s = (MinStack*) malloc(sizeof(MinStack));
    s -> top = -1;
    s -> mt = -1;
    s -> st = (int*) malloc(sizeof(int) * 100000);
    s -> min = (int*) malloc(sizeof(int) * 100000);
    return s;
}

//pushing the new value in stack and comparing from the previous minimum if 
//found less or minstack is empty then push it in min stack also else do nothing.
void minStackPush(MinStack* obj, int val) {
    obj -> top += 1;
    obj -> st[obj -> top] = val;
    
    if(obj -> mt == -1 || obj -> min[obj -> mt] >= val){
        obj -> mt += 1;
        obj -> min[obj -> mt] = val;
    }
}

//popping the top value from stack and also comparing from minstack
//if the popping value is the minimum value then we should also pop it from 
//min stack as it will be no longer minimum in our stack.
void minStackPop(MinStack* obj) {
    if(obj->top==-1)
        return ;
  if (obj -> min[obj -> mt] == obj -> st[obj -> top])
      obj -> mt -= 1;
    obj -> top -= 1;
}

//returning topmost value of stack
int minStackTop(MinStack* obj) {
  return (obj -> st[obj -> top]);
}

//returning minimum value in the stack.
int minStackGetMin(MinStack* obj) {
  return obj -> min[obj -> mt];
}

//freeing up the memory
void minStackFree(MinStack* obj) {
    free(obj);
}

/***************************************END*********************************/

