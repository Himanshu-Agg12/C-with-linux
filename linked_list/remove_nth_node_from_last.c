/* Program to remove nth node from last of a linked list.
 *
 *Assignment No -> (06) 
 *Assignment Name -> 
 *
 *Question No -> (06)
 *
 *Date -> 28/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */
/***********************************Pseudo Code LeetCode**************************/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int size = 0;
    struct ListNode* temp = head;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    printf("%d\n", size);
    temp = head;
    if(size == 1 && n == 1)
        return NULL;
    if(size == n)
        return head = head -> next;
    int i = 0;
    int k = size - n;
    while(++i < k){
        temp = temp -> next;
    }
    temp->next = temp -> next -> next;
    return head;
}

/*********************************End****************************************/

