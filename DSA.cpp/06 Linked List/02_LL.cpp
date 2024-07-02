// Reverse a link list 


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

//reverse function

node* reverse(node* head){
    node* prev = NULL;
    node* current = head;
    node* nextptr = NULL;

    while (current!=NULL)
    {
        nextptr=current->next;
        current->next = prev;

        prev = current;
        current = nextptr;
    }

    return prev;
    
}
    
//reversing using recursive fx

node* reverse_recursive(node* &head){

    if(head==NULL || head->next==NULL){
        return head;  
    }
    
    node* newhead = reverse_recursive(head->next);
    head->next->next=head;
    head->next = NULL;

    return newhead;

}


int main(){

    node* head = NULL;
    append(head, 8);
    append(head, 7);
    append(head, 6);
    append(head, 5);

    cout<<"Original List: ";
    display(head);

    head = reverse(head);
    cout<<"Reversed List: ";
    display(head);

    append(head,10);
    append(head,9);

    cout<<"Original List with additional elements: ";
    display(head);

    head = reverse_recursive(head);
    cout<<"Reversed List using recursive function: ";
    display(head);


return 0;
}