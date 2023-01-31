// PROBLEM LINK --- https://leetcode.com/problems/palindrome-linked-list/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/palindrom-linked-list_799352?leftPanelTab=0

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
  
Node *reverse(Node *node){
    Node *pre = NULL ;
    Node *next = NULL ;
    while(node != NULL){
        next = node -> next ;
        node -> next = pre ;
        pre = node ;
        node = next ;
    }
    return pre ;
}

//Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    //Your code here
    // BRUTEFORCE
    /*
    string str = "" ;
    while(head != NULL){
        str += to_string(head -> data) ;
        head = head -> next ;
    }
    string knnc = str ;
    reverse(knnc.begin() , knnc.end()) ;
    if(str == knnc) return true ;
    else return false ;
    */
    // OPTIMIZED
    // TO FIND  MIDDLE   REVERSE   TO COMPARE
    if(head == NULL || head -> next == NULL) return true ;
    // FIND MIDDLE OF THE LINKED LIST 
    Node *slow = head ;
    Node *fast = head ;
    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    // REVERSE THE RIGHT HALF OF THE LINKED LIST
    slow -> next = reverse(slow -> next) ;
    slow = slow -> next ;
    // COMPARE ELEMENTS UNTIL SLOW REACHES TO NULL
    while(slow != NULL){
        if(head -> data != slow -> data) return false ;
        head = head -> next ;
        slow = slow -> next ;
    }
    return true ;
}

int main()
{
  int T,i,n,l,firstdata;
    cin >> T ;
    while(T--){
        struct Node *head = NULL,  *tail = NULL;
        cin >> n ;
        // taking first data of LL
        cin >> firstdata ; 
        head = new Node(firstdata);
        tail = head ;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin >> l ;
            tail -> next = new Node(l) ;
            tail = tail -> next ;
        }
        cout << isPalindrome(head) << endl ;
    }
    return 0;
}
