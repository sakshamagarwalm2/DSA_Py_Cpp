//Linked-List

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

//function to insert at the Head

void insertAtHead(node* &head, int val){
    node* newNode = new node(val);
    newNode->next = head;
    head = newNode;
}

//function to insert at a given position

void insertAtPosition(node* &head, int val, int pos){

    node* newNode = new node(val);

    if(head==NULL || pos==0){
        insertAtHead(head, val);
        return;
    }

    node* temp = head;
    for(int i=0;i<pos-1 && temp!=NULL; i++){
        temp = temp->next;
    }

    if(temp==NULL){
        cout<<"Position out of range. Insertion not possible."<<endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
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

//Deletion
void deletion(node* &head, int val){

    node* temp = head;

    if(head==NULL){
        cout<<"List is empty. Deletion not possible."<<endl;
        return;
    }

    if(temp->data==val){
        head = temp->next;
        delete temp;
        return;
    }

    while(temp->next->data!=val){
        temp=temp->next;
    }

    node* toDelete = temp->next;
    temp->next=temp->next->next;

    delete toDelete;

}


//searching by value
int search(node* &head, int key){
    node* temp = head;
    int i=0;
    while(temp!=NULL){
        if(temp->data == key)
            return i;
        temp = temp->next;
        i++;
    }
    return -1;
}

//search by index

int searchIndex(node* &head, int index){
    node* temp = head;
    int i=0;
    while(temp!=NULL){
        if(i == index)
            return temp->data;
        temp = temp->next;
        i++;
    }
    return -1;
}

int main(){

    node* head = NULL;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);

    insertAtHead(head,8);
    insertAtHead(head,9);

    cout<<"Linked List: ";
    display(head);

    cout<<"Search for 3: "<<search(head, 3)<<endl;
    cout<<"Search for 10: "<<search(head, 10)<<endl;

    deletion(head, 3);
    cout<<"After Deletion of mid(3): ";
    display(head);
    deletion(head, 9);
    cout<<"After Deletion of head(9): ";
    display(head);
    deletion(head, 4);
    cout<<"After Deletion of tail(4): ";
    display(head);

    insertAtPosition(head, 5, 2);
    cout<<"After Insertion of 5 at pos(2): ";
    display(head);

    cout<<"Search for index2: "<<searchIndex(head, 2)<<endl;
    


return 0;
}