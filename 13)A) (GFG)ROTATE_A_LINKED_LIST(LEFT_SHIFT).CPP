// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* rotate(Node* head, int k)
{
    // Your code here
    Node *curr = head ;
    while(curr -> next != NULL) curr = curr -> next ;
    curr -> next = head ;
    while(k--) curr = curr -> next ;
    head = curr -> next ;
    curr -> next = NULL ;
    return head ;
}

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t ; cin >> t ;
    while(t--){
        int n, val, k;
        cin >> n ;
        cin >> val ;
        Node *head = new Node(val);
        Node *tail = head;
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        cin >> k ;
        head = rotate(head,k);
        printList(head);
    }
    return 1;
}
