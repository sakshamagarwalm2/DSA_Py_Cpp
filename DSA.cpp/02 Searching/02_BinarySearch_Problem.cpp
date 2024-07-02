//Given isn't array with an element that represents N positions along a straight line.
//  Find K Elements such that the minimum distance between any two elements is the maximum possible.

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int mid,int arr[], int n, int k){
    int pos=arr[0];
    int count=1;

    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            count++;
            if(count==k)
                return true;
        }
    }
    return false;
}

int largestmiddistance(int arr[],int n, int k){
    sort(arr, arr+n);
    
    int result=-1;
    int left=1,right=arr[n-1];

    while(left<right){
        int mid=(left+right)/2;
        if(isFeasible(mid,arr,n,k)){
            result=max(result,mid);
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return result;
}

int main(){
    int arr[]={1, 2, 8, 4, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;

    int maxDistance=largestmiddistance(arr, n, k);
    cout<<"The maximum possible distance is "<<maxDistance;

    
return 0;
}