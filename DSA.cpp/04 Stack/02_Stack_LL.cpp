//Stack implimentation using LL

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

//function to push()

void push(node* &head, int val){
    node* newNode = new node(val);
    if(head==NULL){
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

//to pop()

void pop(node* &head){
    if(head==NULL){
        cout<<"Stack is empty. Cannot pop."<<endl;
        return;
    }

    node* temp = head;
    head = head->next;
    delete temp;
}

//to peek()

int peek(node* head){
    if(head==NULL){
        cout<<"Stack is empty. Cannot peek."<<endl;
        return -1;
    }

    return head->data;
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

int main(){

    node* head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);

    cout<<"Stack after pushing: ";
    display(head);

    cout<<"Top element is: "<<peek(head)<<endl;
    pop(head);
    cout<<"Stack after popping: ";
    display(head);
    
return 0;
}