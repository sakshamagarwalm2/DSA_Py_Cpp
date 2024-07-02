//Merge 2 sorted linked lists


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

//function to merge 2 sorted linked lists

node* mergeLists(node* head1, node* head2){
    node* dummynode = new node(-1);
    node* p1 = head1;
    node* p2 = head2;

    node* p3 = dummynode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data <= p2->data){
            p3->next = p1;
            p1 = p1->next;
        }else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1!=NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2!=NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummynode->next;    

}

//using recursion

node* mergeListsRecursive(node* &head1, node* &head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    node* result;
    
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeListsRecursive(head1->next, head2);
    } else{
        result = head2;
        result->next = mergeListsRecursive(head1, head2->next);
        }
        
    return result;
}

int main(){

    // Creating first list
    node* head1 = NULL;
    append(head1, 5);
    append(head1, 10);
    append(head1, 15);

    cout<<"First List: ";
    display(head1);

    // Creating second list
    node* head2 = NULL;
    append(head2, 4);
    append(head2, 9);
    append(head2, 16);
    append(head2, 20);

    cout<<"Second List: ";
    display(head2);

    // Merging the lists
    node* mergedList = mergeLists(head1, head2);
    cout<<"Merged List: ";
    display(mergedList);

    // Merging the lists recursively
    // node* mergedListRecursive = mergeListsRecursive(head1, head2);
    // cout<<"Merged List (Recursive): ";
    // display(mergedListRecursive);

return 0;
}