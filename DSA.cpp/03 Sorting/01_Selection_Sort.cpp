#include<bits/stdc++.h>
using namespace std;

int selectionsort(int arr[],int n){
    int min=NULL;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                min=arr[j];
                arr[j]=arr[i];
                arr[i]=min;
            }
        }
    }

    //print sorted arr
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
//T=O(n^2)
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionsort(arr,n);

return 0;
}