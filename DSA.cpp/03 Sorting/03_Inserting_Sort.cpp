#include<bits/stdc++.h>
using namespace std;

void insertsort(int arr[],int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }

    //print sorted arr
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){

//arr eg
    int arr[] = {9, 4, 6, 2, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertsort(arr, n);

    

return 0;
}