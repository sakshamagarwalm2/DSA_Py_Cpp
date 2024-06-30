#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int n){
    int counter =1;
    while(counter<n){
        for(int i=0; i<n-counter; i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
            counter++;
    }

    //print sorted arr
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[5]={1,8,2,5,7};
    bubblesort(arr, 5);
return 0;
}