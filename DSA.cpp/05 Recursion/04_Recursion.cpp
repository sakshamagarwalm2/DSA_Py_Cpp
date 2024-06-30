//Find the first and last occurence of a number in an array
#include<bits/stdc++.h>
using namespace std;

//firstoccurence
int firstocc(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }

    if(arr[i]==key){
        return i;
    }

    return firstocc(arr,n,i+1,key);
}

//lastoccurence

int lastocc(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }

    int restarray = lastocc(arr, n, i+1, key);
    if(restarray!=-1){
        return restarray;
    }

    if(arr[i]==key){
        return i;
    }

    return -1;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;

    int first = firstocc(arr, n, 0, key);
    int last = lastocc(arr, n, 0, key);

    if(first==-1){
        cout << "Element not found";
    }
    else{
        cout << "First occurrence of " << key << " is at index " << first;
        cout << "\nLast occurrence of " << key << " is at index " << last;
    }

return 0;
}