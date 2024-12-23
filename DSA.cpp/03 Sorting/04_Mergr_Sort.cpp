#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;

    // temp arr 
    int n2 = r - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i=0,j=0;
    int k = l;

    while (i<n1 && j<n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    

}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{

    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}