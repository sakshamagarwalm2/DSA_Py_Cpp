#include<bits/stdc++.h>
using namespace std;

// Find Fibonacci Numbers using Recursion
//recursion use the stacks
int fabb(int n){
    if(n==1 || n==0){
        return (n);
    }else{
    return (fabb(n-1)+fabb(n-2));
    }
}

int main(){
int x , i=0;
   cout << "Enter the number of terms of series : ";
   cin >> x;
   cout << "\nFibonnaci Series : ";
   while(i < x) {
      cout << " " << fabb(i);
      i++;
   }
return 0;
}