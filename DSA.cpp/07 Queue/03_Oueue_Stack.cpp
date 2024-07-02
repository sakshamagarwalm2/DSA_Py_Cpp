//manking a queue using stack


#include<bits/stdc++.h>
using namespace std;

//creating a class queue

class Queue{
    stack<int> s1, s2;
    public:
    void enqueue(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() and s2.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }

    bool isEmpty(){
        return s1.empty() and s2.empty();
    }

};

int main(){

    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<q.pop()<<" ";
    cout<<q.pop()<<" ";

    cout<<q.isEmpty()<<endl;
return 0;
}