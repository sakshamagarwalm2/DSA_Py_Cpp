//finding sum of 2 elements using 2-pointers

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {1, 2, 3, 4, 12, 5, 6, 7, 8, 11, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr,arr+n);

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int i=0,j=n-1;
    int f=0;

    while (i<j)
    {
        if(arr[i]+arr[j]==target){
            f=1;
            cout << "Pair found: " << arr[i] << " and " << arr[j] << endl;
            break;
        }
        else if(arr[i]+arr[j]<target){
            i++;
        }
        else{
            j--;
         
        }
    }

    if(f==0)
        cout<<"not found"<<endl;
    

return 0;
}