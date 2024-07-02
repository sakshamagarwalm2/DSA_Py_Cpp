//Height of a binary tree
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

int height(node* root){
    if(root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

int diameter(node* root){
    if(root == NULL)
    return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(lheight+rheight+1, max(ldiameter, rdiameter));
}

int main(){
    struct node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    
   root->left->left = new node(4);    
   root->left->right = new node(5);  

   cout<<height(root)<<endl;  
   cout<<diameter(root)<<endl;

return 0;
}