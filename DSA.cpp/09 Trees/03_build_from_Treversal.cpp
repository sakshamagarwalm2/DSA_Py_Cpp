//Building Tree from givien Treversal(preorder and inorder)

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

int search(int in[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in[i]==curr){
            return i;
        }
    }
    return -1; // element not found in inorder array
}

node* buildTree(int pre[] , int in[], int start , int end){
    static int idx =0;
    if(start>end){
        return NULL;
    }

    int curr= pre[idx];
    idx++;
    node* root = new node(curr);

    if(start==end){
        return root;
    }

    int pos = search(in,start,end,curr);
    root->left = buildTree(pre,in,start,pos-1);
    root->right = buildTree(pre,in,pos+1,end);
    return root;

}

void inorderprint(node* root){
    if(root==NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

int main(){

    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    int n = sizeof(preorder)/sizeof(preorder[0]);
    node* root = buildTree(preorder,inorder,0,n-1);
    cout<<"Inorder traversal of constructed tree is: ";
    inorderprint(root);
    cout<<endl;

return 0;
}