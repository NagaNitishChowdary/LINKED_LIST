// PROBLEM LINK --- https://leetcode.com/problems/intersection-of-two-linked-lists/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/intersection-of-linked-list_630457?leftPanelTab=0

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // APPROACH 1 --- BRUTEFORCE 
    // TC --- O(N*M)
    /*
    while(headA != NULL){
        ListNode *knnc = headB ;
        while(knnc != NULL){
            if(knnc == headA) return knnc ;
            knnc = knnc -> next ;
        }
        headA = headA -> next ;
    }
    return NULL ;
    */
    // APPROACH 2 --- OPTIMIZED
    // USING UNORDERED MAP 
    // TC --- O(N+M)  SC --- O(N)
    /*
    unordered_map<ListNode*,int> mpp ;
    while(headA){
        mpp[headA]++ ;
        headA = headA -> next ;
    }
    while(headB){
        if(mpp.find(headB) != mpp.end()) return headB ;
        headB = headB -> next ;
    }
    return NULL ;
    */
    // MOST OPTIMIZED APPROACH 
    // TC --- O(2*M)  SC --- O(1)
    ListNode *d1 = headA , *d2 = headB ;
    // if d1 and d2 have different length then we will stop after second iteration
    while(d1 != d2){
        // for the end of first iteration , we just reset the pointer to the head of another linked list 
        d1 = d1 == NULL ? headB : d1 -> next ;
        d2 = d2 == NULL ? headA : d2 -> next ;
    }
    return d1 ;
}
