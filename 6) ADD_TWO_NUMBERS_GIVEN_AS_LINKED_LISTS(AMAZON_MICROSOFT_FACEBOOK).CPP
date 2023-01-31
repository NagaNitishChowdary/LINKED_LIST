// PROBLEM LINK --- https://leetcode.com/problems/add-two-numbers/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/add-two-numbers-as-linked-lists_1170520?leftPanelTab=0

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0) ;
    ListNode *temp = dummy ;
    int carry = 0 ;
    while(l1 != NULL || l2 != NULL || carry){
        int sum = 0 ;
        if(l1 != NULL){
            sum += l1 -> val ;
            l1 = l1 -> next ;
        }
        if(l2 != NULL){
            sum += l2 -> val ;
            l2 = l2 -> next ;
        }
        sum += carry ;
        carry = sum/10 ;
        ListNode *newNode = new ListNode(sum%10) ;
        temp -> next = newNode ;
        temp = temp -> next ;
    }
    return dummy -> next ;
}
