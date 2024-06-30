#include<bits/stdc++.h>
using namespace std;

// Chek if an array is sorted or not using recursion
bool sorted(int arr[],int n){

    // Base case: if array has one element or no element, it is sorted
    if(n==1){
        return true;
    }

    bool restarray = sorted(arr+1,n-1);
    return (restarray && arr[0] <= arr[1]);
}

int main(){

    int arr1[4]={1,2,3,4},arr2[4]={2,6,3,4};
    int n=4;

    cout << "Is array1 sorted? " << (sorted(arr1, n)? "Yes" : "No") << endl;
    cout << "Is array2 sorted? " << (sorted(arr2, n)? "Yes" : "No") << endl;

return 0;
}