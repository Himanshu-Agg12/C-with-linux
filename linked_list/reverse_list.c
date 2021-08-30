/* Program to reverse a linked list from given left to right.
 *
 *Assignment No -> (06) 
 *Assignment Name -> Linked_List
 *
 *Question No -> (07)
 *
 *Id -> 1911981022
 *
 *Date -> 30/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */

//Question Link: https://leetcode.com/problems/reverse-linked-list-ii/

/******************************************Pseudo Code for LEETCODE*****************************/

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *start = head, *end = head;

//if left and righ are equal means no node to reverse.
    if(right - left <= 0)
        return head;

//traverse till left node.
    while(--left){
        start = start -> next;
    }

//traverse till right node.
    while(right--){
        end = end -> next;
    }
    
//temp node which will store the node just previous of start node.
    struct ListNode *temp = head;
    
    if(start == head)
        temp = start;
    else{
        while(temp -> next != start){
            temp = temp -> next;
        }
    }
    
//prev and curr node for reversing the list from left to right.
    struct ListNode *prev = start;
    struct ListNode *curr = start -> next;
    
    while(curr != end){
        struct ListNode *a = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = a;
    }

//it says that if start equals head means temp is at head only so points temp to prev.
    if(start == head){
        temp = prev;
        head = temp;
    }

//else the link the previous node of start to our prev node i.e, our new link after reversing.
    else
        temp -> next = prev;

//at last the left node should points to right node which is now current node.
    start -> next = curr;

//Now we return the head of the operated list.
    return head;
}

/********************************************END************************************************/

