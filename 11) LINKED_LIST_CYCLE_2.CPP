// PROBLEM LINK --- https://leetcode.com/problems/linked-list-cycle-ii/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628?leftPanelTab=0

ListNode *detectCycle(ListNode *head) {
    // BRUTEFORCE --- HASHING
    // TC --- O(N)   SC --- O(N)
    /*
    unordered_map< ListNode* , int > mpp ;
    while(head != NULL){
        if(mpp.find(head) != mpp.end()) return head ;
        mpp[head]++ ;
        head = head -> next ;
    }
    return NULL ;
    */
    // OPTIMIZED APPROACH --- SLOW AND FAST POINTER APPROACH 
    // STEP 1 --- FIND THE COLLISION POINT IF CYCLE EXISTS 
    ListNode *slow = head , *fast = head , *entry = head ;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;
        if(slow == fast){
            while(slow != entry){
                slow = slow -> next ;
                entry = entry -> next ;
            }
            return entry ;
        }
    }
    /*
    if(fast == NULL || fast -> next == NULL) return NULL ;
    // STEP 2 --- TAKING ANOTHER NODE ENTRY AND FINDING THE STARTING POINT OF LL 
    ListNode *entry = head ;
    while(1){
        if(entry == slow) return slow ;
        entry = entry -> next ;
        slow = slow -> next ;
    } */
    return NULL ;
}
