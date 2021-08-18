/* Program to implement sliding window with max.
 *
 *Assignment No -> (04) 
 *Assignment Name -> stacks and queues
 *
 *Question No -> (06)
 *
 *Date -> 18/08/2021
 *
 *author@Himanshu Aggarwal
 *
 *sources: geeks for geeks, stackOverflow, Youtube, discuss section.
 *
 */


/********************PSEUDO CODE FOR LEETCODE***********************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
};

int* maxSW(int* res, int* n, int nsize, int k);
void push(int i, int* n, struct Node** q, struct Node** head);
void pop(struct Node** head);

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){

    int l=numsSize-k+1;
    int* res= malloc(l*sizeof(int));
    *returnSize= l;
    return maxSW(res,nums,numsSize,k);    

}
int* maxSW(int* res, int* n, int nsize, int k)
{
    struct Node* queue=(struct Node*) malloc(sizeof(struct Node));
    queue->val=0;
    queue->prev=NULL;
    queue->next=NULL;
    struct Node* head=queue;
    int i=0;
    for(i=1; i<k; i++)  // generate dequeue(maximum to minimum) for first window(for the size of k)
    {
        push(i,n,&queue,&head);
    }
    res[0]=n[head->val]; //result for 1st sliding window.
    
    if(head->val==0)    //check if 1st value of dequeue (max) is the position which we will left(while sliding window)
        pop(&head);
        
        
    int j=1;    // using as index of result
    for(i=k; i<nsize; i++)  //slide window
    {
        push(i,n,&queue,&head); //push each value(index)

        res[j]=n[head->val];    //result generating
        j++;

        if((i-k+1)==head->val)  //pop max, if we left the position
            pop(&head);
    }
    
    return res;
    
}

void push(int i, int* n, struct Node** q, struct Node** head)
{
    if(n[i]<n[(*q)->val])
    {
        (*q)->next=(struct Node*) malloc(sizeof(struct Node));
        (*q)->next->prev=(*q);
        (*q)=(*q)->next;
        (*q)->val=i;
        (*q)->next=NULL;
    }
    if(n[i]>=n[(*q)->val])
    {
        while((*q)!=NULL && n[i]>=n[(*q)->val] )!

            (*q)=(*q)->prev;
       
        if((*q)==NULL)
        {
            (*q)=(struct Node*) malloc(sizeof(struct Node));
            (*head)=(*q);
            (*q)->val=i;
            (*q)->prev=NULL;
            (*q)->next=NULL;    
        }
        else
        {
            (*q)->next=(struct Node*) malloc(sizeof(struct Node));
            (*q)->next->prev=(*q);
            if((*head)!=NULL && (*head)->val>(*q)->val)
                (*head)=(*q)->next;
            (*q)=(*q)->next;
            (*q)->val=i;
            (*q)->next=NULL;
            
        }
    }
    
    if((*head)==NULL)
    {
        (*head)=(*q);
    }
}

void pop(struct Node** head)
{
    
    *head=(*head)->next;
    
}

/*******************************END*********************************/

