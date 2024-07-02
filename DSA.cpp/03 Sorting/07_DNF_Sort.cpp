#include<bits/stdc++.h>
using namespace std;

void dnfsort(int arr[],int n){

    int low=0;
    int mid=0;
    int high=n-1;

    while (mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
    }
    else if(arr[mid]==1){
            mid++;
    }   
    else{
            swap(arr[mid],arr[high]);
            high--;
    }
    }
    

}

int main(){
    int arr[] = {0, 1, 2, 0, 1, 2, 1, 0, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    dnfsort(arr, n);

    //print sorted arr
    cout << "Sorted array: ";
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
return 0;
}