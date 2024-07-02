//Queue implimentation using LL

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

class Queue{
    node* front;
    node* rear;
    public:
    Queue(){
        front=NULL;
        rear=NULL;
    }
    void enqueue(int x){
        node* temp=new node(x);
        if(front==NULL){
            front=temp;
            rear=temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    }
    int dequeue(){
        if(front==NULL){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        int x=front->data;
        node* temp=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        delete temp;
        return x;
    }
    bool empty(){
        return front==NULL;
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return front->data;
    }
    void display(){
        node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<"Dequeued element: "<<q.dequeue()<<endl;
    q.display();
    cout<<"Front element: "<<q.peek()<<endl;
    cout<<"Is queue empty? "<<(q.empty()?"Yes":"No")<<endl;
    

return 0;
}