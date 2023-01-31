// PROBLEM LINK --- https://leetcode.com/problems/linked-list-cycle/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/cycle-detection-in-a-singly-linked-list_628974

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool detectLoop(Node* head)
{
    // your code here
    /*
    // BRUTEFORCE --- USES HASING 
    // TC --- O(N)   SC --- O(N)
    unordered_map<Node*,int> mpp ;
    while(head != NULL){
        if(mpp.find(head) == mpp.end()) mpp[head]++ ;
        else return true ;
        head = head -> next ;
    }
    return false ;
    */
    // OPTIMIZED APPROACH --- USES SLOW AND FAST POINTERS
    if(head == NULL || head -> next == NULL) return false ;
    Node *slow = head , *fast = head ;
    while(fast -> next && fast -> next -> next){
        slow = slow -> next ;
        fast = fast -> next -> next ;
        if(slow == fast) return true ;
    }
    return false ;
}

int main()
{
    int t ; cin >> t ;
    while(t--)
    {
        int n, num;
        cin >> n ;
        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        int pos ; cin >> pos ;
        loopHere(head,tail,pos);
        if(detectLoop(head)) cout << "True\n" ;
        else cout << "False\n" ;
    }
    return 0;
}
