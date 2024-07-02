///Sorted array to Balanced BST

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

    void pre(Node* root){
        if(root == NULL) return;
        cout << root->data << " ";
        pre(root->left);
        pre(root->right);
    }


Node* sortedArrayToBST(int arr[], int start, int end){
    if(start > end)
        return NULL;

    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = sortedArrayToBST(arr, 0, n-1);

    cout << "Inorder traversal of constructed BST: \n";
    pre(root);
return 0;
}