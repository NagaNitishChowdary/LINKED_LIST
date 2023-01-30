// PROBLEM LINK --- https://leetcode.com/problems/reverse-linked-list/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/reverse-linked-list_920513?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

//Function to reverse a linked list.
struct Node* reverseList(struct Node *head)
{
    // return head of reversed list
    Node *dummy = NULL ;
    while(head != NULL){
        Node *next = head -> next ;
        head -> next = dummy ;
        dummy = head ;
        head = next ;
    }
    return dummy ;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
    int T,n,l,firstdata;
    cin >> T ;
    while(T--){
        struct Node *head = NULL,  *tail = NULL ;
        cin >> n ; 
        cin >> firstdata ;
        head = new Node(firstdata) ;
        tail = head ;
        for (int i=1 ; i<n ; i++)
        {
            cin >> l ;
            tail -> next = new Node(l) ;
            tail = tail -> next ;
        }
        head = reverseList(head);
        printList(head);
        cout << endl ;
    }
    return 0;
}
