// PROBLEM LINK --- https://leetcode.com/problems/rotate-list/ 
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/rotate-linked-list_920454?leftPanelTab=0

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
    if(head == NULL || head -> next == NULL || k == 0) return head ;
    int cnt = 1 ;
    Node *curr = head ;
    while(curr -> next != NULL){
        curr = curr -> next ;
        cnt++ ;
    }
    curr -> next = head ;
    if(k >= cnt) k %= cnt ;
    k = cnt - k ;
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
