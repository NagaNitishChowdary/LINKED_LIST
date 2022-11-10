#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

void printList(node *knnc){
    while(knnc!=NULL){
        cout << knnc -> data << " ";
        knnc = knnc -> next;
    }
    cout << "\n";
}

void front( node **head , int new_data ){
    node *new_node = new node();
    new_node -> data = new_data ;
    new_node -> next = (*head);
    (*head) = new_node ; 
}

void middle( node **head, int new_position , int new_data ){
    
    node *new_node = new node();
    new_node -> data = new_data ;
    node *duplicate = (*head);
    for(int i=0 ; i < new_position - 1 ; i++ ){
        duplicate = duplicate -> next ;
    }
    new_node -> next = duplicate -> next ;
    duplicate -> next = new_node ;

}

void last ( node **head , int new_data ){

    node *new_node = new node() ;
    new_node -> data = new_data ;
    new_node -> next = NULL ;
    node *duplicate = (*head);
    while(duplicate->next != NULL ){
        duplicate = duplicate -> next ;
    }
    duplicate -> next = new_node ;
}

void deletefront( node **head ){
    node *temp = (*head);
    temp = temp -> next ;
    (*head) = (temp) ;
}

int main() {
    node *head=new node();
    node *second=new node();
    node *third=new node();

    head -> data = 100;
    head -> next = second;

    second -> data = 200;
    second -> next = third;

    third -> data = 300;
    third -> next = NULL;

    printList(head);
    
    // INSERTING IN THE FRONT OF THE LINKED LIST 

    front( &head , 50 );
    front( &head , 25 );

    printList(head);

    // INSERTING IN THE MIDDLE OF THE LINKED LIST
    middle( &head , 2 , 999 );

    printList(head);

    // INSERTING IN THE LAST OF THE LINKED LIST
    last( &head , 888 );

    printList(head);

    front( &head , 83 );
    middle( &head , 4 , 83 );
    last( &head , 83 );

    printList(head);

    deletefront(&head);

    printList(head);

    deletelast(&head);

    printList(head);

    return 0;  
}
