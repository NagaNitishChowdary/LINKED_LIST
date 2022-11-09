#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

void printList(node *knnc){
    while(knnc!=NULL){
        cout << knnc->data <<" ";
        knnc = knnc->next;
    }
    cout << "\n" ;
}

int main(){
    node *one=new node();
    node *two=new node();
    node *three=new node();

    one->data = 100;
    one->next = two;
    
    two->data = 200;
    two->next = three;

    three->data = 300;
    three->next = NULL;

    printList(one);

    return 0;
}
