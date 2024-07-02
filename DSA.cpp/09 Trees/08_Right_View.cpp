//Right view of the tree

//Binary Tree

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
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

void rightvieew(node* root){
    if(root == NULL) return;
    
     queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        int n= q.size();
        
        for(int i=0;i<n;i++){
            node* temp = q.front();
            q.pop();

            if (i==n-1)
            {
                
            cout << temp->data << " ";
            }
            
            
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
}

int main(){


    // Create a binary tree with given nodes
    struct node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    /*
        1
       / \
      2   3 
     / \
    4   5   
    */
    
   root->left->left = new node(4);    
   root->left->right = new node(5);    

   rightvieew(root); // Right view of the tree will be 5 3 1.
   
    

return 0;
}