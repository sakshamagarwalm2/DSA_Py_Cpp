// reverse k nodes in LL 


#include<bits/stdc++.h>
using namespace std;

//creating node

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

//function to insert at the Tail

void append(node* &head,int val){
    node* newNode = new node(val);

    if(head==NULL){
        head = newNode;
        return;
    }

    node* temp=head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    
}

//to print

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<" NULL"<<endl;
}

//function to reverse k nodes

node* reverseKNodes(node* head, int k){

    node* prev = NULL;
    node* current = head;
    node* nextptr = NULL;

    int count =0;
    while(current!=NULL && count<k){
        nextptr = current->next;
        current->next = prev;


        prev = current;
        current = nextptr;

        count++;
    }

    if(nextptr!=NULL){
        head->next = reverseKNodes(nextptr, k);
    }
    
    return prev;
}


int main(){

    node* head = NULL;
    
    append(head,8);
    append(head,7);
    append(head,6);
    append(head,5);
    append(head,4);
    append(head,3);
    append(head,2);
    append(head,1);
    
    cout<<"Original Linked List: ";
    display(head);

    int k = 3;
    head = reverseKNodes(head, k);
    
    cout<<"Reversed Linked List: ";
    display(head);
    
    

return 0;
}