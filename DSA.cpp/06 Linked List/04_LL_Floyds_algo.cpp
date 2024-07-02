// Detect Cycle

//Floyd's Algorith
// Hare and Toetise Algo 

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

//make cycle

void makeCycle(node* &head , int pos){
    node* temp = head;
    node* startnode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode = temp;
            
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
    
}


//detect cycle

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            cout<<"Cycle Detected"<<endl;
            return true;
        }

        }
        return false;

}

//remove cycle

void removecycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    fast=head;
    while(fast->next!= slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}


int main(){

    node* head = NULL;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    makeCycle(head, 3);
    cout<<detectCycle(head)<<endl;

    // display(head);

    removecycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);

return 0;
}