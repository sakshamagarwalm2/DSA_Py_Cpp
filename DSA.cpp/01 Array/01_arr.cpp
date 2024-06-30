#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    // input
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // print
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    //max and min
    int maxno=INT_MIN,minno=INT_MAX;

    for(int i=0; i < n; i++){
        // if(arr[i] > maxno){
        //     maxno = arr[i];
        // }

        maxno=max(maxno,arr[i]);


        // if(arr[i] < minno){
        //     minno = arr[i];
        // }
        minno=min(minno,arr[i]);
    }
    cout << "\nMaximum number: " << maxno<<endl;
    cout << "\nMinimum number: " << minno<<endl;


    return 0;
}