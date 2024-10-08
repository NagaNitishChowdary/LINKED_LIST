// PROBLEM LINK --- https://leetcode.com/problems/copy-list-with-random-pointer/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/library/clone-a-linked-list-with-next-and-random-pointer
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head)
{
    //Write your code here
    // APPROACH 1 --- HASHING
    // TC --- O(N)  SC --- O(N)
    /*
    map< Node* , Node* > mpp ;
    Node *temp = head ;
    // 1ST PASS --- CREATION OF NODES AND NO WIRING 
    while(temp != NULL){
        // POINTING THE ORIGINAL NODE TO ITS CLONE NODE 
        // NOW I CAN CLONE NODE IN O(1)
        mpp[temp] = new Node(temp -> data) ;
        temp = temp -> next ;
    }
    
    // 2ND PASS --- FILLING THE NEXT AND RANDOM POINTERS 
    temp = head ;
    while(temp != NULL){
        mpp[temp] -> next = mpp[temp -> next] ;
        mpp[temp] -> arb = mpp[temp -> arb] ;
        temp = temp -> next ;
    }
    return mpp[head] ;
    */
    // APPROACH 2 
    // TC --- O(N) + O(N) + O(N) --- O(N)   SC --- O(1)
    // STEP 1 --- CREATE DEEP COPY NODES IN BETWEEN ORIGINAL NODES 
    Node *iter = head , *front = head ;
    while(iter != NULL){
        front = iter -> next ;
        Node *copyNode = new Node(iter -> data) ;
        iter -> next = copyNode ;
        copyNode -> next = front ;
        iter = front ;
    }
    // STEP 2 --- ASSIGN RANDOM POINTERS TO DEEP COPY NODES
    iter = head ;
    while(iter != NULL){
        if(iter -> arb != NULL) 
            iter -> next -> arb = iter -> arb -> next ;
        iter = iter -> next -> next ;
    }
    // STEP 3 --- DIFFERENTIATE ORIGINAL LIST AND DEEP COPY LIST
    iter = head ;
    Node *psuedoHead = new Node(0) ;
    Node *copy = psuedoHead ;
    while(iter != NULL){
        front = iter -> next -> next ;
        copy -> next = iter -> next ;
        iter -> next = front ;
        copy = copy -> next ;
        iter = iter -> next ;
    }
    return psuedoHead -> next ;
}

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main() {
    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }

            Node *tempB = head;
            Node *temp2B = head2;
            count = -1 ;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        generated_addr = head;
        struct Node *res = copyList(head);
        if(validation(head2,res) && validation(head,res))
            cout << validation(head2, res) << endl;
        else cout << 0 << endl;
    }
    return 0;
}
