// PROBLEM LINK --- https://leetcode.com/problems/middle-of-the-linked-list/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

int getMiddle(Node *head)
{
    // Your code here
    // BRUTEFORCE 
    // TC : O(N) + O(N/2)    SC : O(1)
    /*
    Node *start = new Node(0) ;
    start -> next = head ;
    int cnt = 0 ;
    while(start -> next != NULL){
        cnt++ ;
        start = start -> next ;
    }
    cnt = cnt/2+1 ;
    for(int i=1 ; i<cnt ; i++) head = head -> next ;
    return head -> data ;
    */
            
    // OPTIMIZED APPROACH 
    // TC = O(N/2)   SC = O(1)
    Node *fast = head , *slow = head ;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next ;
        slow = slow -> next ;
    }
    return slow -> data ;
}

int main() {
    int t ; cin >> t ;
    while(t--){
        int N ; cin >> N ;
        int data ; cin >> data ;
        struct Node *head = new Node(data) ;
        struct Node *tail = head ;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout << getMiddle(head) << endl;
    }
    return 0;
}
