#include<bits/stdc++.h>
using namespace std;

void wavesort(int arr[],int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]) swap(arr[i],arr[i-1]);
        if(i<=n-2 && arr[i]>arr[i+1]) swap(arr[i+1],arr[i]);
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    wavesort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    
return 0;
}