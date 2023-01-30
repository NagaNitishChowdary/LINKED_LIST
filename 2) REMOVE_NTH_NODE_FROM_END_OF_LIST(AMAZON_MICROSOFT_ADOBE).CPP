// PROBLEM LINK --- https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/delete-kth-node-from-end-in-linked-list_799912
// PROBLEM LINK --- https://www.geeksforgeeks.org/remove-nth-node-from-end-of-the-linked-list/

// AMAZON || MICROSOFT || ADOBE

#include <bits/stdc++.h>
using namespace std;

class LinkedList {
public:
    // Linked list Node
    class Node {
    public:
        int data;
        Node* next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
    };

    // Head of list
    Node* head;

    // Function to delete the nth node from the end of the
    // given linked list
    Node* deleteNode(int key)
    {
        Node* start = new Node(0) ;
        start -> next = head ;
        Node* fast = start ;
        Node* slow = start ;
        for (int i = 0; i < key; i++) fast = fast -> next ;
        while (fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next ;
        return start -> next ;
    }

    // Function to insert a new Node at front of the list
    Node* push(int new_data)
    {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
        return head;
    }

    // Function to print the linked list
    void printList()
    {
        Node* tnode = head;
        while (tnode != NULL) {
            cout << (tnode->data) << (" ");
            tnode = tnode->next;
        }
    }
};

int main()
{
    LinkedList* llist = new LinkedList();

    llist->head = llist->push(7);
    llist->head = llist->push(1);
    llist->head = llist->push(3);
    llist->head = llist->push(2);

    cout << ("Created Linked list is:\n");
    llist->printList();

    int N = 1;
    llist->head = llist->deleteNode(N);

    cout << ("\nLinked List after Deletion is:\n");
    llist->printList();
}
