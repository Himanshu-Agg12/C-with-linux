/* Program to check whether the give linked list is palindrome or not.
 *
 *Assignment No -> (06) 
 *Assignment Name -> Linked_List
 *
 *Question No -> (04)
 *
 *Date -> 28/08/2021
 *
 *author@Himanshu Aggarwal
 *
 */
/**********************************Pseudo Code LeetCode*********************/

//this function will check for the palindrom by recursion
bool recur(struct ListNode **start, struct ListNode *end){
    //if there is no element in list
    if(end == NULL)
        return true;
    
    //it will check for the palindrome or note at any time
    bool isEqual;
    
    //it stores the values of the nodes
    int num = end -> val;
    
    //recursively move the end to the end of list
    isEqual = recur(start, end -> next);
    
    //if at anytime isEqual false it means not equal so return false.
    if(isEqual == false)
        return false;
    
    //these are recursive callbacks so now the num is pointing to the last element and we will compare
    //with start of the list, also the start should be global or passed by refrence as because changes in start should not lost.
    if((*start) -> val == num){
        //after comapering start with num we move start towards end and end is coming towards head so when they meet it will palindrome
        *start = (*start) -> next;
        return true;
    }else{
        return false;
    }
}

bool isPalindrome(struct ListNode* head){
    return recur(&head, head);
}

/*****************************END*****************************************/
