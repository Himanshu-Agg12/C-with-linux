/* Program to rotate a linked list by k in c.
 *
 *Assignment No -> (06) 
 *Assignment Name -> Linked_List
 *
 *Id -> 1911981022
 *
 *Question No -> (09)
 *
 *Date -> 30/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */

//Question Link: https://leetcode.com/problems/rotate-list/

/***********************************Pseudo Code for LEETCODE*************************************/

struct ListNode* rotateRight(struct ListNode* head, int k){

//first we check if list is null or only 1 element is there then the rotation is same as list itself.
    if(head == NULL || head -> next == NULL)
        return head;

//Now we find size of the list.
    int size = 0;

//this is the iterator node for traversing the list.
    struct ListNode *iter = head;

    while(iter != NULL){
        size++;
        iter = iter -> next;
    }

//now if k is greater then size we make it in range by finding modulo and then subtracting from size
//to get the (size - k)th node.
    int n = size - (k%size);
    
//if we found k is zero or equal to size it means the rotation should equal to list itself.
    if(n == 0 || n == size)
        return head;
    
//else we find the size - nth node and then store its next to NULL by storing the next in temp
//so for later it should not lost.
    iter = head;
    while(--n){
        iter = iter -> next;
    }

//now temp and temp1 storing the nth node.    
    struct ListNode *temp = iter -> next;
    struct ListNode *temp1 = iter -> next;
    
//it will make the last node point to NULL.
    iter -> next = NULL;

//now the remaining half part will now point to head and the head point to new head.
    while(temp1 -> next != NULL){
        temp1 = temp1 -> next;
    }
    
    temp1 -> next = head;
    head = temp;
    
//hence we return our updated head.
    return head;
}

/*************************************************END****************************************/

