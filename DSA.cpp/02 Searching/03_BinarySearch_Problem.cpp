//Search Element in sorted and rooted array.
//We are given an ascending sorted error that has been rotated from a pivot point unknown to us and an element X. 
//Search for X in the array with complexity less than that of linear search

#include<bits/stdc++.h>
using namespace std;

int searchinrotatedarray(int arr[],int key,int left, int right){
    if(left>right)
    return -1;
    
    int mid = left + (right-left)/2;
    
    //If the element is present at the middle itself
    if(arr[mid] == key)
    return mid;
    
    //If the element is present in the right half of the array
    if(arr[mid] <= arr[right]){
        //If the key lies in the right half
        if(key > arr[mid] && key <= arr[right])
        return searchinrotatedarray(arr, key, mid+1, right);
        
        //If the key lies in the left half
        return searchinrotatedarray(arr, key, left, mid-1);
    }
    
    //If the element is present in the left half of the array
    if(key >= arr[left] && key < arr[mid])
    return searchinrotatedarray(arr, key, left, mid-1);
    
    //If the key lies in the right half
    return searchinrotatedarray(arr, key, mid+1, right);
}

int main(){

    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 9;

    int result = searchinrotatedarray(arr, key, 0, n-1);
    
    (result == -1)? printf("Element is not present in array") : printf("Element is present at index %d", result);


return 0;
}