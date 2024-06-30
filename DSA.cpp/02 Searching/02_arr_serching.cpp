#include <bits/stdc++.h>
using namespace std;


//LineraSearching
int linearsearch(int arr[],int n ,int key){

    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1; // key not found

//T=O(n)
//S=O(n)

}

//Binary Search
int binarysearch(int arr[],int n,int key){

    //sorted arr hi hona chahiye
    sort(arr, arr + n);
    int s = 0;
    int e = n - 1;
    while (s<=e)
    {
        int mid=(s+e)/2;

        if (arr[mid] == key){
            return mid;
            }
        else if(arr[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    
    return -1; // key not found    

//T=O(log n)
//S=O(n)

}

int main()
{
    //Linear search
    // serching in arr if present index return

    cout<<"Linear-Searching"<<endl;

    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    //key to find
    int key;
    cout<<"Enter the key to search: ";  
    cin>>key;

    int index= linearsearch(arr,n,key);
    if(index==-1){
        cout<<key<<" is not present in array"<<endl;
    }else{
        cout<<key<<" is present at index "<<index<<endl;
    }

    //Binary Search

    cout<<"Binary-Searching"<<endl;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout<<"Enter the key to search: ";  
    cin>>key;

    index= binarysearch(arr,n,key);
    if(index==-1){
        cout<<key<<" is not present in array";
    }else{
        cout<<key<<" is present at index "<<index;
    }

    return 0;
}