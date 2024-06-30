// Reverse a string using recursion"binod""

#include<bits/stdc++.h>
using namespace std;

string reversestring(string x){
    if(x.length()==0){
        return x;
    }
    string ros = x.substr(1);
    reversestring(ros);
    cout<<x[0];
    return "";
 
}

int main(){

string x="binod";

reversestring(x);

return 0;
}