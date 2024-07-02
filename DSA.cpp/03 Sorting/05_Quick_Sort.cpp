#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i,int r){
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = (l-1);

    for(int j = l; j<=r-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return (i+1);
}

void qucksort(int arr[],int l,int r){
    if(l<r){
        int pi = partition(arr,l,r);
        qucksort(arr,l,pi-1);
        qucksort(arr,pi+1,r);
    }
}
int main(){
    int arr[8]={1,5,2,8,3,7,4,6};
    qucksort(arr,0,7);
    cout<<"Sorted array is: ";
    for(int i=0;i<8;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
return 0;
}