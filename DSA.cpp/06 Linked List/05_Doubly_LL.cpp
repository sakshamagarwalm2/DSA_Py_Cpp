//Doubly LL


#include<bits/stdc++.h>
using namespace std;


//creating node

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

//function to insert at the head of the Doubly Linked List

void insertathead(node* &head,int val){
    node* newNode = new node(val);
    newNode->next = head;

    if(head!=NULL){
    head->prev = newNode;

    }


    head=newNode;
}


//function to insert at the Tail

void append(node* &head,int val){
    node* newNode = new node(val);

    if(head==NULL){
        insertathead(head,val);
        return;
    }

    node* temp=head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev=temp;
    
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

//to delete node at a given position

void deleteNode(node* &head, int pos){
    if(pos==0){
        node* temp = head;
        head = head->next;
        if(head!=NULL)
        head->prev = NULL;
        delete temp;
        return;
    }

    node* temp = head;
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
        if(temp==NULL)
            return;
    }

    node* del = temp->next;
    temp->next = del->next;
    if(del->next!=NULL)
        del->next->prev = temp;
    delete del;
}

int main(){

    node* head = NULL;
    append(head,1);
    append(head,2);
    display(head);

    insertathead(head,0);
    display(head);

    deleteNode(head,1);
    display(head);

return 0;
}