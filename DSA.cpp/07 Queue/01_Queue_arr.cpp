// Queue implimentation using array
// FIFO
// enqueue(), dequeue(), peek(), empty()

#include<bits/stdc++.h>
using namespace std;

#define n 20

class Queue{
    int* arr;
    int front, rear;

    public:
    Queue(){
        arr = new int[n];
        front = rear = -1;
    }

    void enqueu(int x){
        if(rear == n-1){
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = x;

        if(front == -1)
            front++;
    }

    void dequeue(){
        if(front == -1 || rear == front){
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued element: " << arr[front] << endl;
        front++;
    }

    void peek(){
        if(front == -1 || rear == front){
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Peek element: " << arr[front] << endl;
    }

    bool empty(){
        return (front == -1 || rear == front);
    }
};

int main(){


    Queue q;
    cout << "Queue is " << (q.empty()? "empty" : "not empty") << endl;
    
    q.enqueu(10);
    q.enqueu(20);
    q.enqueu(30);
    
    q.dequeue();

    q.peek();
    cout << "Queue is " << (q.empty()? "empty" : "not empty") << endl;


return 0;
}