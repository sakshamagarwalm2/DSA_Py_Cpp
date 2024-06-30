// Replace pi with 3.14 in string 

#include<bits/stdc++.h>
using namespace std;

string repi(string s){
    if(s.length()==0){
        return s;
    }

    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        repi(s.substr(2));
    }
    else{
        cout<<s[0];
        repi(s.substr(1));
    }
}

int main(){
string s="pippxxppixipi";
repi(s);
return 0;
}