//Binary Tree

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

//traverse using preorder

void preOrder(struct node* root){
    if(root == NULL)
        return;
        
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//traverse using inorder

void inOrder(struct node* root){
    if(root == NULL)
        return;
        
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//traverse using postorder

void postOrder(struct node* root){
    if(root == NULL)
        return;
        
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){


    struct node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    
   root->left->left = new node(4);    
   root->left->right = new node(5);    

   preOrder(root);
   cout<<endl;
   inOrder(root);
   cout<<endl;
   postOrder(root);
   cout<<endl;
     

return 0;
}