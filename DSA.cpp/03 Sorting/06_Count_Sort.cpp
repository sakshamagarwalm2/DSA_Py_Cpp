#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[],int n){
    int k=arr[0];
    for(int i=1;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main(){
    int arr[]={1,4,2,2,2,5,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    countsort(arr,n);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}