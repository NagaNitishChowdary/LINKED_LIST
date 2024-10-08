// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/delete-node-in-ll_5881?leftPanelTab=3

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteNode(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T, i, n, l;
    cin >> T ;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    int kk ; cin >> kk ;
    head = deleteNode(head,kk);
    printList(head);
    }
    return 0;
}

Node *deleteNode(Node *head, int pos)
{
   // Write your code here.
   Node *temp=head;
   Node *temp2=head;
   int ct=0;
   if(head==NULL) return head;
   while(temp!=NULL){
       temp=temp->next;
       ct++;
   }
   if(pos+1>ct){
       return head;
   }
   else if(pos==0){
       return head->next;
   }
   else{
       for(int i=1; i<pos; i++){
           temp2=temp2->next;
       }
       temp2->next=temp2->next->next;
   }
   return head;
}
