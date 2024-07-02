//ye ek representation jesa hai for binary search

#include<bits/stdc++.h>
using namespace std;
//node og binary tree

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insertBST(Node* root,int val){
    if(root == NULL) return new Node(val);


    if(val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);

    return root;
}

//inorder
    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

//checking BST

bool isBST(Node* root, Node* min, Node* max){
    if(root == NULL) return true;

    if(min!=NULL && root->data <= min->data){
        return false;
    }
    if(max!= NULL && root->data > max->data){
        return false;
    }
    return isBST(root->left, min, root) && isBST(root->right, root, max);

}

int main(){
    Node* root = NULL;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Is the tree a BST: " << (isBST(root, NULL, NULL)? "Yes" : "No") << endl;
return 0;
}