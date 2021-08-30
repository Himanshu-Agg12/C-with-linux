/* Program to merge two sorted linked lists.
 *
 *Assignment No -> (06) 
 *Assignment Name -> Linked_List
 *
 *Question No -> (07)
 *
 *Date -> 28/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */
/************************************Pseudo Code LeetCode******************************/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL && l2 == NULL)
        return NULL;
    else if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
        struct ListNode* ans = (struct ListNode*) malloc(sizeof(struct ListNode)*1);
        struct ListNode* head = ans;
        while(l1 != NULL && l2!=NULL){
            if(l1->val < l2->val){
                ans -> next = l1;
                l1 = l1->next;
            }
            else{
                ans -> next = l2;
                l2 = l2 -> next;
            }
            ans = ans->next;
        }
        if(l1 != NULL){
            ans -> next = l1;
        }
        else if(l2 != NULL){
            ans -> next = l2;
        }
        ans = NULL;
        return head -> next;
}
/*****************************************************END**************************************/

