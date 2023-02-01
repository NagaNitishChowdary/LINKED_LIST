// PROBLEM LINK --- https://leetcode.com/problems/reverse-nodes-in-k-group/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data ;
    struct node* next;
    node(int x){
        data = x;
        next = NULL;
    }    
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    if(head == NULL || k == 1) return head ;
    node *dummy = new node(0) ;
    dummy -> next = head ;
    node *cur = dummy , *nex = dummy , *pre = dummy ;
    // FIRST CALCULATE NUMBER OF NODES IN LINKED LIST 
    int cnt = 0 ;
    while(cur -> next != NULL){
        cur = cur -> next ;
        cnt++ ;
    }
    while(cnt >= k){
        cur = pre -> next ;
        nex = cur -> next ;
        for(int i=1 ; i<k ; i++){
            cur -> next = nex -> next ;
            nex -> next = pre -> next ;
            pre -> next = nex ;
            nex = cur -> next ;
        }
        // PRE IS MOVING TO LAST NODE OF THE REVERSED LINKED LIST
        pre = cur ;
        cnt -= k ;
    }
    return dummy -> next ;
}

int main(void)
{
    int t ; cin >> t ;
    while(t--){
        struct node* head = NULL;
        struct node* temp = NULL;
        int n ; cin >> n ;
        for(int i=0 ; i<n ; i++){
            int value ; cin >> value ;
            if(i == 0){
                head = new node(value);
                temp = head;
            }
            else{
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        int k ; cin >> k ;
        head = reverse(head, k);
        printList(head);
    }
    return(0);
}
