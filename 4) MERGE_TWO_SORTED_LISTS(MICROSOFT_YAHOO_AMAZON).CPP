// PROBLEM LINK --- https://leetcode.com/problems/merge-two-sorted-lists/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0

#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t ; cin >> t ; 
    while(t--){
        int n , m ;
        cin >> n  >> m ;
        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin >> data ;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }
        cin >> data ;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    /*
    // APPROACH 1 --- USING EXTRA SPACE 
    // SC --- O(N+M)  TC --- O(N+M)
    // EDGE CASES 
    if(head1 == NULL) return head2 ;
    if(head2 == NULL) return head1 ;
    Node *dummy = new Node(0) ;
    Node *knnc ;
    if(head1 -> data > head2 -> data){
        knnc = new Node(head2 -> data) ;
        head2 = head2 -> next ;
    }
    else{
        knnc = new Node(head1 -> data) ;
        head1 = head1 -> next ;
    }
    dummy -> next = knnc ;
    while(head1 && head2){
        if(head1 -> data > head2 -> data){
            knnc -> next = new Node(head2 -> data) ;
            head2 = head2 -> next ;
        }
        else{
            knnc -> next = new Node(head1 -> data) ;
            head1 = head1 -> next ;
        }
        knnc = knnc -> next ;
    }
    while(head1){
        knnc -> next = new Node(head1 -> data) ;
        head1 = head1 -> next ;
        knnc = knnc -> next ;
    }
    while(head2){
        knnc -> next = new Node(head2 -> data) ;
        head2 = head2 -> next ;
        knnc = knnc -> next ;
    }
    return dummy -> next ;
    */
    // APPROACH 2 
    // TC --- O(N+M)  SC --- O(1)
    if(head1 == NULL) return head2 ;
    if(head2 == NULL) return head1 ;
    if(head1 -> data > head2 -> data) std::swap(head1,head2) ;
    Node *res = head1 ;
    while(head1 != NULL && head2 != NULL){
        Node *temp = NULL ;
        while(head1 != NULL && head1 -> data <= head2 -> data){
            temp = head1 ;
            head1 = head1 -> next ;
        }
        temp -> next = head2 ;
        std::swap(head1,head2) ;
    }
    return res ;   
}
