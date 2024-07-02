//Stack inplementation using arr
//LIFO
//push()
//pop()
// top()=peak()
// empty()

#include<bits/stdc++.h>
using namespace std;

#define n 100

class stacks{
    int* arr;
    int top;

    public:
    stacks(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top >= n-1){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack\n";
    }

    void pop(){
        if(top < 0){
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top] << " popped from stack\n";
        top--;
    }

    int peak(){
        if(top < 0){
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top == -1;
    }

};

int main(){
    
    stacks s;
    cout<<s.empty()<<endl;
    s.push(10);
    s.push(20);

    cout << "Top element is: " << s.peak() << endl;
    s.pop();

    cout << "Top element is: " << s.peak() << endl;
    s.push(30);

    cout << "Top element is: " << s.peak() << endl;

    cout<<s.empty()<<endl;
    
return 0;
}