//count number of nodes in the binary tree

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

int countnodes(node* root){
    if(root == NULL)
        return 0;
        
    return 1 + countnodes(root->left) + countnodes(root->right);
}

int sum(node* root){
    if(root == NULL)
    return 0;

    return root->data + sum(root->left) + sum(root->right);
    
}

int main(){

    struct node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    /*
        1
       / \
      2   3 
     / \ / \
    4  5 7  6
    */
    
   root->left->left = new node(4);    
   root->left->right = new node(5);    
   root->right->left = new node(7);    
   root->right->right = new node(6);    

   cout << "Number of nodes in the binary tree is: " << countnodes(root);
   cout << "\nSum of all nodes in the binary tree is: " << sum(root);

return 0;
}