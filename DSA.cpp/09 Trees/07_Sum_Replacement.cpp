//Sum Replacement

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

void replacement(node* root){
    if(root == NULL)
        return;
    
    replacement(root->left);
    replacement(root->right);
    
    if(root->left!= NULL)
        root->data+=root->left->data;
    
    if(root->right!= NULL)
        root->data+=root->right->data;
    
}

void preoder(node* root){
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preoder(root->left);
    preoder(root->right);
}

int main(){
    struct node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    
   root->left->left = new node(4);    
   root->left->right = new node(5);  

   preoder(root);
   cout<<"\n";
   
   replacement(root);
   
   cout<<"Replaced Tree: ";
   preoder(root);
   
   
return 0;
}