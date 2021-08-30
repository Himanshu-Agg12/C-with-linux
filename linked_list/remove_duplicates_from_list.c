/* Program to remove duplicates from the list.
 *
 *Assignment No -> (06) 
 *Assignment Name -> Linked_List
 *
 *Id -> 1911981022
 *
 *Question No -> (05)
 *
 *Date -> 30/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */

//Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*************************************************Pseudo Code for LEETCODE**************************/

struct ListNode* deleteDuplicates(struct ListNode* head){
int last_seen;
struct ListNode* ptr;
struct ListNode* ptr2;
if (head==NULL) return NULL;
while ((head->next != NULL) && (head->val == head->next->val)) {
    ptr=head->next;
    while ((ptr->next != NULL) && (ptr->next->val == head->val))
        ptr = ptr->next;
    head = ptr->next;
    if (head==NULL) return NULL;
}
// Now the head node is unique.
ptr=head;    
while (ptr!=NULL) {
    ptr2 = ptr->next;
    if (ptr2!=NULL) {
        last_seen = ptr2->val;
        while ((ptr2->next!=NULL) && (ptr2->next->val==last_seen)) 
            ptr2 = ptr2->next;
    }
    if (ptr->next != ptr2) ptr->next = ptr2->next;
      else ptr=ptr2;
}
    
return head;
}

/*************************************************END***********************************************/
