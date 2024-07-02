// Given an array and a value , find if there exists 3 numbers whose sum id equsl to given vslue.

#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;


//creating a random arr a[] using vector
vector<int> a(n);

for(auto &i: a)
    cin>>i;
    
int target;
cin>>target;

//sort the array to make it easier to find triplets
bool found=false;

sort(a.begin(),a.end());

for(int i=0;i<n;i++){
    int l=i+1;
    int r=n-1;
    
    while(l<r){
        int sum=a[i]+a[l]+a[r];
        
        if(sum==target){
            found=true;
            cout<<"Triplet found: "<<a[i]<<" + "<<a[l]<<" + "<<a[r]<<" = "<<target<<endl;
            break;
        }
        else if(sum<target)
            l++;
        else
            r--;
    }
    if(found)
        break;
}

if(!found)
    cout<<"No triplet found."<<endl;


return 0;
}